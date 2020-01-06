double medianC(vector<int>& a, vector<int>& b)
    {
        
        int n = a.size();
        int m = b.size();
        int p = (n+m+1)/2;
        // first array passed is of smaller size and we run the binary serch on that array
        int minI=0, maxI=n, i, j;
        
        // i and j are the number of elements in the left part of merged array from a and b respectively
        // left part will contain odd number of elements if n+m is odd
        
        double median;
        
        while(minI<=maxI)
        {
             i = (minI+maxI)/2;
             j = p-i;
            
            // i==0 menas no element of a is in left part, same for j==0
            // i==n menas no element of a is in right part, same for j==m
            
            // if a has elements in left part then check if its last element is smaller than 
            // the first element of b's right part, if not then go to left in array a to find smaller element
            
            if(i>0 && j<m && a[i-1]>b[j]) // galat situtaion
                maxI = i-1;
                
             // if b has elements in left part then check if its last element is smaller than 
            // the first element of a's right part, if not then go to right in array a to find larger element   
            
            else if(i<n && j>0 && b[j-1]>a[i])
               minI= i+1;
            else
            {
            // here we are justa taking a single number, not the median
                if(i==0)
                    median = b[j-1];
                else if(j==0)
                    median = a[i-1];
                else
                    median = max(a[i-1], b[j-1]);
                
                break;
            }
        }
      
      // now if n+m is odd then that single number is median
       if((n+m)%2==1)
           return median;
           
         // here we are dealing with even number of elements so we will need two elements for median
        // if a has all the elements in left part then only b will give the next elements from right part
        
        if(i==n)
             median = (median+b[j])/2;
             
          // if b has all the elements in left part then only a will give the next elements from right part
          
        else if(j==m)
             median = (median+a[i])/2;
             
         // else max of a and b's right part will give the second number
         
        else
            median = (median + min(a[i], b[j])) /2;
        
       return median; 
    }
    
