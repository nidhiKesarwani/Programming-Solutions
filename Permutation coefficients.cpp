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
int permutationCoeff(int n, int k) 
{ 
    int P[n + 1][k + 1]; 
  
    // Caculate value of Permutation  
    // Coefficient in bottom up manner 
    for (int i = 0; i <= n; i++) 
    { 
        for (int j = 0; j <= min(i, k); j++) 
        { 
            // Base Cases 
            if (j == 0) 
                P[i][j] = 1;
            else
                P[i][j] = P[i - 1][j] + (j * P[i - 1][j - 1]); 
                
            P[i][j + 1] = 0; 
        } 
    } 
    return P[n][k]; 
} 
  
ll directCoef(int n, int k)
{
	if(k>n)
	return 0;
	
	ll res =1;
    FOR(i, k)
     res*=(n-i);
	return res;
}
// Driver Code 
int main() 
{ 
    int n = 10, k = 2; 
    printf("Value of P(%d, %d) is %d ", 
            n, k, permutationCoeff(n, k)); 
    return 0; 
} 
