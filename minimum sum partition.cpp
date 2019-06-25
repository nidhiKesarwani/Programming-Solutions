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


int solve (int sum, int i, VII dp[], int total, int arr[])
{
   if(dp[sum][i]!=-1)
     return dp[sum][i];
     
   if(i==0)
    {
    int a = sum;
    int b = total-a;
    if(dp[sum][i]==-1)
      {
        dp[sum][i]= abs(a-b);
        dp[b][i] = dp[sum][i];
      }
      
      return dp[sum][i];
    }
    
    dp[sum][i] = min(solve (sum+arr[i], i-1, dp, total, arr), solve (sum, i-1, dp, total, arr) );
    dp[total-sum][i] = dp[sum][i];
    
    return dp[sum][i];
}
int main() {
     _
    int t;
    cin>>t;
    
    while(t--)
    {
      int n;
      cin>>n;
      
      int arr[n+1];
      int tot=0;
      
      REP(i, 1, n+1)
       {
         cin>>arr[i];
         tot+=arr[i];
       }
      VII dp[tot+1];
      REP(i, 0, tot+1)
       {
         REP(j, 0, n+1)
           dp[i].push_back(-1);
       } 
       
       cout<<solve(0, n, dp, tot, arr)<<nl;
    }
    
   return 0;
}


