#include<bits/stdc++.h>
using namespace std;

struct DISJOINTSET{
    int *parent, *rank; 
    int n;

    DISJOINTSET(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rank   = new int[n+1];

        for(int i =0; i<=n ; i++)
          {
              rank[i]   = 0;
              parent[i] = i;
          }
    }
    
    int find(int u)
      {
          int root = u;

         while(root!=parent[root]) //finding the ultimate parent
           root = parent[root];
         
         // compressing
         // making root every node's parent which was found in way from u to root
         while(u!=root)  
          {
              int next = parent[u];
               parent[u] = root;
               u = next;
          }
         //returning ultimate root
        return root; 
      }

    void unify(int u, int v)
      {
          int x = find(u);
          int y = find(v);

          if (x==y)
            return ;

          // merging the maller sized component into larger one
          if (rank[x] > rank[y])
            {
                rank[x] += rank[y];
                parent[y] = x;
            }
          else 
          {
              rank[y] += rank[x];
              parent[x] = y;
          }
      }

};

int main()
{
    int n;
    cout<<"Enter the number of nodes or elements : ";
    cin>>n;
    DISJOINTSET ds(n);

    ds.find(3);
    ds.unify(3, 7);
}