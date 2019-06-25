#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pqi    priority_queue<int>
#define minheap  priority_queue < int , vector<int> , greater<int> >
#define nl "\n"
#define print(x) cout<<x
#define prints(x) cout<<x<<" "
#define printn(x) cout<<x<<nl
#define newl cout<<nl
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define sti stack<int>
#define qui queue<int>
#define fi first
#define se second
#define mset(x,y) memset(x,y,sizeof(x))
#define REP(i, a, b) for(__typeof(a) i = a;i < b;i++)
#define REPI(i, a, b) for(__typeof(a) i = a;i > b;i--)
#define REPITER(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)
#define eps 1e-6
#define pi 3.141592653589793
using namespace std;
template<class T> inline T gcd(T x, T y) { if (!y) return x; return gcd(y, x%y); }
template<class T> inline T mod(T x) { if(x < 0) return -x; else return x; }
typedef vector<int> VII;
typedef vector<ll> VLL;
typedef pair<int, int> PII;
typedef vector< pair<int, int> > VPII;
typedef vector< pair<PII, int > > VPPI;
const int MOD = 1e9 + 7;
const int INF = 1e9;

bool isLeap(int y)
 {
   if(y%4==0)
    {
      if(y%100 ==0 )
        {
        if(y%400 ==0 )
         return true;
        else
         return false;
        }
       else
        return true;
    }
    else
     return false;
 }
int main() {
     _
    int t;
    cin>>t;
    
    while(t--)
    {
     int e, f;
     cin>>e>>f;
     int dp[e+1][f+1];
    
    REP(i, 0, e+1)
     {
      dp[i][0]=0;
      dp[i][1]=1;
      }
      
      
      REP(j, 1, f+1)
        dp[1][j]=j;
        
       
         
     REP(i, 2, e+1) // eggs
       {
         REP(j, 2, f+1) // floors
           {
              //dp[i][j] = INT_MAX;
              int ans=99999;
              
              REP(k, 1, j+1) // dropping from all floors and taking minimum of all
                {
                  int to = 1 + max (dp[i-1][k-1], dp[i][j-k]);
                  ans = min(ans, to);
                }
                
               dp[i][j] = ans;
           }
       }
       
       cout<<dp[e][f]<<nl;
    }
    
   return 0;
}


