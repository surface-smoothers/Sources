LIB "tst.lib"; tst_init();
LIB "general.lib";
ring r=32003,(a,b,c,d,e),dp;
int n=7;
ideal i=
a^n-b^n,
b^n-c^n,
c^n-d^n,
d^n-e^n,
a^(n-1)*b+b^(n-1)*c+c^(n-1)*d+d^(n-1)*e+e^(n-1)*a;
def i1=timeStd(i,1);
def i2=timeStd(i,20);
listvar();
tst_status(1);$
