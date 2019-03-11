/*

//***************************************************ADACOINS - Ada and Coins.*******************************************************
https://www.spoj.com/problems/ADACOINS/




Time Complexity:O(n).                                                       // Sum of all given coins values.                                                                                                                                                                                        
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    // Sum of all given coins values.                                                  
// Space Complexity:O(1).                                                   
// This is Dynamic Programming based solution. Here, we use bitset, whose index 'i' if set to 1, means sum of i can be obtained by using
// some combi. of coins iter. till then. To add new number, we take OR of curr. bitset value and (curr. bitset<<curr. value) so that
// we get all combi. which includes curr. nums and also which doesn't include curr. num. At the end, we iter. over bitset array and 
// accumulate the #1s encountered till every index and store at that index of accum array.






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
#include<bitset>



using namespace std;




// void fillOccur(vector<bool>&occur, vector<int>&v,vector<int>&accum){        // This is general way of filling DP array to get coins achievable by given coins.
//     occur[0]=true;
//     for(int i=0;i<v.size();i++){    
//         // cout<<"num: "<<v[i]<<endl;
//         for(int j=100000;j>0;j--){
//             if(j-v[i]<0) break;
//             if(occur[j-v[i]]==true) occur[j]=true;
//         }
//     }
//     for(int i=1;i<=100000;i++) accum[i]=(occur[i]?1:0)+accum[i-1];
//     return ;
// }





int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // FILE* cin;
    // cin=fopen("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt","r");
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    int nums, queries;
    cin>>nums>>queries;
    bitset<100005>bt;                                                       // INit. bitset to maxm. sum possible.
    bt[0]=1;                                                                // Setting first bit to 1, indicating sum of 0 is possible.
    vector<int>v(nums,0);
    for(int i=0;i<nums;i++){
        cin>>v[i];
        bt|=bt<<v[i];                                                       // This gets all combi. of coin subsets with and without curr. coin.
        // cout<<bt<<endl;
    } 
    // vector<bool>occur(100005, false);
    vector<int>accum(100005,0);
    // fillOccur(occur,v, accum);
    for(int i=1;i<=100000;i++) accum[i]=bt[i]+accum[i-1];                   // Iter. over bitset array and filling prefix sum array.
    int left, right;
    for(int i=0;i<queries;i++){
        cin>>left>>right;
        int res=accum[right]-accum[left-1];
        cout<<res<<"\n";
    }

    return 0;
}
