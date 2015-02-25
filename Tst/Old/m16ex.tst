  LIB "finvar.lib";
  ring R=0,(x,y,z),dp;
  matrix A[3][3]=0,1,0,-1,0,0,0,0,-1;
  // the group G is generated by A in Gl(3,Q);
  print(A);
  // the fourth power of A is 1:
  print(A*A*A*A); // the fourth power of A is 1
  // Use the first method to compute the invariants of G:
  matrix B(1..3);
  B(1..3)=invariant_ring(A);
  // Singular returns 2 matrices, the first containing
  // primary invariants and the second secondary
  // invariants, i.e. module generators over a Noetherian
  // normalization
  // the third result are the irreducible secondary invariants
  // if the Molien series was available
  print(B(1));
  print(B(2));
  print(B(3));
  // Use the second method,
  // with using random numbers between -1 and 1:
  B(1..3)=invariant_ring_random(A,1);
  print(B(1..3));
LIB "tst.lib";tst_status(1);$
