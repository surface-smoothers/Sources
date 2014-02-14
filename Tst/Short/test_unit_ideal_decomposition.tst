LIB "tst.lib";
tst_init();
echo=1;

LIB("primdec.lib");

proc testMinAssUnitOrigBehaviour(method, I)
{
  def result = method(I);
  ASSUME(0, size(result)==0);
}

proc testPrimdecUnitOrigBehaviour(method, I)
{
  def result = method(I);
  ASSUME(0, size(result)==0);
}

proc testMinAssUnitNewBehaviour(method, I)
{
  def result = method(I);
  ASSUME(0, size(result)==0);
}

proc testPrimdecUnitNewBehaviour(method, I)
{
  def result = method(I);
  ASSUME(0, size(result)==0);
}

proc primdecGTZEkeepKomp (I)          {    return ( primdecGTZE(I,"keep_comp") );    }
proc minAssGTZEFacSTD (I)             {    return ( minAssGTZE(I,"facstd") );    }
proc minAssGTZEnoFacSTD (I)           {    return ( minAssGTZE(I,"noFacstd") );  }
proc minAssGTZEorigNoFacSTD (I)       {    return ( minAssGTZE(I,"GTZ","noFacstd") );       }
proc minAssGTZEorig (I)               {    return ( minAssGTZE(I,"GTZ") );       }

proc primdecSYENoOptimalOrdering (I)  {    return ( primdecSYE(I,0) );           }
proc minAssCharENoOptimalOrdering (I) {    return ( minAssCharE(I,0) );           }

proc minAssPrimesOrig (I) {    return ( Primdec::minAssPrimesE(I) );           }





ring rng = 0,(x,y),dp;
ideal I = x+y,x+1,y;  

list pr = primdecGTZE(I);
ASSUME(0, testPrimaryE(pr,I) );
testPrimdecUnitNewBehaviour( primdecGTZE,I );
testPrimdecUnitNewBehaviour( primdecGTZEkeepKomp,I );
testMinAssUnitNewBehaviour( minAssGTZE, I );
testMinAssUnitNewBehaviour( minAssGTZEFacSTD, I );
testMinAssUnitNewBehaviour( minAssGTZEnoFacSTD, I );
testMinAssUnitNewBehaviour( minAssGTZEorig, I );
testMinAssUnitNewBehaviour( minAssGTZEorigNoFacSTD, I );
testPrimdecUnitNewBehaviour( primdecSYE, I );
testPrimdecUnitNewBehaviour( primdecSYENoOptimalOrdering, I );
testMinAssUnitNewBehaviour( minAssCharE,I );
testMinAssUnitNewBehaviour( minAssCharENoOptimalOrdering,I );
testMinAssUnitNewBehaviour( minAssPrimesOrig,I );


kill rng;
ring rng = 0,(x,y),ds;
ideal I = x+y,x+1,y;  
testPrimdecUnitNewBehaviour( primdecGTZ,I );

testPrimdecUnitNewBehaviour( primdecGTZ,I );
testPrimdecUnitNewBehaviour( primdecGTZEkeepKomp,I );
testMinAssUnitNewBehaviour( minAssGTZ, I );
testMinAssUnitNewBehaviour( minAssGTZEFacSTD, I );
testMinAssUnitNewBehaviour( minAssGTZEnoFacSTD, I );
testMinAssUnitNewBehaviour( minAssGTZEorig, I );
testMinAssUnitNewBehaviour( minAssGTZEorigNoFacSTD, I );
testPrimdecUnitNewBehaviour( primdecSY, I );
testPrimdecUnitNewBehaviour( primdecSYENoOptimalOrdering, I );
testMinAssUnitNewBehaviour( minAssChar,I );
testMinAssUnitNewBehaviour( minAssCharENoOptimalOrdering,I );
testMinAssUnitNewBehaviour( minAssPrimesOrig,I );

kill rng;
ring rng = (7,a),(x,y,z),dp; minpoly = a^2+a+3;
ideal I = x+y,x+1,y; 

testPrimdecUnitNewBehaviour( primdecGTZ,I );
testPrimdecUnitNewBehaviour( primdecGTZEkeepKomp,I );
testMinAssUnitNewBehaviour( minAssGTZ, I );
testMinAssUnitNewBehaviour( minAssGTZEFacSTD, I );
testMinAssUnitNewBehaviour( minAssGTZEnoFacSTD, I );
testMinAssUnitNewBehaviour( minAssGTZEorig, I );
testMinAssUnitNewBehaviour( minAssGTZEorigNoFacSTD, I );
testPrimdecUnitNewBehaviour( primdecSY, I );
testPrimdecUnitNewBehaviour( primdecSYENoOptimalOrdering, I );
testMinAssUnitNewBehaviour( minAssPrimesOrig,I );

//  minAssChar not implemented for...

kill rng;
ring rng = (7,a),(x,y,z),ds; minpoly = a^2 + a+3;
ideal I = x+y,x+1,y; 

testPrimdecUnitNewBehaviour( primdecGTZ,I );
testPrimdecUnitNewBehaviour( primdecGTZEkeepKomp,I );
testMinAssUnitNewBehaviour( minAssGTZ, I );
testMinAssUnitNewBehaviour( minAssGTZEFacSTD, I );
testMinAssUnitNewBehaviour( minAssGTZEnoFacSTD, I );
testMinAssUnitNewBehaviour( minAssGTZEorig, I );
testMinAssUnitNewBehaviour( minAssGTZEorigNoFacSTD, I );
testPrimdecUnitNewBehaviour( primdecSY, I );
testPrimdecUnitNewBehaviour( primdecSYENoOptimalOrdering, I );
testMinAssUnitNewBehaviour( minAssPrimesOrig,I );

// minAssChar not implemented for...


tst_status(1); $
