/*

//***************************************************NOTATRI - Not a Triangle.*******************************************************
https://www.spoj.com/problems/NOTATRI/




Time Complexity:O(n^2)logn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O((n^2)logn).                                                  
// Space Complexity:O(n).                                                   
// This is Binary Search based solution. Here, since we need triangles we can't be formed, the third side needs to be larger than sum
// of two other sides. So, we choose two sides, and do binary search to get min index which satisfies our target condition and add
// all those indices to final result. As, we iterate over j, with i fixex, the sum of two numbers even further increases so, minIndex
// for new combi. would be to right of curr. minIndex, so we make it low for next iter. Thus, at end of iter. we get all combi. which
// won't form triangles.







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





int getIndex(vector<int>&v, int target, int low, int high){                 // Looking for min. height/index which cant form triangle.
    while(low<high){
        int mid=(low+high)/2;
        if(v[mid]<=target) low=mid+1;
        else high=mid;
    }
    return low;
}



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int nums;
    cin>>nums;
    while(nums!=0){
        vector<int>v(nums,0);
        for(int i=0;i<nums;i++) cin>>v[i];
        sort(v.begin(), v.end());
        int res=0;
        for(int i=0;i<nums-2;i++){
            int low=i+2, high=nums-1;
            for(int j=i+1;j<nums-1;j++){
                high=nums-1;
                int idx=getIndex(v,v[i]+v[j], low, high);
                // cout<<"i: "<<i<<" and j: "<<j<<" and idx: "<<idx<<endl;
                if(idx<nums && v[i]+v[j]>=v[idx]) idx++;                    // If curr. index(it would be last index) forms triangle, we inc. the index to make it equal to nums.
                res+=(nums-idx);
                low=idx;
            }
        }
        cout<<res<<endl;
        cin>>nums;
    }

    return 0;
}
