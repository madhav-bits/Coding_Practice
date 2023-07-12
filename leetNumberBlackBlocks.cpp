/*
*
//******************************************************2768. Number of Black Blocks.******************************************************

https://leetcode.com/problems/number-of-black-blocks/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3
3
[[0,0]]
3
3
[[0,0],[1,1],[0,2]]
3
8
[[0,0],[0,3],[0,6],[1,3],[1,2],[2,4],[2,7]]
20
20
[[0,0],[0,3],[0,6],[1,3],[1,2],[2,4],[2,7]]
32
32
[[17,29],[29,16],[19,20],[18,9],[16,7],[20,25],[22,19],[4,9],[14,17],[6,23],[2,2],[20,1],[8,7],[4,7],[14,14],[10,10],[1,27],[18,23],[6,30],[8,18],[26,23],[25,8],[5,6],[3,4]]



// Time Complexity: O(n*4*4)=O(n).											// #indices with black color.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*4*4)=O(n).											// #indices with black color.
// Space Complexity: O(n).	
// This algorithm is observation+HashSet based. Here, since the area of indices coverage is too high, so we iter. over indices with black color and store them
// for further processing. Now, we iter. these indices, for each index we find rectangles which it will be part of, calc. #black indices in those rectangles
// and update the corresponding index in res array: res[cnt]++;. For ex: if one of the rects. of (i,j) gets a count of 3, that means we revisit this (i,j)
// 2 more times when we visit those 2 other indices with black color, same would be the case for all rect. with cnt>1, so we update the res array accordingly
// ex: res[3]=res[3]/3, res[4]=res[4]/4 and subtract nonZero indices's total from total #rectangles possible and update '0' index with it and return res.




// This discussion forum link some explanation for this approach:
// https://leetcode.com/problems/number-of-black-blocks/discuss/3737064/Hashset







class Solution {
public:
    vector<long long> countBlackBlocks(int rows, int cols, vector<vector<int>>& v) {
        vector<long long int>res(5,0);
        unordered_set<long long int>st;
        for(vector<int>&u:v) st.insert((1ll*100000*u[0])+u[1]);
        
        for(vector<int>&u:v) {
            for(int x=max(0, u[0]-1);x<=min(u[0], rows-2);x++) {			// Iter. over all rects. in which this index would be part of.
                for(int y=max(0,u[1]-1);y<=min(u[1], cols-2);y++) {
                    int cnt=st.count((1ll*100000*x)+y)+st.count((1ll*100000*x)+y+1)+st.count((1ll*100000*(x+1))+y)+st.count((1ll*100000*(x+1))+y+1);
																			// Calc. #black indices in this rect.
                    // cout<<"x: "<<x<<" and y: "<<y<<" and cnt: "<<cnt<<endl;
                    res[cnt]++;												// Updating res array's cnt index.
                }
            }
        }
        res[2]/=2;															// Removing the duplicate rect. visits.
        res[3]/=3;
        res[4]/=4;
        long long int nonZero=accumulate(res.begin(), res.end(),0);			// Calc. #rects with nonZero black indices.
        res[0]=1ll*(rows-1)*(cols-1)-nonZero;
        return res;															// Returning the res array showing #rects with index #black indices in them.
    }
};

