﻿# CMakeList.txt : CMake project for dynamic-array, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (double-ended-queue "doubleEndedQueue.cpp" "doubleEndedQueue.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET double-ended-queue PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
