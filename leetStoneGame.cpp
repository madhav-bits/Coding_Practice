/*
*
//************************************************************877. Stone Game.****************************************************

Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number 
of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of 
the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

 

Example 1:

Input: [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
 

Note:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles) is odd.
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,3,4,5]

[3,4,5,3,5,8,9,3]

[1,2]



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).
// Space Complexity: O(n).	
// This algorithm iterates the array, this is sort of brute force sln. I had summed the values from the start, rather starting from the back. 
// As a result, the sum accumulated at various scenarios leading to 2^n scenarios. I had got TLE for this code.


//******************************************************************************************************************************************
//******************************************************************************************************************************************
//******************************************************************************************************************************************
//********************************************************DYNAMIC PROGRAMMING OBSERVATIONS.*************************************************
// Whenever questions with multiple options to choose from occurs. Try to look for states/ which lead to same value, when approached from various 
// possible scenarios.So, that we can cache them, and reuse them when approached the same state from other scenario/selections made. 
// Try to approach the problem from either from start to end/end to start.
// So, that Dynamic Programming can be applied there.
//******************************************************************************************************************************************
//******************************************************************************************************************************************



class Solution {
public:
        
    
    bool findWinner(vector<int>&v,int &count1,int &count2,int start, int close, int turn,int &total){
        if(start==close){
            if(turn==0){
                count1+=v[start];
                if(count1>count2){
                    count1-=v[start];
                    return true;    
                } 
                else{
                    count1-=v[start];
                    return false;
                } 
            } 
            
            if(turn==1){
                count2+=v[start];
                if(count2>count1){
                    count2-=v[start];
                    return true;    
                } 
                else{
                    count2-=v[start];
                    return false;
                } 
            } 
        }
        
        
        if(turn==0){
            if(count1+v[start]>(total/2) || count1+v[close]>(total/2)) return true;
            count1+=v[start];
            if(!findWinner(v,count1,count2,start+1,close,1,total)){
                count1-=v[start];
                return true;
            }
            count1-=v[start];
            count1+=v[close];
            if(!findWinner(v,count1,count2,start,close-1,1,total)){
                count1-=v[close];
                return true;
            }
            count1-=v[close];
            return false;
        }
        
        else if(turn==1){
            if(count2+v[start]>(total/2) || count2+v[close]>(total/2)) return true;
            count2+=v[start];
            if(!findWinner(v,count1,count2,start+1,close,0,total)){
                count2-=v[start];
                return true;
            }
            count2-=v[start];
            count2+=v[close];
            if(!findWinner(v,count1,count2,start,close-1,0,total)){
                count2-=v[close];
                return true;
            }
            count2-=v[close];
            return false;
        }
        
        
    }
    
    
    bool stoneGame(vector<int>& v) {
        int count1=0,count2=0;
        int start=0,close=v.size()-1;
        int total=0;
        for(auto num: v)
            total+=num;
        return findWinner(v,count1,count2,start,close,0,total);
        // if(countt1>count2) return true;
        // else return false;
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is tricky one. As, we have only even number of piles to choose from. Once Alex chooses the first one(either even/odd index). 
// Then Lee has other type to choose from (odd/even), once again adam can choose to same odd/even type as previous. Thus, he can choose all 
// even/odd indices of the vector. As, the sum of all numbers is odd. Either the sum of even/odd indices has to greater than other. Thus, Adam
// always has a possibility to win if chooses the type(Even/Odd) with gretaer sum.









class Solution {
public:
	bool stoneGame(vector<int>& v) {
		return true;
	}
};




//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, dp[i][j] means #more stones that Adam can get if there were only piles from indices [i,j]
// are available. We start from pile of length-1. That's the basic values(initital values) as given vector. Later we when are considering pile of 
// length 'k'. Adam, can take pile at index-'i' or pile at index-'j'. If we take pile at index-'i', then we subtract the best sum/diff that can 
// be taken from rest indices [i+1,j], which will be taken by Lee. If we take value at index j, then best sum/diff of [i,j-1] would be taken 
// by Lee, so that needs to be subtracted. In this way, we iter. from length 1 to v.size(). At the end of iteration, we return the best diff of 
// indices [0,v.size()].







class Solution {
public:
    bool stoneGame(vector<int>& v) {
        // cout<<"vector size "<<v.size()<<endl;
        vector<vector<int>>dp(v.size(), vector<int>(v.size(),0));			// Stores Best diff at possible seq. of piles.
        for(int i=0;i<v.size();i++) dp[i][i]=v[i];							// Init. the base case of pile seq. of len 1.
        
        for(int i=1;i<v.size();i++){										// Start iter. from pile seq. of len 1 to v.size().
            for(int j=0;j<v.size()-i;j++){									// Iter. through all possible start indices of pile seq. of diff. len.
                dp[j][j+i]=max(v[j]-dp[j+1][j+i],v[j+i]-dp[j][j+i-1]);		// Choosing best diff. from two possible piles selected.
            }
        }
        return (dp[0][v.size()-1]>0);										// Returning the best diff. when chosen from seq. [0,v.size()-1].
        // return true;
    }
};









//************************************************************Solution 4:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. This is shrinken version of previous algo. Here, when working on seq. of len 'k'. The dp array
// stores best diff. possible for a seq. of length 'k-1' starting from index 'i' in dp array of index-'i'. Thus, removing need of using 2D 
// array. Which we can make use in max fn. We start working on len=1 to len=v.size(). At the end, we return best diff. possible if seq. len 
// of v.size() starting at index 0 is worked on.






class Solution {
public:
    bool stoneGame(vector<int>& v) {
        vector<int>dp=v;													// Setting the base values for seq. of len 1.
        for(int i=1;i<v.size();i++){										// Start iter. through len of 1 to v.size().
            for(int j=0;j<v.size()-i;j++){									// Start iter. through all possible starts of these seqs.
                dp[j]=max(v[j]-dp[j+1],v[j+i]-dp[j]);						// To get best of seq. for len-'k',best of seq len 'k-1' is used.
            }
        }
        return (dp[0]>0);													// Returning best diff. for len v.size() starting at index-0.
    }
};