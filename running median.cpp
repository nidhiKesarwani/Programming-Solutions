#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int> > minh;

    float med = 0;

    int n;

    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        if(minh.empty() && maxh.empty())
         {
             minh.push(t);
             med = t;
         }
        else if(minh.empty() || minh.size()<maxh.size())
        {
            if(maxh.top()<t)
            {
                int a = maxh.top();
                maxh.pop();
                maxh.push(t);
                minh.push(a);
            }
           else
           {
               minh.push(t);
           }
           //sizes are equal now
           med = ((float)minh.top() + (float)maxh.top())/2;
        }
        else if(maxh.empty() || maxh.size()<minh.size())
        {
            if(minh.top()>t)
            {
                int a = minh.top();
                minh.pop();
                minh.push(t);
                maxh.push(a);
            }
            else
            {
                maxh.push(t);
            }
          med = ((float)minh.top() + (float)maxh.top())/2;  
        }
        else
        {
            
        }

    }
}