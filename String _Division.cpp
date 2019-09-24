bool isDivisible (string s, int n)
{
   
    string ans="";
    int temp = s[0]-'0';
    int idx=1;
  //  cout<<ans << "  "<<ans<<endl;
    while(idx<s.size() && temp<n)
      {
          temp = temp*10 + (s[idx]-'0');
          idx++;
      }
    int rm = temp%n;
    ans += (temp/n)+'0';
    
     while(idx<s.size())
      {
          temp = (temp%n)*10 +  (s[idx]-'0');
          ans += (temp/n)+'0';
          rm = temp%n;
          idx++;
      }
     if (rm>0)
       return false;
   
       return true;
       
}