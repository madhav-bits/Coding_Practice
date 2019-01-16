/*
*
//**********************************************************Longest Subarray Difference.***************************************************

https://www.interviewbit.com/problems/longest-subarray-difference/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



5 3 9 2 5 2
4



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Sliding Windlow and multiset based. Here, we need to track diff. b/w minm and maxm value in every iteration and values are 
// being removed from consideration based on conditions. Maintaining a sorted set of values would be useful for getting maxm. and minm. values 
// easily. So, we use multiset(map can also be used). We push elements into it in every iteration, check for given cdn, if if fails we start 
// removing elements from the start until the cdn gets satisfied. Once, satisfied, we try to update the final max. length subarray. At the end of 
// iteration, return the max. length subarray.






int Solution::solve(vector<int> &v, int target) {
    if(v.size()==1) return 1;												// Base case.
    int start=0,close=0;													// Tracks start, close of window.
    int res=1;																// Tracks max. length subarray satis. given cdns.
    multiset<int>m;															// Stores elements from window.
    for(int i=0;i<v.size();i++){											// Iter. over array.
        close=i;															// Updating the end of window array.
        m.insert(v[i]);														// Inserting curr. elem into window.
        if(*(--m.end())-*m.begin()>=target){								// If cdn fails, remove elem. from start of window.
            m.erase(m.find(v[start]));										// Removing start index' elem. from window.
            start++;														// INc. the index value.
        }
        res=max(res, (int)m.size());										// Update the final result.
    }
    return res;																// Returning the max. length subarray.
}