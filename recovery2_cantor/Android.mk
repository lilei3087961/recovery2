LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    recovery2_cantor.cpp

LOCAL_C_INCLUDES := \
    frameworks/av/services/recovery2/recovery2_tale

LOCAL_SHARED_LIBRARIES := \
    libbinder \
    librecovery2_tale \
    libcutils \
    libutils

LOCAL_MODULE:= librecovery2_cantor

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    recovery2_client.cpp

LOCAL_C_INCLUDES := \
    frameworks/av/services/recovery2/recovery2_tale

LOCAL_SHARED_LIBRARIES := \
    libbinder \
    librecovery2_tale \
    libcutils \
    librecovery2_cantor \
    libutils

LOCAL_MODULE:= recovery2_client

include $(BUILD_EXECUTABLE)
