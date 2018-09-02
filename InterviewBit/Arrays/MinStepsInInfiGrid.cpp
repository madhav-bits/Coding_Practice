/*
*
//************************************************************Min Steps in Infinite Grid.*****************************************************

https://www.interviewbit.com/problems/min-steps-in-infinite-grid/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,0],[1,2],[-1,2]]



[[10,0],[-1,2],[-1,2],[-1,-12]]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Manhattan distance based. We calc. the dist. b/w two adj. pts. We calc. dist along both axis, we choose the bigger axis, 
// because, to cover the smaller length axis, we travel that dist along diagonal axis, rest dist.along the axis of max. diff.






int Solution::coverPoints(vector<int> &u, vector<int> &v) {
    int res=0;
    for(int i=0;i<u.size()-1;i++){											// Iter. over all steps given.
        res+=(abs(u[i]-u[i+1])<abs(v[i]-v[i+1])?abs(v[i]-v[i+1]):abs(u[i]-u[i+1]));	// Calc. dist. needed to reach next point.            
    }
    return res;																// Return overall distance travelled.
    
}

