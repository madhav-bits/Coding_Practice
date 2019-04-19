/*

//***************************************************PAIRS1 - Count the Pairs.*******************************************************
https://www.spoj.com/problems/PAIRS1/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(1).                                                   
// This is Sorting and Binary Search based solution. Here, we sort the given numbers, then perform binary search for greater number 
// that is diff greater than curr. num, once found, we move to next smaller value, once again perform the same step. Until we have
// a range of values to search higher value in.







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

    int nums, diff;
    cin>>nums>>diff;
    vector<int>v(nums,0);
    for(int i=0;i<nums;i++) cin>>v[i];
    sort(v.begin(), v.end());
    int res=0;
    int i=0, low=0, high=v.size()-1;
    while(low<v.size()){
        high=v.size()-1;
        while(low<=high){
            // cout<<"i: "<<i<<" and low: "<<low<<" and high: "<<high<<endl;
            int mid=(low+high)/2;
            if(v[i]+diff==v[mid]){
                // cout<<"i: "<<i<<" and matched at mid: "<<v[mid]<<endl;
                low=mid+1;                                                  // Shortened Binary Search range for next search.
                res++;
                break;
            }else if(v[i]+diff<v[mid]) high=mid-1;
            else low=mid+1;
        }
        i++;
    }
    cout<<res<<endl;

    return 0;
}
