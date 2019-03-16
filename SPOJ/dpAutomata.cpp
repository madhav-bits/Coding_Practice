/*

//*******************************************************AUTOMATA - GAME2.***********************************************************
https://www.spoj.com/problems/AUTOMATA/




Time Complexity:O(n*m).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n*m).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, since few chars represent multiple chars in orig. language. We assign an index,
// based on values from prev. row/clmn values. At the end of iter. we have our result dp[s.length()%2][t.length()].


// In case of '?' dp[i%2][j]=dp[(i-1)%2][j-1]     -- '?' substitues current char from other string.
//                dp[i%2][j]=dp[i%2][j-1]         -- '?' substitues empty char '?'/ '?' can be neglected.




// In case of '*' dp[i%2][j]=dp[(i-1)%2][j-1]     -- '*' substitues current char from other string.
//                dp[i%2][j]=dp[i%2][j-1]         -- '*' substitues empty char '?'/ '?' can be neglected.
//                dp[i%2][j]=dp[i%2][j-1]         -- '*' substitues multiple chars from other string.










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
    string s="", t="";
    for(int a=0;a<tests;a++){
        cin>>t>>s;
        // cout<<"s: "<<s<<" and t: "<<t<<endl;
        vector<vector<bool>>dp(2,vector<bool>(t.length()+1, false));
        dp[0][0]=true;
        for(int j=1;j<=t.length();j++){
            // if(t[j-1]>='a' && t[j-1]<='z') dp[0][j]=false;
            if(t[j-1]=='*' || t[j-1]=='?') dp[0][j]=dp[0][j-1];
        }
        for(int i=1;i<=s.length();i++){
            dp[i%2][0]=false;
            for(int j=1;j<=t.length();j++){
                dp[i%2][j]=false;
                if(s[i-1]==t[j-1]) dp[i%2][j]=dp[(i-1)%2][j-1];
                else if(t[j-1]=='?') dp[i%2][j]=(dp[i%2][j-1] || dp[(i-1)%2][j-1]);
                else if(t[j-1]=='*') dp[i%2][j]=(dp[i%2][j-1] || dp[(i-1)%2][j]);// dp[(i-1)%2][j-1] ||         -- Can also be used.
            }
        }
        if(dp[(s.length())%2][t.length()]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        // cout<<dp[(s.length())%2][t.length()]<<endl;
    }

    return 0;
}
