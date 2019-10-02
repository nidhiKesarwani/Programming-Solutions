int romanToInt(string A)
{
  unordered_map<char, int> um;
    um['I'] = 1;
    um['V'] = 5;
    um['X'] = 10;
    um['L'] = 50;
    um['C'] = 100;
    um['D'] = 500;
    um['M'] = 1000;
    
    int n = A.length();
    int p=0, ans=0;
    for(int i = n-1; i>=0; i--)
    {
        int a = um[A[i]];
        if (a<p)
          ans-=a;
        else
         ans+=a;
         
         p = a;
    }
    
  return ans;
  }
