#include<bits/stdc++.h>

using namespace std;


int main()
{
    string s;
    cin>>s;

    int count[26] = {0};

    int start = 0;
    int l =1;
    count[s[0]-'a']++;

    for(int i=1; i<s.length(); i++)
     {
         count[s[i]]++;
         if(count[s[i]]==2)
          {
              for(int j = start; j<i; j++)
               {
                   count[s[j]]--;
                   if(count[s[i]]==1)
                    {
                        start = j+1;
                        break;
                    }
               }
          }

          l = max(l, i-start+1);
     }

     cout<<l<<endl;
}