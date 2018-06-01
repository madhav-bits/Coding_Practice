/*
*
//******************************************************532. K-diff Pairs in an Array.***********************************************

Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined 
as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,1,4,1,5]
2


[1,1,2,3,3,4,5,6,7]
2



[1, 3, 1, 5, 4,5,4,3]
0


[1, 2, 3, 4, 5]
1



[1, 2, 3, 4, 5,5,5]
2


[1, 2, 3, 4,4,4,-3,-1,-1,0,0, -5,5,5]
2


[-1,1,3,1,5,4]
2






// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is HashMap based. We save the count of occurances of all integers in array. In the second iteration in the map, we check for
// value-k, if it is there, we inc. the count. If k==0, we check for value, and if it's count is >=2, then only inc. the count.





class Solution {
public:
    int findPairs(vector<int>& v, int k) {
        if(v.size()<2 || k<0) return 0;										// We can't form PAIR of values.
        unordered_map<int, int> m;											// Stores count of all integers in array.
        int count=0;
        for(auto num:v) m[num]++;;											// Counts the int. in array.
        for(auto it=m.begin(); it!=m.end();it++){							// Iterating the array.
            if(k==0){														// In case of "0", if the count>1, then only inc. the count as we
                if(it->second>1) count++; 									// need to form a pair of values.
            }
            else{
                if(m.count(it->first-k) ) count++; 							// We check for curr. value-k.
                //if(m.count(v[i]+k)==1) count++;
            } 
        }
        return count;														// Returning the total no. of pairs.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is pointer based. We sort the array, we maintain two ptrs, pointing to the two values, we use to get the diff. Once, diff. is 
// found, we move the last ptr to the right, we also make sure that it moves past dulicate values. If curr. diff is >k, then we inc. the start
// index, else we inc. the last index(it means diff<k or start index is last-1 and waiting for it to increment it's value). On obtaining the 
// diff, we inc. the count.






class Solution {
public:
    int findPairs(vector<int>& v, int k) {
        if(v.size()<2 || k<0) return 0;
        int count=0;
        sort(v.begin(), v.end());											// Sort the given vector.
        int st=0, last=1;													// Pointing to values we are comparing to get diff.
        while(last<v.size()){												// Iterating through the entire array.
            int diff=v[last]-v[st]; 										// Calc. diff.
            if(diff==k){													// If req diff. is obtained.
                count++;													// We inc. the last index.
                last++;															
                while(v[last]==v[last-1]) last++;							// Moving past all duplicates.
            }
            else if(diff>k && st<last-1) st++;								// If curr. diff>k, we need to dec. diff by inc. the start value/index.
            else last++;													// If curr. diff<k/start is last-1 and waiting for last to inc.
        }
        return count;														// Returning the total no. of pairs.
    }
};