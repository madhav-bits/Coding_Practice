/*
*
//**************************************************Largest area of rectangle with permutations.*******************************************

https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3 3 1 0 1 0 1 0 1 0 0

3 4 1 0 1 0 1 0 1 1 0 1 0 1



// Time Complexity: O((n^2)*logn).  
// Space Complexity: O(1).													// As, we are modifying the given array.

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O((n^2)*logn).											// As, we are modifying the given array.
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming/Observation based. Here, as permutations are allowed on columns. We first segregate the #conse. ones
// that contribute to rectangle, which includes them. As, we don't know which combi. of columns gives max. rectangle. We iterate through the
// rows, we sort the values in that row, as contribution of upper ones attached to curr. ones in each column of this row is pushed to this row.
// We calculate the rect. involving all of them. As, rect. height is determined by least contributing clmn, and width determined by #clmns with 
// contri. greater than curr. clmn, we sort the curr. row and calculate the area values at each row and try to update the res. area value and 
// return it at the end of iteration. 








int Solution::solve(vector<vector<int> > &v) {
    int res=0;
    int len=v.size();														// #rows.
    for(int j=0;j<v[0].size();j++){											// Iter. through all clmns. 
        for(int i=1;i<len;i++){												// Iter. through all rows.
            if(v[i][j]==1) v[i][j]+=v[i-1][j];								// Pushing down the contribution of conse. ones of rows in this clmn.
        }
    }
	for(int i=0;i<len;i++){													// Iter. through all rows.
        sort(v[i].begin(), v[i].end());										// Sort the curr. rows values for rect. with this row as the base.
        for(int j=0;j<v[0].size();j++){										// Iter. over clmns in this row.
            res=max(res, v[i][j]*((int)v[0].size()-j));						// Trying to udpate the maxm. rect. area(res var).
        }
    }
    return res;																// Return the max. area possible after perm. of clmns.
}