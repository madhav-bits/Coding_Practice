/*
*
//*****************************************2789. Largest Element in an Array after Merge Operations.**************************************

https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,3,7,9,3]
[5,3,3]
[3,5,6]
[1,2,3,4,5]
[6,5,4,3,2,4,65,6,7,8,7,6,5,4,3,6,7,8,9,8,7,6,5,3,12,4,5,8,98,7,6,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. We use arr[i]<=arr[i+1] to determine Merge conditions, if we do a merge on i,i-1 indices, their total might be>arr[i+1],
// where originally i+1's value >i, so we greedily do merge oper. from the right so that i+1 index in the comparisons would have the greatest possible value
// increasing their prob of satisfying the condition for more number of indices. If condition is satisfied we store the sum in temp arr, we move to 'i-1'
// index, if that index doesn't satisfy condition, we try to maximize the merge oper. total stored in temp var and assign curr. index's val to temp and move to 
// 'i-1' index. We also maximize res at the end of iter with temp value as it might have gathered total of merge oper. for the last seq. of merge oper and
// return res.







class Solution {
public:
    long long maxArrayValue(vector<int>& v) {
        long long int res=v[0], temp=v.back();
        for(int i=v.size()-1;i>0;i--) {										// Iter. from back to front greedily to have greater 'i' index's value.
            if(temp>=v[i-1]) temp+=v[i-1];									// If condition satisfied, we add 'i-1' index's value to temp.
            else {
                if(temp>res) res=temp;										// We maximize res by temp value(sum of Merge oper. ending at curr. index).
                temp=v[i-1];												// Resetting temp value for next seq. of Merge oper.
            }
        }
        if(temp>res) res=temp;												// Maximizing res by sum of last seq. of Merge oper.(temp var)
        return res;															// Returning largest val after Merge oper.
    }
};

