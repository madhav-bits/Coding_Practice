/*
*
//************************************************************356. Line Reflection.*****************************************************

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1],[2,1]]


[[-1,1],[5,1],[3,1],[1,1],[4,1],[2,1]]



[[-1,1],[5,1],[3,1],[1,1],[4,1],[6,1]]



[[-1,1]]



[]



[[-1,1],[1,2]]


[[1,1],[0,0],[-1,1]]


[[1,2],[2,2],[1,4],[2,4]]


[[-16,1],[16,1],[16,1]]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Hash Map based. We form a unique str to represent each pair of points and store them in map. In the second iteration, we 
// find the symmetrical opposite x co-ordinate and search for it's existence in the HashMap.





class Solution {
public:
    bool isReflected(vector<pair<int, int>>& v) {
        unordered_map<string,int>m;
        if(v.size()==0) return true;
        int minm=v[0].first, maxm=v[0].first;								// Extracting minm, maxm x co-ordi.
        for(int i=0;i<v.size();i++){										// Iterate over vector to store coordinates.
            maxm=max(maxm,v[i].first);										// Calc. min,max x co-ordi.
            minm=min(minm, v[i].first);
            string str=to_string(v[i].first)+'#'+to_string(v[i].second);	// Storing the representation in map.
            m[str]=1;
        }
        int total=minm+maxm;
        for(int i=0;i<v.size();i++){										// Iterating over vector.
            string str=to_string(total-v[i].first)+'#'+to_string(v[i].second);// Iter. over symmetrical to mid x co-ordi..
            if(m[str]!=1) return false;										// If not found, return false.
        }
        return true;														// If no issue arises, then return true.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Hash Map based. We iterate over vector and store all points with same x co-ordi. under same key in map. In the second iter.
// we search for symmetrical along mid x co-ordi. in the map, if not found, return false. If no issues arises by end of iteration, then 
// return true.






class Solution {
public:
    bool isReflected(vector<pair<int, int>>& v) {
        unordered_map<int, set<int>>m;
        if(v.size()==0) return true;
        int minm=v[0].first,maxm=v[0].first;								// Calc. minm, maxm. x co-ordi.
        for(int i=0;i<v.size();i++){										// Iterating over all points.
            m[v[i].first].insert(v[i].second);								// Storing all points with same x co-ordi under same key.
            minm=min(minm, v[i].first);
            maxm=max(maxm, v[i].first);
        }
        int total=minm+maxm;
        for(int i=0;i<v.size();i++){										// Iterate over all points.
            if(m.count(total-v[i].first)==0 || m[total-v[i].first]!=m[v[i].first]) return false;// If symm. point found/set of pts. didn't match.
        }
        return true;														// If no issue arises, then return true.
    }
};