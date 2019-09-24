#include<bits/stdc++.h>

using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	 {
	     int n ;
	     cin>>n;
	     
	     unordered_map<string, int> um;
	     for(int i =0; i<n; i++)
	      {
	          string s;
	          cin>>s;
	          um[s] =1;
	      }
	      
	      string q;
	      cin>>q;
	      
	      vector<string> v;
	      n = q.length();
	      string running = "";
	      for(int i = n-1; i>=0; i--)
	       {
	           running = q[i]+running;
	           
	           if (um[running]==1)
	             {
	                 v.push_back(running);
	                 running = "";
	             }
	           else if (v.size()>0)
	           {
	               for(auto s : v)
	                 {
	                     string p = running+s;
	                     if (um[p]==1)
	                      {
	                           v.push_back(p);
	                           running = "";
	                      }
	                 }
	           }
	       }
	     if (running=="")
	       cout<<"1";
	     else
	       cout<<"0";
	       
	       cout<<endl;
	 }
	return 0;
}