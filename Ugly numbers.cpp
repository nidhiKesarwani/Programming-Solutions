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
int getugly(int n)
{
	int ugly[n];
	ugly[0]=1;
	
	int i1=0, i2=0, i3=0;
	int next;
	loop(i, 1, n-1)
	{
		int next_ugly = min(ugly[i1]*2,min( ugly[i2]*3, ugly[i3]*5));
		
		ugly[i] = next_ugly;
		
		if(next_ugly==ugly[i1]*2)
		 i1++;
		if(next_ugly==ugly[i2]*3)
		 i2++;
		if(next_ugly==ugly[i3]*5)
		 i3++;
	}
	return ugly[n-1];
}
int main()
{
    _
    // Happy Coding :)
    int n;
    cin>>n;
    cout<<getugly(n)<<nl;
}


