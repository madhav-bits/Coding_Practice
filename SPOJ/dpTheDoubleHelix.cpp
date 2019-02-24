/*

//***************************************************ANARC05B - The Double HeLiX.***************************************************
https://www.spoj.com/problems/ANARC05B/




Time Complexity:O(m+n).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
//******************************************************THIS IS NOT SPOJ ACCEPTED CODE.**********************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(m*n).                                                   
// This is Dynamic Programming based solution. Here, we form a DP array, at each step we form curr. indices sum based on prev. indices
// we also check whether values from both arrays are equal for curr. index, if equal we assign the bigger value to both value in that
// index. At any index, while updating values, we take the max. of prev. row/prev. col which had already included curr. index and 
// prev.col/prev. row plus curr. index value. At the end of iter. we return the greater of two values.


// This algo. works for all possible scenarios, since here, the given question is strictly increasing, so we can optimally/greedily
// iterate over two arrays at the same time. Thus making it linear time complexity one.







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

    
    int len1, len2;
    cin>>len1;
    while(!cin.eof()){
        vector<int>u(len1);
        for(int a=0;a<len1;a++) cin>>u[a];
        cin>>len2;
        vector<int>v(len2);
        for(int a=0;a<len2;a++) cin>>v[a];
        // cout<<"len1; "<<len1<<" and len2; "<<len2<<endl;
        vector<vector<pair<long long int,long long int>>>dp(len1+1, vector<pair<long long int,long long int>>(len2+1, {0,0}));
        for(int i=1;i<=len1;i++) dp[i][0].first=dp[i-1][0].first+u[i-1];
        for(int j=1;j<=len2;j++) dp[0][j].second=dp[0][j-1].second+v[j-1];

        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                dp[i][j].first=max(dp[i-1][j].first+u[i-1], dp[i][j-1].first);
                dp[i][j].second=max(dp[i][j-1].second+v[j-1], dp[i-1][j].second);
                if(u[i-1]==v[j-1]){
                    dp[i][j].first=max(dp[i][j].first, dp[i][j].second);
                    dp[i][j].second=dp[i][j].first;
                }
                // cout<<dp[i][j].first<<" "<<dp[i][j].second<<" # ";
            }
            // cout<<endl;
        }
        cout<<max(dp[len1][len2].first, dp[len1][len2].second)<<endl;
        cin>>len1;
    }

    return 0;
}


















//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(m+n).                                                  
// Space Complexity:O(1).                                                   
// This is Greedy based solution. Here, since the arrays are strictly increasing, a value in an array can have only one common point
// from another array at max.. So, we iter. over arrays, at each step we add the min. of two values to that array's total sum and inc.
// the index, with hope/expectation that the greater value's common value would be somewhere ahead in other array, thus we aren't 
// loosing best result scenarios. When both values are equal, we assign the greater sum to both sums, inc. both indices. We do this
// until both indices are valid, later, we iter. over unvisited indices in other array. After that we return the max. of two values.














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

    
    int len1, len2;
    cin>>len1;
    while(len1!=0){
        vector<int>u(len1);
        for(int a=0;a<len1;a++) cin>>u[a];
        cin>>len2;
        vector<int>v(len2);
        for(int a=0;a<len2;a++) cin>>v[a];
        long long int sum1=0, sum2=0;
        int i=0, j=0;
        while(i<u.size() && j<v.size()){
            if(u[i]<v[j]) sum1+=u[i++];
            else if(v[j]<u[i]) sum2+=v[j++];
            else{
                sum1=max(sum1, sum2)+u[i];
                sum2=sum1;
                i++;j++;
            }
        }
        while(i<u.size()) sum1+=u[i++];
        while(j<v.size()) sum2+=v[j++];
        cout<<max(sum1, sum2)<<endl;
        cin>>len1;
    }

    return 0;
}