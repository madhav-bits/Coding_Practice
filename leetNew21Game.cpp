/*
*
//******************************************************837. New 21 Game.***********************************************

Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points, and draws numbers while she has less than K points.  During each draw, she gains an integer number of points randomly 
from the range [1, W], where W is an integer.  Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets K or more points.  What is the probability that she has N or less points?

Example 1:

Input: N = 10, K = 1, W = 10
Output: 1.00000
Explanation:  Alice gets a single card, then stops.
Example 2:

Input: N = 6, K = 1, W = 10
Output: 0.60000
Explanation:  Alice gets a single card, then stops.
In 6 out of W = 10 possibilities, she is at or below N = 6 points.
Example 3:

Input: N = 21, K = 17, W = 10
Output: 0.73278
Note:

0 <= K <= N <= 10000
1 <= W <= 10000
Answers will be accepted as correct if they are within 10^-5 of the correct answer.
The judging time limit has been reduced for this question.


//****************************************************************************************************************************************
//****************************************************************************************************************************************
//**************************************************THIS QUESTION HAS STRICT TIMING CONSTRAINTS.******************************************
//****************************************************************************************************************************************
//****************************************************************************************************************************************


*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



19
15
7



7036
5379
3412




5222
4771
8583




7687
6402
3302






// Time Complexity: O(dest+wind).  
// Space Complexity: O(dest+wind).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((dest+wind)*wind).
// Space Complexity: O(dest+wind).	
// This algorithm is Dynamic Programming based.  This is Bottom to Top approach. Where, we start from 0 towards reaching num. b/w dest and target.
// dp[i] represents the prob. of getting req. range nums. if we start picking from "i+1"("i" had been already picked).
// If the new number's prob. of achieving isn't calculated, then we calc. it first by doing recursive calls. IF the curr. num is in the given 
// range of vals, then we return 1. Thus,at the end of iter. we return the prob. of reaching target values, if we start selecting from 1.









class Solution {
public:
    // double overall=0;
    double findProb(int curr, int &target, int &dest, int &wind, double currProb, vector<double>&dp){
        //cout<<"Inside the findProb with curr: "<<curr<<"and currProb: "<<currProb<<endl;
        // cout<<"Inside the fn. with curr: "<<curr<<endl;
        // if(curr>target) return 1.0;
        double pro=1/double(wind);											// Calc. prob. value for each iter.
        if(dp[curr]!=-1){													// If prob. values are already calc.
            // cout<<"Dp value pres. and returning."<<endl;
            return dp[curr];												// Return the value.
        }
        
        double probSum=0;													// Tracks total prob. for curr. num to reach target range values.
        for(int i=1;i<=wind;i++){											// Iter. through the window.
            // cout<<"Curr. index i: "<<i<<endl;
            if(curr+i>target) break;										// If sum is >target, then break loop.
            double res=findProb(curr+i,target,dest,wind,currProb*pro,dp);  	// Give recur. call to calc. prob. to reach target range vals.
            // double temp=(res)*pro;//(res+currProb)*pro;
            // cout<<"res: "<<res<<" and temp: "<<temp<<endl;
            probSum+=res*pro;												// Add the returned probs.
        }
        // cout<<"Accumulated probSum for curr: "<<curr<<" is: "<<probSum<<endl;
        dp[curr]=probSum;													// Assigning the sum to curr. val index in dp array.
        return dp[curr];													// Returning the curr. val's prob.
    }
    
    
    double new21Game(int target, int dest, int wind) {
        vector<double>dp(target+1,-1);
        for(int i=dest;i<=target;i++) dp[i]=1;								// Base values.
        if(0>=dest && 0<=target) return 1;									// Base cdns.
        double st=1;
        return findProb(0,target,dest,wind, st,dp);							// Calling fn. to calc. prob.
        //cout<<"Final prob is: "<<overall<<endl;
        // for(auto num:dp) cout<<"num: "<<num<<endl;
        // return dp[0];													// This would also work fine.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((dest+wind)*wind).
// Space Complexity: O(dest+wind).		
// This algorithm is Dynamic Programming based. This is Top to bottom approach. We start from dest-1, calc. the prob. of reaching target range
// vals. where "dest-1" had been already collected. This way, we move in the reverse drn calc. prob. for all values. At the end, we return 
// prob. to get target range, if we start from 0.





class Solution {
public:
    
    double new21Game(int target, int dest, int wind) {
        vector<double>dp(target+1,-1);										// Declaring a dp array of len. target+1.
        for(int i=dest;i<=target;i++) dp[i]=1;								// Setting the base values.
        if(0>=dest && 0<=target) return 1;									// Base cdns.
        double pro=1/double(wind);											// Calc. the prob. for each iter.
        for(int i=dest-1;i>=0;i--){											// Iter. over all possible values in reverse drn.
            // cout<<"Curr. index: "<<i<<endl;
            double probSum=0;												// Add returned prob. values from next step's vals.
            for(int j=1;j<=wind;j++){										// Iter. over window.
                if(i+j>target) break;										// If next val>target break from loop.
                probSum+=(dp[i+j]*pro);										// Add the returned probs.
            }
            // cout<<"probsum: "<<probSum<<" for i: "<<i<<endl;
            dp[i]=probSum;													// Assign the sum to curr. value index in dp array.
        }
        return dp[0];														// Return the prob. of getting target range, if started from 0.
    }				
};










//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(dest+wind).
// Space Complexity: O(dest+wind).		
// This algorithm is Dynamic Programming based. This algo. is Bottom to Top approach. This algo. is optimization of above algo.. As in the 
// above one, each index value depends on prev. window of values.So, we maintain the sum of prob. of getting target range from 0 to "i" in index
// "i",we do dp[i-1]-dp[i-wind-1] to get the sum of all those prob. values on which curr. index "i" depends on. At the end of iter. return the
// sum of prob. of getting target range vals.
// dp[i] indicates prob. to reach "1" to "i", if started picking from 0.




class Solution {
public:
    
    double new21Game(int target, int dest, int wind) {
        if(dest==0) return 1;												// Base cdn.
        int maxm=dest+wind-1;												// Maxm. vals we are calculating.
        vector<double>dp(maxm+1);											// Init. an array of size maxm+1.
        dp[0]=1;															// Base value(As we already have 0 sum with us prior any picking).
        for(int i=1;i<=maxm;i++){											// Iter. over range of values.
            dp[i]=dp[i-1];													// As, curr. index also includes sum of all previous probs.
            if(i<=wind){													// If curr. index is <window size.
                dp[i]+=dp[i-1]/wind;										// All previous vals. can contribute to curr. index.
            }
            else{															// If curr. index>window size.
                dp[i]+=(dp[i-1]-dp[i-wind-1])/wind;							// All prev. window vals. can contribute.
            }
            if(i>dest){														// If curr. index>dest.
                dp[i]-=(dp[i-1]-dp[dest-1])/wind;							// Prev. windows vals.>dest can't contribute(As we stop picking.)
            }
        }
        
        return dp[target]-dp[dest-1];										// Return the sum. of prob. of getting target range vals.
    }
};