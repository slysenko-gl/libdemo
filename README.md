## Prerequisites

### Mac:

- Xcode Command Line Tools; 

Please, check 'clang --version' from the Terminal.

### Windows:

- Git for Windows;
- MSVC or standalone GCC compiler https://jmeubank.github.io/tdm-gcc/

Make sure that 'git --version' and 'gcc --version' could be running from Command Line.

## How to build Boost for Android Studio

Please clone next projects in your workspace folder:
```
git clone git@github.com:slysenko-gl/libdemo.git libdemo
git clone git@github.com:slysenko-gl/Boost-for-Android.git boost
```

Please, open libdemo project in the Android Studio and wait until it will be synced,
so NDK r28 and CMake 3.31 specified in this project will be downloaded and installed.

Next, please, open Terminal on the Mac or Git Bash command line on the Window for running Boost build script.
Note, that '-toolset=gcc' option is needed for running GCC compiler on the PC only; and the last option should 
be corrected with the path to Android Ndk on your workstation.

```
$ cd boost
$ ./build-android.sh --arch=x86_64,arm64-v8a --target-version=29 --layout=system --without-libraries=context,contract,coroutine,fiber,graph_parallel,python,stacktrace --toolset=gcc /c/Android/sdk/ndk/28.0.13004108
```
This script will try to download Boost distributive For the first running, and it could fail with missing wget tool.
In this case the most simple solution will be to download this Boost archive with your browser and place it into the 'boost' folder manually.
