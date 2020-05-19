#include<iostream>

using namespace std;

void swap(string &s, int i, int j)
{
    char c = s[i];
    s[i]=s[j];
    s[j]=c;
}

void permute(string s, int left, int right)
{
    if(left==right)
     {
         cout<<s<<" ";
         return;
     }

    for(int i=left; i<=right; i++)
    {
        swap(s,i,left);
        permute(s, left+1, right);
    }
}

int main()
{
   string s = "ABC";
   permute(s, 0, s.length()-1);
   cout<<"\n"<<s;
}