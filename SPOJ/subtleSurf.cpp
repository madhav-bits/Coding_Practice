/*

//****************************************************UOFTCC - A Subtle Surf.********************************************************
https://www.spoj.com/problems/UOFTCC/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Greedy/Sliding Window based solution. Here, since we need minm. steps to reach maxm. channel in each day. We sort given
// channels, start from first channel,  we iter. over channels till curr+maxDiff>=iter. channel, once we reach moved past this cdn,
// that index isn't reachable from curr. channel. So, we focus on last reachable index, if it is equal to curr. channel, we need
// not even take this step. So, we return steps taken till curr. index. If both are different, then we take a step, inc. the steps var.
// make this the curr. channel for next iter. Thus, we reach maxm. channel reachable from first channel. We multiply #steps with 
// minTime to get total time required to reach max. channel. We print max. girly channel value and time required to reach it.







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

    
    int days;
    cin>>days;
    int channels, maxDiff, minTime;
    for(int a=0;a<days;a++){
        cin>>channels>>maxDiff>>minTime;
        vector<int>v(channels,0);
        for(int i=0;i<channels;i++) cin>>v[i];
        int curr=v[0];
        sort(v.begin(), v.end());
        int index=0;
        while(index<v.size() && v[index]<=curr) index++;
        index--;
        int steps=0;
        int i=index;
        for(;i<v.size();i++){
            curr=v[i];
            while(i<v.size() && curr+maxDiff>=v[i]) i++;
            i--;
            if(v[i]==curr) break;                                           // If max. reachable channel form curr. has same value as curr, then we can stop iter. and return #steps till then.
            steps++;
            i--;
        }
        cout<<v[i]<<" "<<minTime*steps<<endl;
    }

    return 0;
}
