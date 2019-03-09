/*

//***************************************************WILLITST - Will it ever stop.***************************************************
https://www.spoj.com/problems/WILLITST/




Time Complexity:O(1).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                  
// Space Complexity:O(1).                                                   
// This is Observation based solution. It is observable that powers of 2 would lead to decaying function. (3n+3) can't form any power
// of 2 with any number. If a number isn't power of 2, it would have to go through (3n+3), which wouldn't form power of 2 for next 
// steps to work on. Thus, it would lead to infinite loop.







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

    long long int num;
    cin>>num;
    // cout<<"Num: "<<num<<endl;
    // cout<<"res: "<<
    if((num&(num-1))==0) cout<<"TAK"<<endl;                                 // If num is power of 2.
    else cout<<"NIE"<<endl;

    return 0;
}
