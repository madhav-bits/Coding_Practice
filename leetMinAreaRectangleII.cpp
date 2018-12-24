/*
*
//**********************************************************963. Minimum Area Rectangle II.***************************************************

Given a set of points in the xy-plane, determine the minimum area of any rectangle formed from these points, with sides not necessarily 
parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:



Input: [[1,2],[2,1],[1,0],[0,1]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
Example 2:



Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
Output: 1.00000
Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
Example 3:



Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
Output: 0
Explanation: There is no possible rectangle to form from these points.
Example 4:



Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.
 

Note:

1 <= points.length <= 50
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
Answers within 10^-5 of the actual value will be accepted as correct.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[[0,3],[1,2],[3,1],[1,3],[2,1]]





// Time Complexity: O(n^3).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n^2).	
// This algorithm is HashMap based. Here, we store all coordinates in map. We iterate through loops and choose three distinct indices, check 
// whether they form diagonal and contributing sides(2), and check pythogarous theorem for them. If true, interpolate fourth point of rectangle
// based on three indices, if fourth point present in map, then calculate area of rectangle involving these points. Try to update min. area 
// possible.









class Solution {
public:
    
    long long calcDist(vector<int>&u, vector<int>&v){						// Calc. dist. b/w points specified.
        long int x1=u[0], x2=v[0], y1=u[1], y2=v[1];
        long long res;
        long long a=x1-x2;
        long long b=y1-y2;
        res=(a*a)+(b*b);
        return res;
    }
    
    
    double minAreaFreeRect(vector<vector<int>>& v) {
        double res=INT_MAX;
        unordered_set<string>m;												// Stores points.
        for(int i=0;i<v.size();i++){										// Storing points in map.
            string temp="";
            temp=to_string(v[i][0])+"#"+to_string(v[i][1]);
            m.insert(temp);
        }
        for(int i=0;i<v.size();i++){										// Iter. through given points.
            for(int j=0;j<v.size();j++){
                if(i==j) continue;											// Making sure, they are distinct.
                for(int k=0;k<v.size();k++){								// Making sure, they are distinct.
                    if(i==k || j==k) continue;
                    if(calcDist(v[i], v[j])+calcDist(v[j], v[k])!=calcDist(v[i], v[k])) continue;	// If Pythogarous not satisifed, continue.
                    int x=v[i][0]+v[k][0]-v[j][0];							// Interpolating fourth point.
                    int y=v[i][1]+v[k][1]-v[j][1];
                    string temp=to_string(x)+"#"+to_string(y);
                    if(m.count(temp)==0) continue;							// If present in map, calc. sides lengths.
                    double a=calcDist(v[i], v[j]);							// We get square of side's length.
                    double b=calcDist(v[k], v[j]);
                    double area=sqrt(a*b);									// Calc. area from sides.
                    res=min(res, area);										// Update the min. area obtained.
                }
            }
        }
        if(res==INT_MAX) return 0;											// If rectangle not found, return 0.
        return res;															// Returning the min. area obtained.
    }
};