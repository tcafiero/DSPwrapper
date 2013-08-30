/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class dsp implements dspConstants {
  public static void setG_current_volume(int value) {
    dspJNI.g_current_volume_set(value);
  }

  public static int getG_current_volume() {
    return dspJNI.g_current_volume_get();
  }

  public static boolean initDSP() {
    return dspJNI.initDSP();
  }

  public static boolean dspEnd() {
    return dspJNI.dspEnd();
  }

  public static boolean setVolume(int p_volume) {
    return dspJNI.setVolume(p_volume);
  }

  public static boolean getVolume(SWIGTYPE_p_int p_volume) {
    return dspJNI.getVolume(SWIGTYPE_p_int.getCPtr(p_volume));
  }

  public static boolean increase_Volume() {
    return dspJNI.increase_Volume();
  }

  public static boolean decrease_Volume() {
    return dspJNI.decrease_Volume();
  }

  public static boolean doMute() {
    return dspJNI.doMute();
  }

  public static boolean doDeMute() {
    return dspJNI.doDeMute();
  }

  public static boolean SetBalance(int p_balance) {
    return dspJNI.SetBalance(p_balance);
  }

  public static boolean SetFader(int p_fader) {
    return dspJNI.SetFader(p_fader);
  }

  public static boolean SetLoudness(int p_loudness) {
    return dspJNI.SetLoudness(p_loudness);
  }

  public static boolean setSource(int p_source) {
    return dspJNI.setSource(p_source);
  }

  public static boolean getSource(SWIGTYPE_p_int p_source) {
    return dspJNI.getSource(SWIGTYPE_p_int.getCPtr(p_source));
  }

  public static boolean playSin(int p_volume, int p_frequency, boolean p_enable) {
    return dspJNI.playSin(p_volume, p_frequency, p_enable);
  }

  public static boolean change_band(int p_new_band) {
    return dspJNI.change_band(p_new_band);
  }

  public static void get_band(int p_band, int p_subband) {
    dspJNI.get_band(p_band, p_subband);
  }

  public static boolean set_frequency(int p_frequency, int p_band, int p_subAM_band) {
    return dspJNI.set_frequency(p_frequency, p_band, p_subAM_band);
  }

  public static int get_frequency() {
    return dspJNI.get_frequency();
  }

}
