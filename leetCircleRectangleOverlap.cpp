/*
*
//**************************************************1401. Circle and Rectangle Overlapping.*********************************************

https://leetcode.com/problems/circle-and-rectangle-overlapping/description/


Given a circle represented as (radius, x_center, y_center) and an axis-aligned rectangle represented as (x1, y1, x2, y2), 
where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return True if the circle and rectangle are overlapped otherwise return False.

In other words, check if there are any point (xi, yi) such that belongs to the circle and the rectangle at the same time.

 

Example 1:



Input: radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0) 
Example 2:



Input: radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true
Example 3:



Input: radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
Output: true
Example 4:

Input: radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false
 

Constraints:

1 <= radius <= 2000
-10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4
x1 < x2
y1 < y2





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
0
0
1
-1
3
1


1
0
0
-1
0
0
1


1
1
1
1
-3
2
-1


2
8
6
5
1
10
4



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. Our solution is from a discussion in stackoverflow, below is the link. Here, we calc. the 
// closest point to center of circle on rectangle. Then we calc. dist.^2 from center to the closest point, if it is <= square of dist.
// Then, there is overlap.


// This solution is from this link. It discusses various methods to approach this problem.
// https://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection





class Solution {
public:
    
    int smallestPosition(int psn, int minm, int maxm){
        return max(minm, min(psn, maxm));    
    }
    
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
		// Finding the closest point on rectangle to the center of the circle.
        int closestX=smallestPosition(x_center, x1, x2);
        int closestY=smallestPosition(y_center, y1, y2);
        
		// Calc. x, y coordinate dist of closest point to center of the circle.
        int distX=x_center-closestX;
        int distY=y_center-closestY;
		
		// Calc. Euclidean distance.
        int dist=distX*distX+distY*distY;
        return dist<=radius*radius;											//  If dist<=square of radius, then there is  overlap.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This is another approach to the problem, it is also from the same link. Here, we find gap b/w two centers, if x-gap is>radius+width/2,
// we return false as they are very far from each other. If x-gap<=width/2, then two figures are very close and there would be 
// overlap, we return true. If x-gap>width/2, we look for dist. of rect. corners from center of circle, if dist. is inside circle, we
// return true else return false. Same logic applies to y-gap also.








class Solution {
public:
    
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        
        float width=x2-x1, height=y2-y1;
        // cout<<"width: "<<width<<" height: "<<height<<endl;
        float rectX=(x1+x2)/2.0, rectY=(y1+y2)/2.0; 
        float distX=abs(x_center-rectX), distY=abs(y_center-rectY);			// Calc. gap b/w both centers.
        // cout<<"distX: "<<distX<<" distY: "<<distY<<endl;
        
        if(distX>radius+width/2.0) return false;							// If x-gap is > sum of radius and width/2, then cant overlap.
        if(distY>radius+height/2.0) return false;
        
        if(distX<=width/2.0) return true;									// If x-gap is <=width/2, then there will be overlap.
        if(distY<=height/2.0) return true;
        
        float dist=(distX-width/2.0)*(distX-width/2.0)+(distY-height/2.0)*(distY-height/2.0);// Calc. dist. of rect. corners from center of circle.
        return dist<=radius*radius*1.0;										// If dist is less than radius, return true.
    }
};

