/*

//*******************************************************B. Xenia and Colorful Gems.***********************************************************
https://codeforces.com/problemset/problem/1336/B

This is CodeForces Round-635 Div1. Problem B.



Time Complexity:O(nlogn+mlom+llogl).                                        // m, n, l are three array sizes.                                                                                                                                                                                              
Space Complexity:O(n+m+l).                                                                                                        

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn+mlom+llogl).                                     // m, n, l are three array sizes.                                 
// Space Complexity:O(n+m+l).                                                       
// This is Sorting based. Here, since we are trying to minimize the value the picked values has to be as close to each other
// as possible. We sort all the arrays. We pick a value from one of the array. For it 2 closest values in each of the two other
// arrays. We cover this by using lower_bound on one of the array and upper_bound on the other array. Which covers one possib.,
// we swap the other two arrays, do the same, this covers one other possib. We are left with two cases where other two values are
// on the same side curr. value. We also do the same with two other arrays being the primary array, this covers the same side 
// cases. Thus, we cover all possib. and even find even closer triplets.





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





void findMinimumGap(long long int &res, vector<int>&u, vector<int>&v, vector<int>&w){
    for(int i=0;i<u.size();i++){
        int x=u[i];
        auto it=lower_bound(v.begin(), v.end(), x);
        auto it2=upper_bound(w.begin(), w.end(), x);
        if(it==v.end() || it2==w.begin()) continue;
        it2--;
        int y=*it, z=*it2;
        // cout<<"curr: "<<x<<" and y: "<<y<<" and z: "<<z<<endl;
        res=min(res, 1ll*(x-y)*(x-y)+1ll*(x-z)*(x-z)+1ll*(y-z)*(y-z));
    }
    return ;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, red, blue, green;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>red>>blue>>green;
        vector<int>reds(red), blues(blue), greens(green);
        for(int i=0;i<red;i++) cin>>reds[i];
        for(int i=0;i<blue;i++) cin>>blues[i];
        for(int i=0;i<green;i++) cin>>greens[i];

        sort(reds.begin(), reds.end());                                     // Sorting all three arrays.
        sort(blues.begin(), blues.end());
        sort(greens.begin(), greens.end());
        long long int res=9e18;                                             // Tracks minm. value of the equation.
        
        findMinimumGap(res, reds, greens, blues);                           // Finding triplets where reds is primary array.
        findMinimumGap(res, reds, blues, greens);
        findMinimumGap(res, blues, reds, greens);                           // Finding triplets where blues is primary array.
        findMinimumGap(res, blues, greens, reds);
        findMinimumGap(res, greens, reds, blues);                           // Finding triplets where greens is primary array.
        findMinimumGap(res, greens, blues, reds);
        
        cout<<res<<endl;    
    }
    return 0;
}
