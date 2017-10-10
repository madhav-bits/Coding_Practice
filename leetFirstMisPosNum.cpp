/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

// INSPIRED BY OTHER'S SOLUTION.
//*****************************************************THIS IS LEET ACCEPTED CODE.*********************************************
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        if(v.size()==0)
          return 1;
        for(int i=0;i<v.size();i++){
            while(v[i]>0 && v[i]<=v.size() && v[i]!=v[v[i]-1]){// This last condition prevents stucking in infinite loop
                int temp;// When both the to be swapped values are same.
                temp=v[v[i]-1];
                v[v[i]-1]=v[i];
                v[i]=temp;
            }
        }
        
        for(int i=0;i<v.size();i++){
            if(v[i]!=i+1)
                return i+1;
        }
        return v.size()+1;
    }
};