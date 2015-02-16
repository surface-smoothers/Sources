LIB "tst.lib"; tst_init();
LIB "resbinomial.lib";
ring r1 = 0,(x(1),y(2),x(3),y(4),x(5..7)),dp;
list flag1=identifyvar();
ideal P=x(1)^2*x(3)^5-x(5)^7*y(4),x(6)^3*y(2)^5-x(7)^5,x(5)^3*x(6)-y(4)^3*x(1)^5;
list L=data(P,3,7);
list L2=ECoef(L[1],L[2],3,1,3,7,flag1);
L2[1];  // exponents of the E-Coefficient ideal respect to x(1)
L2[2];  // its coefficients
L2[3];  // classify the type of ideal obtained
ring r2 = 0,(x(1),y(2),x(3),y(4)),dp;
list flag2=identifyvar();
ideal J=x(1)^3*(1-2*y(2)*y(4)^2);  // Bold regular case
list L=data(J,1,4);
list L2=ECoef(L[1],L[2],1,1,3,4,flag2);
L2;
ring r3 = 0,(x(1),y(2),x(3),y(4),x(5..7)),dp;
list flag3=identifyvar();
ideal J=x(1)^3-x(3)^2*y(4)^2,x(1)*x(7)*y(2)-x(6)^3*x(5)*y(4)^3,x(5)^3-x(5)^3*y(2)^2;
list L=data(J,3,7);
list L2=ECoef(L[1],L[2],3,1,2,7,flag3);
L2;
ring r4 = 3,(x(1),y(2),x(3),y(4),x(5..7)),dp;
list flag4=identifyvar();
ideal J=x(1)^3-x(3)^2*y(4)^2,x(1)*x(7)*y(2)-x(6)^3*x(5)*y(4)^3,x(5)^3-x(5)^3*y(2)^2;
list L=data(J,3,7);
list L2=ECoef(L[1],L[2],3,1,2,7,flag4);
L2; // THE COMPUTATIONS ARE NOT CORRECT IN CHARACTERISTIC p>0
// because numbers are treated as 0 in assignments
tst_status(1);$
