#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	// divide in two subsets such that max of (sum of s1, sum of s2) is minimum
	int arr[n+1];
	int sum=0;
	for(int i=1; i<=n; i++)
	  {
	  	cin>>arr[i];
	    sum+=arr[i];
	  	
	  }
	 bool table[sum+1][n+1];
	 for(int i=0; i<=sum; i++)
	  table[i][0]=false;
	  
	 for(int j=0; j<=n; j++)
	  table[0][j]=true;
	  
	 for(int i=1; i<=sum; i++)
	 {
	 	for(int j=1; j<=n; j++)
	 	{
	 		if(arr[j]>i)
	 		  table[i][j] = table[i][j-1];
	 		else
	 		  table[i][j] = (table[i-arr[j]][j-1] || table[i][j-1]);
	 	}
	 	
	 }
	 int ans = INT_MAX;
	for(int i=1; i<=sum/2; i++)
	 {
	    if(table[i][n])
	      {
	      	int h = max(i, sum-i);
	      	ans = min(ans, h);
	      }
	 }
	cout<<ans;  
	return 0;
}
