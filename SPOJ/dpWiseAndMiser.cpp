/*

//*****************************************************MISERMAN - Wise And Miser.*********************************************************
https://www.spoj.com/problems/MISERMAN/




Time Complexity:O(m*n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, at every step, we calc. min. cost till that index from the start, which depends on
// values accumulated in prev. row. Thus, we calc. min. cost to board all buses available for target dest.. We compare the costs of all 
// the buses and return the minm. cost.







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
    int m;int n;
    cin>>m>>n;
    vector<vector<int>>v(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>>dp(2,vector<int>(n,0));
    for(int j=0;j<n;j++) dp[0][j]=v[0][j];

    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i%2][j]=0;
            int val1=INT_MAX,val2=INT_MAX,val3=dp[(i-1)%2][j];;
            if(j-1>=0) val1=dp[(i-1)%2][j-1];
            if(j+1<n) val2=dp[(i-1)%2][j+1];
            dp[i%2][j]=v[i][j]+min(val3,min(val1,val2));
            // cout<<dp[i%2][j]<<" ";
        }
        // cout<<endl;
    }
    int res=INT_MAX;
    for(int j=0;j<n;j++) res=min(res,dp[(m-1)%2][j]);
    cout<<res<<endl;
    return 0;
}