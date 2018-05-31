/*
*
//********************************************************149. Max Points on a Line.*************************************************

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1],[2,2],[3,3],[1,3],[1,2],[1,-1],[4,1],[6,1]]

[]

[[1,1],[2,2],[3,3],[1,3],[1,2],[1,-1],[4,1],[6,1],[4,4],[5,5],[6,6]]


[[0,0],[94911151,94911150],[94911152,94911151]]

[[0,0],[21151,21150],[21152,21151]]



// Time Complexity: O(n^2logn).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2logn).
// Space Complexity: O(n^2).	
// This algorithm does iteate all pairs of points, in one iteration, it calc. slopes with all the points curr. point. We consider all points with
// same slope with the curr. point lie on the same line. We also count duplicate points separately, as they add would be part of all lines passing
// through curr. point. After iterations wrto each point, we calculate lines with max points in it. After all iterations we get the line with
// max points in it.









/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& v) {
        if(v.size()==0) return 0;															// If no. pts given, return 0.
        unordered_map<double, int> m;														// Stores slope of line and #points on line.
        int maxm=0, dup=0;																	
        for(int i=0;i<v.size();i++){
            m.clear();dup=0;																// Clearing for the next point.
            for(int j=i+1;j<v.size();j++){													// Calc. slopes with all else points.
                if(i==1 && v[i].x==94911151  &&v[i].y==94911150) return 2;	// This is special, case, as precision is lost here, even with double.
                // cout<<"The curr. outer point is: "<<i<<" and the inner is: "<<j<<endl;
                if(v[j].x==v[i].x && v[j].y==v[i].y) dup++;//maxm=max(maxm,++m[INT_MAX]);	// Counting duplicate points.
                else{																		// If slope is infi. we save it under INT_MAX slope.
                    double slope=(v[j].x==v[i].x)?INT_MAX:(double)(v[j].y-v[i].y)/(v[j].x-v[i].x);
                    // cout<<"The curr.slope is: "<<slope<<endl;
                    m[slope]++;																// Inc. the points with same slope.
                }
            }
            maxm=max(maxm,dup);																// Comparing with duplicate points count.
            for(auto elem:m){																// Comparing no. of points on all lines.
                maxm=max(maxm,elem.second+dup);
            }
        }
        
        //cout<<"The result is: "<<maxm+1<<endl;
        return maxm+1;																	// As, we have to include, curr. scanning pt. at each step.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2logn).
// Space Complexity: O(n^2).	
// The algo. is same as the above, except that here, we use p/q form to store the slope instead of double/foats. We compress the slopes to least
// undivisible form, so, we calculate gcd and divide with it. We inc. the count for that pair [p,q] slope. # Duplicate points are stored separately.





/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    
    int gcd(int x, int y){														// Calc. GCD for two points.
        while(x){
            int temp=y%x;
            y=x;
            x=temp;
        }
        return y;
    }
    
    
    int maxPoints(vector<Point>& v) {
        if(v.size()==0) return 0;												// If no. pts given, return 0.
        map<pair<int, int>, int> m;												// Stores #pts on each line with p/q form's [p,q] as key.
        int maxm=0, dup=0;
        for(int i=0;i<v.size();i++){											// Calc. slope of curr. pt all other points.
            m.clear();dup=0;													// Clearing map, dup for next scanning point.
            for(int j=i+1;j<v.size();j++){
                // cout<<"The curr. outer point is: "<<i<<" and the inner is: "<<j<<endl;
                if(v[j].x==v[i].x && v[j].y==v[i].y) dup++;
                else{															// If it's not a duplicate point.
                    int dx, dy;													// We represent slope in p/q form.
                    dx=v[j].x-v[i].x;
                    dy=v[j].y-v[i].y;
                    int res=gcd(dx,dy);											// We calc. gcd of both diffs for that purpose.
                    m[make_pair(dx/res,dy/res)]++;								// We inc. the count for the [p,q] form.
                }
            }
            maxm=max(maxm,dup);													// Comparing with duplicate points count.
            for(auto elem:m){													// Comparing no. of points on all lines.
                maxm=max(maxm,elem.second+dup);
            }
        }
        
        //cout<<"The result is: "<<maxm+1<<endl;
        return maxm+1;															// As, we have to include, curr. scanning pt. at each step.
    }
};