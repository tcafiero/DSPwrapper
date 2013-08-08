%module dsp

%{
#include "DSPinterface.h"
%}

typedef enum {
   SRC_NO_SOURCE,
   SRC_TUNER,
   SRC_CD,
   SRC_MP3,
   SRC_CDC,
   SRC_AUX,
   SRC_PHONE,//12s4
   SRC_TTS,
   SRC_TA_PTY,
   SRC_TTS_ON_AUX,
   SRC_AUX_CONVERGENCE,
   SRC_MAX_AUDIO_SOURCES

}  DR_AUDIO_SOURCES_TYPES;

/*
typedef enum {

   ON,
   OFF,
   DR_ERROR

}  DR_DSP_STATUS;
*/


typedef enum {

   AMP_ON,
   AMP_OFF
}  AMP_STATUS;



typedef enum {

   ERROR,
   OK
}  STATUS;


typedef enum {

   AMP_NO_CHANNEL,
   AMP_FRONT_CHANNEL,
   AMP_REAR_CHANNEL,
   AMP_END_CHANNEL

} AMPLI_CHANNEL;


typedef enum {
   NO_GAIN,
   LOW_GAIN12,
   HIGH_GAIN26,
   END_GAIN

} AMPLI_GAINS;


union USUC
{
  unsigned short us;                                            
  unsigned char uc[2];
};


typedef enum
{
	FM_BAND,
	AM_BAND
}TYPE_BAND;

typedef enum
{
	AM_MW_BAND,
	AM_KW_BAND
}TYPE_SUB_BAND;


typedef struct
{
  /* IF Filter center frequency */   /* 1 bytes */
  int FM_IF_Filter_Center_Freq_Main_tuner;
  int AM_IF_Filter_Center_Freq_Main_tuner;
  int FM_IF_Filter_Center_Freq_Sub_tuner;
  int AM_IF_Filter_Center_Freq_Sub_tuner;
  /* Offset alignment */   /* 3 bytes */
  int FM_Offset_Main_tuner_Europe_H;
  int FM_Offset_Main_tuner_Europe_L;
  int FM_Offset_Main_tuner_Japan_H;
  int FM_Offset_Main_tuner_Japan_L;
  int MW_Offset_tuner_Europe_H;
  int MW_Offset_tuner_Europe_L;
  int KW_Offset_tuner_H;
  int KW_Offset_tuner_L;
  int MW_Offset_tuner_USA_H;
  int MW_Offset_tuner_USA_L;
  /* Level alignment */   /* 2 bytes */
  int FM_Level_Main_tuner;
  int FM_Level_Sub_tuner;
  int FM_Level_Main_tuner_Japan;
  int FM_Level_Sub_tuner_Japan;
  int MW_Level_Main_tuner;
  int MW_Level_Sub_tuner;
  int KW_Level_Main_tuner;
  int KW_Level_Sub_tuner;
  /* Stereo decoder */   /* 2 bytes */
  int FM_Stereo_decoder;
  /* free RESERVED */   /* 5 bytes */
  /* CheckSum */   /* 1 byte */
}  DIRANA_ALIGNMENT_TYPE;

int g_current_volume;

#define VOLUMEINDBTABLE  121
#define MAXVOLSTEP 30 + 1


/* library APIs  declarations */
extern STATUS initDirana(void);
extern STATUS setSource(DR_AUDIO_SOURCES_TYPES p_source );
extern STATUS getSource(DR_AUDIO_SOURCES_TYPES *p_source);
extern STATUS setVolume(int p_volume);
extern STATUS getVolume(int *p_volume);
extern STATUS SetBalance( int8_t p_balance );
extern STATUS SetFader( int8_t p_fader );
extern STATUS SetLoudness( uint8_t p_loudness );
//STATUS getStatus(DR_DSP_STATUS *p_status);
extern STATUS setChannelGain(AMPLI_CHANNEL p_channel, AMPLI_GAINS p_gain);
extern STATUS getChannelGain(AMPLI_CHANNEL p_channel, AMPLI_GAINS *p_gain);
extern STATUS playSin(int p_volume);
extern STATUS doMute(void);
extern STATUS doDeMute(void);

extern STATUS change_band(TYPE_BAND p_new_band);
extern void get_band(TYPE_BAND p_band, TYPE_SUB_BAND p_subband);
extern STATUS set_frequency(int p_frequency, TYPE_BAND p_band, TYPE_SUB_BAND p_subAM_band);
extern int get_frequency();

extern STATUS set_LeafDiceCfg(int p_freq, TYPE_BAND p_band, TYPE_SUB_BAND p_subAM_band);
extern STATUS get_Freq_Band_fromTuner(int *p_freq, TYPE_BAND *p_band, TYPE_SUB_BAND *p_subband);


/* main functions */
extern STATUS setSourceAUX();
extern STATUS SetAuxOnPrimaryStereo();
extern STATUS SetTunerOnPrimaryStereo();
extern STATUS SetI2SOnPrimaryStereo();
extern STATUS SetCdcOnPrimaryStereo();
extern STATUS SetPhoneOnPrimaryStereo();
///******************************///
