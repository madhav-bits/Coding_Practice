/*

//****************************************************PARTSUM - Partial Sums.********************************************************
https://www.spoj.com/problems/PARTSUM/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
//*****************************************************THIS IS NOT SPOJ ACCEPTED CODE.***********************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Set based solution. Here, so as to find closest value satisfying given cdns. We push the sums into set and use lower_bound
// to get closest value. The solution is receiving TLE errors.







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
#include<set>



using namespace std;



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    int tests;
    long long int vals, minDiff, mod;
    cin>>tests;

    for(int a=0;a<tests;a++){
        cin>>vals>>minDiff>>mod;
        vector<long long int>v(vals+1,0), total(vals+1,0);
        for(int i=1;i<=vals;i++){
            cin>>v[i];
            total[i]=(total[i]+total[i-1])%mod;
            total[i]=(total[i]+v[i])%mod;
        }

        set<int>st;
        st.insert(total.back());
        int diff=INT_MAX, res=-1;
        for(int i=total.size()-2;i>=0;i--){
            int val=total[i];
            long long int target=val+minDiff;
            if(target<mod){
                // cout<<"Searching for target: "<<target<<endl;
                auto it=lower_bound(st.begin(), st.end(), target);
                int val2=INT_MAX;
                if(it!=st.end()) val2=*it;
                // cout<<"obtained val: "<<val2<<" and diff: "<<val2-val<<endl;
                if(val2-val<diff) diff=val2-val;
            }else{
                target=target%mod;
                // cout<<"Searching for target: "<<target<<endl;
                auto it=lower_bound(st.begin(), st.end(), target);
                int val2=INT_MAX;
                if(it!=st.end()) val2=*it;
                // cout<<"obtained vall2: "<<val2<<" and diff: "<<mod-(val-val2)<<endl;
                long long int temp=mod-(val-val2);
                if(temp<diff) diff=temp;
            }
            // cout<<"inserting in curr. iter. total: "<<total[i]<<endl;
            st.insert(total[i]);
        }
        printf("%d \n", diff);
        // cout<<diff<<endl;
    }
    

    return 0;
}