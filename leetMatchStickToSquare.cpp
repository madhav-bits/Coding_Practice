/*
*
//******************************************************473. Matchsticks to Square.***********************************************

Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you 
can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must 
be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to 
represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,1,2]
[3,4,5,3,3,3,3]
[34,2,5,6,7,6,6,4,3,7,9,7,5,2,6,8,3,7,8,5,4,4]


// Time Complexity: O(4^n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(4^n!).	
// Space Complexity: O(1).	
// This algorithm iterates the array, at each stage takes an value into one of the 4 subsets and goes ahead to choose from the following values,
// If once the length is reached, we return, as all the values are pushed into 4 subsets, without exceeding sum/4 value.

// I MADE A SMALL MISTAKE of pushing far ahead index's values into any of 4 subsets, instead of thinking of curr. index only. That's why Time
// Limit Exceeded error occured.



class Solution {
public:
    bool findCombi(vector<int>v,vector<int>u,int index, int sum){
        if(index==v.size()){
            //if(u[0]==u[1] && u[1] == u[2] && u[2]==sum/4) return true;
            return true;
        }
        int i=index;
            bool res=false;
            for(int j=0;j<4;j++){									// Considering to push the curr. value into any of 4 subsets.
                if(v[i]+u[j]<=sum/4){								// The subset value shouldn't exceed sum/4 value.
                    u[j]+=v[i];
                    res=findCombi(v,u,i+1,sum);
                    u[j]-=v[i];
                }
                if(res) return res;									// Once we that, square can be formed, aborting furthur calls.
            }
        return false;												// If no answer found, after all these iterations, then return false.
    }
    
    bool makesquare(vector<int>& v) {
        if(v.size()<4) return false;								// If elem.<4, sqaure can't be formed.
        int sum=0;
        for(auto num:v) sum+=num;
        if(sum%4!=0) return false;									// If sum of lengths can't be divided into 4 groups, return false.
        vector<int>u(4,0);
        sort(v.rbegin(), v.rend());									// Reverse sorted, to hit if any sum/4 exceeding cases faster.
        return findCombi(v,u,0,sum);								// Return the result from the function call.
    }
};