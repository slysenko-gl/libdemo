## Prerequisites

Android Studio 2024

### Mac:

- Xcode Command Line Tools

Please, check 'clang --version' from the Terminal.

### Windows:

- Git for Windows
- MSVC

If you don't have MSVC installed on your PC, you can use a standalone GCC compiler instead.
For  example, you could download and install https://jmeubank.github.io/tdm-gcc/
In this case, please, add next option to the android build script: '--toolset=gcc'
and make sure that 'gcc --version' could be running from Command Line.

## How to build Boost for Android Studio

Please clone next projects in your workspace folder:

 - https://github.com/slysenko-gl/libdemo
 - https://github.com/slysenko-gl/Boost-for-Android

Next, open libdemo project in the Android Studio and wait until it will be synced,
so NDK r28 specified in this project will be downloaded and installed.

Then it needs to locate the 'android/sdk/ndk/28.0.13004108' folder on your PC,
and setup 'NDK_ROOT' environment variable to this path:
```
NDK_ROOT = C:/Users/username/AppData/Local/Android/Sdk/ndk/28.0.13004108
```

Next, please, open Terminal on the Mac or Git Bash command line on the Window for running Boost build script.
This script will try to download Boost distributive For the first running, and it could fail with missing wget tool.
In this case the most simple solution will be to download this Boost archive with your browser and place it into the 'Boost-for-Android' folder manually.

```
$ cd Boost-for-Android
$ ./build-android.sh \
  --arch=arm64-v8a,x86_64 \
  --target-version=29 \
  --layout=system \
  --without-libraries=context,contract,coroutine,fiber,graph_parallel,python,stacktrace
```

After that, the libdemo app can be built and run in the Android Studio.

