/*

//******************************************************ACTIV - Activities.**********************************************************
https://www.spoj.com/problems/ACTIV/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Sorting based Dynamic Programming solution. Here, since we need events that don't overlap, we sort the intervals based on
// start values. We iter. over values, for each we find intervals, which don't overlap with current one add all those possibilities
// and store the count at curr. index in dp array. We find events that don't overlap with curr. interval add their count, we add
// count of all intervals that start post curr. start time and store them at curr. index. At the end of iter. we return the value
// in zero index of dp array.





// dp[i] indicates total #possible combinations of non-overlapping subset of events starting curr. start time or past it.







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

    
    int options, mod=100000000;
    cin>>options;

    while(options!=-1){
    	vector<pair<int,int>>v(options);
    	vector<long long int>dp(options, 0);
    	vector<int>starts(options, 0);
    	int start, close;
    	for(int i=0;i<options;i++){
    		cin>>start>>close;
    		v[i]={start, close};
    		starts[i]=start;
    	}
    	sort(v.begin(), v.end());
    	sort(starts.begin(), starts.end());
    	int res=0;
    	for(int i=v.size()-1;i>=0;i--){
    		auto it=lower_bound(starts.begin()+i+1, starts.end(), v[i].second);
    		int idx=it-starts.begin();
    		dp[i]=1;
    		if(it!=starts.end()) dp[i]=(dp[i]+dp[idx])%mod;
    		if(i<v.size()-1)
    		dp[i]=(dp[i]+dp[i+1])%mod;
    	}
    	// for(auto num:dp) cout<<num<<" ";
    	// cout<<endl;
    	printf("%08d \n", dp[0]);
    	cin>>options;
    }
    

    return 0;
}









//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Sorting based Dynamic Programming solution. Here, since we need events that don't overlap, we sort the intervals based on
// start values. We iter. over values, for each we find intervals, which don't overlap with current one add all those possibilities
// and store the count at curr. index in dp array. We find events that don't overlap with curr. interval add their count, we add
// count of all intervals that start post curr. start time and store them at curr. index. At the end of iter. we return the value
// in zero index of dp array.


// dp[i] indicates total #possible combinations of non-overlapping subset of events starting curr. start time or past it.





// This algo. is same as above one, except that it uses custom comparator in lower_bound fn(New Technique).







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



struct comp{
	bool operator()(const pair<int,int>&lt, const pair<int,int>&rt) {
		return (lt.first<rt.first || (lt.first==rt.first && lt.second<rt.second));
	}
};




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    int options, mod=100000000;
    cin>>options;

    while(options!=-1){
    	vector<pair<int,int>>v(options);
    	vector<long long int>dp(options, 0);
    	int start, close;
    	for(int i=0;i<options;i++){
    		cin>>start>>close;
    		v[i]={start, close};
    	}
    	sort(v.begin(), v.end());
    	int res=0;
    	for(int i=v.size()-1;i>=0;i--){
    		pair<int,int>temp={v[i].second, v[i].second};
    		auto it=lower_bound(v.begin()+i+1, v.end(), temp, comp());				// Here, comp() isn't needed infact, as we are using default comparison here.
    		int idx=it-v.begin();
    		dp[i]=1;
    		if(it!=v.end()) dp[i]=(dp[i]+dp[idx])%mod;
    		if(i<v.size()-1)
    		dp[i]=(dp[i]+dp[i+1])%mod;
    	}
    	// for(auto num:dp) cout<<num<<" ";
    	// cout<<endl;
    	printf("%08d \n", dp[0]);
    	cin>>options;
    }
    

    return 0;
}