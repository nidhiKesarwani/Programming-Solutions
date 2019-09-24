#include<bits/stdc++.h>

using namespace std;
// expected O(n) with random Partition (without it, it is O(n^2))
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pI = start;
    
    for(int i = start; i<end; i++)
     {
         if (arr[i]<=pivot)
           {
               int a = arr[i];
               arr[i] = arr[pI];
               arr[pI] =a;
               pI++;
           }
     }
               int a = arr[end];
               arr[end] = arr[pI];
               arr[pI] =a;
               
    return pI;
}

int randomPartition(int arr[], int l, int r) 
{ 
    int n = r-l+1; 
    int pI = rand() % n; 
    // this pI is a number with respect to l and r so change it to global pI
    pI = l+pI;
    //now swap
    int a = arr[pI];
    arr[pI] = arr[r];
    arr[r] = a;
    //done
    return partition(arr, l, r); 
} 

int kth(int arr[], int start, int end, int k)
{
    if (start==end)
      return arr[start];


   int pI = partition (arr, start, end);

   if (pI+1==k)
     return arr[pI];

   if (pI+1 < k)
     return kth(arr, pI+1, end, k);
  else
      return kth(arr, start, pI-1, k);
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n ;
	    cin>>n;
	    int arr[n];
	    for(int i =0; i<n; i++)
	      cin>>arr[i];
	     
	    int k;
	    cin>>k;
	    
	    cout<<kth(arr, 0, n-1, k)<<endl;
	}
	
	
	return 0;
}