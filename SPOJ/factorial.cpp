/*

//*******************************************************FCTRL - Factorial.***********************************************************
https://www.spoj.com/problems/FCTRL/




Time Complexity:O(logn/log5).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn/log5).                                                  
// Space Complexity:O(1).                                                   
// This is observation based. Trailing zeroes are becuase of product of 5 with even numbers, so we calc. #5s in the range of numbers
// to be considered. Which can be obtained by dividing given number with powers of 5 and adding the results to final result. At the
// end of iteration, return the final result.








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





using namespace std;



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    int tests;
    cin>>tests;
    // cout<<tests<<endl;
    for(int a=0;a<tests;a++){
        int num;
        cin>>num;
        int res=0;
        int divi=5;
        while(num/divi>0){
            res+=(num/divi);
            divi*=5;
        }
        cout<<res<<endl;
    }
    return 0;
}