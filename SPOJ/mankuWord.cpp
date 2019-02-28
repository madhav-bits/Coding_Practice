/*

//*****************************************************MAY99_2 - Manku Word.*********************************************************
https://www.spoj.com/problems/MAY99_2/




Time Complexity:O(logn/log5).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn/log5).                                                  
// Space Complexity:O(1).                                                   
// This is numericals based solution. This is basically implementing a new denotion of numbers, with slightly different ranking, 
// instead of starting from '0', it starts from '1', which is handled specifically in the logic, we first extract the LSB from the 
// given rank, if the rank is '0', then we change it to '5', else we change it to rem-1 and add it to final stirng, we remove this 
// modified rem from the number and calc. the chars for the rest of the rank until the rank is >0.








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

    
    unordered_map<int,char>m;
    m[0]='m'; m[1]='a'; m[2]='n'; m[3]='k'; m[4]='u';

    int tests;
    cin>>tests;

    unsigned long long int rank;
    for(int a=0;a<tests;a++){
        cin>>rank;
        // rank--;
        string res="";
        while(rank>0){
            int rem=rank%5;
            if(rem==0){                                                     // we change '0' to '5'/'u' in the string.
                res+='u';
                rank-=5;   
            } 
            else{                                                           // Else remainders are changed to 'rem-1' before adding to string.
                res+=m[rem-1];
                rank-=rem;
            }             
            rank/=5;
        }
        reverse(res.begin(), res.end());
        cout<<res<<endl;
    }

    return 0;
}