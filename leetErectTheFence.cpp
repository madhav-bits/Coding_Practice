/*
*
//***************************************************************587. Erect the Fence.******************************************************

There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the 
minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of 
trees which are exactly located on the fence perimeter.

 

Example 1:

Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:

Example 2:

Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:

Even you only have trees in a line, you need to use rope to enclose them. 
 

Note:

All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
All input integers will range from 0 to 100.
The garden has at least one tree.
All coordinates are distinct.
Input points have NO order. No order required for output.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,2],[1,1],[2,2],[2,4],[4,2],[3,3]]

[[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]


[[1,2],[1,0],[1,1],[1,3],[1,4],[2,2],[2,0],[2,4],[3,3],[4,2]]




// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*******************************************************THIS IS LEET ACCEPTED CODE.*************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Jarvis March -Gift wrapping based solution. Here, we find the leftmost point in the graph, put it into final result. Then find the 
// point which is most clockwise to it. Make it the next point in the solution, there can be multiple points with same clockwise psn, like they can be
// collinear, in that case we have consider all of them. So, we maintain an array to store the point which are collinear and are most clockwise to curr.
// point. Then we push all of them into set of wrapping points. In the process, whenever we get the starting point as next point, we stop the process.



// This link has Convex Hull/Gift Wrapping/Jarvis March algo. code:
// https://leetcode.com/problems/erect-the-fence/discuss/103299/Java-Solution-Convex-Hull-Algorithm-Gift-wrapping-aka-Jarvis-march 


// This link has good explanation of this algo:
// https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/










class Solution {
private:
    
    struct comp{															// Custom comparator for set with complex objects.
        bool operator()(const Point&lt, const Point&rt) const{
            return lt.x<rt.x || (lt.x==rt.x && lt.y<rt.y);
        }
    };
    
    int distance(Point a, Point b, Point c){								// Diff. b/w dist. to curr. to fol and curr. to probable fol.
        int y1=a.y-b.y;
        int y2=a.y-c.y;
        int x1=a.x-b.x;
        int x2=a.x-c.x;
        return ((y1*y1+x1*x1)-(y2*y2+x2*x2));
    }
    
    int crossProduct(Point a, Point b, Point c){							// If Pointc is to most clockwise to a than b, then we get >0.
        int y1=a.y-b.y;
        int y2=a.y-c.y;
        int x1=a.x-b.x;
        int x2=a.x-c.x;
        return (y2*x1-y1*x2);
    }
    
    
public:
    
    vector<Point> outerTrees(vector<Point>& v) {
        // vector<Point>res;
        vector<Point>coll;
        set<Point, comp>st;
        Point curr=v[0];
        for(int i=1;i<v.size();i++){										// Taking the leftmost point as one of wrapping points.
            if(v[i].x<curr.x || (v[i].x==curr.x && v[i].y<curr.y)) curr=v[i]; // Choosing leftmost x coordi with lowest y co-ordi.
        }
        Point start=curr;
        // res.push_back(curr);
        st.insert(curr);
        while(true){														// Until we reach the starting point once again.
            Point fol=v[0];													// Take first point as default answer.
            for(int i=1;i<v.size();i++){									// Iter. over all points again.
                if(v[i].x==curr.x && v[i].y ==curr.y) continue;
                int val=crossProduct(curr, fol, v[i]);
                if(val>0){													// If v[i] is more clockwise, then update fol Point.
                    fol=v[i];
                    coll=vector<Point>();									// Empty the list of collinear fol points.
                }else if(val==0){											// If collinear fol points found.
                    if(distance(curr, fol, v[i])<0){						// If curr. point is farther than fol, then update fol.
                        coll.push_back(fol);
                        fol=v[i];
                    }else coll.push_back(v[i]);								// Else, add curr. point to list of collinear fol.
                }
            }
            for(int j=0;j<coll.size();j++) st.insert(coll[j]);				// Adding collinear points to result points.
            if(fol.x==start.x && fol.y == start.y) break;					// If fol point is starting point, break from loop.
            st.insert(fol);													// Add fol point to list of result points.
            curr=fol;														// Update curr. wrapping point.
        }
        return vector<Point>(st.begin(), st.end());							// Return the list of wrapping points.
    }
};













//************************************************************Solution 2:************************************************************
//*******************************************************THIS IS LEET ACCEPTED CODE.*************************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Monotone Chain Convex Hull algorithm. Here, we first sort the given points based on their x,y coordinate's increasing order. Later,
// we form lower, upper hulls. We start forming lower hull from the leftmost point with lowest y coordinates with all points which form concave turns 
// covering all points. We start from rightmost point with highest y coordinates with all points which form concave turns till we reach the starting point.
// At the end of iter., we return the list containing all the wrapping points.





// This page has explanation and discussion about the algorithm, we can also refer Geeksforgeeks and wiki pages for further clear explanation.
// https://leetcode.com/problems/erect-the-fence/discuss/103306/C++-and-Python-easy-wiki-solution
// https://www.geeksforgeeks.org/convex-hull-monotone-chain-algorithm/
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain







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
private:
    
    struct comp{
        bool operator()(const Point&lt, const Point&rt) const{				// Sorting given points based on their x, y coordinates.
            return (lt.x<rt.x || (lt.x==rt.x && lt.y<rt.y));
        }
    };
    
    int crossProduct(Point a, Point b, Point c){							// Cross Product.
        int y1=a.y-b.y;														// Gives >0 for ACW, <0 for CW, ==0 for collinear.
        int y2=a.y-c.y;
        int x1=a.x-b.x;
        int x2=a.x-c.x;
        return (y2*x1-y1*x2);
    }
    
    
public:
    
    vector<Point> outerTrees(vector<Point>& v) {
        vector<Point>res;
        sort(v.begin(), v.end(), comp());									// Sort given points based on their x,y coordinates.
        
        for(int i=0;i<v.size();i++){										// Forming lower hull for the wrap.
            while(res.size()>=2 && crossProduct(res[res.size()-2], res.back(), v[i])<0) res.pop_back();// Removing those points which cause convex turn.
            res.push_back(v[i]);											// Pushing curr. point into list.
        }
        
        if(res.size()==v.size()) return res;
        
        for(int i=v.size()-2;i>=0;i--){										// Forming upper hull for wrap.
            while(res.size()>=2 && crossProduct(res[res.size()-2], res.back(), v[i])<0) res.pop_back();// Removing those points which cause convex turn.
            res.push_back(v[i]);											// Pushing curr. point into list.
        }
        res.pop_back();														// As starting point would be repushed in upper hull, removing duplicate.
        return res;															// Returning all wrapping points.
    }
};



