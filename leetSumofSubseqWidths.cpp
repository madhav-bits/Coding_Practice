/*
*
//******************************************************891. Sum of Subsequence Widths.***********************************************

Given an array of integers A, consider all non-empty subsequences of A.

For any sequence S, let the width of S be the difference between the maximum and minimum element of S.

Return the sum of the widths of all subsequences of A. 

As the answer may be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
 

Note:

1 <= A.length <= 20000
1 <= A[i] <= 20000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[2,1,3]


[2,1,3,5,4]


[21,11,33,12,9]


[2,1,3,4,23123,13,123]


[21,11,33,12,9,2342,234,25,234,34,234,23,42,35,345,23,2,34,24,2,4242,234,234,234,14,1,4,346,45634,523,25,6,46,45,645,7567,567567]




// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is iteration/Observation based. As, we need subsequences where max, min values are crucial, we sort the given numbers. If we take
// a subsequence, it's members have to be in range of min->max values, which is a substring in the sorted array. We iter. over given array,
// at each step, we add/consider all subsequences for which curr. index has the largest/max value. Various subseq. with all earlier values as min.
// are possible. If we are at index, we use all subseq. that end with value at index-1 are used to build subseq. ending at index and add diff. 
// b/w curr. and prev. index's values k times.


// The observation is that ending at index-i, we can create pow(2,index)-1 subsequences. Whose ranges are calc. from subseq. ending with 
// index-1, as those ranges are encountered twice in subseq. ending at index-i and new subseq. of prev. and curr. index value is also added, 
// diff. b/w curr. and prev. index value is added to all these ranges.


// For index-i, k is pow(2,index)-1.



Ex: [1,2,3,4,5]

subseq. ending at 4:

1,4   1,2,4    1,2,3,4     1,3,4 ||  2,4,     2,3,4 ||   3,4

Subseq. ending at 5:

1,5  1,4,5    1,3,5   1,2,5   1,2,3,5   1,3,4,5    1,2,4,5   1,2,3,4,5 ||   2,5    2,4,5    2,3,5   2,3,4,5 ||  3,5  3,4,5 || 4,5  

// #Subseq. starting with each value has doubled and new subseq.(values from curr. and prev. index) is added.



// An easier appraoch is discussed here, in this link:
// https://leetcode.com/problems/sum-of-subsequence-widths/discuss/161267/C++Java1-line-Python-Sort-and-One-Pass









class Solution {
public:
    int sumSubseqWidths(vector<int>& v) {
        sort(v.begin(), v.end());											// Sort the given array.
        int modu=1000000007;
        long int res=0;														// Track the final result.
        long int extra=1;													// #diff. b/w curr. and prev. index values added.
        long int earl=0;													// Sum of values of subseq. ending at prev. index.
        for(int i=1;i<v.size();i++){										// Iter. through all possible end indices.
            extra=(extra*2)%modu;											// As, #subseq. gets twice every time.
            long int ans;													// #Subseq. ending with curr. index.
            ans=(earl*2)%modu;												// As #subseq. ending at curr. index doubles every time.
            long int prev=v[i-1];											// Prev. index value.
            long int diff=(v[i]-prev);										// Calc. diff. to curr. to prev. index.
            ans=(ans+((extra-1)*diff)%modu)%modu;							// Add the diff. to 2*subseq. ending at prev. index.
            res=(res+ans)%modu;												// Update the final result.
            earl=ans;														// Make #subseq. ending at curr. index as prev. value.
            // cout<<"ans: "<<ans<<" and res: "<<res<<endl;
        }
        return res;															// Returning the final result.
    }
};