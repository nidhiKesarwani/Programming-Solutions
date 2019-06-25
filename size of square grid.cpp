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

int main()
{
    _
    // Happy Coding :)
    
      // dimensions of the grid
     int n, m;
     cin>>n>>m;
     
     vector<vi> grid(n);
     FOR(i, n)
     {
     	FOR(j, m)
     	 {
     	  int a;
		   cin>>a;
		   
		   grid[i].eb(a);	
		}
	 }
	 
	 // the number for which we want to know the maximum sized square grid
	 int a;
	 cin>>a;
	 
	 int table[n][m];
	 
	 // i = 0 or j=0 will be the squares of size 1
	 FOR(i, n)
	  table[i][0] = (grid[i][0]==a?1:0);
	 
	 
	 FOR(j, m)
	  table[0][j] = (grid[0][j]==a?1:0);
	  
	  // checking  up, left and diagonal minimum squares till now
	  loop(i, 1, n-1)
	  {
	  	loop(j, 1, m-1)
	  	{
	  		if(grid[i][j]==a)
	  		{
	  		table[i][j] = min(table[i-1][j-1], min(table[i-1][j], table[i][j-1])) + 1;
			}
			else
			table[i][j] = 0;
		}
	  }
	  
	  int max = -1;
	  FOR(i, n)
	   FOR(j, m)
	    if(table[i][j]>max)
	     max = table[i][j];
	     
	     cout<<max;
	  
}


