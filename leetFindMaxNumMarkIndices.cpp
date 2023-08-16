/*
*
//******************************************2576. Find the Maximum Number of Marked Indices.******************************************

https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,5,2,4]
[9,2,5,4]
[7,6,8]
[3,5,6,8,15]
[5,7,4,34,6,66,4,3,34,4,56,7,8,8,76,4,3,35,6,78,8,3,3,87,67,7,4,22]
[5,7,4,34,6,66,4,3,34,4,56,7,8]
[5,7,4,34,6,66,4]
[5,7,4,34,6,66,4,3]
[3,4,4,5,6,7,34,66]
[14,15,16,17,18,19,20]
[4,5,8,8,8]
[1,2,4]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting+Greedy based. we first sort the array as it eases our process. We can get at max. n/2 pairs. So, we greedily try to pair nums from 
// first half with second half of nums in sorted array. If curr. lower*2>curr. higher value, all the greater lower values in first half also would be greater
// than curr. higher number, so we can't pair curr. high number with any unused lower number, so we skip it. In this way we move forward in right half and 
// when we meet the condition for any pair of [i,j], we then increase i from first half. At the end of iter. we retrun 2*i, as that gives how many lower half 
// values are paired with higher vals resulting in pairs.





// This discussion forum had explained the intuition better: 
// https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/discuss/3231114/Two-Pointers







public:
    int maxNumOfMarkedIndices(vector<int>& v) {
        sort(v.begin(), v.end());
        int i=0, len=v.size();
        for(int j=(len/2);j<len && i<len/2;j++) {							// Ensuring first half iter. won't enter second half.
            if(2*v[i]<=v[j]) i++;											// When a pair is formed.
        }
        return 2*i;															// Returning #marked indices that meets the condition.
    }
};

