/*
*
//***********************************************************469. Convex Polygon.***************************************************

Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).

Note:

There are at least 3 and at most 10,000 points.
Coordinates are in the range -10,000 to 10,000.
You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). In other words, we ensure that 
exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.
Example 1:

[[0,0],[0,1],[1,1],[1,0]]

Answer: True

Explanation:
Example 2:

[[0,0],[0,10],[10,10],[10,0],[5,5]]

Answer: False

Explanation:




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,0],[0,1],[0,2],[1,1],[1,0]]


[[0,0],[2,3],[-1,5],[-1,1]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Geometry based. A set of points of convex, if all it's consec. triplet points follow the sign orientation. The figure 
// is concave, if atleast one triplet follows the other drn(CW, ACW), then it's concave. Here, we get orientation from the slope of two vectors,
// if the diff. of first slope and second slope is +ve, it's CW, if it's -ve, then ACW, is it's 0, then collinear.


// If any triplet is collinear, just ignore it, as it supports both clockwise and Anti-Clockwise orientations. As we are given a closed figure,
// we are bound to encounter clockwise Anti-Clockwise oriented triplets and assign a orientation accordingly.




class Solution {
public:
    bool isConvex(vector<vector<int>>& v) {	
        int orien=0;														// Tracks orientation of figure.
        for(int i=0;i<v.size();i++){										// Iterates through the entire array.
            int xDiff1,xDiff2,yDiff1,yDiff2;
            xDiff1=v[(i+1)%2][0]-v[i%2][0];									// Calc. x's diff b/w first two poits under consideration.
            xDiff2=v[(i+2)%2][0]-v[(i+1)%2][0];								// Clac. x's diff b/w second, third points.
            
            yDiff1=v[(i+1)%2][1]-v[i%2][1];									// Calc. y's diff b/w first, second points.
            yDiff2=v[(i+2)%2][1]-v[(i+1)%2][1];								// Clac. x's diff b/w second, third points.
            
            int sign=0;														// Stores the orien. of curr. point.
            int value=yDiff1*xDiff2-yDiff2*xDiff1;							// Calc. the value of drn.
            if(value>0) sign=1;												// Assign orien. accordingly(Clock Wise).
            else if(value<0) sign=-1;										// Anti-Clockwise.
            
            cout<<"The value: "<<value<< " and sign: "<<sign<<endl;
            if(orien==0) orien=sign;										// If orien. not assigned, assign one.
            else if(sign==0) continue;										// If curr. points are collinear, ignore them.
            else if(orien!=sign) return false;								// If curr. orientation doesn't match prev. one, then return false.
        }	
        return true;														// If all orien. match, then return true.
    }
};

