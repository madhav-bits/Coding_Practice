/*
*
//**********************************************************697. Degree of an Array.***************************************************

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2]

[1,2,3,3,3,2,2]

[]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. In the first iteration, we save the indices of all numbers in the array. In the second iteration, we get the
// maxm. #occurances of a number in array. In the last iteration, we subtract the corner indices of numbers with max #occurances and get the least
// value of diff(there might be multiple nums with max #occurances).



// This version of algo. is sort of verbose and uses map to store first and last indices of occurances of all numbers in the array. But
// execution of this algo. is really slow.




class Solution {
public:
    int findShortestSubArray(vector<int>& v) {
        if(v.size()==1) return 1; 
        if(v.size()==0) return 0; 
        unordered_map<int, int> count;
        unordered_map<int, pair<int, int>> m;											// Stores first and last occurances of nums in array.
        for(int i=0;i<v.size();i++){
            count[v[i]]++;
            if(m.count(v[i])==0){
                m[v[i]].first=i;
                m[v[i]].second=i;
            }
            else{
                m[v[i]].first=min(m[v[i]].first,i);
                m[v[i]].second=max(m[v[i]].second,i);
            }
        }
        
        int maxm=INT_MIN, index=-1;
        vector<int> u;
        for(auto it=count.begin();it!=count.end();it++){                                    // Extracing the max. count of ints.
            if(it->second>maxm){
                maxm=it->second;
                u=vector<int>(1,it->first);
            }
            if(it->second==maxm) u.push_back(it->first);                                    // PUshes the values into vector.
        }
        int res, minm=INT_MAX;
        for(int i=0;i<u.size();i++){
            minm=min(minm, m[u[i]].second-m[u[i]].first+1);									// Get the len. of substr covering all same valued nums.
        }
        return minm;
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. In the first iteration, we save the indices of all numbers in the array. In the second iteration, we get the
// maxm. #occurances of a number in array. In the last iteration, we subtract the corner indices of numbers with max #occurances and get the least
// value of diff(there might be multiple nums with max #occurances).


// This algo. is same as that of Sln: 1, except that it optimizes space in second iteration.
// This algo. has the faster execution time of the three algos.





class Solution {
public:
    int findShortestSubArray(vector<int>& v) {
        if(v.size()==1) return 1; 
        if(v.size()==0) return 0; 
        unordered_map<int, vector<int>> count;
        for(int i=0;i<v.size();i++) count[v[i]].push_back(i);								// Saving all indices of occurances of all nums.
        
        int maxm=INT_MIN;																	// Tracks max. #occurances of ints in array.
        for(auto it=count.begin();it!=count.end();it++){                                    // Extracing the max. #occurances of ints.
            // cout<<"Curr. val: "<<it->first<<" and second size: "<<it->second.size()<<endl;
            if(int(it->second.size())>maxm) maxm=it->second.size();
            
        }
        int res, minm=INT_MAX;
        for(auto it=count.begin();it!=count.end();it++){
            // cout<<"Iterating with val: "<<it->first<<" and maxm: "<<maxm<<endl;		// Get the len. of substr covering all same valued nums.
            if(it->second.size()==maxm) minm=min(minm, it->second.back()-it->second[0]+1);// Extracting minm. substr of -nums with max #occurances.
        }
        return minm;
    }
};







//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. In the first iteration, we save the indices of all numbers in the array. In the second iteration, we get the
// maxm. #occurances of a number in array. In the last iteration, we subtract the corner indices of numbers with max #occurances and get the least
// value of diff(there might be multiple nums with max #occurances).


// This algo. is same as that of Sln: 1, except that it optimizes space in second iteration.
// This alg. is even shorter version of Sln: 2, it merges loop1, loop2, as a result #comparisions are increasing effecting execution time.




class Solution {
public:
    int findShortestSubArray(vector<int>& v) {
        if(v.size()==1) return 1; 
        if(v.size()==0) return 0; 
        unordered_map<int, vector<int>> count;
        int maxm=INT_MIN;
        for(int i=0;i<v.size();i++){
            count[v[i]].push_back(i);
            maxm=max(int(count[v[i]].size()),maxm);
        } 
        
        
        //for(auto it=count.begin();it!=count.end();it++)                                    // Extracing the max. count of ints.
        //    maxm=max(maxm,int(it->second.size()));
            
        int res, minm=INT_MAX;
        for(auto it=count.begin();it!=count.end();it++){
            // cout<<"Iterating with val: "<<it->first<<" and maxm: "<<maxm<<endl;
            if(it->second.size()==maxm) minm=min(minm, it->second.back()-it->second[0]+1);
        }
        return minm;
    }
};

