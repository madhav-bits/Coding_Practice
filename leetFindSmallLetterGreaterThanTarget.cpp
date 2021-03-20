/*
*
//***********************************************744. Find Smallest Letter Greater Than Target.***********************************************

https://leetcode.com/problems/find-smallest-letter-greater-than-target/


Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list 
that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"
Note:
letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique letters.
target is a lowercase letter.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


["c","f","j"]
"a"
["c","c","d"]
"c"



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, we first target corner cases where target char is out of range of given chars or equal to last char, 
// so that we would return first char as answer as Letters wrap around. Then we do Bin. Search, if the mid index char<= target char, we move to next 
// index and search in right half hoping greater char in it, if mid index char> target char we pick the high as this this char would satisfy given 
// requirement and search in left half, the char that low index would point at the end of search is the answer and it would be > target char.









class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char target) {
        if(target<v[0] || target>=v.back()) return v[0];					// Corner cases where target is out of given chars range.
        int low=0, high=v.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(v[mid]<=target) low=mid+1;									// If mid<=target char, we search in right half.
            else high=mid;													// If mid>target char, we search in lower half.
        }
        return v[low];														// Return the result char, which is > target char.
    }
};

