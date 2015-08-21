# recovery2
for binder test

1.recovery2_tale/
librecovery2_tale.so      like aidl

2.recovery2/
librecovery2.so           for server do recovery
recovery2                 for addService Recovery2 to ServiceManager,should register in init.rc

3.recovery2_cantor/
recovery2_client          for client for test call binder
librecovery2_cantor.so    for getService Recovery2 from ServiceManager

--------------
init.rc 
service recovery2 /system/bin/recovery2
    class main
