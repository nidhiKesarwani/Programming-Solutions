#include<bits/stdc++.h>

using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	 {
	     string s;
	     cin>>s;
	     int n = s.length();
	     
	     reverse(s.begin(), s.end());
	     
	     int even=0, odd=0;
	     
	     for(int i =0; i<n; i+=2)
	       if (s[i]=='1')
	         even++;
	         
	     for(int i =1; i<n; i+=2)
	       if (s[i]=='1')
	         odd++;   
	    int d = abs(even-odd);
	    if (d%3==0)
	      cout<<'1';
	    else
	      cout<<'0';
	      
	     cout<<endl;
	 }
	return 0;
}
