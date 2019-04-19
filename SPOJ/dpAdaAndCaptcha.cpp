/*

//************************************************ADAROBOT - Ada and CAPTCHA.*****************************************************
https://www.spoj.com/problems/ADAROBOT/




Time Complexity:O(n).                                                       // Maxm. query value.                                                                                                                                                                                 
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
//************************************************THIS IS NOT SPOJ ACCEPTED SOLUTION.****************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(1).                                                   
// This is Dynamic Programming/ hashing based solution. We pre-calculate all values and store results in dp array, and return the 
// results for each query by extracting values from DP array.


// THIS IS NOT ACCEPTED SOLUTION. ITS THROWING TLE ERRORS, DON'T KNOW WHY, MY SOLUTION AND ACCPETED SOLUTION ARE ALMOST THE SAME.




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




// void fillDPArray(vector<long long int>&dp, vector<long long int>&cubes){
//     int num=-1, psn;
//     // for(int i=2;i<dp.size();i++){// 200000000
//     //     if(i%2==0){
//     //         num=i-(i&(i-1));
//     //         psn=log2(num)+1;
//     //     }else{
//     //         num=i-1-((i-1)&(i-2));
//     //         psn=log2(num)+1;
//     //     }
//     //     // cout<<"i: "<<i<<" and fn: "<<psn<<endl;
//     //     dp[i]=pow(psn,3)+dp[i-2];
//     // }

//     for(int i=2;i<=dp.size();i++){// 200000000
//         dp[i]=dp[i-2]+cubes[__builtin_ffsl(1LL * i * (i - 1))];
//     }

// }


vector<long long int>cubes(67,0);
vector<long long int>dp(200000001,0);



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // ifstream cin;
    // cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    for(int i=1;i<=66;i++) cubes[i]=i*i*i;
    for(int i=2;i<=dp.size();i++){// 200000000
        dp[i]=dp[i-2]+cubes[__builtin_ffsl(1LL * i * (i - 1))];
    }

    int queries, query;
    // cin>>queries;
    scanf("%d",&queries);
    int num=0;
    for(int a=0;a<queries;a++){
        scanf("%d", &num);// &v[a]
        printf("%lld \n", dp[num]);  
    }
    
    return 0;
}









//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(1).                                                   
// This is Dynamic Programming/hashing based solution. 


// THIS IS SPOJ ACCEPTED SOLUTION.







#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 200000025;

int Q, N;
int cubes[100];
long long t[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 1; i < 100; i ++)
        cubes[i] = i * i * i;
    for(int i = 2; i < me; i ++)
        t[i] = t[i - 2] + cubes[__builtin_ffsl(1LL * i * (i - 1))];
    
    scanf("%d", &Q);
    while(Q --){
        scanf("%d", &N);
        printf("%lld\n", t[N]);
    }
    
    return 0;
}