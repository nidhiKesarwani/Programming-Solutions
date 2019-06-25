#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fi     first
#define se     second
#define eb     emplace_back
#define mp     make_pair
#define pii    pair<int, int>
#define vi     vector<int>
#define vs     vector<string>
#define vpii   vector<pii>
#define sti    stack<int>
#define qui    queue<int>
#define pqi    priority_queue<int>
#define minheap  priority_queue < int , vector<int> , greater<int> >
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define SZ(x)  ((int)(x.size()))
#define FOR(i,n)    for(auto (i)=0; i<n; i++)
#define FORI(i,n)   for(auto (i)=1; (i)<=(n); (i)++)
#define in(x,y)     ((y).find((x))!=(y).end())
#define all(t)      t.begin(), t.end()
#define loop(i,a,b) for( auto (i)=(a); (i)<=(b); i++)
#define loopr(i,a,b) for( int (i)=a; (i)>=(b); i-- )
#define rmax(a,b)   (a)=max((a),(b));
#define rmin(a,b)   (a)=min((a),(b));
#define nl "\n"
#define print(x) cout<<x
#define prints(x) cout<<x<<" "
#define printn(x) cout<<x<<nl
#define newl cout<<nl
#define ull unsigned long long
#define ll  long long
#define MAX INT_MAX
using namespace std;
ll dp[1<<20];
int mat[21][21];

int main() {
     _
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    
    memset(dp, 0, sizeof(dp));
    memset(mat, 0, sizeof(mat));
    
    for(int i=0; i<n; i++)
     for(int j=0; j<n; j++)
       cin>>mat[i][j];
       
       dp[(1<<n)-1]=1;
       for(int mask = (1<<n)-1; mask>=0; mask--)
       {
         int students = __builtin_popcount(mask);
         for(int i=0; i<n; i++)
           {
             if(mat[students][i]==0 || (mask & (1<<i))) continue;
             dp[mask]+=dp[mask | (1<<i)];
           }
       }
    cout<<dp[0]<<nl;
    }
   return 0;
}



