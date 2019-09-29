#include<bits/stdc++.h>

using namespace std;

int main()
 {
     
     int t;
     cin>>t;

     while(t--)
       {
           int n;
     cin>>n;

     int arr[n];

     for(int i=0; i<n; i++)
      cin>>arr[i];

   vector<pair<int, int> > ans;
   int min = arr[0], start = 0, end=-1;

   for(int i=1; i<n; i++)
    {
       if(arr[start]>arr[i] && end==-1)
        {
           start = i; // new minima found before the local maxima, so update
        }
    else if(arr[i]<arr[i-1])
      {
          ans.push_back({start, end}); // update
          start = i;  //new minima found
          end=-1;
      }
    else
      end = i; // do nothing
    }
    
    if(end !=-1)
      ans.push_back({start, end});
      
      
            for(auto i : ans)
              cout<<"("<<i.first<<" "<<i.second<<") ";

             cout<<endl;
       }
 
 }
