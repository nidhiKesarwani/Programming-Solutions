#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fi     first
#define se     second
#define eb     emplace_back
#define pii    pair<int, int>
#define vi     vector<int>
#define vs     vector<string>
#define vpii   vector<pii>
#define pqi    priority_queue<int>
#define minheap  priority_queue < int , vector<int> , greater<int> >
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define SZ(x)  ((int)(x.size()))
#define FOR(i,n)    for(auto (i)=0; i<n; i++)
#define loop(i,a,b) for( auto (i)=(a); (i)<=(b); i++)
#define loopr(i,a,b) for( int (i)=a; (i)>=(b); i-- )
#define nl "\n"
#define newl cout<<nl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define pow2(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
const double pi = 2 * acos(0.0);
#define inf 0x3f3f3f3f 
using namespace std;
vector<long> bell;
long getBell(int n)
{

	bell.push_back(0);
	bell.push_back(1);
	
	long prev = 1;
	
	int p = n;
	queue<long> q;
	q.push(prev);
	
	while(p--)
	{
		int s = q.size();
		q.push(prev);
		bell.push_back(prev);
		while(s--)
		{
			long t = q.front(); q.pop();
			
			prev+=t;
			q.push(prev);
		}
	}
	return bell[n];
}
int main()
{
    _
    // Happy Coding :)
    int n;
    cin>>n;
    getBell(n);
    
    loop(i, 1, n)
     cout<<bell[i]<<" ";
}


