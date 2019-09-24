int Solution::largestRectangleArea(vector<int> &A) {

    stack<int> index, height;
    int i = 0;
    int n = A.size();
    int area = INT_MIN;
    for(i ; i<n; i++)
     {
         int a = A[i];
         if (height.empty() || a>height.top())
           {
               index.push(i);
               height.push(a);
           }
         else if (a<height.top())
           {
              int lastI, h;
              while(!height.empty() && a<height.top())
               {
                   lastI= index.top();
                   h = height.top();
                   area = max(area, h*(i-lastI));
                   height.pop();
                   index.pop();
               }

                 index.push(lastIndex);
                  height.push(a);
           }
     }
   i=n;
   if (!height.empty())
   {
      while(!height.empty())
      {
          area = max(area, (height.top())*(i-index.top()));
          index.pop();
          height.pop();
      }
   }

  return area;
}
