/*
*
//**********************************************************1057. Campus Bikes.*********************************************************

https://leetcode.com/problems/campus-bikes/


Bikes and workers are provided in arrays which stores their indices. We have to assign bikes to workers closest to them. Dist<worker index<bike index is
the precedence order to be used to deal ambiguity while assigning bikes.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[0,0],[2,1]]
[[1,2],[3,3]]
[[0,0],[1,1],[2,0]]
[[1,0],[2,2],[2,1]]




// Time Complexity: O(m*n*log(m*n)).										// m-#workers, n-#bikes.
// Space Complexity: O(m*n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n*log(m*n)).										// m-#workers, n-#bikes.
// Space Complexity: O(m*n).	
// This algorithm is Sorting based. Here, as we are assigning bikes to workers, dist takes precedence first, if they are equal worker index takes 
// precedence, if they are multiple pairs with same worker id, bike id takes precedence. So, we form array of arrays of pairs where row indicates the
// Manhattan distance and pairs in the row indicates the pairs with that distance. We iter. over it row wise and skip all indices whose corresponding 
// workers or bikes are already assigned. The first pair whose contents aren't assigned are the pair with least distance waiting to get assigned and
// we assign them. In this way we assign bikes to workers meeting the requirements.











class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int,int>>>v(2001);								// Stores worker, bike pairs indices with that distance.
        for(int i=0;i<workers.size();i++){									// Updating dist array with corresponding pairs.
            for(int j=0;j<bikes.size();j++){
                int dist=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                v[dist].push_back({i,j});
            }
        }
        vector<int>res(workers.size(),-1);									// Stores bike id assigned to each worker.
        vector<bool>bikesUsed(bikes.size(),false);							// Marks assigned bikes.
        for(int i=0;i<=2000;i++){
            for(int j=0;j<v[i].size();j++){
                // cout<<"cccchecking worker: "<<v[i][j].first<<" and bike: "<<v[i][j].second<<" with dist: "<<i<<endl;
                if(res[v[i][j].first]!=-1 || bikesUsed[v[i][j].second]==true) continue;// Skip all pairs whose contents are already assigned.
                res[v[i][j].first]=v[i][j].second;							// Updating final res array with bike index.
                bikesUsed[v[i][j].second]=true;								// Marking bike as assigned.
                // cout<<"worker: "<<v[i][j].first<<" gets bike: "<<v[i][j].second<<" with dist: "<<i<<endl;
            }
        }
        return res;															// Returning array which indicates bikes assigned to each worker.
    }
};
