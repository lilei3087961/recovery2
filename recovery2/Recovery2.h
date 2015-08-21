/*
 * Recovery2.h
 *
 *  Created on: Aug 13, 2015
 *      Author: lilei
 */

#ifndef RECOVERY2_H
#define RECOVERY2_H

#include <stdint.h>
#include <sys/types.h>
#include <cutils/compiler.h>
#include <utils/Atomic.h>
#include <utils/Errors.h>
#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <utils/threads.h>

#include <binder/IMemory.h>
#include <binder/MemoryDealer.h>
#include <binder/IBinder.h>
#include <IRecovery2.h>


namespace android {

class Recovery2 :
    public BnRecovery2,
    public IBinder::DeathRecipient
{
    public :

    static      const char* getServiceName() ANDROID_API { return "Recovery2"; }

    			Recovery2() ANDROID_API;
                void        init() ANDROID_API;

    private:

    virtual                 ~Recovery2();

    virtual     void        binderDied(const wp<IBinder>& who);


    virtual     int         doRecovery(int command);

    virtual     int         onTransact(uint32_t code, const Parcel& data,
                                Parcel* reply, uint32_t flags);
};

};

#endif
