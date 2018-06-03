/*
*
//**********************************************************398. Random Pick Index.***************************************************

Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target 
number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


// No test cases worked on.



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is RESERVOIR SAMPLING based. We choose a curr. encountered value with prob. 1/(n+1) and retain the prev. chosen value with prob.
// n/(n+1), thus making sure everyone gets chosen with equal prob.








class Solution {
public:
    vector<int> v;
    Solution(vector<int> nums) {											// Initializing an array.
        v=nums;
    }
    
    int pick(int target) {													
        int len=0, ind=-1;													// Num. of occurances of target value/index of curr. return. value.
        for(int i=0;i<v.size();i++){
            if(v[i]!=target) continue;										
            if(len==0){ len++; ind=i;}										// If first time encount., store that index.
            else{															// If not choose the curr. encount. index with prob. 1/(n+1), reatin 
                len++;														// the prev. chosen value with prob. n/(n+1).
                if(rand()%len==0)
                    ind=i;													// Update the result index.
            }
        }
        return ind;															// Returning the result index.
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */