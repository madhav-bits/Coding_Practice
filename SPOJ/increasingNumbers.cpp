/*

//***************************************************NDS - Increasing numbers.*******************************************************
https://www.spoj.com/problems/NDS/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(m).                                                      // Length of sequence we want to maintain.                                          

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(m).                                                   // Length of sequence we want to maintain.                                                   
// This is Binary Search based solution. Here, we are trying to find the Increasing subsequence of length 'L'. In that subsequence
// we are returning minm. possible value. Here, for every index, we try to push into sequence we are maintaining separately. We find
// the index, which holds closest greater value to curr. value, if curr. value is greater than all values of sep. sequence, we 
// append it to end of sequence. We also make sure that the length of sequence is capped to required length. Since we are replacing
// closest value with a smaller value, we will have smallest possible value at last index. After the entire process
// we return the value stored in last index.










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



int getPsn(vector<int>&res, int target){                                    // Returns the index, which holds closest greater value to curr. number.
    int low=0, high=res.size()-1;
    while(low<high){
        int mid=(low+high)/2;
        if(res[mid]<=target) low=mid+1;
        else high=mid;
    }
    return low;
}

void getNumber(vector<int>&v, vector<int>&res, int rank){

    for(int i=0;i<v.size();i++){
        if(res.size()==0 || (res.size()<rank && res.back()<v[i])) res.push_back(v[i]);
        else if(res.size()<=rank && v[i]< res.back()){                      // The size of array shouldn't increase.
            int index=getPsn(res,v[i]);
            // cout<<"prev num: "<<res[index]<<" and updating num: "<<v[i]<<endl;
            if(index==0 || res[index-1]!=v[i]) res[index]=v[i];
        }
    }
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nums, len;
    cin>>tests;
    for(int a=0;a<tests;a++){
        cin>>nums;
        vector<int>v(nums);
        for(int i=0;i<nums;i++) cin>>v[i];
        cin>>len;
        // cout<<"arr size; "<<v.size()<<" and seq len: "<<len<<endl;
        vector<int>res;
        getNumber(v,res, len);
        // cout<<"res size: "<<res.size()<<endl;
        if(res.size()==len) cout<<res.back()<<endl;
        else cout<<-1<<endl;    
    }
    

    return 0;
}
















//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(m).                                                   // Range of values allowed(1000000).                                                   
// This is Binary Indexed Tree based solution. Here, we are trying to find the Increasing subsequence of length 'L'. We find the
// maxm. length subsequence ending at  values from [1, curr. value-1]. We assign max. length in earlier values and assign it to 
// curr. value and update BIT accordingly. Since, we want maxm. value among prefix values, we can use BIT.









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



void update(vector<int>&tree, int index, int val){                          // Here, we are updating that max. len sequence ending at curr. index would be val/ earlier value.
    while(index<tree.size()){
        tree[index]=max(tree[index], val);
        index=index+(index&(-index));
    }
}





int getMaxLenSequence(vector<int>&tree, int index){                         // We extract maxm. value from start index till given index.
    int res=0;
    while(index>0){
        res=max(tree[index], res);
        index=index-(index&(-index));
    }
    return res;
}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

   
    int tests, nums, len;
    cin>>tests;
    for(int a=0;a<tests;a++){
        cin>>nums;
        vector<int>tree(1000002,0);
        int num, res=INT_MAX;
        vector<int>v(nums);
        for(int i=0;i<nums;i++) cin>>v[i];
        cin>>len;
        for(int i=0;i<nums;i++){
            v[i]++;                                                         // Converting the nums to start from 1.
            int prev=getMaxLenSequence(tree,v[i]-1);
            // cout<<"num: "<<v[i]<<" and maxLenSequence: "<<prev<<endl;
            if(prev==len-1) res=min(res, v[i]-1);                           // If it has len-1 less than curr. value, then try to udpate final result.
            update(tree, v[i], prev+1);                                     // We update that maxm. value at v[i] index would be prev+1.
        } 
        
        // cout<<"arr size; "<<v.size()<<" and seq len: "<<len<<endl;
        if(res==INT_MAX) cout<<-1<<endl;
        else cout<<res<<endl;   
    }

    return 0;
}
