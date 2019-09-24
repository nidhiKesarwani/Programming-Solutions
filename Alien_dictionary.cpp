void topo(vector<int> graph[], int vis[], int v, vector<int>* a)
{
    vis[v]=1;
    
    for(int u : graph[v])
    {
        if (vis[u]==0)
          topo(graph, vis, u, a);
    }
  //  char c = (char) ('a'+v);
    (*a).push_back(v);
}

string printOrder(string dict[], int N, int K)
{
   //Your code here
   // N number of strings, K number of alphabets
   vector<int> graph[26];
   
   for(int i=0; i<N-1;i++)
     {
       string s = dict[i];
       string t = dict[i+1];
       
       int n = min(s.length(), t.length());
       for(int j =0; j<n; j++)
         {
             if (s[j]!=t[j])
               {
                   graph[s[j]-'a'].push_back(t[j]-'a');
                   break;
               }
         }
     }
     
     //graph constructed
     int vis[26]={0};
     //int s = dict[0][0]; // start node
      string ans="";
      vector<int> a;
     for(int i =0; i<26; i++)
     {
         if(graph[i].size()!=0 && vis[i]==0)
         {
           topo(graph, vis, i, &a);
         }
         
     }
    
     for(int i = K-1; i>=0; i--)
      {
          char c = 'a'+a[i];
          ans+=c;
      }
      //cout<<ans<<endl;
     return ans;
     
}
