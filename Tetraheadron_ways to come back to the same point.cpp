
int Solution::solve(int A) {
    long long M = 1000000007;
    long long w= 1;  // numerator
    long long k= 0;
    long long q = 1;  // denominator
    for(int i =1; i<=A; i++)
     {
          long long nw = (k*3)%M;
          long long nk = ( (k*2)%M + w)%M;
           w = nw;
           k = nk;
           q = (q*3)%M;
         
     }
   //now inverse  because of (p/q)%M so (p%M * (q^-1) %M)
   long long res = 1, po = M-2;
   while(po)
   {
       if (po&1)
         res = (res * q)%M;
         
       q = (q*q)%M;
       po = po/2;
   }
   
   //res is inverse
   long long ans = ((w%M * res%M))%M;
   return (int)ans;
}
