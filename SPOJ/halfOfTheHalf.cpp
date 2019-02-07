/*

//******************************************************STRHH - Half of the half.****************************************************
https://www.spoj.com/problems/STRHH/



Time Complexity:O(n).                                                       
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    
// Space Complexity:O(n).
// This is iteration based problem. We iterate till half of the indices of each string, while printing alternating chars form each 
// string.










#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>


using namespace std;



int main() {
    // your code goes here
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    int tests;
    cin>>tests;
    for(int a=0;a<tests;a++){
        string s="";
        cin>>s;
        string res="";
        for(int i=0;i<s.length()/2;i+=2){
            res+=s[i];
        }
        cout<<res<<endl;
    }
    return 0;
}