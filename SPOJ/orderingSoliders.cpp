/*

//*************************************************ORDERS - Ordering the Soldiers.****************************************************
https://www.spoj.com/problems/ORDERS/




Time Complexity:O(n).                                                       // Each query would take O(logn).                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    // Each query would take O(logn).   
// Space Complexity:O(n).                                                   
// This is Segment Tree based solution. Here, as the solidiers to the right of soldier moves soldier 'i' from desired position as they
// would be having highest priority, we first fill up positions as requested by later soliders, then soldier 'i' would be looking at 
// 'k'th vacant position where 'k-1' vacant positions are for the soliders to left of him. So, we look in segtree for index, which has
// kth vacant index. We mask that index has occupied and update tree accordingly(As optim. I am updating it while looking for it).


// This can also be done using BIT as it of cumulative nature, but we are looking for index with kth vacancy. So, we need to perform
// binary search for finding that index on BIT(O(logn*logn)), as it would be slightly complicated, I stick with Segment Tree.








#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>




using namespace std;




void buildTree(vector<int>&segTree, int index, int low, int high){
    if(low>high) return; 

    if(low==high){
        segTree[index]=1;
        return; 
    }
    int mid=(low+high)/2;
    buildTree(segTree, 2*index+1, low, mid);
    buildTree(segTree, 2*index+2, mid+1, high);
    segTree[index]=segTree[2*index+1]+segTree[2*index+2];
    return ;
}



// void updateTree(vector<int>&segTree, int index, int low, int high, int targetIndex){
//     if(low>high) return; 

//     if(low==high && low==targetIndex){
//         segTree[index]--;
//         return ;
//     }

//     int mid=(low+high)/2;
//     if(targetIndex<=mid) updateTree(segTree,2*index+1,low, mid, targetIndex);
//     else if(targetIndex>mid) updateTree(segTree, 2*index+2, mid+1, high, targetIndex);
//     segTree[index]=segTree[2*index+1]+segTree[2*index+2];
//     return ;
// }


int getIndex(vector<int>&segTree, int index, int low, int high, int targetPsn){
    if(low>high) return 0;


    // cout<<"low: "<<low<<" and high; "<<high<<" and targetPsn: "<<targetPsn<<endl;
    if(low==high){
        // if(targetPsn==0)
            segTree[index]=0;
        return low;
    }

    int mid=(low+high)/2;
    int res=-1;
    if(segTree[2*index+1]>=targetPsn) res=getIndex(segTree, 2*index+1, low, mid, targetPsn);
    else res=getIndex(segTree, 2*index+2, mid+1, high, targetPsn-segTree[2*index+1]);
    segTree[index]=segTree[2*index+1]+segTree[2*index+2];
    return res;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nums;
    cin>>tests;
    for(int a=0;a<tests;a++){
        cin>>nums;
        // cout<<"elem: "<<nums<<endl;
        vector<int>segTree(4*nums,0);
        vector<int>v(nums,0);
        for(int i=0;i<nums;i++) cin>>v[i];
        buildTree(segTree, 0, 0, nums-1);
        vector<int>res;
        for(int i=nums-1;i>=0;i--){
            int psn=i-v[i];
            // cout<<"targetPsn: "<<psn<<endl;
            int index=getIndex(segTree, 0, 0, nums-1, psn+1);
            // cout<<"index: "<<index+1<<endl;
            res.push_back(index+1);
            // updateTree(segTree, 0,0, nums-1, index);
        }
        reverse(res.begin(), res.end());
        for(auto num:res) cout<<num<<" ";
        cout<<endl;
    }

    return 0;
}
