#include <jni.h>
#include <assert.h>

#include <libavcodec/avcodec.h>

// avoids "Incorrect return type JNICALL, which should have been jstring." with NDK 25 :/
#define JNICALL

JNIEXPORT jstring JNICALL
Java_com_rom1v_nativesample_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    unsigned v = avcodec_version();
    char *str;
    int r = asprintf(&str, "libavcodec: %u.%u.%u", AV_VERSION_MAJOR(v), AV_VERSION_MINOR(v), AV_VERSION_MICRO(v));
    assert(r != -1);
    return (*env)->NewStringUTF(env, str);
}