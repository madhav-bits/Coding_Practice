/*
*
//**********************************************************268. Missing Number.***************************************************

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,1]
[1,2]
[5,0,2,1,4]
[]
[0]
[1]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based and whole idea is that it places num-"i" in the index "i-1", so at the end in the iteration we check for zero
// The index which contains zero, represents the missing number(index+1), if zero is missing, we can't find the zero in the array, and zero by
// default is the answer. In the first iteration, we check the iterator-index has num(index+1) or not, if not we swap it with the proper index of
// the number in iterator index. We swap in a loop, until we get proper value/0 into curr. index. 



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==1 && nums[0]==1) return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i+1 || nums[i]==0 ) continue;
            while(nums[i]!=i+1 && nums[i]!=0){										// Swapping in loop, until this index gets proper value/zero.
                //cout<<"INdices: "<<i<<" and: "<<nums[i]-1<<" with values: "<<nums[i]<<" and: "<<nums[nums[i]-1]<<endl;
                swap(nums[i], nums[nums[i]-1]);										// Placing curr. value in it's proper place.
            }
        }
        
        int val=0;																	// zero is answer by default.
        for(int i=0;i<nums.size();i++){												// We check for index with zero value.
            //cout<<"Value at index: "<<i<<" is: "<<nums[i]<<endl;
            if(nums[i]==0) val=i+1;													// Then that corres. number is missing.
        }
        return val;																	// Return the missing number.
    }
};




//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. As it's said that we expect a series of nums from 0 to n. We know the expected sum based on the lenght of the
// array. We subtract the sum of array elem. from expected sum to get the missing number.


class Solution {
public:
    int missingNumber(vector<int>& v) {
        int len=v.size(), sum=0;													// Get length of the array.
        for(int i=0;i<v.size();i++){												// Calc. the sum of elem. in the array.
            sum+=v[i];
        }
        return (len*(len+1)/2)-sum;													// Expected Sum-obtained sum gives missing number.
    }
};