/*

//*************************************************RMQSQ - Range Minimum Query.*****************************************************
https://www.spoj.com/problems/RMQSQ/




Time Complexity:O(n+logn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n+logn).                                                  
// Space Complexity:O(n).                                                   
// This is Segment Tree based solution. This question is typical application of Segment Tree. We gather results of intervals in 
// tree's nodes, we iter. over tree and return the vals. from nodes whose intervals lie inside the query interval, we return the 
// minm. of all those values.









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



void fillSegmenTree(vector<int>&v, vector<int>&segTree, int index, int low, int high){
    if(low>high) return ;
    // cout<<"low: "<<low<<" and high: "<<high<<endl;
    if(low==high){
        segTree[index]=v[low];
        return ;
    }
    int mid=(low+high)/2;
    fillSegmenTree(v,segTree,2*index+1, low, mid);
    fillSegmenTree(v,segTree, 2*index+2, mid+1, high);
    segTree[index]=min(segTree[2*index+1], segTree[2*index+2]);
    return ;
}


int getMin(vector<int>&segTree, int index, int low, int high, int start, int close){
    if(start>close) return INT_MAX;
    if(close<low || start>high) return INT_MAX;
    // cout<<"low: "<<low<<" and high: "<<high<<endl;
    if(start<=low && close>=high) return segTree[index];
    int mid=(low+high)/2;
    int lt=getMin(segTree, 2*index+1, low, mid, start, close);
    int rt=getMin(segTree, 2*index+2, mid+1, high, start, close);
    return min(lt, rt);
}



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int vals;
    cin>>vals;
    vector<int>v(vals);
    vector<int>segTree(4*vals+1, INT_MAX);
    for(int i=0;i<vals;i++){
        cin>>v[i];
    }
    fillSegmenTree(v,segTree, 0, 0,vals-1);
    // for(auto num:segTree) cout<<num<<" ";
    // cout<<endl;
    int queries, start, close;
    cin>>queries;
    for(int i=0;i<queries;i++){
        cin>>start>>close;
        // cout<<"start: "<<start<<" and close: "<<close<<endl;
        int res=getMin(segTree, 0, 0,vals-1,start, close);
        cout<<res<<endl;
    }
    return 0;
}