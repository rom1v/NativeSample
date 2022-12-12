#include <jni.h>
#include <string>
#include <cstdio>
#include <cassert>

extern "C" {
#include <libavcodec/avcodec.h>
}

// avoids "Incorrect return type JNICALL, which should have been jstring." with NDK 25 :/
#define JNICALL

extern "C" JNIEXPORT jstring JNICALL
Java_com_rom1v_nativesample_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    unsigned v = avcodec_version();
    std::string hello = "Hello from C++";
    char *str;
    int r = asprintf(&str, "libavcodec: %u.%u.%u", AV_VERSION_MAJOR(v), AV_VERSION_MINOR(v), AV_VERSION_MICRO(v));
    assert(r != -1);
    return env->NewStringUTF(str);
}