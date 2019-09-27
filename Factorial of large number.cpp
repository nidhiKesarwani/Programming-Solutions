#include<bits/stdc++.h>

using namespace std;

void multiply(int res[], int &curr_size , int n)
{
    int carry = 0;
    for(int i = 0; i<curr_size; i++)
     {
         int p = res[i]*n;
         p+=carry;
         res[i] = p%10;
         carry = p/10;
     }
     
    while(carry)
    {
        res[curr_size] = carry%10;
        curr_size++;
        carry = carry/10;
    }
}

void factorial(int n)
{
    int len = 10000;
    int res[len];
    int curr_size = 1;
    res[0]=1;
    
    for( int i=2; i<=n; i++)
     multiply(res, curr_size, i);
     
    for(int i = curr_size-1; i>=0; i--)
     cout<<res[i];
    
    cout<<endl;
}

int main()
 {
	//code
	 int n;
	     cin>>n;
	     factorial(n);
	 
	return 0;
}
