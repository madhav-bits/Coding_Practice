/*

//********************************************************BAT3 - BATMAN3.************************************************************
https://www.spoj.com/problems/BAT3/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. This question is slight modification of Longest Increasing subsequence, however we are
// here trying to get Longest Decareasing Subsequence with small change in case of robin. So, we handle robin separately. Here, 
// while working on an index, we iter. over prev. indices and try to update maxm. #soldiers at curr. index based on prev. indices with
// height>curr. index's height and also based on robin's index irrespective of whether the height at that index. Since, we need maxm.
// #soldiers gatherable, we try to update final result(Max. #soldiers gatherable) at every index.









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
    int nums, robin;
    for(int a=0;a<tests;a++){
        cin>>nums>>robin;
        vector<int>v(nums,0);
        for(int i=0;i<nums;i++) cin>>v[i];
        vector<int>dp(nums,0);
        int res=1;
        dp[0]=1;
        for(int j=1;j<v.size();j++){
            dp[j]=1;
            for(int i=0;i<j;i++){
                if(v[i]>v[j] || robin ==i) dp[j]=max(dp[j], 1+dp[i]);
            }
            res=max(res, dp[j]);
        }
        cout<<res<<endl;
    }
    return 0;
}
