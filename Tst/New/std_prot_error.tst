option();

LIB "tst.lib"; tst_init();

option();

  int N=3;

  option();

  ring ra3=32003,x(1..N),ds;
 degBound=0;


  option();

  ideal i0=
  -7*x(1)^6-49*x(1)^5*x(2)+16*x(1)^4*x(2)^2+27*x(1)^3*x(2)^3-
  38*x(1)^2*x(2)^4+60*x(1)*x(2)^5+70*x(2)^6-28*x(1)^5*x(3)+85*x(1)^4*x(2)*x(3)+
  69*x(1)^3*x(2)^2*x(3)-13*x(1)^2*x(2)^3*x(3)-65*x(1)*x(2)^4*x(3)+51*x(2)^5*x(3)-
  70*x(1)^4*x(3)^2+37*x(1)^3*x(2)*x(3)^2+89*x(1)^2*x(2)^2*x(3)^2-
  82*x(1)*x(2)^3*x(3)^2+6*x(2)^4*x(3)^2-67*x(1)^3*x(3)^3+19*x(1)^2*x(2)*x(3)^3-
  12*x(1)*x(2)^2*x(3)^3-81*x(2)^3*x(3)^3+33*x(1)^2*x(3)^4-98*x(1)*x(2)*x(3)^4+
  51*x(2)^2*x(3)^4+11*x(1)*x(3)^5+11*x(2)*x(3)^5-39*x(3)^6,

  5*x(1)^6-17*x(1)^5*x(2)-62*x(1)^4*x(2)^2+41*x(1)^3*x(2)^3-85*x(1)^2*x(2)^4+
  57*x(1)*x(2)^5-52*x(2)^6+80*x(1)^5*x(3)+19*x(1)^4*x(2)*x(3)-
  72*x(1)^3*x(2)^2*x(3)-34*x(1)^2*x(2)^3*x(3)-46*x(1)*x(2)^4*x(3)-
  6*x(2)^5*x(3)-33*x(1)^4*x(3)^2+44*x(1)^3*x(2)*x(3)^2-23*x(1)^2*x(2)^2*x(3)^2-
  60*x(1)*x(2)^3*x(3)^2+64*x(2)^4*x(3)^2+26*x(1)^3*x(3)^3-84*x(1)^2*x(2)*x(3)^3+
  35*x(1)*x(2)^2*x(3)^3-91*x(2)^3*x(3)^3-93*x(1)^2*x(3)^4+22*x(1)*x(2)*x(3)^4+
  99*x(2)^2*x(3)^4-36*x(1)*x(3)^5+5*x(2)*x(3)^5+46*x(3)^6,
  -32*x(1)^6-73*x(1)^5*x(2)-43*x(1)^4*x(2)^2-55*x(1)^3*x(2)^3-83*x(1)^2*x(2)^4-

  50*x(1)*x(2)^5-74*x(2)^6-56*x(1)^5*x(3)+79*x(1)^4*x(2)*x(3)+
  86*x(1)^3*x(2)^2*x(3)-27*x(1)^2*x(2)^3*x(3)+28*x(1)*x(2)^4*x(3)+71*x(2)^5*x(3)+
  77*x(1)^4*x(3)^2-71*x(1)^3*x(2)*x(3)^2-63*x(1)^2*x(2)^2*x(3)^2-
  22*x(1)*x(2)^3*x(3)^2+17*x(2)^4*x(3)^2+58*x(1)^3*x(3)^3+31*x(1)^2*x(2)*x(3)^3+
  19*x(1)*x(2)^2*x(3)^3-36*x(2)^3*x(3)^3-15*x(1)^2*x(3)^4-9*x(1)*x(2)*x(3)^4+
  42*x(2)^2*x(3)^4-61*x(1)*x(3)^5-67*x(2)*x(3)^5+31*x(3)^6;

  ring r=32003,(a,b,c),ds;
  option();

  map ff=ra3,a+b2,b2-c3,c;

  ideal i=ff(i0);


option();


// option(redSB);
option(prot);
// test(23+32);
option(weightM);

option();
std(i);
option();

tst_status(1);$
