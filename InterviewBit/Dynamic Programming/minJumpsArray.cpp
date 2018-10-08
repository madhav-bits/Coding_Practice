/*
*
//**************************************************************Min Jumps Array.*****************************************************

https://www.interviewbit.com/problems/min-jumps-array/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



6 2 1 3 1 0 2


0


1


0 1



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, we iterate over indices which are reachable from zero index. At every index, we calc./update 
// max. index reachable in next step. If we reach max. index reachable in curr. step, we inc. the steps count. If the last index falls under 
// next max. index reachable, we return curr. step+1.
// A base case is that array has only 1/0 elements, then we return 0.








int Solution::jump(vector<int> &v) {
    if(v.size()<=1) return 0;												// Base cases.
    int step=0,curr=0, next=0;
    for(int i=0;i<v.size();i++){											// ITer. over all indices reachable from zeroth index.
        // cout<<"index: "<<i<<endl;
        if(i>curr) return -1;												// If curr. index isn't reachable, return -1.
        if(i<=curr) next=max(next, i+v[i]);									// Updating max. index reachable in next step. 
        if(next>=v.size()-1) return step+1;									// If last index reachable, return curr. step+1.
        // cout<<"step: "<<step+1<<" and next: "<<next<<endl;
        
        if(i==curr){														// If we are at last index reachable in curr. step.
            curr=next;														// Update/Move to next step.
            step++;															// Inc. the step count.
        }
    }
    //return -1;																// If not reachable return -1.
}
