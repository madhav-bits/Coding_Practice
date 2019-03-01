/*

//*******************************************************FCTRL - Factorial.***********************************************************
https://www.spoj.com/problems/FCTRL/




Time Complexity:O(logn).                                                    // For calc. the power value.                                                                                                                                         
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn).                                                 // For calc. the power value.                                               
// Space Complexity:O(1).                                                   
// This is observation based. Here, #ones follow a pattern. As #digits are concerned(starting 2^(n-1) to (2^n)-1) all have first bit 
// as 1. As #1s used is concerned, above mentioned numbers have 1 in the beginning, else chars have that (val/2) times 1 in them. So,
// we need to add these numbers and return.







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

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    int tests;
    cin>>tests;
    int digits;
    for(int a=0;a<tests;a++){
        cin>>digits;
        long long int vals, nums;
        vals=pow(2,digits-1);                                               // #numbers with first bit as 1.
        long long int temp=vals/2;
        temp=temp*(digits-1);                                               // numbers with 1 in them from 2nd bit to last bit.
        cout<<vals<<" "<<vals+temp<<endl;                                   // Total #ones encountered.
    }
    return 0;
}