/*

//*************************************************CRAN02 - Roommate Agreement.*****************************************************
https://www.spoj.com/problems/CRAN02/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Prefix Sum and Hashing based solution. Since, we are trying to get subarray whose sum is 0, we get prefix sum if curr. 
// total is 'x', then we can form substrings of sum '0' from all previous occurances of prefix sum 'x' to curr. index. To keep track 
// of #previous occurances of curr. total, we use map.









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

    int tests, nums,total,num;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        unordered_map<int,long long int>m;
        m[0]=1;
        total=0;
        cin>>nums;
        long long int res=0;
        for(int i=0;i<nums;i++){
            cin>>num;
            total+=num;
            if(m.count(total)==1) res+=m[total];
            m[total]++;
        }
        cout<<res<<endl;
    }

    return 0;
}
