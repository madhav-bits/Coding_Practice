/*
*
//**************************************************************Delete and Conquer.*******************************************************

https://www.interviewbit.com/problems/delete-and-conquer/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


6 10 20 10 20 10 5



11 4  4 3 6 2 8 3 1 7 2 3





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is observation based. Here, we are supposed to separate largest group in which all nums mutually divides else numbers,means they 
// all are same number. So, we iterate over the entire array and get the #occurances of each number. Iter. over map and get the maxm. occur. of 
// a number. Return total length of array-maxm. occur to get minm. deletions needed.







int Solution::deleteandconquer(vector<int> &v) {
    unordered_map<int,int>m;												// Tracks #occur. of each num.
    for(auto num:v) m[num]++;												// Updating count of each num. in the array.
    int maxm=1;																// Tracks max. occrr. of a num.
    for(auto it=m.begin();it!=m.end();it++){								// Iter. over map.
        if(it->second>maxm) maxm=it->second;								// Getting max. occur. of a num.
    }
    return v.size()-maxm;													// Returning the min. deletions needed.
}
