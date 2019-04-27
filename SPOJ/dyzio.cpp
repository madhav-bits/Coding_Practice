/*

//********************************************************DYZIO - Dyzio.************************************************************
https://www.spoj.com/problems/DYZIO/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Recursion based solution. Here, we have to make cuts according to the string, the instant we get string of min. length,
// we store the cuts made till then.







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




void getCuts(string &s, int &index, double &minLen, int&resCuts, int&cuts, double currLen){
    if(currLen<minLen){
        minLen=currLen;
        resCuts=cuts;
    }

    if(index>=s.length() || s[index]=='0') return ;
    cuts++;
    index++;
    getCuts(s, index, minLen, resCuts, cuts, currLen/2.0);
    index++;
    getCuts(s,index, minLen, resCuts, cuts, currLen/2.0);
    return ;
}






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, len;
    string s="";
    // cin>>tests;
    // cin>>len;
    for(int a=0;a<10;a++){// 
        cin>>len;
        cin>>s;
        // cout<<"string s: "<<s<<endl;
        double minLen=1.1;
        int resCuts=0, index=0, cuts=0;
        getCuts(s,index,minLen, resCuts, cuts, 1.0);
        cout<<resCuts<<endl;
        // cin>>len;
    }

    return 0;
}
