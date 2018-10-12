/*
*
//*********************************************************Container With Most Water.***************************************************


https://www.interviewbit.com/problems/container-with-most-water/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



6 5 4 3 2 1 4

10 1 5 4 3 2 1 3 5 7 9


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Two Pointer based. Here, we start from two ends, we compare both ends, the shorter one, decides the volume the rectangle
// can hold, the curr. psns[i,j] represent unexplored possiblity of rectangles leading to maxm. area involving i/j as one of sides- all other
// possiblities involving i/j as one of rectangle's sides are covered in prev. cases of pointers  iteration. So,this is the only case left
// out, that might lead to greater area. We calc. with min. side, then we move that index towards other ptr. With expectation that next
// might give best area. We do this until both ptrs meet.



// This is similar to TRAPPING RAIN WATER, there at each step of this algo. we extract the area contribution of smaller side and add it to final
// result, move that ptr towards another one, until both ptrs meet.




int Solution::maxArea(vector<int> &v) {
    int res=0;																// Tracks maxm. area possible.
    int i=0, j=v.size()-1;													// Ptrs inti. to both ends.
    // int minm=min(v[j], v[i]);
    while(i<j){																// Until both ptrs meet.
        if(v[i]<=v[j]){														// If left ptr has min. value.
            // res+=v[i];													// Smaller side determines the area of the rectangle.
            res=max(res, v[i]*(j-i));										// Calc. area possible with curr. alignment.
            i++;
        }else{																// Calc. area possible with right one as smaller side.
            // res+=v[j];
            res=max(res, v[j]*(j-i));
            j--;															// Moving the ptr towards left ptr.
        }
    }
    
    return res;																// Returning the maxm. possible rect. area.
}
