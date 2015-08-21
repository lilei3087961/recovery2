/*
 * recovery2_client.cpp
 *
 *  Created on: Aug 21, 2015
 *      Author: lilei
 */

#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <IRecovery2.h>
#include <recovery2_cantor.h>

using namespace android;

int main(int argc, char **argv)
{
	ALOGE(">>lileir>>%s",__FILE__);
    sp<IRecovery2>  myIRecovery2= defaultRecovery2();
    myIRecovery2->doRecovery(1);

    return 0;
}



