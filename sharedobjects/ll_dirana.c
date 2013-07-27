/*
 * libdirana.c
 *
 *  Created on: 16/lug/2013
 *      Author: user
 */

#include "DSPinterface.h"
#include <stdio.h>

/* library APIs  declarations */
STATUS initDirana(void)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS setSource(DR_AUDIO_SOURCES_TYPES p_source )
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}


STATUS getSource(DR_AUDIO_SOURCES_TYPES *p_source)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}


STATUS setVolume(int p_volume)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}


STATUS getVolume(int *p_volume)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}


//STATUS getStatus(DR_DSP_STATUS *p_status);
STATUS setChannelGain(AMPLI_CHANNEL p_channel, AMPLI_GAINS p_gain)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS getChannelGain(AMPLI_CHANNEL p_channel, AMPLI_GAINS *p_gain)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS playSin(int p_volume)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS doMute(void)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS doDeMute(void)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}


STATUS change_band(TYPE_BAND p_new_band)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

void get_band(TYPE_BAND p_band, TYPE_SUB_BAND p_subband)
{
	printf("Function Activated: %s (dirana)\n",__func__);
}

STATUS set_frequency(int p_frequency, TYPE_BAND p_band, TYPE_SUB_BAND p_subAM_band)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

int get_frequency()
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}


STATUS set_LeafDiceCfg(int p_freq, TYPE_BAND p_band, TYPE_SUB_BAND p_subAM_band)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS get_Freq_Band_fromTuner(int *p_freq, TYPE_BAND *p_band, TYPE_SUB_BAND *p_subband)
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}



/* main functions */
STATUS setSourceAUX()
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS SetAuxOnPrimaryStereo()
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS SetTunerOnPrimaryStereo()
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS SetI2SOnPrimaryStereo()
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS SetCdcOnPrimaryStereo()
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}

STATUS SetPhoneOnPrimaryStereo()
{
	printf("Function Activated: %s (dirana)\n",__func__);
	return OK;
}



