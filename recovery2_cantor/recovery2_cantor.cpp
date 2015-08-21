#include <utils/Mutex.h>
#include <utils/Log.h>

#include <binder/IServiceManager.h>

#include <IRecovery2.h>
#include <recovery2_cantor.h>

namespace android {

    sp<IRecovery2> gIRecovery2;
    sp<Recovery2Client> gRecovery2Client;

    sp<IRecovery2> defaultRecovery2()
    {
        if (gIRecovery2 != NULL) return gIRecovery2;

        sp<IServiceManager> sm = defaultServiceManager();
        sp<IBinder> binder;

        do {
            binder = sm->getService(String16("Recovery2"));
            if (binder != 0)
                break;
             ALOGE(">>lileir>>Recovery2 not published, waiting...");
             usleep(100000); // 1s
        } while(true);

        if (gRecovery2Client == NULL)
        {
        	gRecovery2Client = new Recovery2Client();
        }

        binder->linkToDeath(gRecovery2Client);

        gIRecovery2 = interface_cast<IRecovery2>(binder);

        return gIRecovery2;
    }

    void Recovery2Client::binderDied(const wp<IBinder>& who) {
        ALOGE(">>lileir>>Recovery2Client:: service died !!\n");
        gIRecovery2 = NULL;
    }

    class BpRecovery2Client : public BpInterface<IRecovery2Client>
    {
    public:
        BpRecovery2Client(const sp<IBinder>& impl)
            : BpInterface<IRecovery2Client>(impl)
        {
        }

    };

    IMPLEMENT_META_INTERFACE(Recovery2Client, "IRecovery2Client");

    status_t BnRecovery2Client::onTransact(
            uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
    {
        switch (code) {
            default:
                return BBinder::onTransact(code, data, reply, flags);
        }
    }

}
