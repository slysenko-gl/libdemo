#include <jni.h>
#include <string>

#include <boost/url.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_lib_1demo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */)
{

    std::string myURL = "https://subdomain.example.com/api/test";

    boost::urls::url_view url(myURL);
    std::string host = url.host();

    std::string hello = "Hello from C++";
    hello.append("\n");
    hello.append(host);

    return env->NewStringUTF(hello.c_str());
}