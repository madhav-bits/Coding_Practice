/*
//*************************************************VECTAR12 - Garden of Mangu.********************************************************
https://www.spoj.com/problems/VECTAR12/




Time Complexity:O(m*n).                                                     // O(1) for each query.
Space Complexity:O(m*n).

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                  // O(1) for each query.
// Space Complexity:O(m*n).
// This is Dynamic Programming based solution. Here, so as to reach target index, we have to make a vertical movement in every step,
// that makes getting #moves to have defined paths and makes it have optimal substructure property. So, we precompute the values for the
// largest rows, cols mentioned in the question. After precomputing, we iter. over queries and return the values directly from the DP
// array.






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

    int mod=1000000007;
    vector<vector<int>>dirs({{-1,-1},{-1,0},{-1,1}});
    vector<vector<int>>dp(7000, vector<int>(7000,0));
    dp[0][0]=1;

    for(int i=1;i<7000;i++){// int i=0;i<7000;i++
        for(int j=0;j<7000;j++){// int i=0;i<7000;i++
            if(j>i) break;
            for(int k=0;k<dirs.size();k++){
                int dx=dirs[k][0], dy=dirs[k][1];
                if(i+dx<0 || i+dx>=7000 || j+dy<0 || j+dy>=7000) continue;
                // if(i==1 && j==0) cout<<"dx; "<<dx<<"and dy: "<<dy<<endl;
                dp[i][j]=(dp[i][j]+dp[i+dx][j+dy])%mod;
            }
        }
    }

    // for(int i=5;i>=0;i--){
    //     for(int j=0;j<=5;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    int tests;
    cin>>tests;
    int row, col, moves;
    for(int a=0;a<tests;a++){
        cin>>row>>col;
        cout<<dp[row][col]<<endl;
    }


    return 0;
}
