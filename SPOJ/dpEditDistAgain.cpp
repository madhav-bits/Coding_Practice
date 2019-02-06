/*

//*****************************************************************EDIT - Edit Distance Again.************************************************************
https://www.spoj.com/problems/EDIT/




Time Complexity:O(n).                                                       
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    
// Space Complexity:O(n).
// This is Dynamic Programmng problem. Here, at each step, we make sure that the chars are alternative to prev. char, if we had to switch case of 
// alphabet, we add 1 to moves ot prev. char's opposite case, if not we just accept #moves to get prev. index' opposite case. At the end of iter.,
// we return the min. #moves to get smaller/Block case in last index.











#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>



using namespace std;

int main() {
    // your code goes here
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    string str="";
    while(cin>>str){
        if(str.length()==0){
            cout<<0<<endl;
            continue;
        }
        // cout<<"str: "<<str<<endl;
        vector<vector<int>>dp(2,vector<int>(str.length(),str.length()));// 0 is small, 1 is capital.
        dp[0][0]=1;dp[1][0]=1;
        if(str[0]>=97 && str[0]<=122) dp[0][0]=0;
        else dp[1][0]=0;
        // cout<<"small: "<<dp[0][0]<<" capital: "<<dp[1][0]<<endl;
        for(int i=1;i<str.length();i++){
            if(str[i]>=97 && str[i]<=122){                                  // Curr. char is small case.
                dp[0][i]=dp[1][i-1];            // Small case.
                dp[1][i]=dp[0][i-1]+1;          // Block case.
            }else{                                                          // Curr. char is Block case.
                dp[0][i]=dp[1][i-1]+1;          // Small case.
                dp[1][i]=dp[0][i-1];            // Block case.
            }
            // cout<<"i: "<<i<<" small: "<<dp[0][i]<<"capital: "<<dp[1][i]<<endl;
        }
        // cout<<"Out of iter."<<endl;
        cout<<min(dp[0][str.length()-1], dp[1][str.length()-1])<<endl;
    }
    return 0;
}