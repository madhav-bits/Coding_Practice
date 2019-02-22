/*

//*******************************************************SAFECRAC - Crack the Safe.**************************************************
https://www.spoj.com/problems/SAFECRAC/




Time Complexity:O(m*n).                                                                                                                                                                                             
Space Complexity:O(m*n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(m*n).                                                   
// This is DFS and Dynamic Programming based solution. Here, we iterate over all possible ways and hash/store those values in the 
// DP array, we also take advantage of symmetry in the keyboard by updating symmetrical values, when one of symmetrical is obtained, 
// we update the other one also. Since, we have quite a few queries, we pre-computer the DP array for max. length possible and 
// store the results for all possible lengths in the question. For every query, we iterate over possible ways for each starting point
// and add all those steps and return them.



// dp[i][j] indicates #ways possible for (100000-i+1) steps(including this step) starting from number 'j'.









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




int mod=1000000007;
vector<int>dirs;


long long int getWays(vector<vector<int>>&dp, int curr, int psn, int len){

    if(psn==len) return 1;    
    if(dp[psn][curr]!=-1) return dp[psn][curr];    
    long long int res=0;
    int x=(curr-1)/3, y=(curr-1)%3;
    
    for(int i=0;i<4;i++){
        int dx=dirs[i], dy=dirs[i+1];
        if(x+dx<0 || y+dy<0 || y+dy>=3) continue;
        int fol=((x+dx)*3)+(y+dy);
        if(fol>9) continue;
        // cout<<"curr: "<<curr<<" and fol: "<<fol+1<<endl;
        long long int val=getWays(dp, fol+1, psn+1, len);
        res=(res+val)%mod;
    }


    if(curr==1 || curr==9){
        dp[psn][1]=res;
        dp[psn][9]=res;
    }
    else if(curr==4 || curr==8){
        dp[psn][4]=res;
        dp[psn][8]=res;
    }else if(curr==2 || curr==6){
        dp[psn][2]=res;
        dp[psn][6]=res;
    }
    else dp[psn][curr]=res;
    return res;

}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    dirs=vector<int>({-1,0,1,0,-1});
    int tests;
    cin>>tests;

    long long int res2=0;
    vector<vector<int>>dp(100000+1, vector<int>(11,-1));
    for(int i=1;i<=10;i++) dp[100000][i]=1;
    for(int i=1;i<=10;i++){
        long long val=getWays(dp,i,1,100000);
        // cout<<"start i: "<<i<<" and val: "<<val<<endl;
        res2=(res2+val)%mod;
    }
    // cout<<"final val; "<<res2<<endl;


    for(int a=0;a<tests;a++){
        int len;
        cin>>len;
        long long int res=0;
        int psn=100000-len+1;
        for(int i=1;i<=10;i++){
            res=(res+dp[psn][i])%mod;
        }
        cout<<res<<endl;
    }
    

    return 0;
}