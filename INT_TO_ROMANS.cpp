string intToRoman(int A) {
    
    string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int    value[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    string s = "";
    int i =0;
     while(A>0)
        {
            if (A-value[i]>=0)
              {
                  s+=roman[i];
                  A-=value[i];
              }
             else
             i++;
        }
   return s; 
}
