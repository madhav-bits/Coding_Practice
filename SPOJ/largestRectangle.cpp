/*

//*******************************************HISTOGRA - Largest Rectangle in a Histogram.********************************************
https://www.spoj.com/problems/HISTOGRA/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Stack based solution. Here, we find/track the all the possible rectangles each index would influence. If we have height
// 'h' at index 'i', then this would be influence the heigt of the rectangle to it's left, right sides till the heights in those
// indices are greater than 'h', this requirement ideally suits stack usage. We use stack to keep track of indices with closest
// smaller height indices on both sides to each index, we return the maxm. possible area of rectangle formed.











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

    int nums;
    cin>>nums;
    while(nums!=0){
        vector<long long int>v(nums);
        for(int i=0;i<nums;i++) cin>>v[i];
        v.push_back(-1);
        stack<int>st;
        st.push(0);
        long long int res=0;
        for(int i=1;i<v.size();i++){
            while(!st.empty() && v[st.top()]>v[i]){
                int curr=st.top();
                st.pop();
                if(st.empty()) res=max(res, (long long int)i*v[curr]);
                else{
                    res=max(res, (long long int)v[curr]*(i-st.top()-1));
                }
            }
            st.push(i);
        }

        cout<<res<<endl;
        cin>>nums;
    }

    return 0;
}
