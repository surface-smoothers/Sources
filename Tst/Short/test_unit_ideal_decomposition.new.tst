LIB "tst.lib";
tst_init();
echo=1;

LIB("primdec.lib");

proc testMinAssUnitOrigBehaviour(method, I)
{
  def result = method(I);
  result;
  ASSUME(0, size(result)==1);
}

proc testPrimdecUnitOrigBehaviour(method, I)
{
  def result = method(I);
  ASSUME(0, size(result)==1);
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

 /*
 decomp 
 pseudo_prim_dec_charsets 
 pseudo_prim_dec_special_charsets 
 pseudo_prim_dec_i 
*/


proc wDecompE (I)         {    return ( Primdec::decompE(I) );     }
proc wDecomp (I)          {    return ( Primdec::convList(Primdec::decomp(I) ) );     }


proc primdecGTZEkeepKomp (I)         {    return ( primdecGTZE(I,"keep_comp") );     }
proc primdecGTZkeepKomp (I)          {    return ( primdecGTZ (I,"keep_comp") );     }

proc minAssGTZEFacSTD (I)            {    return ( minAssGTZE(I,"facstd") );         }
proc minAssGTZFacSTD  (I)            {    return ( minAssGTZ (I,"facstd") );         }

proc minAssGTZEnoFacSTD (I)          {    return ( minAssGTZE(I,"noFacstd") );       }
proc minAssGTZnoFacSTD  (I)          {    return ( minAssGTZ (I,"noFacstd") );       }

proc minAssGTZEorigNoFacSTD (I)      {    return ( minAssGTZE(I,"GTZ","noFacstd") ); }
proc minAssGTZorigNoFacSTD (I)       {    return ( minAssGTZ (I,"GTZ","noFacstd") ); }

proc minAssGTZEGTZ (I)               {    return ( minAssGTZE(I,"GTZ") );            }
proc minAssGTZGTZ  (I)               {    return ( minAssGTZ (I,"GTZ") );            }

proc primdecSYENoOptimalOrdering (I) {    return ( primdecSYE(I,0) );                }
proc primdecSYNoOptimalOrdering  (I) {    return ( primdecSY (I,0) );                }

proc minAssCharENoOptimalOrdering(I) {    return ( minAssCharE(I,0) );               }
proc minAssCharNoOptimalOrdering (I) {    return ( minAssChar (I,0) );               }

proc primdecEUsingMinAssChar  (I)    {    return ( Primdec::prim_decE(I,0) );        }
proc primdecUsingMinAssChar   (I)    {    return ( Primdec::prim_dec(I,0) );         }



proc primdecGTZkeepKomp (I)          {    return ( primdecGTZ(I,"keep_comp") );       }
proc minAssGTZFacSTD    (I)          {    return ( minAssGTZ(I,"facstd") );           }
proc minAssGTZnoFacSTD  (I)          {    return ( minAssGTZ(I,"noFacstd") );         }
proc minAssGTZorigNoFacSTD (I)       {    return ( minAssGTZ(I,"GTZ","noFacstd") );   }
proc minAssGTZorig      (I)          {    return ( minAssGTZ(I,"GTZ") );              }
proc primdecSYNoOptimalOrdering  (I) {    return ( primdecSY(I,0) );                  }
proc minAssCharNoOptimalOrdering (I) {    return ( minAssChar(I,0) );                 }


proc minAssPrimesNew  (I)           {    return ( Primdec::minAssPrimesE(I) );        }
proc minAssPrimesOrig (I)           {    return ( Primdec::minAssPrimes(I) );         }


proc minAssPrimesOldNew  (I)        {    return ( Primdec::minAssPrimesoldE(I) );    }
proc minAssPrimesOldOrig (I)        {    return ( Primdec::minAssPrimesold (I) );    }

proc minAssNew  (I)                 {    return ( Primdec::minAssE(I) );             }
proc minAssOrig (I)                 {    return ( Primdec::minAss (I) );             }


proc minAssPrimCharsetsECurrentOrd(I)    {    return ( Primdec::min_ass_prim_charsetsE(I,0)) ; }
proc minAssPrimCharsetsCurrentOrd (I)    {    return ( Primdec::min_ass_prim_charsets (I,0)) ; }

proc minAssPrimCharsetsEOptimalOrd (I)    {    return ( Primdec::min_ass_prim_charsetsE(I,1)) ; }
proc minAssPrimCharsetsOptimalOrd  (I)    {    return ( Primdec::min_ass_prim_charsets (I,1)) ; }


proc minAssPrimCharsets0New  (I)    {    return ( Primdec::min_ass_prim_charsets0E(I,0)) ; }
proc minAssPrimCharsets0Orig (I)    {    return ( Primdec::min_ass_prim_charsets0 (I,0)) ; }

proc minAssPrimCharsets1New   (I)   {    return ( Primdec::min_ass_prim_charsets1E(I,1)) ; }
proc minAssPrimCharsets1Orig  (I)   {    return ( Primdec::min_ass_prim_charsets1 (I,1)) ; }

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
ring rng = 0,(x,y),dp;
ideal I = x+y,x+1,y;  

list pr = primdecGTZE(I);
ASSUME(0, testPrimaryE(pr,I) );

testPrimdecUnitNewBehaviour( wDecompE,        I );

testPrimdecUnitNewBehaviour( primdecGTZE,        I );
testPrimdecUnitNewBehaviour( primdecGTZEkeepKomp,I );
testMinAssUnitNewBehaviour ( minAssGTZE,         I );
testMinAssUnitNewBehaviour ( minAssGTZEFacSTD,   I );
testMinAssUnitNewBehaviour ( minAssGTZEnoFacSTD, I );
testMinAssUnitNewBehaviour ( minAssGTZEorig,     I );
testMinAssUnitNewBehaviour ( minAssGTZEorigNoFacSTD, I );

testPrimdecUnitNewBehaviour( primdecSYE,                  I );
testPrimdecUnitNewBehaviour( primdecSYENoOptimalOrdering, I );
testMinAssUnitNewBehaviour ( minAssCharE,                 I );
testMinAssUnitNewBehaviour ( minAssCharENoOptimalOrdering,I );
testMinAssUnitNewBehaviour ( minAssNew,                   I );
testMinAssUnitNewBehaviour ( minAssPrimesNew,             I );
testMinAssUnitNewBehaviour ( minAssPrimesOldNew,          I );
testMinAssUnitNewBehaviour ( primdecEUsingMinAssChar,     I );
testMinAssUnitNewBehaviour ( minAssPrimCharsetsECurrentOrd,I );
testMinAssUnitNewBehaviour ( minAssPrimCharsetsEOptimalOrd,I );
testMinAssUnitNewBehaviour ( minAssPrimCharsets0New,      I );
testMinAssUnitNewBehaviour ( minAssPrimCharsets1New,      I );
testMinAssUnitNewBehaviour ( minAssPrimesNew,             I );

//////////////////////////////////////////////////////////////////////////////////////////////
testPrimdecUnitOrigBehaviour( wDecomp,        I );
testPrimdecUnitOrigBehaviour( primdecGTZ,I );
testPrimdecUnitOrigBehaviour( primdecGTZkeepKomp,I );
testMinAssUnitOrigBehaviour ( minAssGTZ, I );
testMinAssUnitOrigBehaviour ( minAssGTZFacSTD, I );
testMinAssUnitOrigBehaviour ( minAssGTZnoFacSTD, I );
testMinAssUnitOrigBehaviour ( minAssGTZorig, I );
testMinAssUnitOrigBehaviour ( minAssGTZorigNoFacSTD, I );
testPrimdecUnitOrigBehaviour( primdecSY, I );
testPrimdecUnitOrigBehaviour( primdecSYNoOptimalOrdering, I );
testMinAssUnitOrigBehaviour ( minAssChar,I );
testMinAssUnitOrigBehaviour ( minAssCharNoOptimalOrdering,I );
testMinAssUnitOrigBehaviour ( minAssOrig,I );
testMinAssUnitOrigBehaviour ( minAssPrimesOrig,I );

// do not worry about this one
// testMinAssUnitOrigBehaviour( minAssPrimesOldOrig,I );

testMinAssUnitOrigBehaviour( primdecUsingMinAssChar,I );
testMinAssUnitOrigBehaviour( minAssPrimCharsetsCurrentOrd,I );
testMinAssUnitOrigBehaviour( minAssPrimCharsetsOptimalOrd,I );
testMinAssUnitOrigBehaviour( minAssPrimCharsets0Orig,I );
testMinAssUnitOrigBehaviour( minAssPrimCharsets1Orig,I );
testMinAssUnitOrigBehaviour( minAssPrimesOrig,I );




testMinAssUnitNewBehaviour( absPrimdecGTZE,I );
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
ring rng = 0,(x,y),dp;
ideal I = x+y,x+1,y;  

list pr = primdecGTZE(I);
 
testPrimdecUnitOrigBehaviour( primdecGTZ,I );
testPrimdecUnitOrigBehaviour( primdecGTZkeepKomp,I );
testMinAssUnitOrigBehaviour( minAssGTZ, I );
testMinAssUnitOrigBehaviour( minAssGTZFacSTD, I );
testMinAssUnitOrigBehaviour( minAssGTZnoFacSTD, I );
testMinAssUnitOrigBehaviour( minAssGTZorig, I );
testMinAssUnitOrigBehaviour( minAssGTZorigNoFacSTD, I );
testPrimdecUnitOrigBehaviour( primdecSY, I );
testPrimdecUnitOrigBehaviour( primdecSYNoOptimalOrdering, I );
testMinAssUnitOrigBehaviour( minAssChar,I );
testMinAssUnitOrigBehaviour( minAssCharNoOptimalOrdering,I );
testMinAssUnitOrigBehaviour( minAssPrimesOrig,I );


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

kill rng;
ring rng = 0,(x,y),ds;
ideal I = x+y,x+1,y;  

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
testMinAssUnitNewBehaviour( minAssPrimesNew,I );
testMinAssUnitNewBehaviour( absPrimdecGTZE,I );


testPrimdecUnitOrigBehaviour( primdecGTZ,I );

testPrimdecUnitOrigBehaviour( primdecGTZ,I );
testPrimdecUnitOrigBehaviour( primdecGTZkeepKomp,I );
testMinAssUnitOrigBehaviour( minAssGTZ, I );
testMinAssUnitOrigBehaviour( minAssGTZFacSTD, I );
testMinAssUnitOrigBehaviour( minAssGTZnoFacSTD, I );
testMinAssUnitOrigBehaviour( minAssGTZorig, I );
testMinAssUnitOrigBehaviour( minAssGTZorigNoFacSTD, I );
testPrimdecUnitOrigBehaviour( primdecSY, I );
testPrimdecUnitOrigBehaviour( primdecSYNoOptimalOrdering, I );
testMinAssUnitOrigBehaviour( minAssChar,I );
testMinAssUnitOrigBehaviour( minAssCharNoOptimalOrdering,I );
testMinAssUnitOrigBehaviour( minAssPrimesOrig,I );
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
kill rng;
ring rng = (7,a),(x,y,z),dp; minpoly = a^2+a+3;
ideal I = x+y,x+1,y; 

testPrimdecUnitNewBehaviour( wDecompE,        I );

testPrimdecUnitNewBehaviour( primdecGTZE,        I );
testPrimdecUnitNewBehaviour( primdecGTZEkeepKomp,I );
testMinAssUnitNewBehaviour ( minAssGTZE,         I );
testMinAssUnitNewBehaviour ( minAssGTZEFacSTD,   I );
testMinAssUnitNewBehaviour ( minAssGTZEnoFacSTD, I );
testMinAssUnitNewBehaviour ( minAssGTZEorig,     I );
testMinAssUnitNewBehaviour ( minAssGTZEorigNoFacSTD, I );

testPrimdecUnitNewBehaviour( primdecSYE,                  I );
testPrimdecUnitNewBehaviour( primdecSYENoOptimalOrdering, I );
testMinAssUnitNewBehaviour ( minAssCharE,                 I );
testMinAssUnitNewBehaviour ( minAssCharENoOptimalOrdering,I );
testMinAssUnitNewBehaviour ( minAssNew,                   I );
testMinAssUnitNewBehaviour ( minAssPrimesNew,             I );
testMinAssUnitNewBehaviour ( minAssPrimesOldNew,          I );
testMinAssUnitNewBehaviour ( primdecEUsingMinAssChar,     I );
testMinAssUnitNewBehaviour ( minAssPrimCharsetsECurrentOrd,I );
testMinAssUnitNewBehaviour ( minAssPrimCharsetsEOptimalOrd,I );
testMinAssUnitNewBehaviour ( minAssPrimCharsets0New,      I );
testMinAssUnitNewBehaviour ( minAssPrimCharsets1New,      I );
testMinAssUnitNewBehaviour ( minAssPrimesNew,             I );

//////////////////////////////////////////////////////////////////////////////////////////////
testPrimdecUnitOrigBehaviour( wDecomp,        I );
testPrimdecUnitOrigBehaviour( primdecGTZ,I );
testPrimdecUnitOrigBehaviour( primdecGTZkeepKomp,I );
testMinAssUnitOrigBehaviour ( minAssGTZ, I );
testMinAssUnitOrigBehaviour ( minAssGTZFacSTD, I );
testMinAssUnitOrigBehaviour ( minAssGTZnoFacSTD, I );
testMinAssUnitOrigBehaviour ( minAssGTZorig, I );
testMinAssUnitOrigBehaviour ( minAssGTZorigNoFacSTD, I );
testPrimdecUnitOrigBehaviour( primdecSY, I );
testPrimdecUnitOrigBehaviour( primdecSYNoOptimalOrdering, I );
testMinAssUnitOrigBehaviour ( minAssChar,I );
testMinAssUnitOrigBehaviour ( minAssCharNoOptimalOrdering,I );
testMinAssUnitOrigBehaviour ( minAssOrig,I );
testMinAssUnitOrigBehaviour ( minAssPrimesOrig,I );

// do not worry about this one
// testMinAssUnitOrigBehaviour( minAssPrimesOldOrig,I );

testMinAssUnitOrigBehaviour( primdecUsingMinAssChar,I );
testMinAssUnitOrigBehaviour( minAssPrimCharsetsCurrentOrd,I );
testMinAssUnitOrigBehaviour( minAssPrimCharsetsOptimalOrd,I );
testMinAssUnitOrigBehaviour( minAssPrimCharsets0Orig,I );
testMinAssUnitOrigBehaviour( minAssPrimCharsets1Orig,I );
testMinAssUnitOrigBehaviour( minAssPrimesOrig,I );

//  minAssChar not implemented for...
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
kill rng;
ring rng = (7,a),(x,y,z),ds; minpoly = a^2 + a+3;
ideal I = x+y,x+1,y; 

testPrimdecUnitNewBehaviour( primdecGTZE,I );
testPrimdecUnitNewBehaviour( primdecGTZEkeepKomp,I );
testMinAssUnitNewBehaviour( minAssGTZE, I );
testMinAssUnitNewBehaviour( minAssGTZEFacSTD, I );
testMinAssUnitNewBehaviour( minAssGTZEnoFacSTD, I );
testMinAssUnitNewBehaviour( minAssGTZEorig, I );
testMinAssUnitNewBehaviour( minAssGTZEorigNoFacSTD, I );
testPrimdecUnitNewBehaviour( primdecSYE, I );
testPrimdecUnitNewBehaviour( primdecSYENoOptimalOrdering, I );
testMinAssUnitNewBehaviour( minAssPrimesNew,I );

// minAssChar not implemented for...


tst_status(1); $
