/*

//*******************************************************COINS - Bytelandian gold coins.***************************************************
https://www.spoj.com/problems/COINS/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, we can approach form Bottom To Top, for which I am getting TLE error as we are
// calculating #coins for lot of numbers, which are not useful in calculating the coins obtained from given number. In case of Top To
// Bottom, we only touch those numbers which are needed to calculate max #coins for given number.







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


 


long long int getMaxSum(long long int num, unordered_map<int,long long int>&m){
    if(m.count(num)==1) return m[num];
    // cout<<"inside fn. with num: "<<num<<endl;
    long long int res=max(num, getMaxSum(num/2, m)+getMaxSum(num/3, m)+getMaxSum(num/4, m));
    m[num]=res;
    return res;
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    // while(!cin.eof()){                                                   // Bottom To Top DP is giving TLE error.
    //     int nums;
    //     cin>>nums;
    //     vector<int>dp(nums+1,0);
    //     for(int i=1;i<=nums;i++){
    //         dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);
    //     }
    //     cout<<dp[nums]<<endl;
    // }


    long long int nums;
    while(cin>>nums){
        
        // cin>>nums;
        unordered_map<int, long long int>m;
        m[0]=0;
        long long int res=getMaxSum(nums,m);
        cout<<res<<endl;
    }
    return 0;
}