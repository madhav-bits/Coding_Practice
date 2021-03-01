/*
*
//**********************************************************1710. Maximum Units on a Truck.*************************************************

https://leetcode.com/problems/maximum-units-on-a-truck/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[11,5],[12,4],[13,7]]
26


// Time Complexity: O(nlogn).												// n-length of the boxes array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n-length of the boxes array.
// Space Complexity: O(1).	
// This algorithm is sorting based. As, we want to maximize the units into truck, for every box placed, we place the box with max units available. In this
// way we ensure that we are placing maxm. units in the boxes allowed.




class Solution {
public:
    int maximumUnits(vector<vector<int>>& v, int truckSize) {
        int res=0;
        for(int i=0;i<v.size();i++){										// Swapping unitsPerBox, numBoxes to make sorting easier.
            swap(v[i][0],v[i][1]);
        }
        sort(v.rbegin(),v.rend());											// Sort array in desc. order of unitsPerBox.
        int index=0;
        while(index<v.size() && truckSize){									// If space and boxes are available.
            int minm=min(truckSize,v[index][1]);							// Calc. space curr. set of boxes would occupy.
            res+=minm*v[index][0];
            v[index][1]-=minm;												// Removing boxes as they are loaded into truck.
            truckSize-=minm;												// Decreasing available space.
            index++;
        }
        return res;															// Returning the total #units loaded into truck.
    }
};