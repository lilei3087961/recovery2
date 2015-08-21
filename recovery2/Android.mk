LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    Recovery2.cpp \


LOCAL_C_INCLUDES := \
    frameworks/av/services/recovery2/recovery2_tale

LOCAL_SHARED_LIBRARIES := \
    libbinder \
    libcutils \
    libutils \
    librecovery2_tale \
    libmedia \
    liblog \
    libc

LOCAL_MODULE:= librecovery2
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    main_recovery2.cpp
    
LOCAL_C_INCLUDES := \
    frameworks/av/services/recovery2/recovery2_tale
    

LOCAL_SHARED_LIBRARIES := \
    librecovery2 \
    libbinder \
    librecovery2_tale \
    libcutils \
	libutils

LOCAL_MODULE := recovery2

include $(BUILD_EXECUTABLE)


