/*

//*******************************************************CODEM3 - Problem3.***********************************************************
https://www.spoj.com/problems/CODEM3/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(1).                                                   
// This is Array based solution. Here, since we are trying to get non-zeros to left with minm. moves, we count #non-zero elem. to 
// right of leftmost zero. Since, we can get each non-zero to left in order with just one swap, we return the count of zeros after the 
// entire iteration.







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

    int tests, nums;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>nums;
        vector<int>v(nums,0);
        for(int i=0;i<nums;i++) cin>>v[i];
        int res=0, count=0;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==0) res=count;
            else count++;
        }
        cout<<res<<endl;
    }

    return 0;
}
