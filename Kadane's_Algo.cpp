#include<bits/stdc++.h>

using namespace std;
int maxSubArraySum(int arr[], int n)
{
        int global = INT_MIN;
	      int maxE = *(max_element(arr, arr+n));
	      int curr = 0;
	      
	      for(int i =0; i<n; i++)
	        {
	            if (curr+arr[i]<0)
	              curr = 0;
	            else
	             {
	                 curr+=arr[i];
	                 if (curr>global)
	                   global = curr;
	             }
	        }
	    //if all are negative    
	   if (global==INT_MIN)
	     global = maxE;
	     
	 return global;    
}
int main()
 {
	//code
	      int n ;
	      cin>>n;
	      
	      int arr[n];
	      
	      for(int i =0; i<n; i++)
	       cin>>arr[i];
	      cout<<maxSubArraySum(arr, n)<<endl;
	return 0;
}
