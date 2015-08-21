/*
 * Recovery2.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: lilei
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <errno.h>

#include <pthread.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <sys/un.h>
#include <signal.h>
#include <pthread.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <utils/Log.h>
#include <cutils/properties.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include <media/AudioSystem.h>
#include <stdio.h>
#include <Recovery2.h>

namespace android {


	Recovery2::Recovery2()
	{
	}
    Recovery2::~Recovery2()
	{
	}

    void Recovery2::init()
    {
    }
	void Recovery2::binderDied(const wp<IBinder>& /* who */)
	{
		/**TODO: Watching mediaserver*/
	}
	int  Recovery2::doRecovery(int command)
	{
//		String8 clientCommand8(clientCommand);
//		ALOGE(">>lileir>>doRecovery clientCommand8 is:%s",clientCommand8.string());
//		if (strcmp(clientCommand8.string(), "--wipe_data") == 0) {
		ALOGE(">>lileir>>doRecovery command is:%d",command);
		if(command == 1){
				int ret = system("wipe data");
				printf(">>lileir>>wipe data ret:%s \n",ret);
				sleep(1);
				int ret2 = system("reboot");
				ALOGE(">>lileir>>wipe data ret:%s",ret);
		}
		return 0;
	}
	status_t Recovery2::onTransact(
	    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
	{
	    status_t err = BnRecovery2::onTransact(code, data, reply, flags);

	    if (err == UNKNOWN_TRANSACTION || err == PERMISSION_DENIED) {
	        CHECK_INTERFACE(ISymphonia, data, reply);
	        switch (code) {
	            case 1001 :
	            {
	                ALOGE(">>lileir>>%s bad thansaction code = %d\n", __FUNCTION__, code);
	            }
	        }
	    }
	    return err;
	}

};


