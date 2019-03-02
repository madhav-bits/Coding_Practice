/*

//***********************************************************EKO - Eko.***************************************************************
https://www.spoj.com/problems/EKO/




Time Complexity:O(nlogn+n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn+n).                                                  
// Space Complexity:O(n).                                                   
// This is Sorting based solution. Here, we are looking for greatest height which gives required volume, which reduces wastage 
// of logs. SO, we iterate from the right, at each step, we calc. the vol. obtained with that height. We return the last encountered
// height satisfying given cdns. We skip those indices whose height already produces more than target volume. As, they are covered
// when calc. volumes for their next indices.







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

    
    int nums, target;
    cin>>nums>>target;
    vector<int>v(nums);
    for(int i=0;i<nums;i++) cin>>v[i];
    sort(v.begin(), v.end());


    int total=0, res=0;
    for(int i=v.size()-1;i>=0;i--){
        if(total>target) break;
        int fol=v.size()-i;
        int diff=(target-total)/fol;
        if(total+(diff*fol)!=target) diff++;
        // cout<<"i: "<<i<<" and val: "<<v[i]<<" and diff: "<<diff<<endl;
        res=v[i]-diff;
        if(i>0)
        total+=(v[i]-v[i-1])*fol;
    }
    cout<<res<<endl;
    return 0;
}












//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(nlogn+(logn)^2)=O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Binary Search based solution. We take lowest, highest possible values, check whether they satisfy given cdns are not, if 
// true, include it in the reduced interval. At last return the start of the interval. We find the index of the mid value, we calc.
// the volume of logs obtained with this height using the precomputed array, which tracks vol. of logs available for given heights.








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

    
    int nums, target;
    cin>>nums>>target;
    vector<int>v(nums);
    for(int i=0;i<nums;i++) cin>>v[i];
    sort(v.begin(), v.end());


    long long int total=0, res=0;
    vector<long long int>contri(nums,0);
    for(int i=v.size()-2;i>=0;i--){
        int fol=v.size()-i-1;
        contri[i]=contri[i+1]+(v[i+1]-v[i])*fol;
    }
    // for(auto it=v.begin();it!=v.end();it++) cout<<*it<<" ";
    // cout<<endl;
    // for(auto it=contri.begin();it!=contri.end();it++) cout<<*it<<" ";
    // cout<<endl;
    long long int low=0, high=v.back();
    while(low<high){
        int mid=(low+high+1)/2;
        int idx=upper_bound(v.begin(), v.end(), mid)-v.begin();
        
        // cout<<"low: "<<low<<" and high: "<<high<<" and mid: "<<mid<<" and idx: "<<idx<<endl;
        int fol=v.size()-idx;
        // cout<<"vol: "<<contri[idx]+(v[idx]-mid)*fol<<endl;
        if(contri[idx]+(v[idx]-mid)*fol>=target) low=mid;
        else high=mid-1;
    }
    cout<<low<<endl;

    return 0;
}



