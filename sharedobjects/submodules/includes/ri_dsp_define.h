/********************************************************************************
 *  C-Header file for Dirana2                                                   *
 ********************************************************************************
 *                                                                              *
 *  File name    : ri_dsp_define.h                                              *
 *                                                                              *
 *  Purpose      : This file contains defines not present on Philips include    *
 *                 file                                                         *
 ********************************************************************************/

#ifndef DSP_DEFINE_H
#define DSP_DEFINE_H

/* Hw control registers for dsps. */   
#define DSPs_HW_CTR_REG            0x000010
/* Control register for Clocks and PLLs */
#define CLKPLL_CTR_REG             0x000020
/* I2s Control �1� register analog power-down  register */
#define APD_CTRL1                  0x000040

/* Connection register for the TDSP1 for RDS */
#define RDS_CONN_TDSP1_REG         0x010FF0

/* Miscellaneous control register for TDSP1E */
#define TDSP1E_MISC_CTR_REG        0x030ff9

/* RDS1 control register */
#define RDS1_CTR_REG               0x000035
/* RDS2 control register */
#define RDS2_CTR_REG               0x00003D

/* Frequency mixer �0� register for PDC2 */
#define PDC2_FMIX_0_REG            0x050FF5
/* Frequency mixer �1� register for PDC2 */
#define PDC2_FMIX_1_REG            0x050FD8

/* Frequency mixer �0� register for PDC1 */
#define PDC1_FMIX_0_REG            0x010FF5
/* Frequency mixer �1� register for PDC1 */
#define PDC1_FMIX_1_REG            0x010FD8

/* I2s input output Control register */                                       
#define IIC_IIS_IO_ConTRol         0x0D0FF6   

/* BANDWIDTH DURING AFUPDATE  */                                       
#define FCIB_1_MinBw_AFU           0x010327   


#endif //#ifndef DSP_DEFINE_H

