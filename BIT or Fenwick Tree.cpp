void add(int BIT[], int idx, int val)
{
    while (idx < BIT.length())
     {
         BIT[idx]+=val;
         idx = idx+(idx &(-idx)); //extract the last set bit, add it, move forward
     }
}

int getSum(int BIT[], int idx)
{
    int sum =0;
    
    while(idx>0)
     {
         sum+=BIT[idx];
         idx = idx-(idx & (-idx)); //extract the last set bit, add it, move backward
     }
    return sum;
}


// given the arry of size n
// make array BIT of size n+1, for 1 base indexing
// one by one add 

int main()
 {
	//code
	
	     int n ;
	     cin>>n;
	     
	     int arr[n];
	     for(int i =0; i<n; i++)
	       cin>>arr[i];
	      int BIT[n+1] = {0};
        for(int i =0; i<n; i++)
          add(BIT, i+1, arr[i]); // these are same as updates at (i+1)th position with value arr[i], adding
          
        // tree constructed
        // now to find the sum at position i
        // just call getSum(BIT, i)
        
        cout<<getSum(BIT, 5); // sum of first 5 elements
	return 0;
}
