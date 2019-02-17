/*

//*************************************************COUNT - Another Very Easy Problem! WOW!!!.**********************************************
hhttps://www.spoj.com/problems/COUNT/




Time Complexity:O(m*n).                                                                                                                                                                                             
Space Complexity:O(m*n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(m*n).                                                   
// This is Dynamic Programming based problem. This problem can be converted to problem where each truck can contain zero or more 
// computers, in that case the recurrence equation gets easy, dp[i][j]=dp[i-j][j]+dp[i][j-1], that is a computer can be placed in 
// a truck or skipped. As, a problem where each truck has >=1 computers, it is translated to (n-k) comp, k trucks, where each can 
// contain >=0 computers on each truck. We can return dp[n-k][k] at the end of iteration.







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

    int mod=1988;
    int comp,buses;
    cin>>comp>>buses;
    while(comp!=0 || buses!=0){
        vector<vector<int>>dp(comp+1, vector<int>(buses+1,0));

        for(int j=0;j<=buses;j++) dp[0][j]=1;

        for(int i=1;i<=comp;i++){
            for(int j=1;j<=buses;j++){
                if(i-j>=0)
                    dp[i][j]=(dp[i][j]+dp[i-j][j])%mod;

                dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
                // cout<<
            }
        }
        cout<<dp[comp-buses][buses]<<endl;
        cin>>comp>>buses;
    }

    return 0;
}