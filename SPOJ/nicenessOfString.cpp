/*

//**********************************************IITKWPCA - Niceness of the string.**************************************************
https://www.spoj.com/problems/IITKWPCA/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Set based solution. Here, we push the string's words into the set and get the Unique words in the string.







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
#include<sstream>




using namespace std;






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;
    string s="";
    cin.ignore();
    for(int a=0;a<tests;a++){
        getline(cin,s);
        // cout<<"Full str: "<<s<<endl;
        stringstream ss;
        ss.str(s);//    ss<<s can also be used.
        s="";
        unordered_set<string>m;
        while(ss>>s){
            // cout<<"str: "<<s<<endl;
            m.insert(s);
        }
        cout<<m.size()<<endl;
    }

    return 0;
}
