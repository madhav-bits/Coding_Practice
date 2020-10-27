/*
*
//***********************************************1620. Coordinate With Maximum Network Quality.****************************************

https://leetcode.com/problems/coordinate-with-maximum-network-quality/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.






// Time Complexity: O(n*k^2).  												// n- #towers, k- range of x,y-indices of towers.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k^2).												// n- #towers, k- range of x,y-indices of towers.
// Space Complexity: O(1).	
// This algorithm is iteration based. Since we are trying to find a spot with maxm. quality. As, all the points are in Quadrant 1
// b/w [0,0] and [50, 50], so the desired maxm. quality point would also be in this range, as if we are moving away from this range,
// the contribution from all the points would be decreasing as the dist. from all the points would increase. 







class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int>res;
        int maxQuality=-1;
        for(int i=0;i<=50;i++){												// Range of indices the target index can be present.
            for(int j=0;j<=50;j++){
                int qual=0;
                for(int k=0;k<towers.size();k++){							// Iter. over all towers.
                    if(towers[k][0]<i-radius || towers[k][0]>i+radius) continue;// If it is > radius dist. from the point along x-axis. 
                    if(towers[k][1]<j-radius || towers[k][1]>j+radius) continue;// If it is > radius dist. from the point along y-axis.
                    int dx=towers[k][0]-i, dy=towers[k][1]-j;
                    double dist=sqrt(dx*dx+dy*dy);							// Calc. dist b/w point and curr. tower.
                    int val=1.0*towers[k][2]/(1.0+dist);
                    if(dist>radius) continue;								// If dist. >radius ignore quality bec. of tower.
                    qual+=val;
                }
                // if(i==2 && j==1) cout<<"qual: "<<qual<<endl;
                if(qual>maxQuality){										// Trying to track the point with maxm. quality.
                    maxQuality=qual;
                    res={i,j};
                }
            }
        }
        // cout<<"maxQ: "<<maxQuality<<endl;
        return res;															// Returning point with maxm. quality.
    }
};