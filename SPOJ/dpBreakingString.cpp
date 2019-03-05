/*

//*************************************************BRKSTRNG - Breaking String.*******************************************************
https://www.spoj.com/problems/BRKSTRNG/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n^2).                                                      

*/


//***********************************************************Solution 1.*************************************************************
//**************************************************THIS IS NOT SPOJ ACCEPTED CODE.**************************************************
// Time Complexity:O(n^3).                                                  
// Space Complexity:O(n^2).                                                   
// This is Dynamic Programming based solution. This is typical DP implementation, where to find the DP value for a substring, we
// iter. all possible breaks and choose the optimum one. Which I had implemented in both Top Down and Bottom To Top. I am getting
// TLE errors.


// This question is specifically answerable by this Knuth Optimization of DP Technique.









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




long long int getMinCost(vector<vector<long long int>>&dp, vector<int>&v, int low, int high, int start, int close){
    if(low>high) return 0;
    if(dp[low][high]!=-1) return dp[low][high];
    int cost=close-start+1;
    long long int res=LONG_LONG_MAX;
    for(int i=low;i<=high;i++){
        int psn=v[i]-1;
        long long int val=getMinCost(dp, v, low, i-1, start, psn)+getMinCost(dp, v, i+1, high, psn+1, close);
        if(cost+val<res) res=cost+val;
        // res=min(res, cost+val);
    }
    dp[low][high]=res;
    // cout<<"start: "<<start<<" and close; "<<close<<" and cost: "<<res<<endl;
    return res;
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int length, breaks;
    cin>>length;
    while(!cin.eof()){
        cin>>breaks;
        vector<int>v(breaks);
        for(int a=0;a<breaks;a++){
            cin>>v[a];
        }
        vector<vector<long long int>>dp(breaks+1, vector<long long int>(breaks+1, 0));
        long long int res;
        // res=getMinCost(dp, v, 0, breaks-1, 0, length-1);
        for(int j=0;j<v.size();j++){
            for(int i=j;i>=0;i--){
                long long int cost;
                long long int high=(j+1<v.size())?v[j+1]:(length);
                long long int low=(i-1>=0)?v[i-1]+1:1;
                cost=high-low+1;
                // cout<<"i: "<<i<<" and j: "<<j<<" and cost: "<<cost<<endl;
                long long int minm=LONG_MAX;
                for(int k=j;k>=i;k--){
                    long long int part1, part2;
                    part1=(k+1>j)?0:dp[k+1][j];
                    part2=(k-1<i)?0:dp[i][k-1];
                    minm=min(minm, part2+part1+cost);
                }
                dp[i][j]=minm;
            }
        }

        // for(int i=0;i<v.size();i++){
        //     for(int j=0;j<v.size();j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }


        cout<<dp[0][v.size()-1]<<endl;


        cin>>length;
    }
    

    return 0;
}








//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n^2).                                                   
// This is Knuth Optimization of Dynamic Programming based solution. As, this follows Quadrangle inequality and monotonic in nature.
// We can apply this optimization. Where the optimum point for new substring[i,j] is in between optimum point of substr [i][j-1] and
// [i+1][j], so we iter. only b/w these points while calculating the optimum index for curr. substring. This optimizes algo. from 
// O(n^3) to O(n^2).




// The optimization is listed here: http://codeforces.com/blog/entry/8219
// A link to a code discussing the same: https://github.com/gabrielrussoc/competitive-programming/blob/master/spoj/brkstrng.cpp
// This question is asked in another OJ:
// http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=2860










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




long long int dp[1005][1005], optim[1005][1005];



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int length, breaks;
    cin>>length;
    while(!cin.eof()){
        cin>>breaks;
        vector<int>v(breaks+2,0);
        for(int i=1;i<=breaks;i++){
            cin>>v[i];
        }
        v[breaks+1]=length;
        for(int i=0;i<=breaks;i++){
            optim[i][i+1]=i+1;
            dp[i][i+1]=0;
            // dp[i][i]=INT_MAX;
        }
        // dp[breaks+1][breaks+1]=INT_MAX;
        for(int len=2;len<=breaks+1;len++){
            for(int i=0;i+len<=breaks+1;i++){
                int left=optim[i][i+len-1], right=optim[i+1][i+len];
                int minm=INT_MAX, minIndex=-1;
                for(int j=left;j<=right;j++){
                    int cost=dp[i][j]+dp[j][i+len]+v[i+len]-v[i];
                    if(cost<minm){
                        minm=cost;
                        minIndex=j;
                    }
                }
                dp[i][i+len]=minm;
                optim[i][i+len]=minIndex;
            }
        }
        cout<<dp[0][breaks+1]<<endl;
        cin>>length;
    }
    

    return 0;
}


