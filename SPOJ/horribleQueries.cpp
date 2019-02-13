/*

//*******************************************************HORRIBLE - Horrible Queries.*****************************************************
https://www.spoj.com/problems/HORRIBLE/




Time Complexity:O(logn).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn).                                                  
// Space Complexity:O(1).               
// THIS QUESTION IS PERFECT EXAMPLE FOR WORKING ON SEGMENT TREE AND LAZY PROPAGATION.                                    
// This is Segment Tree and lazy propagation based. Here, if a update reaches a node, we update that node, then update lazy nodes 
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



void addValues(vector<long long int>&v, vector<long long int>&lazy, ll index, ll start, ll close, ll low, ll high,ll value){

    if(lazy[index]!=0){
        v[index]+=lazy[index]*(close-start+1);
        if(start!=close){ 
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(start>close || low>close || high<start) return ;


    if(low<=start && close<=high){
        v[index]+=value*(close-start+1);
        if(start==close) return ;
        lazy[2*index+1]+=value;
        lazy[2*index+2]+=value;
        return ;
    }

    ll mid=(start+close)/2;
    addValues(v,lazy, 2*index+1,start,mid,low, high, value);
    addValues(v,lazy, 2*index+2,mid+1,close,low, high, value);
    v[index]=v[2*index+1]+v[2*index+2];

}


int getSum1(vector<long long int>& v, vector<long long int>&lazy, ll index, int start, int close, int low, int high){
    // if(start==close) return v[index];
    if(low<=start && close<=high) return v[index];
    int res=0;
    int mid=(start+close)/2;
    res+=(low<=mid)?getSum1(v,lazy, 2*index+1, start, mid, low, high):0;
    res+=(high>mid)?getSum1(v,lazy, 2*index+2,mid+1, close, low, high):0;
    return res;
}



long int getSum(vector<long long int> &v, vector<long long int>&lazy, ll index, ll start, ll close, ll low, ll high){
    
    if(lazy[index]!=0){
        v[index]+=lazy[index]*(close-start+1);
        if(start!=close){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }

    if(start>close || low>close || high<start) return 0;
    if(low<=start && close<=high){
        return v[index];    
    }
    ll res=0;
    ll mid=(start+close)/2;
    res+=getSum(v,lazy, 2*index+1, start, mid, low, high);
    res+=getSum(v,lazy, 2*index+2,mid+1, close, low, high);
    return res;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    ll tests;
    cin>>tests;
    for(int a=0;a<tests;a++){
        ll elem, queries;
        cin>>elem>>queries;
        vector<long long int>v(4*elem+1,0);
        vector<long long int>lazy(4*elem+1,0);        
        for(int i=0;i<queries;i++){
            ll type, low, high, value;
            cin>>type>>low>>high;
            if(type==0){
                cin>>value;
                addValues(v,lazy, 0, 0,elem-1,low-1,high-1,value);
            }else{
                // for(int j=0;j<v.size();j++) cout<<v[j]<<" ";
                // cout<<endl;
                ll res=getSum(v,lazy, 0, 0,elem-1, low-1, high-1);
                cout<<res<<endl;
            }
        }
    }
    return 0;
}