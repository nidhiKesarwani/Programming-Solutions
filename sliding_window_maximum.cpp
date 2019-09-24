vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> q;
    for(int i =0; i<k ; i++)
      {
        if(q.empty())
          q.push_front(i);
        else
          {
              while(!q.empty() && A[q.back()] <= A[i])
                 q.pop_back();

              q.push_back(i);
          }
      }
    vector<int> v;
    v.push_back(A[q.front()]);

   for(int i=k; i<n; i++)
   {
       int l = i-k+1;

       while(!q.empty() && q.front()<l)
         q.pop_front();

         // now same procedure
        if(q.empty())
          q.push_front(i);
        else
          {
              while(!q.empty() && A[q.back()] <= A[i])
                 q.pop_back();

              q.push_back(i);
          } 

        v.push_back(A[q.front()]);
   }
  return v;
}