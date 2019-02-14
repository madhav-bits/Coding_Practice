/*

//*******************************************************FCTRL - Factorial.***********************************************************
https://www.spoj.com/problems/FCTRL/




Time Complexity:O(n^2logk).                                                                                                                                                                                             
Space Complexity:O(k).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2logk).                                                  
// Space Complexity:O(k).                                                   
// This is Priority Queu based solution. Here, we push sums into PQ, while making sure that the size of PQ remains that of target rank.
// Then the top of PQ would be kth ranked subset sum.


// I am getting Time Limit Exceeded errors.







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



#define ll long long


using namespace std;




// struct comp{
//     bool operator()(ll&lt, ll&rt){    // Max. Heap.
//         return lt<rt;
//     }
// };


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    ll nums, target;
    cin>>nums>>target;

    vector<ll>v(nums);
    bool found=false;
    priority_queue<ll>pq;
    for(int i=0;i<v.size();i++) cin>>v[i];
    for(int i=0;i<v.size();i++){
        ll sum=0;
        for(int j=i;j<v.size();j++){
            sum+=v[j];
            if(pq.size()==target){
                if(sum<pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }else pq.push(sum);
        }
    }
    cout<<pq.top()<<endl;
    return 0;
}