/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#define SWIGJAVA

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif 
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif



/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  (*jenv)->ExceptionClear(jenv);
  excep = (*jenv)->FindClass(jenv, except_ptr->java_exception);
  if (excep)
    (*jenv)->ThrowNew(jenv, excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include "libdirana.h"


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT void JNICALL Java_dspJNI_USUC_1us_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  union USUC *arg1 = (union USUC *) 0 ;
  unsigned short arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(union USUC **)&jarg1; 
  arg2 = (unsigned short)jarg2; 
  if (arg1) (arg1)->us = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_USUC_1us_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  union USUC *arg1 = (union USUC *) 0 ;
  unsigned short result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(union USUC **)&jarg1; 
  result = (unsigned short) ((arg1)->us);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_USUC_1uc_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  union USUC *arg1 = (union USUC *) 0 ;
  unsigned char *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(union USUC **)&jarg1; 
  arg2 = *(unsigned char **)&jarg2; 
  {
    size_t ii;
    unsigned char *b = (unsigned char *) arg1->uc;
    for (ii = 0; ii < (size_t)2; ii++) b[ii] = *((unsigned char *) arg2 + ii);
  }
  
}


SWIGEXPORT jlong JNICALL Java_dspJNI_USUC_1uc_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  union USUC *arg1 = (union USUC *) 0 ;
  unsigned char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(union USUC **)&jarg1; 
  result = (unsigned char *)(unsigned char *) ((arg1)->uc);
  *(unsigned char **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_dspJNI_new_1USUC(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  union USUC *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (union USUC *)calloc(1, sizeof(union USUC));
  *(union USUC **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_delete_1USUC(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  union USUC *arg1 = (union USUC *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(union USUC **)&jarg1; 
  free((char *) arg1);
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1IF_1Filter_1Center_1Freq_1Main_1tuner_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_IF_Filter_Center_Freq_Main_tuner = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1IF_1Filter_1Center_1Freq_1Main_1tuner_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_IF_Filter_Center_Freq_Main_tuner);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1AM_1IF_1Filter_1Center_1Freq_1Main_1tuner_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->AM_IF_Filter_Center_Freq_Main_tuner = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1AM_1IF_1Filter_1Center_1Freq_1Main_1tuner_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->AM_IF_Filter_Center_Freq_Main_tuner);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1IF_1Filter_1Center_1Freq_1Sub_1tuner_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_IF_Filter_Center_Freq_Sub_tuner = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1IF_1Filter_1Center_1Freq_1Sub_1tuner_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_IF_Filter_Center_Freq_Sub_tuner);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1AM_1IF_1Filter_1Center_1Freq_1Sub_1tuner_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->AM_IF_Filter_Center_Freq_Sub_tuner = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1AM_1IF_1Filter_1Center_1Freq_1Sub_1tuner_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->AM_IF_Filter_Center_Freq_Sub_tuner);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Offset_1Main_1tuner_1Europe_1H_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_Offset_Main_tuner_Europe_H = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Offset_1Main_1tuner_1Europe_1H_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_Offset_Main_tuner_Europe_H);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Offset_1Main_1tuner_1Europe_1L_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_Offset_Main_tuner_Europe_L = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Offset_1Main_1tuner_1Europe_1L_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_Offset_Main_tuner_Europe_L);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Offset_1Main_1tuner_1Japan_1H_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_Offset_Main_tuner_Japan_H = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Offset_1Main_1tuner_1Japan_1H_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_Offset_Main_tuner_Japan_H);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Offset_1Main_1tuner_1Japan_1L_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_Offset_Main_tuner_Japan_L = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Offset_1Main_1tuner_1Japan_1L_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_Offset_Main_tuner_Japan_L);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Offset_1tuner_1Europe_1H_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->MW_Offset_tuner_Europe_H = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Offset_1tuner_1Europe_1H_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->MW_Offset_tuner_Europe_H);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Offset_1tuner_1Europe_1L_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->MW_Offset_tuner_Europe_L = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Offset_1tuner_1Europe_1L_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->MW_Offset_tuner_Europe_L);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1KW_1Offset_1tuner_1H_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->KW_Offset_tuner_H = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1KW_1Offset_1tuner_1H_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->KW_Offset_tuner_H);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1KW_1Offset_1tuner_1L_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->KW_Offset_tuner_L = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1KW_1Offset_1tuner_1L_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->KW_Offset_tuner_L);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Offset_1tuner_1USA_1H_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->MW_Offset_tuner_USA_H = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Offset_1tuner_1USA_1H_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->MW_Offset_tuner_USA_H);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Offset_1tuner_1USA_1L_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->MW_Offset_tuner_USA_L = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Offset_1tuner_1USA_1L_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->MW_Offset_tuner_USA_L);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Level_1Main_1tuner_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_Level_Main_tuner = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Level_1Main_1tuner_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_Level_Main_tuner);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Level_1Sub_1tuner_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_Level_Sub_tuner = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Level_1Sub_1tuner_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_Level_Sub_tuner);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Level_1Main_1tuner_1Japan_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_Level_Main_tuner_Japan = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Level_1Main_1tuner_1Japan_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_Level_Main_tuner_Japan);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Level_1Sub_1tuner_1Japan_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_Level_Sub_tuner_Japan = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Level_1Sub_1tuner_1Japan_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_Level_Sub_tuner_Japan);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Level_1Main_1tuner_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->MW_Level_Main_tuner = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Level_1Main_1tuner_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->MW_Level_Main_tuner);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Level_1Sub_1tuner_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->MW_Level_Sub_tuner = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1MW_1Level_1Sub_1tuner_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->MW_Level_Sub_tuner);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1KW_1Level_1Main_1tuner_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->KW_Level_Main_tuner = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1KW_1Level_1Main_1tuner_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->KW_Level_Main_tuner);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1KW_1Level_1Sub_1tuner_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->KW_Level_Sub_tuner = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1KW_1Level_1Sub_1tuner_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->KW_Level_Sub_tuner);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Stereo_1decoder_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->FM_Stereo_decoder = arg2;
}


SWIGEXPORT jint JNICALL Java_dspJNI_DIRANA_1ALIGNMENT_1TYPE_1FM_1Stereo_1decoder_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  result = (int) ((arg1)->FM_Stereo_decoder);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_dspJNI_new_1DIRANA_1ALIGNMENT_1TYPE(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  DIRANA_ALIGNMENT_TYPE *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (DIRANA_ALIGNMENT_TYPE *)calloc(1, sizeof(DIRANA_ALIGNMENT_TYPE));
  *(DIRANA_ALIGNMENT_TYPE **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_delete_1DIRANA_1ALIGNMENT_1TYPE(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  DIRANA_ALIGNMENT_TYPE *arg1 = (DIRANA_ALIGNMENT_TYPE *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(DIRANA_ALIGNMENT_TYPE **)&jarg1; 
  free((char *) arg1);
}


SWIGEXPORT void JNICALL Java_dspJNI_g_1current_1volume_1set(JNIEnv *jenv, jclass jcls, jint jarg1) {
  int arg1 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  g_current_volume = arg1;
}


SWIGEXPORT jint JNICALL Java_dspJNI_g_1current_1volume_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)g_current_volume;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_VOLUMEINDBTABLE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int) 121;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_MAXVOLSTEP_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int) 30+1;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_initDirana(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  result = (STATUS)initDirana();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_setSource(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  DR_AUDIO_SOURCES_TYPES arg1 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (DR_AUDIO_SOURCES_TYPES)jarg1; 
  result = (STATUS)setSource(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_getSource(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  DR_AUDIO_SOURCES_TYPES *arg1 = (DR_AUDIO_SOURCES_TYPES *) 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(DR_AUDIO_SOURCES_TYPES **)&jarg1; 
  result = (STATUS)getSource(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_setVolume(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  int arg1 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  result = (STATUS)setVolume(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_getVolume(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  int *arg1 = (int *) 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(int **)&jarg1; 
  result = (STATUS)getVolume(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_setChannelGain(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  jint jresult = 0 ;
  AMPLI_CHANNEL arg1 ;
  AMPLI_GAINS arg2 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (AMPLI_CHANNEL)jarg1; 
  arg2 = (AMPLI_GAINS)jarg2; 
  result = (STATUS)setChannelGain(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_getChannelGain(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2) {
  jint jresult = 0 ;
  AMPLI_CHANNEL arg1 ;
  AMPLI_GAINS *arg2 = (AMPLI_GAINS *) 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (AMPLI_CHANNEL)jarg1; 
  arg2 = *(AMPLI_GAINS **)&jarg2; 
  result = (STATUS)getChannelGain(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_playSin(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  int arg1 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  result = (STATUS)playSin(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_doMute(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  result = (STATUS)doMute();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_doDeMute(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  result = (STATUS)doDeMute();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_change_1band(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  TYPE_BAND arg1 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (TYPE_BAND)jarg1; 
  result = (STATUS)change_band(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_dspJNI_get_1band(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  TYPE_BAND arg1 ;
  TYPE_SUB_BAND arg2 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (TYPE_BAND)jarg1; 
  arg2 = (TYPE_SUB_BAND)jarg2; 
  get_band(arg1,arg2);
}


SWIGEXPORT jint JNICALL Java_dspJNI_set_1frequency(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2, jint jarg3) {
  jint jresult = 0 ;
  int arg1 ;
  TYPE_BAND arg2 ;
  TYPE_SUB_BAND arg3 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  arg2 = (TYPE_BAND)jarg2; 
  arg3 = (TYPE_SUB_BAND)jarg3; 
  result = (STATUS)set_frequency(arg1,arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_get_1frequency(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)get_frequency();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_set_1LeafDiceCfg(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2, jint jarg3) {
  jint jresult = 0 ;
  int arg1 ;
  TYPE_BAND arg2 ;
  TYPE_SUB_BAND arg3 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  arg2 = (TYPE_BAND)jarg2; 
  arg3 = (TYPE_SUB_BAND)jarg3; 
  result = (STATUS)set_LeafDiceCfg(arg1,arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_get_1Freq_1Band_1fromTuner(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3) {
  jint jresult = 0 ;
  int *arg1 = (int *) 0 ;
  TYPE_BAND *arg2 = (TYPE_BAND *) 0 ;
  TYPE_SUB_BAND *arg3 = (TYPE_SUB_BAND *) 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(int **)&jarg1; 
  arg2 = *(TYPE_BAND **)&jarg2; 
  arg3 = *(TYPE_SUB_BAND **)&jarg3; 
  result = (STATUS)get_Freq_Band_fromTuner(arg1,arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_setSourceAUX(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  result = (STATUS)setSourceAUX();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_SetAuxOnPrimaryStereo(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  result = (STATUS)SetAuxOnPrimaryStereo();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_SetTunerOnPrimaryStereo(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  result = (STATUS)SetTunerOnPrimaryStereo();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_SetI2SOnPrimaryStereo(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  result = (STATUS)SetI2SOnPrimaryStereo();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_SetCdcOnPrimaryStereo(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  result = (STATUS)SetCdcOnPrimaryStereo();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_dspJNI_SetPhoneOnPrimaryStereo(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  STATUS result;
  
  (void)jenv;
  (void)jcls;
  result = (STATUS)SetPhoneOnPrimaryStereo();
  jresult = (jint)result; 
  return jresult;
}


#ifdef __cplusplus
}
#endif

