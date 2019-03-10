/*

//*******************************************************STAMPS - Stamps.***********************************************************
https://www.spoj.com/problems/STAMPS/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Greedy based solution. Here, since we need minimum friends to get the desired #stamps. We sort them and iter. from last
// until we get the desired stamps or we have iter. over all friends. If by the end of iter. if we still require stamps, we print
// impossible else we print the minm. #friends we had asked.







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

    int tests, target, friends;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>target>>friends;
        vector<int>v(friends,0);
        for(int i=0;i<friends;i++) cin>>v[i];
        sort(v.begin(), v.end());
        int res=0;
        for(int i=v.size()-1;i>=0 && target>0;i--){
            res++;
            target-=v[i];
        }
        cout<<"Scenario #"<<a<<":"<<endl;
        if(target<=0) cout<<res<<endl<<endl;
        else cout<<"impossible"<<endl<<endl;
    }

    return 0;
}
