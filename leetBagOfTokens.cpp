/*
*
//******************************************************948. Bag of Tokens.******************************************************

https://leetcode.com/problems/bag-of-tokens/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[100]
50
[100,200,300,400]
200
[1,2,2,2,2,2,2,3,3,3,3,3]
2
[]
85



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Greedy based. We sort the given array of token values. We use the given power greedily by playing least valued tokens first in inc. order
// and inc. score by 1 for each token played. If curr. power<token value, we use 1 score value and play against highest valued non-played token and inc. 
// power by token value, as we are going from highest to lowest non-played token values at any instant we are getting max. power in exchange of 1 score lost.
// Now, we once again use this renewed power to play against non-played least valued tokens thus in every step we ensure to loose least possible power and 
// gain highest power for every score we sacrifice, thus ensuring our collected score would be maxm. 
// One corner case is where we try to play against a token, but because of low power we go and exchange a score for power but that's the last index in the 
// array to be played, so we dec. score by 1 while we are not able to use the power, so we only play the last token if we are going to gain score by it.
// If rem. indices are non-zero if we sacrifice a score for power we certainly get atleast 1 score with the newly gained power as we will play against lower 
// valued tokens where there would be atleast 1 rem. lower valued token left, so we aren't dec. the score as a whole and affect final result.







class Solution {
public:
    int bagOfTokensScore(vector<int>& v, int power) {
        // Max Score.
        // Loose token[i] power gain 1 score
        // Gain token[i] power loose 1 score
        if(v.size()==0) return 0;
        sort(v.begin(), v.end());
        if(power<v[0]) return 0;
        int score=0, i=0, j=v.size()-1;
        while(i<j) {
            if(v[i]<=power) {												// If we have enough power, we play curr. token and inc. score by 1.
                score++;
                power-=v[i++];												// Dec. the power and inc. score.
            } else if(score>0) {											// In case of insufficient power, we lost 1 score for max possible power gain.
                score--;
                power+=v[j--];												// Inc. power and dec score by 1.
            } else break;													// If both conditions not met, we can't play with any rem. token to inc. score.
        }
        if(v[i]<=power) score++;											// If last rem. token's power<=curr. power we inc. score by 1.
        return score;														// Returning max. possible score we can get.
    }
};

