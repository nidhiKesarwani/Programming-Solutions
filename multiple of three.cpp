#include<bits/stdc++.h>
using namespace std;

int fact[1000001];

void fun()
{
    fact[0]=fact[1]=1;

    for(int i=2; i<1000001)
      fact[i] = fact[i-1]*i;
}

int main()
{
   int t;
   cin>>t;

   while(t--)
    {
         int n;
    cin>>n;
    int arr[n];
    int c[3];
    for(int i=0; i<n; i++)
     {
         cin>>arr[i];
         c[arr[i]%3]++;
     }

     int ans =0;
     ans += ((c[0]*(c[0]-1))/2); // for two
     ans += c[1]*c[2]; //for two
     ans += fact[c[0]]/ (fact[c[0]]-3)*(fact[3]);
     ans += fact[c[1]]/ (fact[c[1]]-3)*(fact[3]);
     ans += fact[c[2]]/ (fact[c[2]]-3)*(fact[3]);
     ans += c[0]*c[1]*c[2];

     cout<<ans<<endl;
    }
    
}