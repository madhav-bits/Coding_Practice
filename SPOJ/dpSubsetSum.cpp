/*

//******************************************************MAIN72 - Subset sum.**********************************************************
https://www.spoj.com/problems/MAIN72/




Time Complexity:O(k).                                                       // k- maxm. possible sum of all values in given array.                                                                                                                                   
Space Complexity:O(k).                                                      // k- maxm. possible sum of all values in given array. 

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(k).                                                    // k- maxm. possible sum of all values in given array. 
// Space Complexity:O(k).                                                   // k- maxm. possible sum of all values in given array.                                                   
// This is Dynamic Programming based solution. Here, we are trying to get various subsequence sums, so we use bitset for this purpose.
// We init bitset with maxm. sum size and setting zero index, for each value in array, we or curr. bitset and it's right shifted state
// by curr. value times. Thus, at the end of entire process, we have bitset set to 1 in all those indices, whose sum is attainable
// by one of subsequences of given array. So, we iter. array bitset and add those indices which are set to 1 and return the total.







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





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nums, total=0;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>nums;
        total=0;
        vector<int>v(nums);
        for(int i=0;i<nums;i++){
            cin>>v[i];
            total+=v[i];    
        } 
        bitset<1000001>bt(1);
        for(int i=0;i<v.size();i++){
            bt=bt|(bt<<(v[i]));
        }
        int res=0, psn=0;
        while(psn<=total){
            if(bt[psn]==1) res+=psn;
            psn++;
        }
        cout<<res<<endl;
    }

    return 0;
}
