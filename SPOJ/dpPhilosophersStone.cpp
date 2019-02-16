/*

//*******************************************************BYTESM2 - Philosophers Stone.*****************************************************
https://www.spoj.com/problems/FCTRL/




Time Complexity:O(m*n).                                                                                                                                                                                             
Space Complexity:O(m).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(m*n).                                                   
// This is Dynamic Programming based solution. Here, we first initialize first row values, as they have only one way to reach them. Later
// we iterate over following indices, assign them greatest values by picking the maxm. value of the reachable adjacent indices in prev. 
// row. At the end of iter, we iter. over last row and return the maxm. value.







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

    for(int a=0;a<tests;a++){
        int rows, cols;
        cin>>rows>>cols;
        // cout<<"rows: "<<rows<<" and cols; "<<cols<<endl;
        vector<vector<int>>v(rows, vector<int>(cols,0));
        vector<vector<int>>dp(rows, vector<int>(cols,0));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>v[i][j];
            }
        }


        for(int j=0;j<cols;j++) dp[0][j]=v[0][j];

        for(int i=1;i<rows;i++){
            for(int j=0;j<cols;j++){
                int maxm=dp[i-1][j];
                if(j-1>=0) maxm=max(maxm, dp[i-1][j-1]);
                if(j+1<v[0].size()) maxm=max(maxm, dp[i-1][j+1]);
                dp[i][j]=maxm+v[i][j];
            }
        }

        int res=0;
        for(int j=0;j<cols;j++) res=max(res, dp[rows-1][j]);
        cout<<res<<endl;
    }

    return 0;
}























//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(m).                                                   
// This is Dynamic Programming based solution. Here, we first initialize first row values, as they have only one way to reach them. Later
// we iterate over following indices, assign them greatest values by picking the maxm. value of the reachable adjacent indices in prev. 
// row. At the end of iter, we iter. over last row and return the maxm. value.


// This sln is similar to prev. one, since each row's values depend only on prev. row, we use only two rows.





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

    for(int a=0;a<tests;a++){
        int rows, cols;
        cin>>rows>>cols;
        // cout<<"rows: "<<rows<<" and cols; "<<cols<<endl;
        vector<vector<int>>v(rows, vector<int>(cols,0));
        vector<vector<int>>dp(2, vector<int>(cols,0));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>v[i][j];
            }
        }


        for(int j=0;j<cols;j++) dp[0][j]=v[0][j];

        for(int i=1;i<rows;i++){
            for(int j=0;j<cols;j++){
                int maxm=dp[(i-1)%2][j];
                if(j-1>=0) maxm=max(maxm, dp[(i-1)%2][j-1]);
                if(j+1<v[0].size()) maxm=max(maxm, dp[(i-1)%2][j+1]);
                dp[i%2][j]=maxm+v[i][j];
            }
        }

        int res=0;
        for(int j=0;j<cols;j++) res=max(res, dp[(rows-1)%2][j]);
        cout<<res<<endl;
    }

    return 0;
}