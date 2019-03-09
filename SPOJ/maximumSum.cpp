/*

//*********************************************************KGSS - Maximum Sum.*******************************************************
https://www.spoj.com/problems/KGSS/




Time Complexity:O(n).                                                       // Query, update would take O(logn) time.                                                                                                                                                                                         
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    // Query, update would take O(logn) time.
// Space Complexity:O(n).                                            
// This is Segment Tree based. Here, we first initiailze the segment tree based on intitial vector. Next, we perform queries/updates
// on segment tree accordingly. Here, in case of query, we extract values from those intervals which are completely inside query
// range and try to get max. two values of them. At each node, we maintain a list of top two values in that range. In case of update,
// we reach down to leaf and update all it's parents in recursion.













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



void buildTree(vector<pair<int,int>>&segTree, vector<int>&v, int index, int low, int high){
    if(low>high) return ;
    if(low==high){
        segTree[index].first=v[low];
        segTree[index].second=INT_MIN;
        return ;
    }
    int mid=(low+high)/2;
    buildTree(segTree, v, 2*index+1, low, mid);
    buildTree(segTree,v,2*index+2, mid+1, high);
    int maxL=segTree[2*index+1].first, maxR=segTree[2*index+2].first;
    int minL=segTree[2*index+1].second, minR=segTree[2*index+2].second;
    segTree[index].first=max(maxL, maxR);
    segTree[index].second=max(min(maxL, maxR), max(minL, minR));
    return ;
}






void updateTree(vector<pair<int,int>>&segTree, int index, int low, int high, int qIndex, int qValue){
    if(low>high) return ;

    if(low==high && low==qIndex){
        segTree[index].first=qValue;
        segTree[index].second=INT_MIN;
        return ;
    }
    int mid=(low+high)/2;
    if(qIndex<=mid) updateTree(segTree,2*index+1, low, mid, qIndex, qValue);
    else updateTree(segTree,2*index+2, mid+1, high, qIndex, qValue);
    int maxL=segTree[2*index+1].first, maxR=segTree[2*index+2].first;

    int minL=segTree[2*index+1].second, minR=segTree[2*index+2].second;
    segTree[index].first=max(maxL, maxR);
    segTree[index].second=max(min(maxL, maxR), max(minL, minR));
    return ;
}





pair<int,int>getMax(vector<pair<int,int>>&segTree,int index, int low, int high, int qStart, int qClose){
    if(low>high) return {INT_MIN, INT_MIN};
    if(qStart<=low && high<=qClose) return segTree[index];
    int mid=(low+high)/2;
    pair<int,int>lt={INT_MIN, INT_MIN}, rt={INT_MIN, INT_MIN}, res={INT_MIN, INT_MIN};
    if(qStart<=mid) lt=getMax(segTree, 2*index+1, low, mid, qStart, qClose);
    if(qClose>mid) rt=getMax(segTree, 2*index+2, mid+1, high, qStart, qClose);

    res.first=max(lt.first, rt.first);
    res.second=max(min(lt.first, rt.first), max(lt.second, rt.second));
    return res;
}





int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int nums, queries;
    cin>>nums;
    vector<int>v(nums);
    for(int i=0;i<nums;i++) cin>>v[i];
    vector<pair<int,int>>segTree(4*nums,{-1,-1});
    buildTree(segTree, v, 0,0,nums-1);
    cin>>queries;
    string s="";
    int start=-1,close=-1;
    for(int a=0;a<queries;a++){
        cin>>s>>start>>close;
        if(s=="Q"){
            // cout<<"Query: start: "<<start<<" and close: "<<close<<endl;
            pair<int,int> res=getMax(segTree,0,0,nums-1, start-1, close-1);
            cout<<res.first+res.second<<endl;
        }else{
            updateTree(segTree,0,0,nums-1, start-1, close);
        }
    }
    return 0;
}