//      https://leetcode.com/problems/leftmost-column-with-at-least-a-one/
/*
A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.
*/


/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */


//   Problem asks for a logarithmic solution

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> v = binaryMatrix.dimensions();
        int n = v[0], m = v[1];
        int ans=m;
        
        for(int i=0; i<n; i++)
        {
          // check each row,
          //  range goes from lo=0 to hi = last found column - 1 
            
            int lo=0, hi = ans-1;
            while(lo<hi)
            {
                int mid = lo + (hi-lo)/2;
                
                int a = binaryMatrix.get(i, mid);
                if(a==0)
                    lo = mid+1;
                else
                    hi = mid;
            }
            
            // if this is less than prvios found answer, update
            //  if it's the first column, no need to check further
            if(lo<m && binaryMatrix.get(i, lo) && lo<ans)
            {
                ans = lo;
                if(ans==0)
                    break;
            }
        }
        // if nothing found, return -1
        if(ans==m)
            ans=-1;
        return ans;
    }
};
