/*

//*******************************************************CODEM5 - Problem5.***********************************************************
https://www.spoj.com/problems/CODEM5/




Time Complexity:O(n*m).                                                     //  m is the target number.                                                                                                                                                                                      
Space Complexity:O(m).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n*m).                                                  //  m is the target number.    
// Space Complexity:O(m).                                                   
// This is Dynamic Programming based solution. This is taking up any of the given numbers to make up the target number, while doing
// this, we will try to update the target sum(indices) with minm. #elements used for this sum. At the end of iter., we will have 
// minm. #nums to coins to get this sum in the (target+1) numbered index, we return the value in this index.







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

    int tests;
    cin>>tests;
    int nums, target;
    for(int a=0;a<tests;a++){
        cin>>nums>>target;
        vector<int>dp(target+1, INT_MAX);
        dp[0]=0;
        int num;
        for(int i=0;i<nums;i++){
            cin>>num;
            for(int j=target;j>0;j--){
                if(j-num>=0 && dp[j-num]!=INT_MAX) dp[j]=min(dp[j], dp[j-num]+1);
            }
        }
        if(dp[target]==INT_MAX) cout<<"impossible"<<endl;
        else cout<<dp[target]<<endl;
    }

    return 0;
}
