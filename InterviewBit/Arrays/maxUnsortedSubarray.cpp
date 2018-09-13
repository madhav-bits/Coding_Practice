/*
*
//************************************************************Maximum Unsorted Subarray.***************************************************


https://www.interviewbit.com/problems/maximum-unsorted-subarray/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


12 11 4 8 5 6 8 2 7 3 9 10

5 1 2 3 4 5

1 1


2 2 1





// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We do 4 iterations. First to find the minm. value that is unsorted, then in the second iter. we find
// it's index in the sorted array by iter. from the start. In the third iter. we find the largest num, which is unsorted, in the fourth iter. 
// we search for it's index by coming from the back. At the end, if everythin is sorted, we return -1 else we return the obtained indices.







vector<int> Solution::subUnsort(vector<int> &v) {
    int close=INT_MIN, start=INT_MAX;
    for(int i=0;i<v.size();i++){											// Searching for val. with minm. unsorted value.
        if(i>0 && v[i]<v[i-1] && v[i]<start) start=v[i];					// Updating minm. unsorted value.
    }
	
    int k=0;																// Init. the iterator.
    for(;k<v.size();k++){													// Looking for it's index in Sorted array.
        if(v[k]>start) break;												// When a greater val. than minm unsorted is encoun. then break.
    }
    
    
    int minm=INT_MAX;														// Init. minm value.
    for(int j=v.size()-1;j>=0;j--){											// Searching for maxm. unsorted value.
        if(v[j]>minm && v[j]>=close) close=v[j];							// If curr. val is unsorted and larger than prev. maxm unsorted val.
        minm=min(minm,v[j]);												// Update the minm. value encountered.
    }
    int l=v.size()-1;														// Init. the iterator.
    for(;l>=0;l--){															// Looking for it's psn in Sorted Array.
        if(v[l]<close) break;												// When a smaller than maxm. unsorted val. is found.
    }
    // cout<<"Start: "<<start<<" and close: "<<close<<endl;
    if(k==v.size() && l==-1) return vector<int>({-1});						// If given array is already sorted.
    return vector<int>({k,l});												// Return the start, end indices.
}
