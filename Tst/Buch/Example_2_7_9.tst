LIB "tst.lib";
tst_init();

LIB"matrix.lib";
proc tensorMaps(matrix M, matrix N)
{
   int r=ncols(M);
   int s=nrows(M);
   int p=ncols(N);
   int q=nrows(N);
   int a,b,c,d;
   matrix R[s*q][r*p];
   for(b=1;b<=p;b++)
   {
      for(d=1;d<=q;d++)
      {
         for(a=1;a<=r;a++)
         {
            for(c=1;c<=s;c++)
            {
               R[(c-1)*q+d,(a-1)*p+b]=M[c,a]*N[d,b];
            }
         }
      }
   }
   return(R);
}

proc tensorMod(matrix Phi, matrix Psi)
{
   int s=nrows(Phi);
   int q=nrows(Psi);
   matrix A=tensorMaps(unitmat(s),Psi);  //Is tensor Psi
   matrix B=tensorMaps(Phi,unitmat(q));  //Phi tensor Iq
   matrix R=concat(A,B);                 //sum of A and B
   return(R);
}

ring A=0,(x,y,z),dp;
matrix M[3][3]=1,2,3,4,5,6,7,8,9;
matrix N[2][2]=x,y,0,z;
print(M);

print(N);

print(tensorMod(M,N));


tst_status(1);$
