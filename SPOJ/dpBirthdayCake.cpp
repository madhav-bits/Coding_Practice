/*

//*******************************************************BCAKE - Birthday Cake.***********************************************************
https://www.spoj.com/problems/BCAKE/




Time Complexity:O(n^4).                                                                                                                                                                                             
Space Complexity:O(n^2).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^4).                                                  
// Space Complexity:O(n^2).                                                   
// This is Dynamic Programming based solution. Here, we build a DP matrix to store the #chocolates to it's TOP-LEFT side. We iter.
// over the entire matrix and calculate the #chocolates in the submatrices starting from each index. We use the dp matrix to get the
// #chocolates and if the #chocolates is equal to target chocolates, we update the final returning submatrix area.

// We optimize the iter. by iterating submatrices whose area is less than result till then also #chocolates is less than target 
// chocolates.






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







void getMinArea(vector<vector<int>>&dp, int x, int y, int rows, int cols, int target, int&res){

	for(int i=x;i<rows && (i-x+1)<=res;i++){
		for(int j=y;j<cols && ((i-x+1)*(j-y+1)<=res);j++){
			int choco=dp[i][j];
			if(x>0) choco-=dp[x-1][j];
			if(y>0) choco-=dp[i][y-1];
			if(x>0 && y>0) choco+=dp[x-1][y-1];
			if(choco>target) break;
			if(choco!=target) continue;
			res=(i-x+1)*(j-y+1);
		}
	}
	return ;
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, rows, cols, chocolates;
    cin>>tests;
    for(int a=0;a<tests;a++){
    	cin>>rows>>cols>>chocolates;
    	vector<vector<char>>v(rows, vector<char>(cols,'.'));
    	vector<vector<int>>dp(rows, vector<int>(cols,0));
    	for(int i=0;i<rows;i++){
    		for(int j=0;j<cols;j++){
    			cin>>v[i][j];
    		}
    	}

    	int res=rows*cols+1;
    	for(int i=0;i<rows;i++){
    		for(int j=0;j<cols;j++){
    			int total=0;
    			if(i>0) total+=dp[i-1][j];
    			if(j>0) total+=dp[i][j-1];
    			if(i>0 && j>0) total-=dp[i-1][j-1];
    			total+=(v[i][j]=='C')?1:0;
    			dp[i][j]=total;
    			// cout<<dp[i][j]<<" ";
    		}
    		// cout<<endl;
    	}

    	for(int i=0;i<rows;i++){
    		for(int j=0;j<cols;j++){
    			getMinArea(dp, i,j, rows, cols, chocolates, res);
    		}
    	}
    	// cout<<"The final res: "<<res<<endl;
    	if(res==rows*cols+1) cout<<-1<<endl;
    	else cout<<res<<endl;

    }

    return 0;
}
