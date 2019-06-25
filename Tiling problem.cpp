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
//if(cond) x++ you can write x += cond
//use iota
//tie and tuple
//pair<int,pair<int,pair<int,int>>> noooo  tuple<int,int,int,int>  yes get<0> first element
using namespace std;

int ways(int n, int m)
{
	int count[n+1];
	
	count[0]=0;
	loop(i, 1, n)
	{
		if(i<m)
		{
			count[i]=1;
		}
		else if(i==m)
		 count[i]=2;
		else   // i-1 for one horizontal  and i-m for one vertical
		 count[i] = count[i-1] + count[i-m];
	}
	
	return count[n];
}

int main()
{
    _
    // Happy Coding :)
    
     int n, m;
     cin>>n>>m;
     
}


