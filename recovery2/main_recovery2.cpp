#include <stdio.h>
#include <stdlib.h>
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include "Recovery2.h"
using namespace android;

int main(int argc, char **argv)
{
	  ProcessState::self()->setThreadPoolMaxThreadCount(4);

	    sp<ProcessState> ps(ProcessState::self());
	    ps->startThreadPool();

	    //Symphonia::instantiate();
	    sp<Recovery2> recovery2 = new Recovery2();

	    recovery2->init();

	    sp<IServiceManager> sm(defaultServiceManager());
	    status_t status = sm->addService(String16(Recovery2::getServiceName()), recovery2, false);
	    if (status != OK) {
	        ALOGE(">>lileir>>addService %s fail \n",Recovery2::getServiceName());
	        return -1;
	    }

	    if (sm->checkService(String16(Recovery2::getServiceName())) != NULL) {
	        ALOGD(">>lileir>>addService %s succeeded\n", Recovery2::getServiceName());
	    } else {
	        ALOGD(">>lileir>>addService %s fail\n", Recovery2::getServiceName());
	    }

	    ProcessState::self()->startThreadPool();

	    IPCThreadState::self()->joinThreadPool();

	    //symphonia->waiting();

	    return 0;
}
