/*

//*********************************************************CRDS - Cards.*************************************************************
https://www.spoj.com/problems/CRDS/




Time Complexity:O(1).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                  
// Space Complexity:O(1).                                                   
// This is Observation based. Here, we get the #cards for given #level from the formula obtained from observation. Here, since
// we have div. as part of calculation, I tried to evade doing inverse modulo calc. by performing mod on level provided and 
// gathering #cards in long long int format, at the end we calc. the modulo and print the result.









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
    int mod=1000007;
    for(int a=0;a<tests;a++){
        long long int level;
        cin>>level;
        level%=mod;
        // long long int numer=(level*((3*(level+1))%mod))%mod;
        long long int numer=(level*((3*(level+1))));
        numer=numer/2;                                                      // As we have div, to avoid inverse modulo calc. 
                                                                            // just taken entire value and calc. mod value then.
        // level=level%mod;
        numer-=level;
        cout<<numer%mod<<endl;
    }
    return 0;
}