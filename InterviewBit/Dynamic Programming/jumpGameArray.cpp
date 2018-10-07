/*
*
//************************************************************Jump Game Array.*******************************************************


https://www.interviewbit.com/problems/jump-game-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



5 3 2 1 0 4


6 2 1 2 2 1 0


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. Here, we iterate till indices where we can max. reach based on the max. jump we can make from
// indices we had visited. If, we moved/(can reach) past the last index, then we return true.If not we return false.







int Solution::canJump(vector<int> &v) {
    int maxm=0;																// Maxm. index we can iterate till.
    for(int i=0;i<v.size();i++){											// Iter. through indices reachable.
        if(i<=maxm){														// UPdating max. index reachable based on jumps from indices iterated.
            maxm=max(maxm, v[i]+i);
        }else return 0;														// If curr. index not reachable, return false.
        if(maxm>=v.size()-1) return 1;										// If reachable index is >=last index, return true.
    }
    
}
