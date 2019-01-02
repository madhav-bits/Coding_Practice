/*
*
//**************************************************************Assign Mice to Holes.*******************************************************

https://www.interviewbit.com/problems/assign-mice-to-holes/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3 4 -4 2
3 4 0 5



0
0





// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Greedy based. Here, in order get to min. dist. for each of the mices to travel. Each mouse has to go to the first unoccupied
// hole if holes are allocated to the mouses in inc. order of their coordinates where holes are assigned in order of their coridnates. In this 
// allocation scheme, there would be minimum overlaps b/w the runs of the mouses whatsoever the position of the holes may be. Thus, we get minm.
// possible longest distance for a mouse.








int Solution::mice(vector<int> &mice, vector<int> &holes) {
    if(mice.size()==0) return 0;											// Base case.
    int res=INT_MIN;														// Init. the minm. var.
    sort(mice.begin(), mice.end());											// Sort mice, holes arrays.
    sort(holes.begin(), holes.end());
    for(int i=0;i<mice.size();i++){											// Assign holes to mouses in inc. order of both of their psns.
        res=max(res,abs(mice[i]-holes[i]));									// Trying to update the maxm. distance var.
    }
    return res;																// Returning the maxm. dist travelled by a mice.
}