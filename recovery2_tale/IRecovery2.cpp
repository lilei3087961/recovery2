/*
 * IRecovery2.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: lilei
 */
#include <stdint.h>
#include <sys/types.h>

#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include "IRecovery2.h"
namespace android {
  class BpRecovery2 : public BpInterface<IRecovery2>
  {
      public :
	  	BpRecovery2(const sp<IBinder>& impl)
	                 : BpInterface<IRecovery2>(impl)
		{
		}
	  	virtual int doRecovery(int command){
	  		Parcel data, reply;
	  		ALOGE(">>lileir>>%s",__FUNCTION__);
			data.writeInterfaceToken(IRecovery2::getInterfaceDescriptor());
			//data.writeString16(clientCommand);
			data.writeInt32(command);
			remote()->transact(BnRecovery2::DO_RECOVERY, data, &reply);
			return reply.readInt32();
	  	}
  };

  IMPLEMENT_META_INTERFACE(Recovery2, "deathprophet.IRecovery2");

  int BnRecovery2::onTransact(uint32_t code, const Parcel& data,
          Parcel* reply, uint32_t flags){
	  switch(code) {
	              case DO_RECOVERY: {
	            	  ALOGE(">>lileir>>%s>>case DO_RECOVERY",__FUNCTION__);
                      CHECK_INTERFACE(IRecovery2, data, reply);
                      //const String16 clientCommand = data.readString16();
                      int command = data.readInt32();
                      int result = doRecovery(command);
                      reply->writeInt32(result);
                      return NO_ERROR;
	              }
	              default: {
	            	  return BBinder::onTransact(code, data, reply, flags);
				  }
      }
  }
};




