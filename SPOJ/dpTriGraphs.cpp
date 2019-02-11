/*

//*********************************************************ACPC10D - Tri graphsl.*********************************************************
https://www.spoj.com/problems/ACPC10D/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(1).                                                   
// This is Dynamic Programming based solution. Here, at every step we extract min. dist. of all possible paths leadig to index under
// consideration. At the end, we return the minm. dist target index from src index.







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
    int test=0;
    while(true){
        test++;
        int rows;
        cin>>rows;
        if(rows==0) break;
        vector<vector<long long int>>dp(2,vector<long long int>(3,0));
        for(int j=0;j<3;j++) cin>>dp[0][j];
        dp[0][0]=LONG_LONG_MAX;
        dp[0][2]=dp[0][2]+dp[0][1];
        // cout<<dp[0][0]<<" "<<dp[0][1]<<" "<<dp[0][2]<<endl;
        for(int i=1;i<rows;i++){
            for(int j=0;j<3;j++){
                cin>>dp[i%2][j];
                long long int lt=INT_MAX,rt=INT_MAX,sm=INT_MAX;
                if(j-1>=0){
                    lt=dp[(i-1)%2][j-1];
                    sm=dp[i%2][j-1];
                } 
                if(j+1<3) rt=dp[(i-1)%2][j+1];
                int minm=min(sm,min(dp[(i-1)%2][j],min(lt,rt)));
                dp[i%2][j]+=minm;
                // cout<<dp[i%2][j]<<" ";
            }
            // cout<<endl;
            
        }
        cout<<test<<". "<<dp[(rows-1)%2][1]<<endl;  
    }

    return 0;
}