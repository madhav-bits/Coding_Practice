/*
*
//**********************************************************1146. Snapshot Array.*****************************************************

https://leetcode.com/problems/snapshot-array/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
["SnapshotArray","snap","snap","set","snap","get","set","get","snap","get"]
[[1],[],[],[0,4],[],[0,1],[0,12],[0,1],[],[0,3]]



// Time Complexity: O(logm).												// m-#snapshots till that find query.
// Space Complexity: O(n+l).												// n- snapShot array size, l-#updates.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logm).												// m-#snapshots till that find query.
// Space Complexity: O(n+l).												// n- snapShot array size, l-#updates.
// This algorithm is Binary Search based. Here, we store the changes in the index values in those respective indices while using snapNums to track the 
// changes. If we change an index's value multiple times in the snap duration, we update the last value if not we append new val and snapNum at the end.
// When get is called, we do Binary Search on that index for a snapNum<=required snapNum.











class SnapshotArray {
public:
    int snapNum;
    vector<vector<pair<int,int>>>snapShots;									// index:[snapNum, val] format tracks snapNums and updated vals in resp. indices.		
    SnapshotArray(int length) {
        snapShots=vector<vector<pair<int,int>>>(length);
        for(int i=0;i<length;i++){
            snapShots[i].push_back({-1,0});									// Init. snapShot array with default snapNums and default vals.
        }
        snapNum=0;															// Init. snapShot Number value.
    }
    
    void set(int index, int val) {
        if(snapShots[index].back().first==snapNum) snapShots[index].back().second=val;// Updating the index with the snapNum, updated value.
        else snapShots[index].push_back({snapNum, val});					// If curr. change is first change in this Snap, we add new entry into that index.
        return ; 
    }
    
    int snap() {
        snapNum++;															// Updating the snap count.
        return snapNum-1;
    }
    
    int get(int index, int snap_id) {
        int low=0, high=snapShots[index].size()-1;
        while(low<high){													// Binary Search for the required snap_id in that index of snapShot array.
            // cout<<"low: "<<low<<" and high: "<<high<<endl;
            int mid=1+((low+high)/2);
            if(snapShots[index][mid].first<=snap_id) low=mid;
            else high=mid-1;
        }
        return snapShots[index][low].second;								// Returning val from greatest snapNum<=required snapNum.
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

