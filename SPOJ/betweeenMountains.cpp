/*

//************************************************ACPC11B - Between the Mountains.****************************************************
https://www.spoj.com/problems/ACPC11B/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Sorting based solution. Here, since we need numbers which are close to each other, we sort the two arrays, iter. over
// two arrays from least to highest. While comparing two values, that would be the least diff. pair the smallest of them could form with
// num. from other array. So, we try to update the final result var. with the abs diff. and inc. the ptr of smaller value's array with
// hope we might find num. even more closer to larger number. We do this until we reach end of one of the arrays. Print the minm. diff
// encountered in the process.





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

    int tests, len1, len2;
    cin>>tests;
    for(int a=0;a<tests;a++){
        cin>>len1;
        vector<int>u(len1);
        for(int i=0;i<len1;i++) cin>>u[i];
            cin>>len2;
        vector<int>v(len2);
        for(int i=0;i<len2;i++) cin>>v[i];
        sort(u.begin(), u.end());
        sort(v.begin(), v.end());
        int res=INT_MAX;
        int i=0, j=0;
        while(i<u.size() && j<v.size()){
            res=min(res, abs(u[i]-v[j]));
            if(u[i]<v[j]) i++;
            else j++;
        }
        cout<<res<<endl;
    }

    return 0;
}
