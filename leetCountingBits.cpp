/*

//******************************************************338. Counting Bits.**************************************************

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in 
their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in 
linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Credits:
Special thanks to @ syedee for adding this problem and creating all test cases.


//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

// Solution 1: 
//Starting from zero, we find max. overlap b/w current and previous numbers, thus finding common bits, till then, so we need to add one more-
//- 1 bit to it.



class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i=1;i<=num;i++)							//Starting from 1, as 0 by default has zero 1 bits.
            res[i]=res[i&(i-1)]+1;						//Finding max. overlap b/w curr. and previous numbers and adding 1 more 1 bit to it.
        return res;
    }
};