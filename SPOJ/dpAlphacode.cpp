/*

//***************************************************************ACODE - Alphacode.********************************************************
https://www.spoj.com/problems/ACODE/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(1).                                                      // As, curr. index depends on 2 following indices, we can so-
                                                                            // -lve by an array of only 3 elem.                 

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                              
// Space Complexity:O(1).                                                   // As, curr. index depends on 2 following indices, we can so-
                                                                            // -lve by an array of only 3 elem.                                                   
// This is Dynamic Programming based solution. Here, at each step we form the first char formable, then add the #chars possible formable
// following the first char, which are pre calculated and stored in DP array. This way, we get #chars formable starting at each index, at
// last we return #chars formable starting from index '0'.





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



#define ll long long

using namespace std;




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    string s="";
    cin>>s;
    while(s!="0"){
        // cout<<"str: "<<s<<endl;
        vector<ll>dp(s.length()+1,0);
        dp.back()=1;
        if(s[s.length()-1]!='0') dp[s.length()-1]=1;
        for(int i=s.length()-2;i>=0;i--){
            if(s[i]=='0') continue;
            dp[i]+=dp[i+1];
            if(s[i]=='1') dp[i]+=dp[i+2];
            if(s[i]=='2' && s[i]<='6') dp[i]+=dp[i+2];
        }
        // for(auto num:dp) cout<<num<<" ";
        // cout<<endl;
        cout<<dp[0]<<endl;
        cin>>s;
    }
    

    return 0;
}