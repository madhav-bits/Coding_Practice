/*
*
//**************************************************************Coins in a Line.*********************************************************


https://www.interviewbit.com/problems/coins-in-a-line/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


10 4 7 6 8 2 11 3 2 9 1



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. As, we can take number from both ends, we have use max. coins collectable from possible subsets of
// remaining coins. So, we construct a 2D DP array. dp[i][j] indicates max. coins collectable from coins from [i,j] indices. dp[i,j] depends
// on last two indince's values + min( two possible remaining subsets after removing edge coins). If i index is used, then next person can take
// i+1, j, so, he take index which gives the curr. person, the min. sum. Same logic can be applied can be applied to picking the j index.









int Solution::maxcoin(vector<int> &v) {
    vector<vector<int>>dp(v.size(), vector<int>(v.size(),0));				// Init. a 2D DP array.
    for(int i=0;i<v.size();i++) dp[i][i]=v[i];								// Substrings of length 1.
	
    for(int len=2;len<=v.size();len++){										// Iter. through all possible substring lengths.
        // cout<<"len: "<<len<<endl;
        for(int i=0;i<=v.size()-len;i++){									// Iter. through all starts for curr. length.
            if(len==2) dp[i][i+1]=max(v[i], v[i+1]);						// This is for substr of length 2.
            else{															// As, the opponent makes sure that we choose subset with min. dp value.
                dp[i][i+len-1]=max(dp[i][i+len-1], min(v[i]+dp[i+1][i+len-2], v[i]+dp[i+2][i+len-1]));// Choosing the rem. subset, with min. value.
                
				// dp[i][i+len-1]=max(dp[i][i+len-1], v[i]+dp[i+2][i+len-1]);
                
				
				
                dp[i][i+len-1]=max(dp[i][i+len-1], min(v[i+len-1]+dp[i+1][i+len-2],v[i+len-1]+dp[i][i+len-3]));// If we choose j index.
                
				// dp[i][i+len-1]=max(dp[i][i+len-1], v[i+len-1]+dp[i][i+len-3]);
            }
            
        }
    }
    return dp[0][v.size()-1];												// Returning max. extractable value for entire string.
    
}
