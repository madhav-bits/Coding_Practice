/*
*
//******************************************************447. Number of Boomerangs.***********************************************

Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i 
and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] 
(inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[[0,0],[1,0],[2,0],[1,1]]

[[0,1], [1,2],[2,3]]




// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is iteration based. We iterate the entire array, and calc. the dist. of curr. point to all other points(except self). After 
// the iteration, we go through each row containing distances of all points from curr. point, we store those distances in a map. If,we get a 
// distance more than twice, we take it's permutation of choosing 2 value and add it to final result.






class Solution {
public:
    
    
    int numberOfBoomerangs(vector<pair<int, int>>& v) {
        vector<vector<double>>dp(v.size(),vector<double>(v.size(),0));		// Stores dist. b/w two points.
        for(int i=0;i<v.size();i++){										// Calc. area b/w two points.
            for(int j=0;j<i;j++){
                dp[i][j]=sqrt(pow(v[i].first-v[j].first,2)+pow(v[i].second-v[j].second,2));
            }
        }
        for(int i=0;i<v.size();i++){                    					// Copying. area to other side(Area is symmetrical).
            for(int j=i+1;j<v.size();j++){
                dp[i][j]=dp[j][i];
            }
        }
        
        // for(auto nums:dp){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        
        unordered_map<double, double>m;										// Stores dist b/w points in map, to get #occurances(equidistant pts).
        int count=0;														// Stores num. of boomerangs.
        for(int i=0;i<v.size();i++){	
            m.clear();														// Starting from a fresh map.
            for(int j=0;j<v.size();j++){									// Stores area from curr. point to all other pts.
                if(i!=j) m[dp[i][j]]++;
            }
            // for(auto it:m){
            //     cout<<"area: "<<it.first<<" value: "<<it.second<<endl;
            // }
            for(auto it=m.begin();it!=m.end();it++){						// Calc. #boomerangs with curr. point as first num. in tuple.
                count+=(it->second)*(it->second-1);
            }
            // cout<<"After row i: "<<i<<" count: "<<count<<endl;
        }
        // cout<<"The resutl si: "<<count<<endl;
        return count;														// Returning total #boomerangs.
        
    }
};