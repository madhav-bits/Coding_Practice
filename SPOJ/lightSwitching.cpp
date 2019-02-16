/*

//*********************************************************LITE - Light Switching.********************************************************
https://www.spoj.com/problems/LITE/




Time Complexity:O(logn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn).                                                  
// Space Complexity:O(n).                                                   
// This is Segment Tree based solution. Here, in the lazy tree, we save #inversions each index in that range needs to make. If #invers-
// -ions are odd, then we invert, if not we just ignore the count and pass on the inversions to the count. We maintain a stable 
// Segment Tree, which gives results for range queries.








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



void addValues(vector<long long int>&v, vector<long long int>&lazy, ll index, ll start, ll close, ll low, ll high){

    if(lazy[index]!=0){
        if(lazy[index]%2==1)
            v[index]=(close-start+1)-v[index];
        if(start!=close){ 
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(start>close || low>close || high<start) return ;


    if(low<=start && close<=high){
        v[index]=(close-start+1)-v[index];
        if(start==close) return ;
        lazy[2*index+1]+=1;
        lazy[2*index+2]+=1;
        return ;
    }

    ll mid=(start+close)/2;
    addValues(v,lazy, 2*index+1,start,mid,low, high);
    addValues(v,lazy, 2*index+2,mid+1,close,low, high);
    v[index]=v[2*index+1]+v[2*index+2];

}





long int getSum(vector<long long int> &v, vector<long long int>&lazy, ll index, ll start, ll close, ll low, ll high){
    
    if(lazy[index]!=0){
        if(lazy[index]%2==1)
            v[index]=(close-start+1)-v[index];
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


    int elem;
    cin>>elem;
    int queries;
    cin>>queries;
    // cout<<" elem: "<<elem<<" and queries: "<<queries<<endl;
    vector<long long int>v(4*elem+1,0);
    vector<long long int>lazy(4*elem+1,0);
    for(int i=0;i<queries;i++){
        ll type, low, high;
        cin>>type>>low>>high;
        // cout<<"type: "<<type<<" low; "<<low<<" high: "<<high<<endl;
        if(type==0){
            addValues(v,lazy, 0, 0,elem-1,low-1,high-1);
        }else{
            ll res=getSum(v,lazy, 0, 0,elem-1, low-1, high-1);
            cout<<res<<endl;
        }
    }
    return 0;
}