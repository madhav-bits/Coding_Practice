/*
*
//******************************************************795. Number of Subarrays with Bounded Maximum.***********************************************

We are given an array A of positive integers, and two positive integers L and R (L <= R).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least 
 and at most R.

Example :
Input: 
A = [2, 1, 4, 3]
L = 2
R = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Note:

L, R  and A[i] will be an integer in the range [0, 10^9].
The length of A will be in the range of [1, 50000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[2,0,3,1,4,3,4,6,3,2,7,9,8,3,2,1,6,5]
4
8

[2,0,3,1,4,3,4,6,3,2,7,9,8,3,2,1,6,5]
3
8



[876,880,482,260,132,421,732,703,795,420,871,445,400,291,358,589,617,202,755,810,227,813,549,791,418,528,835,401,526,584,873,662,13,314,988,101,299,816,833,224,160,852,179,769,646,558,661,808,651,982,878,918,406,551,467,87,139,387,16,531,307,389,939,551,613,36,528,460,404,314,66,111,458,531,944,461,951,419,82,896,467,353,704,905,705,760,61,422,395,298,127,516,153,299,801,341,668,598,98,241]
658
719




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
// This algorithm iterates the array maintains the beginning of subarray satisfying the conditions, also maintains the last index's integer which is
// in the range. So, no. in these indices range contribute to the subarrays ending with indices with value <L. For indices with >=L, it forms
// subarrays with all elements of large subarray starting from it's beginning. This can be optimized, by tweaking the variable flow.





class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& v, int L, int R) {
        int count=0, len=0, temp=0, maxm=0, start=0, prev;
        for(int i=0;i<v.size();i++){
            if(len==0 && v[i]<=R){							// Marks the beginning of the large subarray.
                len=1;
                if(v[i]>=L){								// Marking the occurance of # satisfying condition.
                    count++;
                    start=i;
                    prev=i;
                }
                else{										// Just marking the beginning of large subarray.
                    start=i;
                    prev=i-1;
                }
            }
            else if(len!=0 && v[i]<L){						// If the curr. value is <L, it's contribution to the final subarrays.
                //cout<<"The start is: "<<start<<" and the prev is: "<<prev<<" and len is: "<<len<<endl;
                count+=prev-start+1;						// Starting from the first member of large subarray satis. the condi. to the last index.
                len++;
            }
            else if(len!=0 && v[i]<=R){						// If the curr. value is >L && <=R, it's contribution to the final subarrays.
                len++;										// As, all the mem. till now in large subarray contribute to the final subarrays.
                count+=len;
                temp++;
                prev=i;
            }
            else{
                len=0; 
                temp=0;
            }
            //cout<<"The index i: "<<i<<" and the count is: "<<count<<endl;
        }
        return count;										// Return the total # subarrays satisfying the condition.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************THIS IS A VERY GOOD PROBLEM.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we are forming subarrays whose max. val is >=L and <=R. We cnt subarrays by using two vars.
// startIndex is where the current subarray starts, leftWidth is the #indices including from startIndex to L<=x<=R which is base of 
// subarray's existence. Whenever we encounter a value in target range, we can form subarrays ending at curr. index with starting index
// from startIndex, so we add i-startIndex+1 to result. We also update the leftWidth as this index would be the last index of left subarr.
// possib. When we encounter a val.<L, then we can form subarrays with indices starting from startIndex to index of prev. target val's
// index, which is stored as leftWidth, so we add this to result. If we face val.>R, then this index can't be in subarrays, so we update
// startIndex to next index, also leftWidth to 0. We return total cnt at the end of iteration.



// THere are many detailed solutions in the Leetcode discussion forum.
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117595/Short-Java-O(n)-Solution
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/



class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& v, int L, int R) {
        int res=0, startIndex=0, leftWidth=0;								// Tracks start of valid startIndices, left side of subarrays.
        for(int i=0;i<v.size();i++){										// Iter. over given array.
            if(v[i]>=L && v[i]<=R){											// If target val. found.
                res+=i-startIndex+1;										// Add subarr with start index from startIndex to i to result.
                leftWidth=i-startIndex+1;									// Reassign leftWidth as 'i' would be it's last index.
            }else if(v[i]<L) res+=leftWidth;								// Add leftWidth, as we form arr with all startindices in leftWidth.
            else{															// If greater val. found, it can't be in subarray.
                startIndex=i+1;												// Move startIndex to next index.
                leftWidth=0;												// Assign it 0, as there are valid no start indices.
            } 
        }
        return res;															// Return the total num. of valid subarrays.
    }
};


