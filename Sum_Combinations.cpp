int waysToConstructSum(int arr[], int n, int sum)
{
    int table[sum+1][n+1];
    for(int i =0; i<sum+1; i++)
      table[i][0] = 0;
      
    for(int j=0; j<=n; j++)
      table[0][j] =1;
      
      
     for(int i = 1; i<sum+1; i++)
       {
           for(int j = 1; j<n+1; j++)
            {
                table[i][j] = table[i][j-1];
                
                if(arr[j-1]<=i)
                  table[i][j]+= table[i-arr[j-1]][j-1];
            }
       }
       
     return table[sum][n];
}
