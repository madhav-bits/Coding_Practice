/*
*
//******************************************1619. Mean of Array After Removing Some Elements.*******************************************

https://leetcode.com/problems/mean-of-array-after-removing-some-elements/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on test cases provided with the question.



// Time Complexity: O(nlogn). 												// n- length of the array. 
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n- length of the array. 
// Space Complexity: O(1).	
// This algorithm is sorting based. Here, we sort the array and get the total from 5% to 95% length of sorted array length. We divide
// with 0.9*v.size() to get the mean of the total.

// Another solution which is apt if the array length is large is maintaining two PRIORITY QUEUES max and min to extract bottom 5% and 
// maxm 5% values and substract their total from entire sum of array to get remaining sum, calculate it's mean and return it.
// Time Complexity: O(nlogk) 												// k=n/20.		
// Space Complexity: O(k)




class Solution {
public:
    double trimMean(vector<int>& v) {
        // int len=v.size()/20, total=0, sub=0;
        // priority_queue<int, vector<int>, greater<int>>minPQ;
        // priority_queue<int>maxPQ;
        // for(int i=0;i<v.size();i++){
        //     total+=v[i];
        //     minPQ.push(v[i]);
        //     maxPQ.push(v[i]);
        //     if(minPQ.size()>len) minPQ.pop();
        //     if(maxPQ.size()>len) maxPQ.pop();
        // }
        // while(!minPQ.empty()){
        //     sub+=minPQ.top();
        //     minPQ.pop();
        // }
        // while(!maxPQ.empty()){
        //     sub+=maxPQ.top();
        //     maxPQ.pop();
        // }
        // return (0.0+total-sub)/(0.9*v.size());
        sort(v.begin(), v.end());
        double total=0;
        int len=v.size()/20;
        for(int i=len;i<v.size()-len;i++){
            total+=v[i];
        }
        return (0.0+total)/(0.9*v.size());
    }
};