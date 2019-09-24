#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};

bool isValid(int i, int j, int n, int m)
{
    return (i>=0 && i<n && j>=0 && j<m);
}


int main()
 {
	 int t;
     cin>>t;

     while(t--)
      {
          int n ;
          cin>>n;
          int p =4, q=3;

          long long  mobile[p][q];

          for(int i=0; i<4; i++)
            for(int j =0; j<3; j++)
              mobile[i][j]=1;

          mobile[3][0] = mobile[3][2]=0;

          long long sum = 10;
          int o=1;
          for(o; o<=n; o++)
            {
                if (o==n)
                   break;

                long long dp[p][q];
                for(int i =0; i<p; i++)
                  for(int j =0; j<q; j++)
                    {
                        dp[i][j] = mobile[i][j];
                        for(int k =0; k<4; k++)
                          {
                              int x = i+dx[k];
                              int y = j+dy[k];

                              if (isValid(x, y, p, q))
                                {
                                    dp[i][j] += mobile[x][y];
                                }
                          }
                    }

               dp[3][0] = dp[3][2] = sum = 0;
               
               for(int i =0; i<p; i++)
                  for(int j =0; j<q; j++)
                   { mobile[i][j] = dp[i][j];
                    sum+=dp[i][j];}


            }

         cout<<sum<<endl;
      }
}
