/*

//************************************************CODFURY - Megatron and his rage.****************************************************
https://www.spoj.com/problems/CODFURY/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Sliding window based solution. Here,   we iter. over given array and take in current elem. into window, if the sum is>target.
// We remove elem. from the start until the sum of window<target. We try to udpate with largest window length. We update if curr. 
// window is smaller or window of same length with smaller sum. After the iter. we return the window's sum and largest width of window.







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

    int tests, planets, limit;
    cin>>tests;
    for(int a=0;a<tests;a++){
        cin>>planets>>limit;
        vector<int>v(planets,0);
        for(int i=0;i<planets;i++) cin>>v[i];
        int sum=0, start=0, close=0, res=0, vol=0;
        for(int i=0;i<planets;i++){
            close=i;
            sum+=v[i];
            while(start<=close && sum>limit){
                sum-=v[start];
                start++;
            }
            if(close-start+1>res || (close-start+1==res && sum<vol)){
                res=close-start+1;
                vol=sum;
            }
            // res=max(res, close-start+1);
        }
        cout<<vol<<" "<<res<<endl;
    }

    return 0;
}
