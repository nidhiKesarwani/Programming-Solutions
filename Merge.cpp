 struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 * 
bool cmp(Interval &i1, Interval &i2)
{
    if(i1.start == i2.start)
      return i1.end<i2.end;

    return i1.start<i2.end;
}
vector<Interval> Solution::insert(vector<Interval> & I, Interval G ) 
{
   sort(I.begin(), I.end(), cmp);

   stack<Interval> s;
   vector<Interval> sol;

   s.push(I[0]);

   for(int i=1; i<I.size(); i++)
   {
       Interval f = s.top(); s.pop();
       Interval g = I[i];

       if((f.start < g.start && f.end < g.start) )
       {
           sol.push_back(f);
           s.push(g);
       }
       else
       {
           int a = min(f.start , g.start );
           int b = max(f.end, g.end())
           Interval k(a, b);
           s.push(k);
       }
       
   }
   if(!s.empty())
    {
        sol.push_back(s.top());
    }
}