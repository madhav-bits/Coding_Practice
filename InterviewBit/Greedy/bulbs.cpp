/*
*
//********************************************************************Bulbs.************************************************************

https://www.interviewbit.com/problems/bulbs/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


11 0 0 1 1 1 0 1 0 1 1 0


3 1 1 1

0

2 0 0




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. Here, we make sure that few changes made by a move aren't changed by later moves. We approach the wire from 
// left to right, we switch for first bulb turned of, all rest bulbs are inverted, now we travel on turned on bulbs till we find a off bulb, we 
// turn on that bulb's switch, in this way we reach till end. That is we count number of alternately valued consecutive num seqs in the array.








int Solution::bulbs(vector<int> &v) {
    if(v.size()==0) return 0;												// Base case.
    int res=0;																// Tracks min. moves required.
    int val=0;																// The curr. state we are looking for(On/Off).
    int i=0;
    for(;i<v.size();i++){													// Iter. through the bulb.
        // cout<<"indx: "<<i<<endl;
        if(v[i]==val){														// If req. state obtained, we inc. count by 1, change the state.
            res++;
            if(val==0) val=1;
            else val=0;
        }
        // cout<<" res; "<<res<<endl;
    }
    
    return res;																// Returning min. moves required.
}
