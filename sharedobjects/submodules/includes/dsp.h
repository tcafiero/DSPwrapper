/******************************************************/
/*****   libDirana  Header file  **********************/
/*****   Akhela                  **********************/
/******************************************************/

#ifndef DSP_H
#define DSP_H

#include "Radio_774x.h"
#include "ri_audio_7741.h"
#include "SDSP_7741.h"
#include "ri_dsp_define.h"
#include "ri_audio_7741.h"
#include "stdint.h"


typedef uint8_t uint8 ;
typedef uint16_t uint16 ;
typedef uint32_t uint32 ;
typedef uint64_t uint64 ;
typedef int8_t sint8 ;
typedef int16_t sint16 ;
typedef int32_t sint32 ;
typedef int64_t sint64 ;



#define DELAY_TIME 10000
#define X_REG_SIZE 3
#define Y_REG_SIZE 2
#define TUNER_REG_SIZE_WRITE 7
#define TUNER_REG_SIZE_READ 11
#define SAF7730ADDR (0x38>>1)
#define AMPLADDR (0xD8>>1)
#define ADDR SAF7730ADDR
#define MAX_BUF 256

#define TUNER_T1A_ADDRESS  0x62   /* main_tuner   ->   Lupin: 0xC4 */
#define TUNER_T1B_ADDRESS  0x60   /*  sub_tuner   ->   Lupin: 0xC0 */


/** \def <tt>BALANCE_MIN</tt>Min balance value*/
#define BALANCE_MIN          -11
/** \def <tt>BALANCE_MAX</tt>Max balance value*/
#define BALANCE_MAX           11
/** \def <tt>BALANCE_DEFAULT</tt>Default balance value*/
#define BALANCE_DEFAULT        0


/** \def <tt>FADER_MIN</tt>Min fader value*/
#define FADER_MIN            -11
/** \def <tt>FADER_MAX</tt>Max fader value*/
#define FADER_MAX             11
/** \def <tt>FADER_DEFAULT</tt>Default fader value*/
#define FADER_DEFAULT          0

/** \def <tt>BASS_MIN</tt>Min bass value*/
#define BASS_MIN             -10
/** \def <tt>BASS_MAX</tt>Max bass value*/
#define BASS_MAX              10
/** \def <tt>BASS_DEFAULT</tt>Default bass value*/
#define BASS_DEFAULT           0

/** \def <tt>TREBLE_MIN</tt>Min treble value*/
#define TREBLE_MIN           -10
/** \def <tt>TREBLE_MAX</tt>Max treble value*/
#define TREBLE_MAX            10
/** \def <tt>TREBLE_DEFAULT</tt>Default treble value*/
#define TREBLE_DEFAULT         0         0


#define LOUDNESS_ON 1
#define LOUDNESS_OFF 0

// Loudness treble filter
#define LOUDNESS_T_BOOST_MAX (0x3A3) // 9dB
#define LOUDNESS_T_COEFF 5

// Loudness bass filter
#define LOUDNESS_B_BOOST_MAX (0x614)   // 17dB
#define LOUDNESS_B_COEFF 8


/** \def <tt>TREBLE_DEFAULT</tt>Number of treble table coefficients */
#define TREBLE_NB_COEFF 6
/** \def <tt>TREBLE_DEFAULT</tt>Number of volume table coefficients */
#define VOLUME_NB_STEP 80

#define LOUDNESS_STEPS 15
/**
 * Maximum attenuation used in volume table calculation
 */
#define MAX_DB_ATTENUATION 120

#define SUPERPOS_VOLUME_DB_STEPS 68

#define VOLUMEINDBTABLE  121

/**
 * Balance table
 */
extern const uint16 balance_table[BALANCE_MAX*2+1][2];

/**
 * Fader table
 */
extern const uint16 fader_table[BALANCE_MAX*2+1][2];

extern const uint16 bass_table[BASS_MAX*2+1];

extern const uint16 bass_coefficients_table[10];

extern const uint16 treble_table[TREBLE_MAX*2+1][TREBLE_NB_COEFF];

extern const uint16 Loudness_treble_filter[LOUDNESS_T_COEFF];

extern const uint16 Loudness_bass_filter[LOUDNESS_B_COEFF];

extern const uint16 superpos_volume_table[SUPERPOS_VOLUME_DB_STEPS];

extern const uint16 loudness_boost_table[VOLUME_NB_STEP + 1];





STATUS dspStart(int p_devnum);
STATUS dspInit();
STATUS initTuner();
STATUS doDspMute(int val);
STATUS dspWrite(unsigned int p_address,
                unsigned char p_reg_size,
				unsigned int p_value_to_write);
STATUS dspRead( unsigned int p_addr, 
                unsigned char p_reg_size,
				int *p_read_value );
STATUS dspTunerWrite(unsigned int p_tuner_address,
		unsigned char p_reg_size,
		unsigned char * p_value_to_write);
STATUS dspTunerRead(unsigned int p_tuner_address,
		unsigned char p_reg_size,
		unsigned char *p_value_read);
STATUS dspEnd (void);
STATUS setSlvAddr(int p_addr);

int open_device (char *p_devname);
int close_device ();
//int HDR_I2C_IOctlWrite(char *p_param, unsigned char p_param_size);
  STATUS startUpDiRaNAprocedure();

  #define Radio1_on_Primary     ADSP_EASYP_SrcSw_Tuner1onA //Set tuner as primary source
  #define CD_A_On_Primay        ADSP_EASYP_SrcSw_AIN2onA   //Set Cd Changer as primary source
  #define Aux_on_Primary        ADSP_EASYP_SrcSw_AIN0onA   //Set Auxiliary source as primary source
  #define CD_Audio_On_Primary   ADSP_EASYP_SrcSw_I2S2onA   //Set Cd Audio as primary source
  #define Mp3_On_Primary        ADSP_EASYP_SrcSw_I2S2onA   //Set Mp3 src  as primary source
  #define TTS_On_Primary        ADSP_EASYP_SrcSw_I2S3onA   //Set TTS  as primary source
  #define BT_on_Primary         ADSP_EASYP_SrcSw_I2S4onA   //Set BT input as primary source
  #define DAB_on_Primary        ADSP_EASYP_SrcSw_I2S1onA   //Set DAB input as primary source

  #define Radio1_on_Secondary   ADSP_EASYP_SrcSw_Tuner1onB //Set tuner as Secondary source
  #define CD_A_On_Secondary     ADSP_EASYP_SrcSw_AIN2onB   //Set Cd Changer as Secondary source
  #define Aux_on_Secondary      ADSP_EASYP_SrcSw_AIN0onB   //Set Auxiliary source as Secondary source
  #define CD_Audio_On_Secondary ADSP_EASYP_SrcSw_I2S2onB   //Set Cd Audio as Secondary source
  #define Mp3_On_Secondary      ADSP_EASYP_SrcSw_I2S2onB   //Set Mp3 src  as Secondary source
  #define MicIn_On_Secondary    ADSP_EASYP_SrcSw_I2S2onB   //Set Mic In On Secondary
  #define TTS_On_Secondary      ADSP_EASYP_SrcSw_I2S3onB   //Set TTS  as Secondary source
  #define PhoneA_viaAD12        ADSP_EASYP_SrcSw_AIN4ViaAD12  //Set Phone source as primary in AD 12
  #define PhoneA_viaAD34        ADSP_EASYP_SrcSw_AIN4ViaAD34  //Set Phone source as Secondary in AD 34

  #define Nav_viaAD12           ADSP_EASYP_SrcSw_AIN3ViaAD12 //Nav Input via AD12
#endif //#ifndef DSP_H
