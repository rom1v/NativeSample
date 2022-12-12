#include <jni.h>
#include <string>

// avoids "Incorrect return type JNICALL, which should have been jstring." with NDK 25 :/
#define JNICALL

extern "C" JNIEXPORT jstring JNICALL
Java_com_rom1v_nativesample_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}