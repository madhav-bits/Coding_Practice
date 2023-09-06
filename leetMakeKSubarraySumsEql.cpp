/*
*
//**************************************************2607. Make K-Subarray Sums Equal.**************************************************

https://leetcode.com/problems/make-k-subarray-sums-equal/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,4,1,3]
2
[2,5,5,7]
3
[25,74,93,65,7,89,6,33,12,95,73,8,89,24,43,66,9,9,23,76,38,56,35,65,68,6,7,9,23,1,34,45]
7
[25,74,93,65,7,89,6,33,12,95,73]
7



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Observation based. We see that all indices which leave same rem in index%k should have same value so that window has constant total as it 
// slides. There would be connection b/w indices giving diff. remainders at the end of array as the array is circular. We also see that index leaving rem j is 
// only connected i rem index and it can't connect with any other diff. rem. index as this connection occurs in only last window indices, which gives us a 
// conclusion that once we start and cover all connected indices until we can't find anymore unvisited indices in loop. We won't have any other later loops
// converging with these indices as each diff. rem indices pair with only 1 diff. index and these are covered in earlier loops.
// So, we start loop and collect all connected indices and find the median so that #oper. to have a common value would be minm and change all vals to median val.
// We calc. #oper. needed and add it to res and return it at the end of iter.






class Solution {
public:
    long long makeSubKSumEqual(vector<int>& v, int k) {
        long long int res=0;
        for(int i=0;i<k;i++) {
            if(v[i]==0) continue;											// If already covered, skip this loop.
            vector<int>arr;
            int j=i;
            while(v[j]!=0) {												// Collect all connected indices.
                arr.push_back(v[j]);
                v[j]=0;
                j=(j+k)%v.size();
            }
            nth_element(arr.begin(), arr.begin()+(arr.size()/2), arr.end());// Find the median of connected indices.
            // for(int num:arr) cout<<num<<" ";
            // cout<<endl;
            int median=arr[arr.size()/2];
            // cout<<"i: "<<i<<" and val: "<<median<<endl;
            for(int num:arr) {												// Calc. #oper. to convert all nums to median num.
                if(num>median) res+=num-median;
                else res+=median-num;
            }
        }
        return res;															// Returning minm #oper needed so that K-subarray sum remains constant.
    }
};

