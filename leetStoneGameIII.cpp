/*
*
//*******************************************************1406. Stone Game III.***************************************************

https://leetcode.com/problems/stone-game-iii/description/


Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated 
value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2 or 3 stones from the first 
remaining stones in the row.

The score of each player is the sum of values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a 
tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win or "Tie" if they end the game with the same score.

 

Example 1:

Input: values = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and 
Bob wins.
Example 2:

Input: values = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. The next move Alice will take the pile with 
value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. The next move Alice will take the pile with 
value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.
Example 3:

Input: values = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise 
she will lose.
Example 4:

Input: values = [1,2,3,-1,-2,-3,7]
Output: "Alice"
Example 5:

Input: values = [-1,-2,-3]
Output: "Tie"
 

Constraints:

1 <= values.length <= 50000
-1000 <= values[i] <= 1000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.



[1,2,3,7]
[1,2,3,-9]
[1,2,3,6]
[1,2,3,-1,-2,-3,7]
[-1,-2,-3]



// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(n).	
// This algorithm is Dynamic Programing based. Here, at every step a player takes sufficient indices to make sure that he gets maxm.
// total at the end of the game. While being at an index, we get sum from three possible moves, we also calc. total from the rest of 
// the moves by(cumu[index+dx+1]-dp[index+dx+1]), dp gives best total by other player starting from next index, we can get curr. player's
// total from subtr. dp value from cumu. sum of indices to the right. We take the maxm. total possible from three moves and assign to 
// curr. move/index. At the end of iter., we see maxm. total of Alice(dp[0]), we also calc. Bob's (total-dp[0]), we return decision based
// on the comparision.


// This is Top to Bottom/ Recursive Approach.





class Solution {
public:
    
    void findMaxTotal(vector<int>&v, vector<int>&dp, vector<int>&cumu, int index){
        if(index==v.size() || dp[index]!=-1) return ;						// If out of bound, if index is already visited return val.
        int maxm=INT_MIN, curr=0;											// Tracks maxm. total starting curr. index.
        for(int dx=0;dx<3;dx++){											// Iter. for three moves.
            curr+=v[index+dx];
            if(index+dx+1==v.size()){										// If we are at last index.
                if(curr>maxm) maxm=curr;									// Update maxm. var.
                break;    
            } 
            findMaxTotal(v, dp, cumu, index+dx+1);							// Give recursive call for next index.
            if(curr+cumu[index+dx+1]-dp[index+dx+1]>maxm) maxm=curr+cumu[index+dx+1]-dp[index+dx+1];// Updating maxm. var.
        }
        // maxm=max(maxm, curr);
        dp[index]=maxm;														// Assigning maxm. var to curr. dp index.
        return ;
    }
    
    string stoneGameIII(vector<int>& v) {
        vector<int>dp(v.size(),-1);											// Stores best total of a player starting index 'i'.
        vector<int>cumu(v.size(),0);										// Stores cumu. sum of values from the right.
        int total=0;
        for(int i=v.size()-1;i>=0;i--){										// Iter. over array to collect cumu. sum.
            total+=v[i];
            cumu[i]=total;
        }
        findMaxTotal(v,dp,cumu, 0);											// Call to init. DP calc.
        // for(int i=0;i<v.size();i++)
        //     cout<<dp[i]<<endl;
        int rem=total-dp[0];												// Total of Bob.
        if(dp[0]>rem) return "Alice";										// If Alice has more than Bob.
        else if(dp[0]==rem) return "Tie";
        else return "Bob";
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(n).	
// This algorithm is same as the above one. But, it is Bottom-Top Approach or iterative one.



class Solution {
public:
    
    string stoneGameIII(vector<int>& v) {
        vector<int>dp(v.size(),-1);
        vector<int>cumu(v.size(),0);
        int total=0;
        for(int i=v.size()-1;i>=0;i--){
            total+=v[i];
            cumu[i]=total;
        }
        
        // for(int i=0;i<v.size();i++)
        //     cout<<dp[i]<<endl;
        for(int i=v.size()-1;i>=0;i--){
            int sum=0, maxm=INT_MIN;
            for(int dx=0;dx<3;dx++){
                sum+=v[i+dx];
                if((i+dx+1)==(int)v.size()){
                    if(sum>maxm) maxm=sum;
                    break;
                }
                if(sum+cumu[i+dx+1]-dp[i+dx+1]>maxm) maxm=sum+cumu[i+dx+1]-dp[i+dx+1];
            }
            dp[i]=maxm;
        }
        int rem=total-dp[0];
        if(dp[0]>rem) return "Alice";
        else if(dp[0]==rem) return "Tie";
        else return "Bob";
    }
};



/*

[1,2,3,7]
[1,2,3,-9]
[1,2,3,6]
[1,2,3,-1,-2,-3,7]
[-1,-2,-3]



*/