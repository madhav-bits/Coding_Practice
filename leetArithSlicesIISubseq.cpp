/*
*
//**************************************************446. Arithmetic Slices II - Subsequence.*******************************************

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive 
elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such 
that 0 ≤ P0 < P1 < ... < Pk < N.

A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In 
particular, this means that k ≥ 2.

The function should return the number of arithmetic subsequence slices in the array A.

The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less 
than 231-1.


Example:

Input: [2, 4, 6, 8, 10]

Output: 7

Explanation:
All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[2,2,4,4,6,3,2,3,8,5,519,10,7,9,7,10,12]



[2,2,4,4,5,6,8,2,2,4,2,6,6,8,10,4,12]




[0,2000000000,-294967296]




// Time Complexity: O(n^2).  												// Ammortized Complexity.
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).													// Ammortized Complexity.
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programmig based. Here, the prev[i][diff] indicates the number of seq. with 2 elem. with difference of diff.
// combi[i][diff] # arith. seq. with >=3 elements with diff. b/w them. We build combi[i][diff] based on prev[j][diff] values during our iteration
// from 0 to 'i-1' indices, with i as point of reference. As, combi indicates seq. with length>=3, combi[i][diff] take values numbers of seq.
// formed with v[j] as it's last elem., we also have to include seq. of length 3 with v[j] and v[i] as their last numbers, so we use prev[j][diff]
// values while adding this new sequence combi. count. After updating all values, we iterate through all indices and diff. formed with that
// index as last number and add it to final count and return count.



// We can further optimize this solution by adding all combi. of seq. of len>=2 with diff. to final count at every step while adding to combi.
// count.



class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
		if(v.size()<=2) return 0;											// Base indices.
        int res=0;															// Final result count.
        // vector<vector<int>>prev(v.size(),vector<int>(v.size(),0)), combi(v.size(),vector<int>(v.size(),0));
        unordered_map<int,unordered_map<long int,int>>prev,combi;			// Tracks #combi. of arith. seq. of len>=3 and len=2.
        for(int i=0;i<v.size();i++){										// Iter. through all indices.
            for(int j=0;j<i;j++){											// Iter. through it's prev. indices.
                long int diff=(long int)v[i]-v[j];
                prev[i][diff]++;											// Updating #seq. with v[j] and v[i] as last elem.
                if(combi[j].count(diff)==1)									// Adding all combi. of len>=3 with 'j' as last elem. with 'diff'.
                    combi[i][diff]+=combi[j][diff];
                if(prev[j].count(diff)==1)									// Adding all combi. of len==2 with v[j] as last elem.
                    combi[i][diff]+=prev[j][diff];
            }
        }
        for(int i=0;i<v.size();i++){										// Iter. through all indices.
            // cout<<"index i: "<<i<<endl;
            for(auto it=combi[i].begin();it!=combi[i].end();it++){			// Iter. through all diff. it forms.
                // cout<<"The count for diff: "<<it->first<<" is: "<<it->second<<endl;
                res+=it->second;
            }
        }
        return res;
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).													// Ammortized Complexity.
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programmig based. This algo. is same as prev. one, but further optimzed space complexity by letting combi. represent
// arith. seq. of len>=2 instead of len>=3. And adding only len>=3 sequences combi. to final count.






class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
		if(v.size()<=2) return 0;
        int res=0;
        vector<unordered_map<long int,int>>prev(v.size()), combi(v.size());
        for(int i=0;i<v.size();i++){
            for(int j=0;j<i;j++){
                long int diff=(long int)v[i]-v[j];
                if(combi[j].count(diff)==1)									// Adding all arith. seq. combi. with len>=2 to seq. ending with v[i].
                    combi[i][diff]+=combi[j][diff];
                
                if(combi[j].count(diff)==1)									// If prev. seq. exist, add them to final result count.
                    res+=combi[j][diff];
                combi[i][diff]++;											// Adding curr. seq. of len=2 formed by v[j] and v[i] to combi. count.
            }
        }
        return res;															// Returning the final count.
    }
};