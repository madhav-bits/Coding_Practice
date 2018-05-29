/*
*
//**************************************************581. Shortest Unsorted Continuous Subarray.*******************************************

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array 
will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[2,4,6,8,8,10,9,8,14,15]
[2,6,4,8,10,9,15]
[]
[1,2,3,4]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. In the first two iterations, we calculate the indices till whom the values are in order. If the iterators
// reach the end of vector, then there is no unsorted elem. in array. Next, we find the smallest and largest misplaced value. In the last two iter.
// we will find the correct indices for these values, we subtract these values+1 to get number of indices need to ordered.








class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        int res=0;
        int i1=0, i2=v.size()-1, small=INT_MAX, large=INT_MIN;
        while(i1+1<v.size() && v[i1+1]>=v[i1]) i1++;								// Calc. last proper valued index from start.
        while(i2-1>=0 && v[i2-1]<=v[i2]) i2--;										// Calc. last proper valued index from end.
        
        //cout<<" i1: "<<i1<<" and i2: "<<i2<<endl;
        if(i1==v.size()-1 && i2==0) return 0;										// If no unsorted elem. exists, return 0.
        while(i1<v.size()){															// Calc. least valued misplaced elem.
            small=min(small,v[i1]);
            i1++;
        }
        while(i2>=0){																// Cacl. largest valued misplaced elem.
            large=max(large,v[i2]);
            i2--;
        }
        
        int i=0, j=v.size()-1;
        while(i<v.size() && v[i]<=small) i++;										// Calc. the proper index for the smallest misplaced value.
        while(j>=0 && v[j]>=large) j--;												// Calc. the proper index for the largest misplaced value.
        //cout<<"i: "<<i<<" and j: "<<j<<endl;
        return j-i+1;																// Returning #indices need to be ordered.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. In the first two iterations, we calculate the indices till whom the values are in order. If the iterators
// reach the end of vector, then there is no unsorted elem. in array. Next, we find the smallest and largest misplaced value. In the last two iter.
// we will find the correct indices for these values, we subtract these values+1 to get number of indices need to ordered.

// This is slightly improved version, which dec. number of iterations.






class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        int res=0;
        int i1=0, i2=v.size()-1, small=INT_MAX, large=INT_MIN;
        while(i1+1<v.size() && v[i1+1]>=v[i1]) i1++;
        while(i2-1>=0 && v[i2-1]<=v[i2]) i2--;
        //cout<<" i1: "<<i1<<" and i2: "<<i2<<endl;
        if(i1==v.size()-1 && i2==0) return 0;
        for(int k=i1;k<=i2;k++){                                //i1, i2 are last indices whose values are arrnaged.
            small=min(small, v[k]);
            large=max(large, v[k]);
        }
        
        int i=0, j=v.size()-1;
        while(i<=i1 && v[i]<=small) i++;
        while(j>=i2 && v[j]>=large) j--;
        //cout<<"i: "<<i<<" and j: "<<j<<endl;//[2,4,6,8,8,10,9,8,14,15]
        return j-i+1;
    }
};