/*
*
//******************************************************2233. Maximum Product After K Increments.******************************************************

https://leetcode.com/problems/maximum-product-after-k-increments/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,4]
5
[6,3,3,2]
2
[5,4,6,3,2,5,4,2,8,6,5,6,12,14,15,23,24,36,31,59,43,47]
35



// Time Complexity: O(n+klogn).																			// k-#incrementing operations, n-#nums provided.				
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+klogn).																			// k-#incrementing operations, n-#nums provided.								
// Space Complexity: O(n).	
// This algorithm is Greedy+Priority Queue based. Here, we have to increase the value of the least value in every step for maximum increase in product. So, we push all the nums into PQ, we pop least value every time, inc 
// it's value by 1, if the next least value is lot greater than curr. least value,we try to increase the curr. value as much as we can(within allowed #operations) and we push num into PQ. After K operations, we calc. prod. 
// of all nums and return the product.







class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0]+k;
        int res=1, mod=1000000007;
        priority_queue<int, vector<int>, greater<int>>pq;												// Defining Min PQ.
        for(int&num:nums) {																				// Pushing all nums into PQ.
            pq.push(num);
        }
        while(k) {																						// Does K Operations.
            int val=pq.top()+1;																			// Inc. the value of least valued num by 1.
            k--;
            pq.pop();
            while(k && val<pq.top()) {																	// We avoid multiple push, pop on same num by this optimization step.
                k--;																					// If curr. value is still<next least value, we inc. the curr. value by using possible #operations.
                val++;
            }
            pq.push(val);																				// Push the updated value into PQ.
        }
        
        while(!pq.empty()) {																			// Calc. prod of all nums.
            res=(1ll*res*pq.top())%mod;
            pq.pop();
        }
        return res;																						// Returning the prod. of all nums.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+k+n).																		// k-#incrementing operations, n-#nums provided.								
// Space Complexity: O(1).	
// This algorithm is Greedy+Sotring based. Since we have to increase the least valued numbers at every step, to get the max product after the operations, we sort the numbers, we increse the least values first, if they become
// >it's adjacent value, we increse the adjacent value next, if the adjacent value still isn't >it's adjacent after increment, we go back to first index and increase it's value and repeat the process. This is basically 
// cautiously inreasing the value of least values at every step and ensuring we increase the value of all duplicates of least value before moving/incrementing further.


// This algorithm is from the Submissions Tab(Picked from one of the lowest Time Complexity submissions in the graph.).




class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0]+k;
        
        int res=1, mod=1000000007, ind=0;
        sort(nums.begin(), nums.end());
        while(k) {																						// Performing K operations.
            k--;
            nums[ind]++;																				// Inc. the curr. index(least value) by 1.
            if(ind<nums.size()-1 && nums[ind]>nums[ind+1]) ind++;										// If the curr. value>it's adjacent(greater index) value, we move to right to increase the adjacent value by 1.
            else ind=0;																					// If the value is still <it's adjacent, that means all left values are also<it's adjacent, so we go ind-'0' and inc by 1.
        }
        for(int&num:nums) {																				// Calc. prod of all nums and returning it.
            res=(1ll*res*num)%mod;
        }
        return res;																						// Returning the prod of all nums.
    }
};

