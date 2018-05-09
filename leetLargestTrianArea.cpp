/*
*
//******************************************************812. Largest Triangle Area.***********************************************

You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.


Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,0],[4,1],[2,3],[1,5],[2,5]]

[[1,1],[2,1],[3,4],[2,7],[9,0]]


// Time Complexity: O(n^3).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(1).	
// This algorithm goes through all possible combinations of vertices and calculates their area by using Heron's Formula,
// and maintains the max. area of triangle till then. Thus, after all possible combinations are checked, we return the max. area of triangle.



class Solution {
public:
    
    double length(float ax, float ay, float bx, float by){								// Calc. the length of the side.
        return abs(sqrt(pow(ax-bx,2)+pow(ay-by,2)));
    }
    
    double largestTriangleArea(vector<vector<int>>& v) {
        double maxm=INT_MIN;															// Holds the maxm. area of triangle possible.
        for(int i=0;i<v.size()-2;i++){
            for(int j=i+1;j<v.size()-1;j++){
                for(int k=j+1;k<v.size();k++){
                    //cout<<"i: "<<i<<" and j: "<<j<<" and k: "<<k<<endl;
                    //cout<<"The area of traingle is: "<<0.5*length(v[i][0], v[i][1], v[j][0], v[j][1])*length((v[i][0]+v[j][0])/2, (v[i][1]+v[j][1])/2, v[k][0], v[k][1])<<endl;
                    double side1=length(v[i][0], v[i][1], v[j][0], v[j][1]);			// Calc. length of the side.	
                    double side2=length(v[j][0], v[j][1], v[k][0], v[k][1]);
                    double side3=length(v[i][0], v[i][1], v[k][0], v[k][1]);
                    double avg=(side1+side2+side3)/2;									// Calc. avg. of side lengths.
                    //maxm=max(maxm, 0.5*length(v[i][0], v[i][1], v[j][0], v[j][1])*length(v[k][0]-(v[i][0]+v[j][0])/2, v[k][1]-(v[i][1]+v[j][1])/2, v[k][0], v[k][1]));
                    //cout<<"The area of triangle is: "<<abs(sqrt(avg*(avg-side1)*(avg-side2)*(avg-side3)))<<endl;
                    maxm=max(maxm, abs(sqrt(avg*(avg-side1)*(avg-side2)*(avg-side3))));	// Using Heron's Formula to calc. the area of triangle.
                }
            }
        }
        
        return maxm;																	// Returning the max. area of triangle possible.
    }
};




