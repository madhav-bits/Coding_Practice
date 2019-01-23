/*
*
//************************************************************Ways to color a 3xN Board.*****************************************************

https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



4


3


2


18






// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. Here, at each clmn, we check # ways to get triplets, twins in curr. clmn based on arrangements in
// prev. clmn. So, at the end of iter., we have #triplets, #twins in last clmn, we add them and return them in mod form.



// triplets- An arrangment in which 3 colors are used to fill 3 blocks in a clmn.
// twins- An arrangement in which 2 colors are used to fill 3 blocks in a clmn.



// geeksforgeeks has this solution explained in this link:
// https://www.geeksforgeeks.org/ways-color-3n-board-using-4-colors/



// Official solution in interviewbit compares 36 possibilities in each clmn with 36 combinations in prev. clmn and if they sync. we add possib. 
// to get that combi. in prev. clmn to #possib to get curr. clmn's possib. This way we iter. over all clmns, finally we get #combi. for last clmn.






int getCombi(int num){														// Calc. #combi. to fill given dim.
    int mod=1000000007;				
    long long int twins=12, triplets=24;									// Base values of 1 clmn.
    for(int i=2;i<=num;i++){												// Iter. through clmns given.
        long long int temp=triplets;										// Temp. storing triplets value from prev. clmn.
        triplets=(triplets*11+twins*10)%mod;								// Calc. new triplet value.
        twins=(twins*7+temp*5)%mod;											// Calc. new twin value.
    }
    return (triplets+twins)%mod;											// Return #ways to fill given board.
}

int Solution::solve(int num) {
    return getCombi(num);													// Call fn. to get #ways to fill given board.
}
