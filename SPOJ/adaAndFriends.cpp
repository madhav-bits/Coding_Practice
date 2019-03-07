/*

//**************************************************ADAFRIEN - Ada and Friends.******************************************************
https://www.spoj.com/problems/ADAFRIEN/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Map and Sorting based solution. Here, so as to save maxm. money she has to unfriend top 'k' costly friends, which we can 
// get by adding cost of different instances of same friend using map, then inversely sorting the costs, choosing top 'k' friends and
// returning their total cost.









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






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int friends, remove;
    cin>>friends>>remove;
    unordered_map<string,long long int>m;
    string s;
    int cost;
    for(int i=0;i<friends;i++){
        cin>>s>>cost;
        m[s]+=cost;
    }
    vector<long long int>v;
    for(auto it=m.begin();it!=m.end();it++) v.push_back(it->second);
    sort(v.rbegin(), v.rend());
    long long int res=0;
    for(int i=0;i<remove && i<v.size();i++) res+=v[i];
    cout<<res<<endl;

    return 0;
}
