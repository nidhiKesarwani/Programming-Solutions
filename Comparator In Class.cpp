class Solution {
public:
    
    bool cmp(const vector<int> & A, const vector<int> &B)
    {
        int a = abs(A[0]), b = abs(A[1]), c = abs(B[0]), d = abs(B[1]);
        
       if(sqrt(a*a + b*b) <= sqrt(c*c + d*d))
           return true;
        return false;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>> points, int K) {
       
        // this part, in place of cmp we will write " [this] (vector<int> a, vector<int> b) { return cmp(a, b);} "
        sort(points.begin(), points.end(), [this] (vector<int> a, vector<int> b) { return cmp(a, b); } );
        
        vector<vector<int> > ans;
        for(int i=0; i<K; i++)
            ans.push_back(points[i]);
        
        return ans;
    }
};
