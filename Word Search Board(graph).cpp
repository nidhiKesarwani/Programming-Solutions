int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isSafe(int i, int j, int n, int m)
{
    if (i>=0 && i<n && j>=0 && j<m)
      return true;
      
    return false;
}
// question from interviewBit
// if we use the second pair in queue as string , int to know the current string, memory is wasted
// as no need to store the string
// now if we just store the i, still memory limit exceeds as same node may be visited by disfferent origins
// here visited is not used as repetition of node is allowed
// so use a indicator that this node is in queue, when paopped out, make it false


int Solution::exist(vector<string> &mat, string B) {
     int n = mat.size();
     int m = mat[0].length();
     string f = "";
     f+=B[0];
     vector< vector<bool> > cuurentlyInQueue(n, vector<bool> (m, false));
    // vis[1][3] = true;
    queue< pair < pair<int, int>, int > > Q; 
     for(int i=0; i<n; i++)
       {
           //cout<<mat[i]<<endl;
           for(int j =0; j<m; j++)
            if(mat[i][j]==B[0])
             { Q.push({{i, j}, 1});
              cuurentlyInQueue[i][j]=true;}
       }
    
     while(!Q.empty())
      {
         
          auto p = Q.front().first;
          int i = Q.front().second;
          
          Q.pop();
          cuurentlyInQueue[p.first][p.second]=false;
          
          if (i==B.length())
          return 1;
         
             for(int k =0; k<4; k++)
                {
                    int x = dx[k]+p.first;
                    int y = dy[k]+p.second;
                    
                    if (isSafe(x, y, n, m) && mat[x][y]==B[i] && cuurentlyInQueue[x][y]==false)
                     { Q.push({{x, y}, i+1});
                       cuurentlyInQueue[x][y] = true;
                     }
                }
      }
   return 0; 
}


