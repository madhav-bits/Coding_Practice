/*
*
//*****************************************2164. Sort Even and Odd Indices Independently.***************************************

https://leetcode.com/problems/sort-even-and-odd-indices-independently/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,1,2,3]
[2,1]
[5,6,5,4,7,6,5,6,6,5,7,7,8,7,7,6,5,34,3,87,6,7,5,4,3,45,65,7,7,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Map based. Since the range of nums is smaller we use an array/map to track #occur. of each num and iterate it from back/front based on 
// requirement and fill the indices of the array and return it.







class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>evenOccur(101, 0), oddOccur(101, 0);
        for(int i=0;i<nums.size();i++) {
            if(i%2==0) evenOccur[nums[i]]++;								// Even index's nums are stored in evenOccur array.
            else oddOccur[nums[i]]++;										// Odd index's nums are stored in oddOccur array.
        }
        int j=0,k=100;
        for(int i=0;i<nums.size();i++) {
            if(i%2==0) {													// Filling even indices in Non-Dec. order.
                while(j<=100 && evenOccur[j]==0) j++;						// Skipping nums whose #occur. is zero.
                nums[i]=j;													// Updating the index with sorted num.
                evenOccur[j]--;
            } else {														// Filling odd indices in Non-Inc. order.
                while(k>=0 && oddOccur[k]==0) k--;
                nums[i]=k;
                oddOccur[k]--;
            }
        }
        return nums;														// Returning the array after sorting it as per the requirement.
    }
};

