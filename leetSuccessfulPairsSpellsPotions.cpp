/*
*
//********************************************2300. Successful Pairs of Spells and Potions.**********************************************

https://leetcode.com/problems/successful-pairs-of-spells-and-potions/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,1,3]
[1,2,3,4,5]
7
[3,1,2]
[8,5,8]
16



// Time Complexity: O(m*logm+n*logm).										//n-#Spells, m-#potions.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*logm+n*logm).										//n-#Spells, m-#potions.
// Space Complexity: O(1).	
// This algorithm is Sorting+Binary Search based. As, we are trying to get #potions that pairs with a spell and meets the condition, we observe that there 
// is a monotonic nature in the potions that meet the condition-> if a potion value can pair with a spell and meet condition, then all potion vals greater than
// this potion value would also meet condition. So, we can use Binary Search to find least valued potion that meets the condition and get count of rem. potions
// and update res array, we repeat the same process for all spells and update res accordingly and return res at the end of iter.







class Solution {
public:
    
    int findSmallestPotionIndex(vector<int>&v, long long int target) {		// Binary Search to find least valued potion that meets the condition.
        if(v.back()<target) return v.size();
        int low=0, high=v.size()-1;
        while(low<high) {
            int mid=(low+high)/2;
            if(v[mid]<target) low=mid+1;
            else high=mid;
        }
        return low;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int>res(spells.size(),0);									// Sorting the potions in inc. order.
        for(int i=0;i<spells.size();i++) {									// Iter. over all spells.
            long long int least=(success+spells[i]-1)/spells[i];
            // int index=lower_bound(potions.begin(), potions.end(), least)-potions.begin();
            int index=findSmallestPotionIndex(potions, least);				// Binary Search to find least valued potion meeting condition.
            res[i]=potions.size()-index;									// Updating res array with potions count.
        }
        return res;															// Returning array with potions count that meets the condition for every spell.
    }
};

