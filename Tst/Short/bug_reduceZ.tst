LIB "tst.lib";
tst_init();

LIB("primdecint.lib");
proc reduceZW(p,I) 
{
    return ( Primdecint::reduceZ(p,std(I)) ); 
}
ring r=integer,(x,y),dp;

poly  p = 11x+5y;
ideal J = 5x,5y;
  reduce( p, std(J) );
reduceZW( p, std(J) ); 
ASSUME(0, 0 != reduceZW( p,std(J) )   );


tst_status(1); $

