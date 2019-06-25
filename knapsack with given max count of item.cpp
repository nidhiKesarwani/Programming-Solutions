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
typedef vector< pair<int, PII > > VPPI;
const int MOD = 1e9 + 7;
const int INF = 1e9;



////////////////////////   

/*given number of items, their weights, prices then max weight and max count;  find the maximum price that can be obtained given only one item can be bought of one type*/


ll cal(int W, int c, int i, int n, ll w[], ll p[], ll sum)
{
  
  if(c==0 || i>=n)
   {
     return sum;
   }
   ll ans1 = sum;
   ll ans2 =sum;
   if(W-w[i]>=0)
     ans1 = cal(W-w[i], c-1, i+1, n, w, p, sum+p[i]);
     
   ans2 = cal(W, c, i+1, n, w, p, sum);
  
  return max(ans1, ans2);
   
}

int main() {
     _
    int t;
    cin>>t;
    
    REP(d, 1, t+1)
    {
      int n;
      cin>>n;
      
      ll w[n], p[n];
       REP(i,0, n)
         cin>>p[i]>>w[i];
         
        int W, c;
        cin>>W>>c;
        bool f = false;
         REP(i, 0, n)
          if(w[i]<=W)
            {
            	f = true;
            	break;
            }
        cout<<"For Day #"<<d<<":"<<nl;
        if(f)
        cout<<cal(W, c, 0, n, w, p, 0)<<nl; 
        else
        cout<<"-1"<<nl;
    }
    
   return 0;
}



