
#include<bits/stdc++.h>
using namespace std;
string printOrder(string [], int , int );
string order;
bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}
	
	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();
	
	return p1<p2;
}
	
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    
        string ss = printOrder(s,n,k);
        order="";
        for(int i=0;i<ss.size();i++)
        order+=ss[i];
        
        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp,temp+n,f);
        
        bool f= true;
        for(int i=0;i<n;i++)
        if(s[i]!=temp[i])f=false;
        
        cout<<f;
        cout<<endl;
        
    }
	return 0;
}



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
