/*

//**********************************************HOTELS - Hotels Along the Croatian Coast.*********************************************
https://www.spoj.com/problems/HOTELS/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Sliding Window based solution. Here, we iter. over given array, at any instant, we retain a valid window whose sum is 
// <=target value. We include the curr. num while iterating, if sum>target, we keep on removing elem. from start from the window
// until sum<target. Once, the window sum is valid, we try to maximize the result sum var. At the end of iter., we return the
// result var.






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

    int hotels, target;
    long long int sum=0, res=0;
    int start=0, close=0;
    cin>>hotels>>target;
    // cout<<"target: "<<target<<endl;
    vector<int>v(hotels, 0);
    for(int i=0;i<hotels;i++){
        cin>>v[i];
        close=i;
        sum+=v[close];
        while(start<close && sum>target){
            sum-=v[start++];
        }
        res=max(res,sum);
    }
    cout<<res<<endl;

    return 0;
}
