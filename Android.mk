LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := daemon.cpp maplock.cpp
LOCAL_MODULE := iocached
include $(BUILD_EXECUTABLE)
