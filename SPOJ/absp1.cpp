/*

//*******************************************************ABSP1 - abs(a-b) I.***********************************************************
https://www.spoj.com/problems/ABSP1/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(1).                                                   
// This is observation based. One observation is that cumulative of mod operations is valid, if each of inner terms are all positive
// or all negative, here if we form pairs where first element would be smaller value/ smaller index and second would be of larger 
// value/larger index. We can accumulate this by summing all first terms as we read from STDIN in an var. When at an index 'i', we 
// have 'i-1' prev. values with which curr. forms pairs, we have all their sum, we get cumulative second term by mult. curr. num by 
// it's index and get abs diff. and add it to result. At end of iter., return the result.





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

    long long int res=0, prev=0, len=0;
    for(int a=0;a<tests;a++){
        cin>>len;
        cin>>prev;
        res=0;
        long long int num;
        for(int i=1;i<len;i++){
            cin>>num;
            res+=abs(prev-(num*i));
            // cout<<"prev: "<<prev<<"and num: "<<num<<endl;
            prev+=num;
        }
        cout<<res<<endl;
    }
    
    return 0;
}