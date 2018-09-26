/*
*
//*************************************************************Matrix Median.******************************************************


https://www.interviewbit.com/problems/matrix-median/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3 3 1 5 5 2 5 6 5 6 7


3 3 1 3 5 2 6 9 3 6 9


1 11 1 2 2 2 2 2 3 3 3 3 3




// Time Complexity: O(log(maxm-minm)).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(log(maxm-minm)).
// Space Complexity: O(1).	
// This algorithm is Binary Search problem. We take min, maxm values among the values in the matrix. Then, we do Binary Search on the range
// of numbers present. We do a upper_bound on each row, to get #values <=curr. value(mid). If #values are <=total values/2, then we move to 
// right half, else we move to left half.

// Observations:
// In Binary Search always try to push high val. to the left(instead of pushing low val. to the right in else cdn), as the other case will lead
// to Infinite loop(low=mid in every iter.)







int Solution::findMedian(vector<vector<int> > &v) {
    if(v.size()==0) return 0;												// Base case.
    int dist=(v.size()*v[0].size())/2;										// Calc. mid dist from start.
    int low=v[0][0], high=v[v.size()-1][v[0].size()-1];
    for(int i=0;i<v.size();i++){											// Extracts maxm, minm value in the given Matrix.
        low=min(low, v[i][0]);
        high=max(high, v[i].back());
    }
    while(low<high){														// Iter. in a valid interval.
        // cout<<"low: "<<low<<" and high: "<<high<<endl;
        int mid=low+(high-low)/2;											// Calc. mid value.
        int count=0;														// Tracks #values satisfying below cdn.
        for(int i=0;i<v.size();i++)											//#less than or equal to mid value.
            count+=upper_bound(v[i].begin(), v[i].end(), mid)-v[i].begin();	// Counts #values<=curr. value(mid).
            
        // if(count>dist) high=mid-1;										// Not properly structured.
        // else low=mid;													// low moving to right(Causes infinite loop at the end in few cases).
        
        if(count<=dist) low=mid+1;											// If curr. val isn't median, move right.
        else high=mid;														// Moving to left(high value moving) in else cdn.
    }
    return low;																// Returning the median.
}

