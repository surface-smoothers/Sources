LIB "tst.lib"; tst_init();
LIB "crypto.lib";
ring R = 0,z,dp;
bigint h=10;
bigint p=h^30+4;
PollardRho(p,5000,0);
tst_status(1);$
