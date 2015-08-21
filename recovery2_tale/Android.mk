LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    IRecovery2.cpp

LOCAL_SHARED_LIBRARIES := \
    libbinder \
    libcutils \
    libutils \
    liblog

LOCAL_MODULE:= librecovery2_tale

include $(BUILD_SHARED_LIBRARY)
