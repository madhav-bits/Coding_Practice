/*
*
//**************************************************309. Best Time to Buy and Sell Stock with Cooldown.*******************************************

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an 
increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,6,6,7,7]
[]
[1,1,1,1]
[1,1,1,1,2,2,2,3,3]
[1,1,1,1,2,2,2,3,3,4,4,4,4,5,6]
[1,2,3,4,5,6,7,7,7,7,7,7,7,7,8,8,7,8,9,10,1,1,1,1,1]

[1,2,3,0,1]
[1,1,2,2,3,0,0,1,2,3]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates through the array maintains three states- Hold, Sold, Rest.
// REST- State following the selling the stock, continuing to rest.
// HOLD- Maintaining the purchased stocks or purchase a new stock.
// SELL- Sell the stock we currently have(HOLD).

//*****************************************************************************************************************************************
// In detail explanation for this algorithm can be found in the disucssions forum section of this question.



class Solution {
public:
    int maxProfit(vector<int>& v) {
        
        int  rest=0, sold=0, hold=INT_MIN;
        for(int i=0;i<v.size();i++){
            int prevRest=rest;
            rest=max(rest, sold);										// Can have prev rest value or prev sold value.
            sold=hold+v[i];												// Need to sell stock form hold stocks.
            hold= max(hold, prevRest-v[i]);                         	// Can have prev hold value, or purchase following rest.
        }
        
        return max(sold,rest);											// Returning the max. of sold or rest state.
    }
};




//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the prices, chooses which maxm price to be chosen to sell based on the prices following the max. price. This algo.
// has passed 192/211 test cases.



class Solution {
public:
    int maxProfit(vector<int>& v) {
        int minm=INT_MAX;
        int maxm=INT_MIN;
        int prof=0;
        for(int i=0;i<v.size();i++){
            
            while(i<v.size() && v[i]<minm){                                 // Finding the stock to purchase.
                minm=v[i];
                i++;
            }
            if(i==v.size()) break;
            maxm=v[i-1];
            while(i<v.size() && v[i]>maxm){									// Finding the price to sell the stock.
                maxm=v[i];
                i++;
            }
            if(i==v.size()){												// If end of days is reached, then just sell the stock and return.
                cout<<"Added to final prof: "<<prof<<" with maxm. is: "<<maxm<<" and minm is: "<<minm<<endl;
                prof+=maxm-minm;
                return prof;
            }
            else{
                if(i+1<v.size() && v[i+1]-v[i]>(maxm-v[i-2])){              // Selling moving a step back.
                    maxm=v[i-2];
                    cout<<"Added to prof: "<<prof<<" with maxm. is: "<<maxm<<" and minm is: "<<minm<<endl;
                    prof+=(maxm-minm);
                    
                }
                minm=v[i];
            }
        }
        cout<<"The result is: "<<prof<<endl;
        return prof;														// Returning the overall profit.
    }
};