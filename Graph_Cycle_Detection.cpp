bool isCyclic(int v, vector<int> graph[], vector<int> &color)
{
    color[v]=1;
    //process starts, nodes enters into the stack
    for(int u : graph[v])
      {
          if (color[u]==1) //if already in the stack
            return true;
            
          if( color[u]==0 && isCyclic(u, graph, color)) //if some other node in cycle
             return true;
      }
     //process ends 
    color[v] = 2;
    
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    
    vector<int> graph[A+1]; //directed graph
    vector<int> color(A+1, 0); //colors of the nodes
    // 0 for unvisited, 1 for being visited and 2 for visited
    for(int i=0; i<B.size(); i++)
      graph[B[i]].push_back(C[i]);
      
     for(int i = 1; i<=A; i++)
        if (color[i]==0 && isCyclic(i, graph, color))
           return 0;
    
     return 1;
}
