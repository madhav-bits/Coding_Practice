/*

//*******************************************************EDIST - Edit distance.***********************************************************
https://www.spoj.com/problems/EDIST/




Time Complexity:O(m*n).                                                                                                                                                                                             
Space Complexity:O(m).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(m*n).                                                   
// This is Dynamic Programming based solution. Here, at each step we try to get min. moves to equal target, src stirngs till that index
// by choosing a step form one of three methods available. At the end of iteration, we get the min. moves to match entire given target
// string to dest. string.







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
    // cout<<tests<<endl;
    for(int a=0;a<tests;a++){
        string s,t;
        cin>>s>>t;
        vector<vector<int>>dp(s.length()+1, vector<int>(t.length()+1, 0));
        for(int i=0;i<dp.size();i++) dp[i][0]=i;
        for(int j=0;j<dp[0].size();j++) dp[0][j]=j;

        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                int dist=(s[i-1]==t[j-1])?dp[i-1][j-1]:(dp[i-1][j-1]+1);
                dp[i][j]=min(dp[i][j],dist);
            }
        }
        // for(auto nums:dp){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        cout<<dp[s.length()][t.length()]<<endl;
    }
    // return 0;
}









//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(m).                                                   
// This is Dynamic Programming based solution. This is same as the above solution, except that is space optimized version of above
// solution.













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
    // cout<<tests<<endl;
    for(int a=0;a<tests;a++){
        string s,t;
        cin>>s>>t;
        vector<vector<int>>dp(2, vector<int>(t.length()+1, 0));
        // for(int i=0;i<dp.size();i++) dp[i][0]=i;
        for(int j=0;j<dp[0].size();j++) dp[0][j]=j;
        for(int i=1;i<=s.length();i++){
            dp[i%2][0]=i;
            for(int j=1;j<dp[0].size();j++){
                // dp[i%2][j]=0;
                dp[i%2][j]=min(dp[(i-1)%2][j],dp[i%2][j-1])+1;
                int dist=(s[i-1]==t[j-1])?dp[(i-1)%2][j-1]:(dp[(i-1)%2][j-1]+1);
                dp[i%2][j]=min(dp[i%2][j],dist);
            }
        }
        // for(auto nums:dp){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        cout<<dp[s.length()%2][t.length()]<<endl;
    }
    // return 0;
}