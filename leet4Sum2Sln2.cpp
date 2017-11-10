/*

//********************************************************454. 4Sum II.*********************************************************
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the 
range of -228 to 228 - 1 and the result 
is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

// Time Complexity: O(n^2).
// Space Complexity: O(n^2).
//*****************************************************THIS IS LEET ACCPETED CODE.************************************************
*/
class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int len=a.size();
        unordered_map<int, int> m;
        int count=0, sum=0;
        for(int i=0;i<len;i++)// Pushing data(Sum of values) from C, D vectors into unordered_map- m.
            for(int j=0;j<len;j++){
                m[c[i]+d[j]]++;
            }
        for(int i=0;i<len;i++){// Iterating through both the vectors.
            for(int j=0;j<len;j++){
                sum=a[i]+b[j];// Unordered_map takes O(1) time to fetch the required value.
                count+=m[-sum];//Finding out number of times required sum is acheivable from adding contents of C, D.
            }// Whose sum is stored in map-m, attained by iterating through contents of C, D(O(n^2)).
        }
        //cout<<"The count is: "<<count<<endl;
        return count;
    }
};