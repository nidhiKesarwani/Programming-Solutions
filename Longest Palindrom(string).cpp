int maxPalindrome(string v)
{
 
    int ans = 1, st=0, en=0;
    for(int i = 1; i<n; i++)
     {
         int low, high;
         // first even length, with the center as the space between this 
         // and previous element
         
         low = i-1, high = i;
         while(low>=0 && high <n && v[low]==v[high])
           {
               if (ans< high-low+1)
               {
               ans = high-low+1;
               st = low; en = high;
               }
               low--; high++;
           }
          // now odd length, with the center as the the current element
        low = i-1, high = i+1;
        
         while(low>=0 && high <n && v[low]==v[high])
           {
               if (ans< high-low+1)
               {
               ans = high-low+1;
               st = low; en = high;
               }
               low--; high++;
           }
     }
    // string from st to en is the substring wee need
   return ans;
}
