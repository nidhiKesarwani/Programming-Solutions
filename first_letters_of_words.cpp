#include<bits/stdc++.h>

using namespace std;

int main()
{
    
  string s;
  getline (cin, s); 
  
  string result = "";
  //result+=s[0];
  
  char prev = ' ';
  for(auto c : s)
   {
     if(prev == ' ' && c!=' ')
       result+=c;
       
       prev = c;
   }
   
   cout<<result;
}