CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(design_pattern)

ADD_COMPILE_OPTIONS(-std=c++2a)

ADD_SUBDIRECTORY(observer_pattern)

ADD_EXECUTABLE(main "main.cpp")

TARGET_LINK_LIBRARIES(main OBSERVER_PATTERN)
