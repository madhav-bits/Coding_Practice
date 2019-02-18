/*

//*****************************************************MBALL - Feline Olympics - Mouseball.************************************************
https://www.spoj.com/problems/MBALL/




Time Complexity:O(m*n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, since we need combinations of points(the points that constitute total score are
// equivalent when considered with different permutations of them). Here, we iterate over diff. scoring ways, and at each scoring way
// we iterate over diff. scores, if a score is possible to score(#ways !=0), we add that number to (curr. score+curr. scoring possib. 
// value). In this way we can ensure permutations of scoring possibilities that lead to same total score doesn't arise. At the end of
// iteration, we return #ways to get given target score with given scoring options.







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

    vector<int>scores({2,3,6,7,8});
    int tests;
    cin>>tests;

    for(int a=0;a<tests;a++){
        int target;
        cin>>target;
        // cout<<"target: "<<target<<endl;
        vector<long long int>dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<scores.size();i++){
            int score=scores[i];
            for(int j=0;j<target;j++){
                if(dp[j]!=0 && j+score<=target) dp[j+score]+=dp[j]; // If curr. score is possible and next score is within target, update it.
            }
        }
        // for(int i=0;i<=target;i++){
        //     cout<<"i: "<<i<<" and possib: "<<dp[i]<<endl;
        // }
        cout<<dp[target]<<endl;
    }
    

    return 0;
}