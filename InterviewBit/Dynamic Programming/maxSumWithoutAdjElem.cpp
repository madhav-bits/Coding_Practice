/*
*
//********************************************************Max Sum Without Adjacent Elements.*************************************************

https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2 3 5 7 6 1 5 6


2 4 1 2 3 4 2 3 4 5


2 5 1 23 34 2 12 30 9 8 12 23




// Time Complexity: O(n).  
// Space Complexity: O(k).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, as taken elements shouldn't be adjacent. If values from clmn 'j' is taken, then we won't
// consider clmn 'j-1'. We will try to add maxm sum that was observed till row 'j-2' and curr. clmn's element and update dp index array. We also
// iterate the maxm sum till clmn 'j-1' now, to be considered in next iteration. After the end of iteration, we also try to udpate maxm. sum
// with values stored in last clmn of DP array.



// dp[0][j] is the maxm. sum obtained by including jth clmn first row and the maxm. sum observed till 'j-2' clmns.
// dp[1][j] is the maxm. sum obtained by including jth clmn second row and the maxm. sum observed till 'j-2' clmns.

// maxm. is maxm. sum observed till 'j-2' clmn in every iteration.





int Solution::adjacent(vector<vector<int> > &v) {
    if(v.size()==0) return 0;												// Base case.
    if(v[0].size()==1) return max(v[0][0], v[1][0]);						// Base case.
    vector<vector<int>>dp(2, vector<int>(v[0].size(),0));					// Init. DP array.
    int maxm=0;																// Tracks maxm. sum observed till 'j-2' in every iteration.
    dp[0][0]=v[0][0];														// Base case init.
    dp[1][0]=v[1][0];
    // cout<<"maxm init: "<<maxm<<endl;
    for(int j=1;j<v[0].size();j++){											// Iter. over all clmns.
        dp[0][j]=maxm+v[0][j];												// We are considering curr. clmn first row and maxm. till clmn 'j-2'.
        dp[1][j]=maxm+v[1][j];												// We are considering curr. clmn second row and maxm. till clmn 'j-2'.
        maxm=max(dp[0][j-1], maxm);											// Updating maxm. var with values from prev. clmn.
        maxm=max(dp[1][j-1], maxm);
        // cout<<"j: "<<j<<" and maxm: "<<maxm<<endl;
    }
    maxm=max(dp[0][dp[0].size()-1], maxm);									// Updating maxm. var with values from last clmn.
    maxm=max(dp[1][dp[0].size()-1], maxm);
    return maxm;															// Returning the maxm. sum observed.
}











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(k).													// DP array of size 4 is used.
// This algorithm is Dynamic Programming based. Here, as taken elements shouldn't be adjacent. If values from clmn 'j' is taken, then we won't
// consider clmn 'j-1'. We will try to add maxm sum that was observed till row 'j-2' and curr. clmn's element and update dp index array. We also
// iterate the maxm sum till clmn 'j-1' now, to be considered in next iteration. After the end of iteration, we also try to udpate maxm. sum
// with values stored in last clmn of DP array.



// dp[0][j] is the maxm. sum obtained by including jth clmn first row and the maxm. sum observed till 'j-2' clmns.
// dp[1][j] is the maxm. sum obtained by including jth clmn second row and the maxm. sum observed till 'j-2' clmns.

// maxm. is maxm. sum observed till 'j-2' clmn in every iteration.


// This algo. is same as above one,except that is is optimized space complexity wise.


int Solution::adjacent(vector<vector<int> > &v) {
    if(v.size()==0) return 0;
    if(v[0].size()==1) return max(v[0][0], v[1][0]);
    vector<vector<int>>dp(2, vector<int>(2,0));
    int maxm=0;
    dp[0][0]=v[0][0];
    dp[1][0]=v[1][0];
    // cout<<"maxm init: "<<maxm<<endl;
    for(int j=1;j<v[0].size();j++){
        dp[0][j%2]=0;dp[1][j%2]=0;
        
        dp[0][j%2]=maxm+v[0][j];
        dp[1][j%2]=maxm+v[1][j];
        maxm=max(dp[0][(j-1)%2], maxm);
        maxm=max(dp[1][(j-1)%2], maxm);
        // cout<<"j: "<<j<<" and maxm: "<<maxm<<endl;
    }
    maxm=max(dp[0][(v[0].size()-1)%2], maxm);
    maxm=max(dp[1][(v[0].size()-1)%2], maxm);
    return maxm;
}
