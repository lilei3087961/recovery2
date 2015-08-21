/*
 * IRecovery2.h
 *
 *  Created on: Aug 13, 2015
 *      Author: lilei
 */
#ifndef ITALE_H
#define ITALE_H
#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>

#include <binder/IInterface.h>

namespace android {
  class IRecovery2 : public IInterface {

	  public :
		 DECLARE_META_INTERFACE(Recovery2);

		 virtual int doRecovery(int command) = 0;
  };
  class BnRecovery2 : public BnInterface<IRecovery2> {

     public :
	  	  enum {
			  DO_RECOVERY = 0,
	  	  };
	  	  virtual int onTransact(uint32_t code, const Parcel& data,
	              Parcel* reply, uint32_t flags = 0);
  };
}
#endif



