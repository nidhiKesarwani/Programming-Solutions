#include<bits/stdc++.h>

using namespace std;

void multiply(string s, string t)
{
    if(s.length()==0 || t.length() ==0)
     cout<<"0";
    else
    {
        int n, m;
        n = s.length();
        m = t.length();

        vector<int> res (n+m, 0);
        int e=0, f=0;

        for(int i=m-1; i>=0; i--)
         {
             f=0;
             int c=0;
             int a = t[i]-'0';

             for(int j = n-1; j>=0; j--)
              {
                  int num = (s[j]-'0')*a + res[e+f] + c;
                  c = num/10;
                  res[e+f] = num%10;
                  f++;
              }
              if(c>0)
                res[e+f]+=c;
              e++;
         }
      int i = res.size()-1;
      while(i>=0 && res[i]==0)
       i--;

       if(i==-1)
        {
            cout<<"0";
            return;
        }
       string  s = "";
       while(i>=0)
         s+= (to_string(res[i--]));
      
      cout<<s;
    }
    
}
int main()
{
    string s1, s2;
    cin>>s1>>s2;

    if((s1[0]=='-' || s2[0]=='-') && (s1[0]!='-' || s2[0]!='-'))
     {
         cout<<"-";
     } 
    if(s1[0]=='-')
      s1 = s1.substr(1);
    if(s2[0]=='-')
      s2 = s2.substr(1);

      multiply(s1, s2);

}