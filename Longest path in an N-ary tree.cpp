//code can be easily modified for binary tree

int nowTellTheMaxDistance(vector<int> graph[], bool vis[], int v, int &ans)
{
   // check recursively for every node in tree
    vis[v] = true;
    // store two sides that has max and second max number of nodes
    int a=0, b=0;
    
    for(int u : graph[v])
     {
         if (vis[u]==false)
           {
               int m = nowTellTheMaxDistance(graph, vis, u, ans);
                // updation of a, b  b is the max
               if (m>=b)
               {
                   a = b;
                   b = m;
               }
               else if (m>a)
                 a = m;
           }
     }
   // not necessarily true that the root node will have the longest path
   // so if we find some node that does't go through root but have a+b ,aximum
   // then update (number of nodes in path a+b+1, and length a+b)
   ans = max(ans, a+b);
  // we are sending the maximum + 1, so that the root node knows how many max
  // number of nodes this side can give
  // so for this side it is b, so it will include itself and return b+1
  // understood you dumb??
  // you don't understand the code you wrote yourself
  // now enjoy
  return b+1;
}
int Solution::solve(vector<int> &A) {
    
    // very confusing question, so just pay attention
    // make a graph
    // need to find the longest path
    // not the number of nodes in longest path
    int n = A.size();
    
    vector<int> graph[n];
    bool vis[n];
    for(int i=0; i<n; i++)
    {
        if (A[i]==-1)
          continue;
        else
          graph[A[i]].push_back(i);
          
          vis[i]= false;
    }
    //graph constructed
    int ans = 0, i = 0;
    // call dfs on 0
    nowTellTheMaxDistance(graph, vis, i, ans );
      
    return ans;
}
