#ifndef CANTOR_H
#define CANTOR_H

namespace android {

    sp<IRecovery2> defaultRecovery2();

    extern sp<IRecovery2> gIRecovery2;

    class IRecovery2Client : public IInterface
    {
    public:
        DECLARE_META_INTERFACE(Recovery2Client);
    };

    class BnRecovery2Client : public BnInterface<IRecovery2Client>
    {
    public:
        virtual status_t    onTransact( uint32_t code,
                                        const Parcel& data,
                                        Parcel* reply,
                                        uint32_t flags = 0);
    };

    class Recovery2Client: public IBinder::DeathRecipient, public BnRecovery2Client
    {
    public:
    	Recovery2Client() {
        }

        virtual void binderDied(const wp<IBinder>& who);
    };

};

#endif
