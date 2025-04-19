# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("lib_demo")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.

# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.
add_library(${CMAKE_PROJECT_NAME} SHARED
        # List C/C++ source files with relative paths to this CMakeLists.txt.
        native-lib.cpp)

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
        # List libraries link to the target library
        android
        log)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_RELEASE_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

#set(Boost_NO_SYSTEM_PATHS TRUE)
#set(Boost_NO_BOOST_CMAKE TRUE)

#set(CMAKE_FIND_DEBUG_MODE TRUE)
#set(Boost_VERBOSE TRUE)

#find_package(Boost 1.85 REQUIRED CONFIG HINTS C:/Android/boost/build/out/${CMAKE_ANDROID_ARCH_ABI}/lib/cmake)

#set(Boost_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../boost/build/out/${CMAKE_ANDROID_ARCH_ABI}/lib/cmake")
#find_package(Boost 1.85.0 CONFIG REQUIRED COMPONENTS "url")

#message(Boost_INCLUDE_DIR="${Boost_INCLUDE_DIR}")
#message(Boost_LIBRARY_DIRS="${Boost_LIBRARY_DIRS}")

set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../boost/build/out/${CMAKE_ANDROID_ARCH_ABI}")
set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}/include")
set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/lib")

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${BOOST_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${BOOST_LIBRARY_DIRS}/libboost_url.a)


