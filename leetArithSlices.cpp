/*
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two 
consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

//***************************************************THIS IS LEET ACCEPED CODE.*************************************************
// Got the inspiration for small logic from other source.***********************************************************************
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int size=v.size();
        int count=0;
        for(int i=0; i+2<size;i++){
            int start =i;// Saves the beginning of the array sequence we will be working on.
            while(v[i+2]+v[i]==2* v[i+1] && i+2<v.size() ){
                count+= i-start+1;// This makes sure that the AM series starting from start, start+1,...i-1 indexes are also counted.
                i++;// This inc.the index of the vector element on which we have to work on.
            }
        }
        return count;
    }
};