/*

//*******************************************************INVCNT - Inversion Count.*****************************************************
https://www.spoj.com/problems/INVCNT/




Time Complexity:O(nlogn).                                                   // O(logn) for each query.                                                                                                                                                                                      
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn).                                                 // O(logn) for each query.          
// Space Complexity:O(n).               
// THIS QUESTION IS PERFECT EXAMPLE FOR WORKING ON SEGMENT TREE AND LAZY PROPAGATION.                                    
// This is Segment Tree and lazy propagation based. Here, we want values which are less than curr. value after curr. index and since 
// the range of nums is very large, we can't form segment tree based on values, so we compress numbers by linking each number with its
// index and sorting them based on values. We now iter. from greater to smaller values. We look for #nums with smaller indices than 
// curr. num by performing range search from [0,curr.index-1]. We now push curr. index into the segment Tree. Since, the updates are 
// single index updates, the update would be needing leaves and lazy propagation would have no effect.
// 
// Here, if a update reaches a node, we update that node, then update lazy nodes 
// of child. If there is partial overlap with current node, we call both child and update curr. node based on both child's value.
// When queried for sum, we update curr. node if it's got any lazy value, if there is complete overlap, return the node's value, else
// if there is partial overlap, we query both child and return the sum of both queries.











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


#define ll long long


using namespace std;



struct comp{

    bool operator()(pair<int,int>&lt, pair<int,int>&rt){
        return lt.first>rt.first;
    }
};



void updateTree(vector<int>&segTree, vector<int>&lazy, int index, int low, int high, int targetIndex){
    if(low>high) return;
    // cout<<"low; "<<low<<" and high: "<<high<<endl;
    if(lazy[index]!=0){
        segTree[index]+=lazy[index];
        if(low!=high){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }

    if(targetIndex<=low && high<=targetIndex){                              // Here, we would be reaching leaves, so lazy tree is of no use.
        segTree[index]++;
        if(low!=high){
            lazy[2*index+1]+=1;
            lazy[2*index+2]+=1;
        }
        return ;
    }

    // if(low==high && low==targetIndex){                                   // This can also be used instead of above if condition.
    //     // cout<<"updated for low: "<<low<<endl;
    //     segTree[index]++;
    //     if(low!=high){
    //         lazy[2*index+1]+=1;
    //         lazy[2*index+2]+=1;
    //     }
    //     return ;
    // }

    // if(low==high) return ;
    int mid=(low+high)/2;
    if(targetIndex<=mid) updateTree(segTree, lazy, 2*index+1, low, mid, targetIndex);
    else updateTree(segTree, lazy, 2*index+2, mid+1, high, targetIndex);
    segTree[index]=segTree[2*index+1]+segTree[2*index+2];
    return ;
}



int getInverse(vector<int>&segTree, vector<int>&lazy, int index, int low, int high, int qStart, int qEnd){
    if(low>high) return 0;
    // cout<<"Searching and low; "<<low<<" and high: "<<high<<endl;
    if(lazy[index]!=0){
        segTree[index]+=lazy[index];
        if(low!=high){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(qStart<=low && high<=qEnd) return segTree[index];
    int mid=(low+high)/2;
    int res=0;
    if(mid<qEnd) res+=getInverse(segTree, lazy, 2*index+2, mid+1, high, qStart, qEnd);
    if(qStart<=mid) res+=getInverse(segTree, lazy, 2*index+1, low, mid, qStart, qEnd);
    return res;
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nums;
    cin>>tests;

    for(int a=0;a<tests;a++){
        cin>>nums;
        int num;
        vector<pair<int,int>>pairs(nums);
        for(int i=0;i<nums;i++){
            cin>>num;
            pairs[i]={num,i};
        }
        sort(pairs.begin(), pairs.end(), comp());
        // for(auto pr:pairs){
        //     cout<<"val: "<<pr.first<<" and index: "<<pr.second<<endl;
        // }
        vector<int>segTree(4*nums,0), lazy(4*nums+3, 0);
        vector<int>res(nums,0);                                             // Left it for debugging purpose.
        long long int ans=0;
        for(int i=0;i<nums;i++){
            int num=pairs[i].first, ind=pairs[i].second;
            int val=0;
            if(ind>0) val=getInverse(segTree,lazy, 0,0,nums-1, 0, ind-1);
            res[ind]=val;
            ans+=val;
            updateTree(segTree, lazy, 0, 0, nums-1, ind);
        }
        // for(auto num:res) cout<<num<<" ";
        // cout<<endl;
        cout<<ans<<endl;

    }
    return 0;
}