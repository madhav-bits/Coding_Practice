/*
*
//********************************************1497. Check If Array Pairs Are Divisible by k.********************************************

https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/


Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return True If you can find a way to do that or False otherwise.

 

Example 1:

Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
Example 2:

Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).
Example 3:

Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
Example 4:

Input: arr = [-10,10], k = 2
Output: true
Example 5:

Input: arr = [-1,1,-2,2,-3,3,-4,4], k = 3
Output: true
 

Constraints:

arr.length == n
1 <= n <= 10^5
n is even.
-10^9 <= arr[i] <= 10^9
1 <= k <= 10^5



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,2,3,4,5,10,6,7,8,9]
5
[1,2,3,4,5,6]
7
[1,2,3,4,5,6]
10
[-10,10]
2
[-1,1,-2,2,-3,3,-4,4]
3
[-4,-7,5,2,9,1,10,4,-8,-3]
3



// Time Complexity: O(n+k).													// n- length of the array.
// Space Complexity: O(k).													// Num by which all pairs have to be divisible.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+k).													// n- length of the array.
// Space Complexity: O(k).													// Num by which all pairs have to be divisible.
// This algorithm is observation based. Here, we cnt #nums which leave a rem of 'i' in index 'i'. In case of neg. as they product neg. rems, 
// we make them posi. and store them in this array. Later, we iter. over with two ptrs, start=1, close=k-1, picking indices such that their
// addn would be divisible by k. In case of even 'k', we need to add 'k/2' rem. nums with themselves, so their cnt has to be even. If we
// face any issues, we return false. If we satisfied above all observations and haven't faced any issues. All pairs are divi. by k, we 
// return true.








class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>occur(k);
        for(auto num:arr){													// Cnting #nums. with same rem.
            occur[((num%k)+k)%k]++;
        }
        // for(int i=0;i<k;i++)
        //     cout<<"i: "<<i<<" and occur: "<<occur[i]<<endl;
        int i=1, j=k-1;														// Forming pairs whose addn. would be div. by 'k'.
        while(i<=j){														// Iter. over all possible rems and their cnt.
            if(i==j){														// In case of even 'k', mid rems have to be paired with themselves.
                if(occur[i]%2!=0) return false;								// So, their cnt has to even to form pairs.
            }else{
                if(occur[i]!=occur[j]) return false;					// If cnt. of pairing rems don't match, then all nums. can't form pairs.
            }
            i++;j--;														// Moving the iterator.
        }
        return true;														// No issues found and all pairs formed, return true.
    }
};

