/*
*
//*******************************************2212. Maximum Points in an Archery Competition.********************************************

https://leetcode.com/problems/maximum-points-in-an-archery-competition/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


9
[1,1,0,1,0,0,2,1,0,1,2,0]
3
[0,0,1,0,0,0,0,0,0,0,0,2]
148
[1,29,10,2,10,0,0,30,4,50,10,2]


// Solution 3 has best Time Complexity and slightly suboptimal Space Complexity.
// Time Complexity: O(2^m).													//m-range of scoring sections.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n-#arrows, m-#scoring sections.
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, as there are many combinations of arrows to get best score, we use DP. As we don't want to get duplicate combinations of 
// scoring sections in final result, we iter. over scoring sections in sequence and for each of it, we iter. from top to bottom arrow values. When we are at 'i', we check if 
// we have enough arrows to win this section, if yes we add curr. section's score to score of 'i-curr. arrows' index's score and try to maximize the score at this #arrows. Also
// at every step, we try to maximize and track the best score and it's corresponding rep of indices. After the entire process, we iter. over 'rep' and update set indices #arrows
// to alice's arrows+1 in res array and add remaining arrows to zero index and return the res array.


// dp[i]={rep, score}, it stores rep of scoring sections/indices bob won, score he got after winning those sections.
// Generally DP is preferred in these type of problems but here since the range of scoring sections is really small, exploring all combinations of sections would be less run time 
// intensive.







class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& alice) {
        vector<int>res(alice.size(),0);
        // This approach allows to get a combination to win on alice but it won't give us the maximum possible points bob can win.
        // int i=0,j=alice.size()-1;
        // while(i<j) {
        //     while(i<j && res[i]==0) i++;
        //     // if(i==j) break;
        //     res[j]++;
        //     j--;
        //     res[i]--;
        // }
        // return res; 
        
        
        vector<pair<int,int>>dp(numArrows+1, {0,0});
        int rep=0, maxScore=0;
        for(int i=0;i<12;i++) {												// Iter. over scoring sections in sequence.
            int cost=alice[i]+1;
            for(int j=numArrows;j>=cost;j--) {								// Iter. over entire range of available arrows.
                if(dp[j-cost].second+i>dp[j].second) {						// If prev. score+curr. score>curr. rep maxScore, we update curr. rep maxScore and it's rep.
                    dp[j].second=dp[j-cost].second+i;	
                    dp[j].first=((dp[j-cost].first) | (1<<i));
                    if(dp[j].second>maxScore) {								// If score>maxScore, we update maxScore and it's rep.
                        maxScore=dp[j].second;
                        rep=dp[j].first;
                    }
                }
            }
        }
        int ind=0, total=0;
        while(rep) {														// We fill the res array based on the rep.
            if((rep&1)!=0) numArrows-=res[ind]=alice[ind]+1;				// If curr. index is used, we assign alice[i]+1 arrows to curr. index for us to win.
            rep>>=1;
            ind++;															// Moving to next index.
        }
        if(numArrows!=0) res.back()+=numArrows;								// Assigning the remaining arrows to zero index.
        return res;															// Returning the res array with #arrows used in each section, which gives maxScore.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*2^m).												//m-range of scoring sections.
// Space Complexity: O(1).	
// This algorithm is Brute Force based. We explore all possible combination of winning sections, for each section we calc. #arrows required and score attained, if score>maxScore,
// we track the rep and the maxScore. After entire iteration, we iter. over rep and update res array as explained above.







class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& alice) {
        vector<int>res(alice.size(),0);
        int cap=(1<<12), maxScore=0, rep=0;
        for(int curr=0;curr<cap;curr++) {									// Iter. over all combinations of winning sections.
            int remArrows=numArrows, score=0;
            for(int i=0;remArrows>0 && i<12;i++) {							// Calc. score and assigning arrows for this combination of sections.
                if((curr&(1<<i))!=0) {
                    remArrows-=(alice[i]+1);
                    score+=i;
                }
            }
            if(remArrows>=0 && score>maxScore) {							// If curr. score>maxScore, we track maxScore and it's rep.
                maxScore=score;
                rep=curr;
            }
        }
        int ind=0, currArrows=0;
        while(rep>0) {														// We fill the res array based on the rep.
            if((rep&1)!=0) currArrows+=res[ind]=alice[ind]+1;
            rep>>=1;
            ind++;
        }
        res[0]+=(numArrows-currArrows);
        return res;															// Returning the res array with #arrows used in each section, which gives maxScore.
    }
};











//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^m).													//m-range of scoring sections.
// Space Complexity: O(m).	
// This algorithm is Brute Force+DFS based. This approach is same as above, instead of creating all combinations in for loops, we use DFS to create all such combinations, 
// track maxScore and it's corresponding rep. Later build res array based on rep as explained above and return it.








class Solution {
public:
    
    void getBestScore(int index, int currScore, int currRep, vector<int>&alice, int& rep, int& maxScore, int remArrows) {
        if(currScore>maxScore) {											// If curr. score>maxScore, we track maxScore and it's rep.
            maxScore=currScore;
            rep=currRep;
        }
        if(index>=alice.size()) return ;									// If no indices left to explore, we stop the DFS.
        
        if(remArrows>=alice[index]+1) getBestScore(index+1, currScore+index, (currRep|(1<<index)), alice, rep, maxScore, remArrows-alice[index]-1);// We win curr. section/index.
        getBestScore(index+1, currScore, currRep, alice, rep, maxScore, remArrows);// We skip this section and move to next section.
        return ;
    }
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& alice) {
        vector<int>res(alice.size(),0);
        int rep=0, maxScore=0, ind=0;
        getBestScore(0, 0, 0, alice, rep, maxScore, numArrows);				// DFS call to find the combination that gives the best score.
        while(rep>0) {														// We fill the res array based on the rep.
            if((rep&1)!=0) numArrows-=res[ind]=alice[ind]+1;
            rep>>=1;
            ind++;
        }
        res[0]+=numArrows;
        return res;															// Returning the res array with #arrows used in each section, which gives maxScore.
    }
};

