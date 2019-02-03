
/*

//*****************************************************************ABA12C - Buying Apples!*************************************************************
https://www.spoj.com/problems/ABA12C/



Time Complexity:O(m*n).
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).
// Space Complexity:O(n).
// This is Dynamic Progamming based solution. This is KnapSack based problem. I Don't know why we haven't considered the friends condition. We have
// our Knapsack based only achieving the target weight with min. price.









#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<climits>


using namespace std;


int findCost(int friends, int req, vector<int>&apples){
    int res=0;
    // cout<<"call"<<endl;
    vector<int>dp(req+1,INT_MAX);
    dp[0]=0;
    for(int i=0;i<=req;i++){
        if(dp[i]==INT_MAX) continue;
        for(int j=0;j<apples.size();j++){
            if(apples[j]==-1) continue;
            if(i+j+1<=req) dp[i+j+1]=min(dp[i+j+1], dp[i]+apples[j]);
        }    
    }    
    // for(int i=0;i<=req;i++){
    //     cout<<"i: "<<i<<" and price: "<<dp[i]<<endl;
    // }
    // cout<<"yo"<<endl;
    if(dp[req]==INT_MAX) return -1;
    return dp[req];
}

int main() {
	// your code goes here
	int tests;
	cin>>tests;
	for(int i=0;i<tests;i++){
	    // cout<<"i: "<<i<<endl;
		int friends, req;
		cin>>friends>>req;
// 		cout<<"friends: "<<friends<<" and req: "<<req<<endl;
		vector<int>apples(req);
		for(int j=0;j<req;j++){
			cin>>apples[j];
		}
		// cot<<endl;
		int res=findCost(friends, req, apples);
		cout<<res<<endl;
	}

	return 0;
}