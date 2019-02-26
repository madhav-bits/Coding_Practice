/*
//***********************************************ALTSEQ - Alternating Sequences.*****************************************************
https://www.spoj.com/problems/ALTSEQ/




Time Complexity:O(n^2).
Space Complexity:O(n).

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).
// Space Complexity:O(n).
// This is Dynamic Programming based solution. Here, at every step, we form the atlernating sequence by comparing the curr. num with
// opposite sign value's array and where each value is linked to max. alt. len which it can form, after comparing curr. val with
// all those values, we extract max. len alternating sequence from them and assign it to curr. value and push it in it's resp(pos/neg)
// array along with maxLen. After obtaining every len's maxLen, we try to update the total array's alternating seq. maxLen. Print this
// value at the end of iteration.







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


int getLen(vector<pair<int,int>>&v, int val){
    int res=1;
    for(int i=0;i<v.size();i++){
        if(val>v[i].first && res<v[i].second+1) res=v[i].second+1;
    }
    return res;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int len;
    cin>>len;
    vector<int>v(len,0);
    for(int a=0;a<len;a++) cin>>v[a];
    vector<pair<int,int>>pos, neg;
    int res=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>0){
            int maxm=getLen(neg,v[i]);
            if(maxm>res) res=maxm;
            pos.push_back({v[i], maxm});
        }else{
            int maxm=getLen(pos, abs(v[i]));
            if(maxm>res) res=maxm;
            neg.push_back({abs(v[i]), maxm});
        }
    }
    cout<<res<<endl;


    return 0;
}
