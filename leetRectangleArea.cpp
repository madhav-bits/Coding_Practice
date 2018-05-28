/*
*
//**********************************************************223. Rectangle Area.***************************************************

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: -3, 0, 3, 4, 0, -1, 9, 2
Output: 45
Note:
Assume that the total area is never beyond the maximum possible value of int.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


-3
0
3
4
0
-1
9
2


0
0
0
0
-1
-1
1
1





// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is based on finding the overlapping length of both rectangles. We first find whether the two rectangles are overlapping or not.
// If they are not overlapping return sum of two rectangles, if not find the common area, then subtract that from sum of two rectangles.









class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1=(C-A)*(D-B);																	// Calc. area of two rentangles.
        int area2=(G-E)*(H-F);
        int res=0;
        if(!(max(A,E)< min(C,G)) ||  ! (max(B,F)< min(D,H))) return area1+area2;			// If either of length/breadth doesn't overlap.
        int len=min(C,G)-max(A,E);															// Finding overlapping in the x-axis.
        int bre=min(D,H)-max(B,F);															// Finding overlapping in the y-axis.
        //int overlap=len*bre;
        //cout<<"Area1: "<<area1<<" and area2: "<<area2<<endl;
        //cout<<"The len: "<<len<<" and breadth is: "<<bre<<endl;
        return area1+area2-(len*bre);														// Finding the total area of two rentangles.
    }
};
