/*
*
//************************************1475. Final Prices With a Special Discount in a Shop.*************************************

https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/


Given the array prices where prices[i] is the price of the ith item in a shop. There is a special discount for items in the shop, if 
you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and 
prices[j] <= prices[i], otherwise, you will not receive any discount at all.

Return an array where the ith element is the final price you will pay for the ith item of the shop considering the special discount.

 

Example 1:

Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation: 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4. 
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2. 
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4. 
For items 3 and 4 you will not receive any discount at all.
Example 2:

Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.
Example 3:

Input: prices = [10,1,1,6]
Output: [9,0,1,6]
 

Constraints:

1 <= prices.length <= 500
1 <= prices[i] <= 10^3




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

[1,4,6,9,12,16]


[9,7,5,3,2,1]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. Here, at every step we remove all entries in stack which are greater than curr.val, thus we get first 
// index with lesser value than curr. index. We calc. diff. and update the res array, if the stack if empty, then there is no discount 
// for that index.







class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        vector<int>res(v.size(),0);											// Stores final prices of each index.
        stack<int>st;														// Stores indices with lesser price than curr. index's price.
        for(int i=v.size()-1;i>=0;i--){										// Iter. over all indices.
            while(!st.empty() && v[i]<v[st.top()]) st.pop();				// Removing prices with greater values then curr. price.
            int val=v[i];
            if(!st.empty()) val-=v[st.top()];								// Dec. the discount price.
            res[i]=val;														// Pushing the final price into array.
            st.push(i);														// Push curr. index into stack.
        }
        return res;															// Return the arr. with final prices.
    }
};