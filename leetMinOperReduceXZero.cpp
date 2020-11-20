/*
*
//******************************************1658. Minimum Operations to Reduce X to Zero.************************************************

https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,1,4,2,3]
5
[5,6,7,8,9]
4
[3,2,20,1,1,3]
10
[2,5,2,6,3,2,6,7,8,5,5,4]
12
[8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309]
134365



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. Here, since all nums are posi. we can use this method. At every stage we add num. into 
// window, we keep deleting nums. from start of window until the total is<=target value. If the window total is target, we try to
// maximize the window size, as the non-window portion which contributes to x would be of least size. If no satisfying window is 
// found, we return -1.








class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int start=0, sum=0, res=0, total=0;
        for(auto num:v) total+=num;
        if(total<x) return -1;
        if(total==x) return v.size();
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            while(sum>(total-x))
                sum-=v[start++];
            // cout<<"i: "<<i<<" and sum: "<<sum<<endl;
            if(sum==(total-x))
                res=max(res, i-start+1);
        }
        return (res==0)?-1:v.size()-res;
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is HashMap based. Here, we store the cumulative of nums. in array. We store those values in map, at every stage, 
// we look for curr. sum-target to check whether we are able to get a subarray whose sum is target and we try to maximize the subarr.
// length, which makes required deleting indices to be less as possible.




class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int total=0;
        for(auto num:v) total+=num;
        if(total<x) return -1;
        if(total==x) return v.size();
        unordered_map<int,int>m;
        int target=total-x;
        // cout<<"total: "<<total<<" and target: "<<target<<endl;
        m[0]=-1;
        int curr=0, res=-1;
        for(int i=0;i<v.size();i++){										// Iter. over entire array.
            curr+=v[i];
            if(m.count(curr)==0) m[curr]=i;									// Updating map with curr. sum.
            if(m.count(curr-target)==1){									// If subarr. with target sum is found. Maxi. window size.
                res=max(res, i-m[curr-target]);
                // cout<<"i: "<<i<<" and prev: "<<m[curr-target]<<endl;
            }
            
        }
        return (res==-1)?-1:v.size()-res;									// Returning the length of indices to be deleted.
    }
};
