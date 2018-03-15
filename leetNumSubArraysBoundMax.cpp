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