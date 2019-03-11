/*

//**************************************************ALIEN - Aliens at the train.******************************************************
https://www.spoj.com/problems/ALIEN/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Sliding Window based solution. Here, we iter. over stations making it as the last station in the window, if the sum>target,
// we remove stations from the start till the sum of window's elements is <target. We try to update the longest window length var.
// if the window length matches, we take the window with smallest window sum. and return the longest window length with small window's
// element sum. 







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

    
    int tests, nums, target, resSum=0;
    cin>>tests;

    for(int a=0;a<tests;a++){
        cin>>nums>>target;
        vector<int>v(nums,0);
        long long int sum=0, num=0;
        int start=0, close=0, res=0;
        for(int i=0;i<nums;i++){
            cin>>v[i];
            close=i;
            sum+=v[i];
            while(sum>target){
                sum-=v[start++];
            }
            if(close-start+1>res || (close-start+1==res && sum<resSum)){
                res=close-start+1;
                resSum=sum;
            }
            res=max(res, close-start+1);
        } 
        cout<<resSum<<" "<<res<<endl;
            
    }

    return 0;
}
