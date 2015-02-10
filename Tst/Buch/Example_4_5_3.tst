LIB "tst.lib";
tst_init();

option(redSB);
ring R=0,(x,y),lp;
ideal a1=x;
ideal a2=y2+2y+1,x-1;
ideal a3=y2-2y+1,x-1;
ideal I=intersect(a1,a2,a3);
poly h=y4-2y2+1;
ideal I1=quotient(I,h);

ideal rad=I1;

ideal I2=std(I,h);
dim(I2);

ideal u=finduni(I2);
u;

I2=I2,x2-1,y2-1;

rad=intersect(rad,I2);
rad;

tst_status(1);$
