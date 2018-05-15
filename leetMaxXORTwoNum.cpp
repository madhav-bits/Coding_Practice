/*
*
//****************************************************421. Maximum XOR of Two Numbers in an Array.*********************************************

Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.






// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Trie Based(Since O(n) is required). We classify the given ints into two parts(with 0/1 in the curr. scanning bit). If 
// those parts contain 0/1s in the next significant bit, then we get 1 if we do XOR. This way we reach recursively to the end. Extracing max.
// possible value at each stage using nums from both the parts.

// Far more clear explanation is given in the one of the description posts.



class Solution {
public:
    
    
    int calcXor(vector<int>& nums, int oneStart, int oneEnd, int zeroStart, int zeroEnd, int val, int shift) {
        if (shift == -1) return val;
        int mask = 1<<shift, j = oneStart, k = zeroStart;
        for (int i = oneStart; i <= oneEnd; i++) 
            if (nums[i]&mask) swap(nums[i], nums[j++]);
        for (int i = zeroStart; i <= zeroEnd; i++) 
            if (nums[i]&mask) swap(nums[i], nums[k++]);
        if (j > oneStart && j <= oneEnd) {
            int ans = 0;
            if (k > zeroStart) 
                ans = calcXor(nums, j, oneEnd, zeroStart, k-1, val*2+1, shift-1);
            if (k <= zeroEnd) 
                ans = max(ans, calcXor(nums, oneStart, j-1, k, zeroEnd, val*2+1, shift-1));
            return ans;
        }
        else if (j <= oneStart) {
            if (k > zeroStart) 
                return calcXor(nums, oneStart, oneEnd, zeroStart, k-1, val*2+1, shift-1);
            else 
                return calcXor(nums, oneStart, oneEnd, zeroStart, zeroEnd, val*2, shift-1);
        }
        else {
            if (k <= zeroEnd) 
                return calcXor(nums, oneStart, oneEnd, k, zeroEnd, val*2+1, shift-1);
            else 
                return calcXor(nums, oneStart, oneEnd, zeroStart, zeroEnd, val*2, shift-1);
        }
    }
    
    
    int findMaximumXOR(vector<int>& nums) {
        
        int n = nums.size();
        return calcXor(nums, 0, n-1, 0, n-1, 0, 30);
    }
};