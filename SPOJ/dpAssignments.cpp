/*

//*****************************************************ASSIGN - Assignments.*********************************************************
https://www.spoj.com/problems/ASSIGN/




Time Complexity:O(2^n*n).                                                                                                                                                                                             
Space Complexity:O(2^n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(2^n*n^2).                                                  
// Space Complexity:O(2^n).                                                   
// This is Dynamic Programming based solution. We iter. over all people assign tasks to each of them in a sequence, at each step
// we update bitmask array to reflect #ways to assign tasks among first 'i' people. At the end of iter., we return #ways to assign
// 'n' tasks among first 'n' people.









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
    // cin>>tests;
    scanf("%d", &tests);
    int nums;
    for(int a=0;a<tests;a++){
        // cin>>nums;
        scanf("%d", &nums);
        vector<vector<bool>>pref(nums, vector<bool>(nums, false));
        int num;
        for(int i=0;i<nums;i++){
            for(int j=0;j<nums;j++){
                // cin>>num;
                scanf("%d", &num);
                pref[i][j]=(num==1)?true:false; 
                // cout<<pref[i][j]<<" ";   
            } 
            // cout<<endl;
        }
        int limit=pow(2,nums)*2;
        vector<long long int>dp(limit,0);
        dp[0]=1;
        for(int i=0;i<nums;i++){
            vector<long long int>curr(limit,0);
            for(int j=1;j<=nums;j++){
                for(int k=0;k<limit;k++){
                    // int com=(k&(1<<j));
                    if( pref[i][j-1] && (k&(1<<j))==0){
                        // cout<<"matched at i: "<<i<<" and j: "<<j<<endl;
                        curr[k|(1<<j)]+=dp[k];    
                    } 
                }
            }
            // dp=curr;
            for(int l=0;l<limit;l++) dp[l]+=curr[l];
        }
        // for(int l=0;l<limit;l++) cout<<dp[l]<<" ";
        // cout<<endl;
        // cout<<dp[limit-2]<<endl; 
        printf("%lld \n", dp[limit-2]);
    }

    return 0;
}






















//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(2^n*n).                                                  
// Space Complexity:O(2^n).                                                   
// This is Dynamic Programming based and Bitmasking solution based on Ryser's formula. We use bitmasking to keep track of tasks
// assigned. We iter. over [1,2^tasks]. While filling the array corresponding to 'i', we calc. #set bits in it, if we have x bits
// set, then it need to store #possibilties to assign x tasks among first 'x' participants. We remove each set bit at a time and add
// the #possibiities to assign 'x-1' tasks among first 'x-1' participants to this dp[x]. Since, the resulting(mask&(~(1<<j))) had
// been already calculated, we take those values. At the end of iter., we return #ways to assign n tasks to n people, so we return
// value stored in (2^n)-1  index.

// ******************************************This adoption is the masterpiece of DP in this problem.*********************************
// dp[i] indicates #ways to assign set bit indexed tasks among first ($set-bits) people.





// This link has some explanation regarding the bitmasking:
// https://discuss.codechef.com/t/dynamic-programming-bit-masking/6767


// This link has some explanation about bit masking and about this algorithm:
// https://discuss.codechef.com/questions/49669/assign-spoj-redynamic-programming-with-bitmask









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
    // scanf("%d", &tests);
    int nums;
    for(int a=0;a<tests;a++){
        cin>>nums;
        // scanf("%d", &nums);
        vector<vector<bool>>pref(nums, vector<bool>(nums, false));
        int num;
        for(int i=0;i<nums;i++){
            for(int j=0;j<nums;j++){
                cin>>num;
                // scanf("%d", &num);
                pref[i][j]=(num==1)?true:false; 
                // cout<<pref[i][j]<<" ";   
            } 
            // cout<<endl;
        }
        int limit=pow(2,nums);
        vector<long long int>dp(limit,0);
        dp[0]=1;
        for(int mask=1;mask<limit;mask++){
            int i=0, temp=1;
            for(int j=0;j<nums;j++){
                if(mask&temp) i++;
                temp*=2;
            }
            // cout<<"mask: "<<mask<<" and the bits: "<<i<<endl;
            for(int j=0;j<nums;j++){
                if(pref[i-1][j]==false) continue;
                if((mask&(1<<j))==0) continue;
                dp[mask]+=dp[mask&(~(1<<j))];
            }
        }
        // for(int i=0;i<limit;i++){
        //     cout<<"i: "<<i<<" and val: "<<dp[i]<<endl;
        // }
        cout<<dp[limit-1]<<endl;
    }
    return 0;
}
