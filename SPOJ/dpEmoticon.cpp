/*

//*******************************************************BLKEK - Emoticon.***********************************************************
https://www.spoj.com/problems/BLKEK/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(1).                                                   
// This is Dynamic Programming based solution. Here, we need diff. combinations of "KEK", so we focus on #first K's, E's and second K's.
// Here, when we face 'K', it acts as both second/first 'K', as second 'K', it converts all E's to KEK. So, we add #E's to final result.
// Now, it acts a first 'K', We will also inc. the count of 'K'. Whenever we encounter 'E', it converts all first 'K's till then into 
// KEs, we inc. the count of Es by first Ks. Thus, at the end of iter. we have final result storing all combinations of KEKs.









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

    int tests;
    cin>>tests;
    string s="";
    for(int a=0;a<tests;a++){
        cin>>s;
        long long int res=0;
        int first=0, second=0;
        int index=0;
        while(index<s.length()){
            if(s[index]=='K'){
                res+=second;                                                // #occurances of KE's converted to KEKs.
                first++;
            }else if(s[index]=='E') second+=first;                          // #occurances of K's till then are converted to KEs.
            // cout<<"index: "<<index<<" and sum: "<<res<<endl;
            index++;
        }
        cout<<res<<endl;
    }

    return 0;
}
