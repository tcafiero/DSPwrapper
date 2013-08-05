///******************************************************///
///******************************************************///
///*************   libDirana  Source file   *************///
///*************   Akhela                   *************///
///******************************************************///
///******************************************************///

///**** System's includes ****///
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

///**** Library's includes ****///
#include "i2c-dev.h"
#include "DSPinterface.h"
#include "dsp.h"
#include "utils.h"


///* global statics *///
int g_I2C_hndl;


int g_amp_on = AMP_OFF;

/* Buffer to allow a switch on secondary i2c bus */
static unsigned char g_tuner_SwitchOnSecBusBuf[] =
{
  0x00, 0xFF, 0xFF
};

#define SUPERPOS_VOLUME_DB_STEPS 68
// Superposition block volume array
const unsigned short superpos_volume_table[SUPERPOS_VOLUME_DB_STEPS] =
{
    0x000, // -inf
    0xFFE, //-66
    0xFFE, //-65
    0xFFE, //-64
    0xFFE, //-63
    0xFFE, //-62
    0xFFE, //-61
    0xFFD, //-60
    0xFFD, //-59
    0xFFD, //-58
    0xFFD, //-57
    0xFFC, //-56
    0xFFC, //-55
    0xFFB, //-54
    0xFFB, //-53
    0xFFA, //-52
    0xFFA, //-51
    0xFF9, //-50
    0xFF8, //-49
    0xFF7, //-48
    0xFF6, //-47
    0xFF5, //-46
    0xFF4, //-45
    0xFF3, //-44
    0xFF1, //-43
    0xFEF, //-42
    0xFED, //-41
    0xFEB, //-40
    0xFE9, //-39
    0xFE6, //-38
    0xFE3, //-37
    0xFDF, //-36
    0xFDB, //-35
    0xFD7, //-34
    0xFD2, //-33
    0xFCC, //-32
    0xFC6, //-31
    0xFBF, //-30
    0xFB7, //-29
    0xFAE, //-28
    0xFA4, //-27
    0xF99, //-26
    0xF8C, //-25
    0xF7E, //-24
    0xF6F, //-23
    0xF5D, //-22
    0xF49, //-21
    0xF33, //-20
    0xF1A, //-19
    0xEFE, //-18
    0xEDE, //-17
    0xEBB, //-16
    0xE93, //-15
    0xE67, //-14
    0xE35, //-13
    0xDFD, //-12
    0xDBE, //-11
    0xD78, //-10
    0xD29, //-9
    0xCD0, //-8
    0xC6D, //-7
    0xBFD, //-6
    0xB80, //-5
    0xAF3, //-4
    0xA56, //-3
    0x9A5, //-2
    0x8DE, //-1
    0x800, //0

};

///***************************************************///
///*  DSP Layer interfaces                           *///
///***************************************************///

/* ************************************************  */
/*   API    : doDspInit                                */
/*   RETURN : OK or ERROR                            */
/* ************************************************* */
STATUS doDspInit()
{
   STATUS l_res = OK;
   //step 0
   	//command to set IFAGC at maximum attenuation to allow correct IFADC start-up
   	unsigned char tuner_init[2] = {0x55, 0x38};
   	unsigned char tuner_read[TUNER_REG_SIZE_READ] ={0x00};
    l_res = dspTunerWrite( TUNER_T1A_ADDRESS, Y_REG_SIZE, &tuner_init[0] );

    if(l_res ==OK)
    {
    	   usleep(DELAY_TIME);
	l_res = dspTunerRead(TUNER_T1A_ADDRESS, TUNER_REG_SIZE_READ, &tuner_read[0]);
    }

   l_res = dspWrite( 0x10, X_REG_SIZE, 0x1249 );//Reset all DSPs DSP_CTR

   if(l_res == OK)
     {
  	  l_res = dspWrite(0x10,X_REG_SIZE,0x1248);//Release TDSP1
        usleep(DELAY_TIME);
     }

   if(l_res == OK)
     {
  	  l_res = dspWrite(0x10,X_REG_SIZE,0x1208);//Release TDSP1E
        usleep(DELAY_TIME);
     }

   if(l_res == OK)
   {
	  l_res = dspWrite(0x10,X_REG_SIZE,0x00);//Release TDSP2, SDSP and ADSP
      usleep(DELAY_TIME);
   }

   if(l_res == OK)
   {
      l_res = dspWrite(0x20,X_REG_SIZE,0xCC6);
   }

   if(l_res == OK)
   {
      l_res = dspWrite(0x0901FB, X_REG_SIZE,0x800000); /* Start all SRC's */
   }

   if(l_res == OK)
   {
	   l_res = dspWrite(0x010005, 3, 0x000052);  /* Main FM on Primary channel via SRC1 */
    }
   if(l_res == OK)
    {
 	   l_res = dspWrite(0x0D006F, 3, 0x000013);  /* Main FM on Primary channel via SRC1 */
    }

   if(l_res == OK)
   {
      l_res = dspWrite(0x0901FC, X_REG_SIZE,0x800000);
   }

   if(l_res == OK)
   {
      l_res = dspWrite(0x0901FD, X_REG_SIZE,0x800000);
   }

   if(l_res == OK)
   {
      l_res = dspWrite(0x0901FE, X_REG_SIZE,0x800000);
   }

   if(l_res == OK)
   {
      l_res = dspWrite(ADSP_X_KickOffADSP, X_REG_SIZE,0x000001); ///kickOff ADSP
   }

  return(l_res);
}




/* ************************************************  */
/*   API    : dspStart                               */
/*   RETURN : OK or ERROR                            */
/* ************************************************* */
STATUS dspStart(int p_devnum)
{
   char l_devname[MAX_BUF];
   STATUS  l_res = OK;
   g_I2C_hndl=0;
   snprintf(l_devname,MAX_BUF,"/dev/i2c-%d",p_devnum);

   int fd = open_device (l_devname);

   if ( fd < 0 )
   {
      l_res=ERROR;
   }

   if(l_res == OK)
   {
	  l_res = setSlvAddr(ADDR);
   }

   if(l_res == OK)
     {
   		l_res = startUpDiRaNAprocedure();
     }

   return (l_res);
}

STATUS dspEnd()
{
 return close_device();
}

/** ************************************************  **/
/**   API    : dspWrite                                */
/**   RETURN : OK or ERROR                             */
/** ************************************************* **/
STATUS dspWrite(unsigned int p_address,
                unsigned char p_reg_size,
				unsigned int p_value_to_write)
{
   unsigned char l_data[6];
   struct i2c_rdwr_ioctl_data l_work_queue;
   struct i2c_msg l_msg_vect[2];  
   int l_ret=0;
   unsigned char *l_p_data;
   unsigned char l_add_H=0;
   unsigned char l_add_M=0;
   unsigned char l_add_L=0;
   unsigned char l_radio_address=SAF7730ADDR;
   
   STATUS l_ret_status=OK;
   
   if(g_I2C_hndl<=0)
   {
      PrintMessage(RED_PRINT,"dspWrite: I2C handle is not valid!!!");
	  l_ret_status=ERROR;
   }
   
   if(OK == l_ret_status)
   {
     PrintMessage(RED_PRINT,"dspWrite: writing 0x%06X at address 0x%06X with reg size %d \n",p_value_to_write, p_address, p_reg_size );

     l_p_data=(unsigned char *)&p_address;

     l_add_H=*(l_p_data);
     l_add_M=*(++l_p_data);
     l_add_L=*(++l_p_data);
     l_data[0]=l_add_L;
     l_data[1]=l_add_M;
     l_data[2]=l_add_H;

     l_p_data=(unsigned char *)&p_value_to_write;

     if(p_reg_size==X_REG_SIZE)
     {
       l_data[3] = l_p_data[2];
       l_data[4] = l_p_data[1];
       l_data[5] = l_p_data[0];
     }


     if(p_reg_size==Y_REG_SIZE)
     {
       l_data[3] = l_p_data[1];
       l_data[4] = l_p_data[0];
     }

     l_msg_vect[0].addr=l_radio_address;        /** SETTO L'INDIRIZZO DELLO SLAVE SUL QUALE VOGLIO LEGGERE **/
     l_msg_vect[0].flags=0x0;                 /** operazione di scrittura dato **/
     l_msg_vect[0].len=p_reg_size+3;             /** 3 byte indirizzo registro + reg_size **/
     l_msg_vect[0].buf=(char *)&l_data[0];  /** buffer con address e valore da scrivere**/
     l_work_queue.nmsgs=1;
     l_work_queue.msgs=(struct i2c_msg*)&l_msg_vect[0];


     l_ret = ioctl(g_I2C_hndl,I2C_RDWR,(unsigned long)&l_work_queue);
//     PrintMessage(RED_PRINT,"\t ioctl l_work_queue with ret: %d\n",l_ret);

    if ( l_ret < 0 ) 
    {

       PrintMessage(RED_PRINT,"\tdspWrite:Error during I2C_RDWR ioctl with error code: %d\n",l_ret);
       l_ret_status=ERROR;
    }
    else
    {
      l_ret_status=OK;
    }
  }
  
  return(l_ret_status);
   
}


/** ************************************************  **/
/**   API    : dspRead                                 */
/**   RETURN : OK or ERROR                             */
/** ************************************************* **/
STATUS dspRead( unsigned int p_addr,
                unsigned char p_reg_size, 
				int *p_read_value )
{
	 PrintMessage(RED_PRINT,"dspRead: reading 0X%08X ",p_addr);

   struct i2c_rdwr_ioctl_data l_work_queue;
   struct i2c_msg l_msg_vect[2]; 
   int l_tmp_value=0;
   int l_ret;
   
   unsigned char l_data[7];
   unsigned char *l_p_data;
   unsigned char l_add_H=0;
   unsigned char l_add_M=0;
   unsigned char l_add_L=0;
   unsigned char l_radio_address=SAF7730ADDR;


   if(g_I2C_hndl<=0)
   {
      PrintMessage(RED_PRINT,"dspRead: I2C handle is not valid!!!");
      return (ERROR);
   }


   l_p_data=(unsigned char *)&p_addr;

   if (p_reg_size <= 3) 
   {
     l_add_H=*(l_p_data);
      l_add_M=*(++l_p_data);
      l_add_L=*(++l_p_data);

      l_data[0]=l_add_L;
      l_data[1]=l_add_M;
      l_data[2]=l_add_H;
      l_data[3]=0x00;
      l_data[4]=0x00;
      l_data[5]=0x00;


      l_msg_vect[0].addr=l_radio_address;        /** SETTO L'INDIRIZZO DELLO SLAVE SUL QUALE VOGLIO LEGGERE **/
      l_msg_vect[0].flags=0x4000;                 /** operazione di scrittura **/
      l_msg_vect[0].len=3;                     /** 3 byte **/
      l_msg_vect[0].buf=(char *)&l_data[0];  /** buffer da scrivere**/

      l_msg_vect[1].addr=l_radio_address;        /** SETTO L'INDIRIZZO DELLO SLAVE SUL QUALE VOGLIO LEGGERE **/
      l_msg_vect[1].flags=1;                /** operazione di lettura **/
      l_msg_vect[1].len=p_reg_size;               /** 3 byte **/
      l_msg_vect[1].buf=(char *)&l_data[3];  /** buffer da riempire con i valori letti**/

      l_work_queue.nmsgs=2;
      l_work_queue.msgs=(struct i2c_msg*)&l_msg_vect[0];

      ioctl(g_I2C_hndl,I2C_TIMEOUT,2);  /* set the timeout    */
      ioctl(g_I2C_hndl,I2C_RETRIES,1);  /* set the retries    */
      l_ret = ioctl(g_I2C_hndl,I2C_RDWR,(unsigned long)&l_work_queue);

      if ( l_ret < 0 ) 
      {
         PrintMessage(RED_PRINT,"\tdspRead:Error during I2C_RDWR ioctl with error code: %d\n",l_ret);
         return (ERROR);
      }
      else
      {
        memcpy((unsigned char *)&(l_tmp_value),(unsigned char *)&(l_data[3]),3);
        PrintMessage(RED_PRINT,"\t*-*-*-*-dspRead: valore letto=0X%08X",l_tmp_value);
         if( p_reg_size == Y_REG_SIZE ){

         p_read_value[0] = l_data[3]<<8 | l_data[4];

         }
         else if( p_reg_size == X_REG_SIZE )
         {

         p_read_value[0] = l_data[3]<<16 | l_data[4]<<8 | l_data[5];

         }
         else
         {
            PrintMessage(RED_PRINT,"\tdspRead: ERROR wrong register size!!!");
            return (ERROR);
         }

        return (OK);
      }
   }
   else
   {
      PrintMessage(RED_PRINT,"\tdspRead: ERROR wrong size");
   }

   return (ERROR);

}


/** ************************************************  **/
/**   API    : dspWrite                                */
/**   RETURN : OK or ERROR                             */
/** ************************************************* **/
STATUS dspTunerWrite(unsigned int p_tuner_address,
		unsigned char p_reg_size,
		unsigned char *p_value_to_write)
{
   struct i2c_rdwr_ioctl_data l_work_queue;
   struct i2c_msg l_msg_vect[2];
   int l_ret=0;
   unsigned char l_radio_address = SAF7730ADDR;

   STATUS l_ret_status=OK;

   if(g_I2C_hndl<=0)
   {
      PrintMessage(RED_PRINT,"dspTunerWrite: I2C handle is not valid!!!");
	  l_ret_status=ERROR;
   }

   if(OK == l_ret_status)
   {
     PrintMessage(RED_PRINT,"dspTunerWrite: writing 0x%X at address 0x%06X with reg size %d ", p_value_to_write, p_tuner_address, p_reg_size );

     /* WRITE 3 bytes of register address */

     l_msg_vect[0].addr = l_radio_address;    /** SETTO L'INDIRIZZO DELLO SLAVE SUL QUALE VOGLIO LEGGERE **/
     l_msg_vect[0].flags = 0x0;               /** operazione di scrittura dato **/
     l_msg_vect[0].len = X_REG_SIZE;//sizeof( g_tuner_SwitchOnSecBusBuf );    /** 3 byte size indirizzo  tuner **/
     l_msg_vect[0].buf =(char*) &g_tuner_SwitchOnSecBusBuf[0];   /** 3 byte indirizzo  tuner **/


     /* Write data into DIRANA */
     l_msg_vect[1].addr = p_tuner_address;//indirizzo leafdice main tuner
     l_msg_vect[1].flags = 0x0;
     l_msg_vect[1].len = p_reg_size;
     l_msg_vect[1].buf =(char *) &p_value_to_write[0];
//     int i=0;
//   	 for(i=0;i<TUNER_REG_SIZE_WRITE;i++)
//	  {
//		 PrintMessage(RED_PRINT,"\tp_value_to_write[%d] = 0x%x",i, p_value_to_write[i]);
//	   }


     l_work_queue.nmsgs=2;
     l_work_queue.msgs=(struct i2c_msg*)&l_msg_vect[0];

     /* Request Write Operation to TUNER */
     l_ret = ioctl(g_I2C_hndl,I2C_RDWR,(unsigned long)&l_work_queue);
     if ( l_ret < 0 )
    {
       PrintMessage(RED_PRINT,"\tdspTunerWrite:Error during I2C_RDWR ioctl with error code: %d\n",l_ret);
       l_ret_status=ERROR;
    }
    else
    {
      l_ret_status=OK;
    }
  }

  return(l_ret_status);

}


STATUS dspTunerRead(unsigned int p_tuner_address,
		unsigned char p_reg_size,
		unsigned char *p_value_read)
{
	STATUS l_ret_status=OK;
	int l_ret_ioctl= 0 ;
	struct i2c_rdwr_ioctl_data l_work_queue;
	struct i2c_msg l_msg_vect[2];

	if(g_I2C_hndl<=0)
	  {
		 PrintMessage(RED_PRINT,"dspTunerRead: I2C handle is not valid!!!");
	  l_ret_status=ERROR;
	  }

	  if(OK == l_ret_status)
	  {
		PrintMessage(RED_PRINT,"dspTunerRead: reading at address 0x%06X with reg size %d ", p_tuner_address, p_reg_size );

        /* WRITE 3 bytes of register address */
	   l_msg_vect[0].addr = SAF7730ADDR ;    /** SETTO L'INDIRIZZO DELLO SLAVE SUL QUALE VOGLIO LEGGERE **/
	   l_msg_vect[0].flags = 0x0;               /** operazione di scrittura dato **/
	   l_msg_vect[0].len = X_REG_SIZE;//sizeof( g_tuner_SwitchOnSecBusBuf );    /** 3 byte size indirizzo  tuner **/
	   l_msg_vect[0].buf =(char*) &g_tuner_SwitchOnSecBusBuf[0];   /** 3 byte indirizzo  tuner **/


	   l_msg_vect[1].addr=p_tuner_address;        /** SETTO L'INDIRIZZO DELLO SLAVE SUL QUALE VOGLIO LEGGERE **/
	   l_msg_vect[1].flags=1;                /** operazione di lettura **/
	   l_msg_vect[1].len=p_reg_size;               /** 3 byte **/
	   l_msg_vect[1].buf=(char *)&p_value_read[0];  /** buffer da riempire con i valori letti**/


	 l_work_queue.nmsgs=2;
	 l_work_queue.msgs=(struct i2c_msg*)&l_msg_vect[0];

    /* Request Write Operation to TUNER */
        l_ret_ioctl = ioctl(g_I2C_hndl,I2C_RDWR,(unsigned long)&l_work_queue);

        if(l_ret_ioctl<0)
        {
        	l_ret_status = ERROR;
        }
//        else
//        {
//          int i=0;
//		  for(i=0;i<p_reg_size;i++)
//		   {
//			 PrintMessage(RED_PRINT,"\tREAD tuner[%d] = 0x%x",i, p_value_read[i]);
//		  }
//        }
	  }


  return l_ret_status;
}


int open_device (char *p_devname)
{
  int l_ret = EXIT_SUCCESS;	
  
  printf("Apro il device %s\n",p_devname);
  g_I2C_hndl = open(p_devname,O_RDWR);
  if ( g_I2C_hndl < 0 )
  {
    printf("Non riesco ad aprire il file %s\n",p_devname);
	l_ret = EXIT_FAILURE;
    //return EXIT_FAILURE;
  }
  
  //return EXIT_SUCCESS;
  return(l_ret);
}

int close_device ()
{
  return close (g_I2C_hndl);
}


STATUS setSlvAddr(int p_addr)
{
   STATUS l_res = OK;

   if ( ioctl(g_I2C_hndl,I2C_SLAVE,p_addr) < 0 )
   {
      printf("Errore %d %s\n",errno,strerror(errno));
      l_res = ERROR;
   }

   return(l_res);

}


//************************************//
STATUS doDspMute(int val)
{
   STATUS l_res = OK;
   
   switch(val)
   {
      case 0:
      {
         if(l_res == OK)
         {
            /** disable MUTE on primary channel*/
            l_res = dspWrite(ADSP_Y_Mute_P,Y_REG_SIZE,0x000800); 
         }

         if(l_res == OK)
         {
            /** disable MUTE on secondary channel*/
            l_res = dspWrite(ADSP_Y_Mute_S,Y_REG_SIZE,0x000800); 
         }
      }
      break;
      case 1:
      {
         if(l_res == OK)
         {
            /** muting primary channel*/
            l_res = dspWrite(ADSP_Y_Mute_P,Y_REG_SIZE,0x000000);
         }

         if(l_res == OK)
         {
            /** muting secondary channel*/
            l_res = dspWrite(ADSP_Y_Mute_S,Y_REG_SIZE,0x000000);
         }
      }
      break;
      default:
      {
         l_res = ERROR;
      }
      break;
   }

   return(l_res);
}

STATUS initTuner()
{
	int l_res;
	STATUS l_return = OK;
	unsigned char tuner_read[TUNER_REG_SIZE_READ] ={ 0x00 };
	unsigned char tuner_init[] = {
		        0x30,0x87,0xAA,0xE2,0x07,0x00,0x04
		    };
//	int i=0;
//	for(i=0;i<TUNER_REG_SIZE_WRITE;i++)
//	  {
//	     PrintMessage(RED_PRINT,"\ttuner_init[%d] = 0x%x",i, tuner_init[i]);
//	  }
	l_res = dspTunerWrite( TUNER_T1A_ADDRESS, TUNER_REG_SIZE_WRITE, &tuner_init[0] );

if (l_res==OK )
	   {

	l_return= OK;
		l_res = dspTunerRead(TUNER_T1A_ADDRESS, TUNER_REG_SIZE_READ, &tuner_read[0]);
//		for(i=0;i<TUNER_REG_SIZE_READ;i++)
//			  {
//			     		 PrintMessage(RED_PRINT,"\ttuner_read[%d] = 0x%x",i, tuner_read[i]);
//			  }
  	  }
	else
	 {
		l_return= ERROR;
	  }
return l_return;
}

STATUS startUpDiRaNAprocedure()
{
	STATUS l_res = OK;

	//step 0
	//command to set IFAGC at maximum attenuation to allow correct IFADC start-up
	unsigned char tuner_init[2] = {0x55, 0x38};
    l_res = dspTunerWrite( TUNER_T1A_ADDRESS, Y_REG_SIZE, &tuner_init[0] );

    //step 1
    //Reset all DSPs
    if (OK == l_res )
     {
   	  l_res = dspWrite( 0x000010, X_REG_SIZE, 0x1249 );
     }
    //Set DSP speed to 135.2 MHz
    //step 2
    if(l_res == OK)
      {
         l_res = dspWrite(0x000020,X_REG_SIZE,0xCC6);
      }
    //step 3 e 4 patch--->necessarie?

    //step 5
    //Disable RGPDAC1 & 2 and IFAD1
    if(l_res == OK)
          {
             l_res = dspWrite(0x000040,X_REG_SIZE,0x3B20);
          }

    //step 6
    //Disable PDC1 Clock
    if(l_res == OK)
		 {
			l_res = dspWrite(0x000050,Y_REG_SIZE,0x07FE);
		 }

    //step 7
    //PDC2: Default changed
    if(l_res == OK)
   		 {
   			l_res = dspWrite(0x050FD4,X_REG_SIZE,0x070240);
   		 }

    //step 8
//    PDC2: AGC Gain default
    if(l_res == OK)
       		 {
       			l_res = dspWrite(0x050FCA,X_REG_SIZE,0xEA7DBF);
       		 }
    //step 9
    //Write PDC2 AGC gain default, required to activate the AGC_GAIN_1_2 setting
    if(l_res == OK)
           		 {
           			l_res = dspWrite(0x050FC0,X_REG_SIZE,0x0FF000);
           		 }
    //step 10
    //Release TDSP1
    if(l_res == OK)
       {
    	  l_res = dspWrite(0x000010,X_REG_SIZE,0x1248);//Release TDSP1
        }

    //step 11
       // Kick-Off Radio program
    if(l_res == OK)
        {
     	  l_res = dspWrite(0x010008,X_REG_SIZE,0x000001);
       }

    //step 12
       // Release TDSP1E
    if(l_res == OK)
           {
        	  l_res = dspWrite(0x000010,X_REG_SIZE,0x001208);
           }

    //step 13
       //13 DSP_CTR 000010 001249 000000 Release TDSP2, SDSP and ADSP
    if(l_res == OK)
              {
           	  l_res = dspWrite(0x000010,X_REG_SIZE,0x000000);
              }

    //step 14
       //14 DSP_CTR 000010 001249 000090 Enable dynamic PRAM (to use patches)
    if(l_res == OK)
		{
		  l_res = dspWrite(0x000010,X_REG_SIZE,0x000090);
	   }

    //step 15, 16 --> patch necessarie?

    //step 17
       // 17 ADSP_X_KeyCode / KickOffADSP 0D0001 000000 000001 KickOff ADSP
    if(l_res == OK)
		{
		  l_res = dspWrite(ADSP_X_KeyCode,X_REG_SIZE,0x00001);
	   }
    //step 18
       //18 SDSP_X_CtrlTS1 0901FB 000000 800000 Enable Sample Rate converter 1
    if(l_res == OK)
	   {
		  l_res = dspWrite(SDSP_X_CtrlTS1,X_REG_SIZE,0x800000);
	  }
    //step 19
          //19 PDC2_AGC_CTRL_0 050FF4 * 704317 Correct AGC_d thresholds & timing, to be sent after release of TDSPs
//    if(l_res == OK)
//	   {
//		  l_res = dspWrite(0x005FF4,X_REG_SIZE,0x704317);
//	  }

    //20 DAC_DELAY 0000C0 0033 0088 Enable Sequential DAC delay
//    if(l_res == OK)
//	   {
//		  l_res = dspWrite(0x0000C0,X_REG_SIZE,0x0088);
//	  }

//    21 TDSP1E_Y_IntVal5 0311B6 07FF 07F5
    if(l_res == OK)
	   {
		  l_res = dspWrite(TDSP1E_Y_IntVal5,X_REG_SIZE,0x07F5);
	  }
//    22 TDSP1E_Y_IntVal6 0311B7 07FA 07CF
    if(l_res == OK)
	   {
		  l_res = dspWrite(TDSP1E_Y_IntVal6,X_REG_SIZE,0x07CF);
	  }
//    23 TDSP1E_X_IntVal7 030189 066FC5 0621A5
    if(l_res == OK)
	   {
		  l_res = dspWrite(TDSP1E_X_IntVal7,X_REG_SIZE,0x0621A5);
	  }
//    24 TDSP1E_X_IntVal8 03018A 2E9CCC 1F47D0
//    Recommended AM level detector
//    coefficients:
//    enables reasonable AM seek time
//    (~50msec)
    if(l_res == OK)
  	   {
  		  l_res = dspWrite(TDSP1E_X_IntVal8,X_REG_SIZE,0x1F47D0);
  	  }
//    25 TDSP1_X_pFW_TunDly 01003A 010080 007080 Tuner delay, for correct AFU readout
    if(l_res == OK)
    	   {
    		  l_res = dspWrite(0x01003A,X_REG_SIZE,0x007080);
    	  }
//    26 ACIS_1_pIFIntDly 03013D * 028080 Corrected AM Noiseblanker value (patch)
    if(l_res == OK)
      	   {
      		  l_res = dspWrite(0x03013D,X_REG_SIZE,0x028080);
      	  }
//    27 TDSP1_X_FW_RadMod 010005 000052 000052 Set radio mode to FM
    if(l_res == OK)
		   {
			  l_res = dspWrite(TDSP1_X_FW_RadMod,X_REG_SIZE,0x000052);
		  }
//    28 ADSP_X_EasyP_Index 0D006F 000000 000013 Main FM to primary channel
    if(l_res == OK)
		   {
			  l_res = dspWrite(ADSP_X_EasyP_Index,X_REG_SIZE,0x000013);
		  }
//    29 ADSP_Y_Vol_Main1P 0D1050 0400 0800 Set primary channel to 0 dB
    if(l_res == OK)
   		   {
   			  l_res = dspWrite(ADSP_Y_Vol_Main1P,X_REG_SIZE,0x0800);
   		  }
//    30 ADSP_Y_Vol_Main2P 0D1051 0000 0200 Set primary channel to 0 dB
    if(l_res == OK)
      		   {
      			  l_res = dspWrite(ADSP_Y_Vol_Main2P,X_REG_SIZE,0x0200);
      		  }
//    31 TDSP1E_Y_FW_FDLE_1_RanOfs 03101A 0FC2 alignment Level alignment for FM radio mode
    if(l_res == OK)
          		   {
          			  l_res = dspWrite(TDSP1E_Y_FW_FDLE_1_RanOfs,X_REG_SIZE,0x0FC2);
          		  }
//    32 TDSP1E_Y_FMLR_1_GanCor 031312 054C alignment Stereo alignment for FM radio mode
    if(l_res == OK)
              		   {
              			  l_res = dspWrite(TDSP1E_Y_FMLR_1_GanCor,X_REG_SIZE,0x054C);
              		  }
//    33 PDC2_FMIX_0 050FF5 E27647 alignment Frequency offset alignment value for FM
    if(l_res == OK)
	   {
		  l_res = dspWrite(0x050FF5,X_REG_SIZE,0xE27647);
	  }
//    34 PDC2_FMIX_1 050FD8 E27647 alignment Frequency offset alignment value for FM
    if(l_res == OK)
	   {
		  l_res = dspWrite(0x050FD8,X_REG_SIZE,0xE27647);
	  }
//    35 LEAF-DICE preset command to FM, 98.0MHz  00FFFF - RS (1) C4 30 87 A8 00 0x 00    00
//    Note: tuning command needs to be sent always after radio mode selection
	unsigned char tuner_tuning[7] = {0x30, 0x87, 0xA8, 0x00, 0x00, 0x00, 0x00};
	if(l_res == OK)
	   {
		l_res = dspTunerWrite( TUNER_T1A_ADDRESS, Y_REG_SIZE, &tuner_tuning[0] );
	   }

//    36 ADSP_Y_Mute_P 0D106D 0000 0800 Release primary channel mute
	 if(l_res == OK)
	   {
		  l_res = dspWrite(ADSP_Y_Mute_P,X_REG_SIZE,0x0800);
	  }

	 return l_res;
}

