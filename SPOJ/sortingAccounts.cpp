/*

//*******************************************************SBANK - Sorting Bank Accounts.***********************************************************
https://www.spoj.com/problems/SBANK/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Map based. Storing the strings based on occurance in map and tracking their count. At the end iter. over maps, which would
// give increasing number of accounts with their counts.






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
#include<map>



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
        int accounts;
        cin>>accounts;
        map<string,int>m;
        cin.ignore();
        for(int b=0;b<accounts;b++){
            string temp;
            getline(cin,temp);
            m[temp]++;
        }
        for(auto it=m.begin();it!=m.end();it++){
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;
    }
    return 0;
}