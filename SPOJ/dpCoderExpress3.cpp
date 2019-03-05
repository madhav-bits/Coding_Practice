/*

//***************************************************CODERE3 - Coder Express 3!!.*****************************************************
https://www.spoj.com/problems/CODERE3/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. This is slight variation of Longest Increasing Subsequence problem. Here, we look for 
// increasing sequences from both ends, so we maitaind two dp arrays and calc. increasing subseq. from both ends by performing DP
// process two times. The longest subseq. can have it's peak at any index, So we iter. over two arrays and get the maxm. total
// subseq. length with curr. index as it's peak and return the best of those sums.


// inc[i] indicates maxm. length of inc. subseq ending at index 'i'.

// dec[i] indicates maxm. length of dec. subseq starting at index 'i'.




// This can also be solved in O(nlogn) time, but it's sort of complicated to implement.






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

    for(int a=0;a<tests;a++){
        int boxes;
        cin>>boxes;
        vector<int>v(boxes,0), inc(boxes, 1), dec(boxes,1);
        for(int i=0;i<boxes;i++) cin>>v[i];

        for(int j=1;j<v.size();j++){
            for(int i=j-1;i>=0;i--){
                if(v[i]<v[j]) inc[j]=max(inc[j], inc[i]+1);
            }
        }

        for(int i=v.size()-1;i>=0;i--){
            for(int j=i+1;j<v.size();j++){
                if(v[i]>v[j]) dec[i]=max(dec[i], dec[j]+1);
            }
        }
        int res=0;
        for(int i=0;i<v.size();i++){
            // cout<<"i: "<<i<<" and inc: "<<inc[i]<<" and dec: "<<dec[i]<<endl;
            res=max(res, inc[i]+dec[i]-1);                                  // As, peak in counted in two arrays we subtract 1.
        }
        cout<<res<<endl;

    }
    


    return 0;
}