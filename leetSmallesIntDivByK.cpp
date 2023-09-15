/*
*
//*********************************************1015. Smallest Integer Divisible by K.***********************************************

https://leetcode.com/problems/smallest-integer-divisible-by-k/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
3
2
34
67
78548
335
73954
8
7678
546
36
9456
34
679
68
45
23
5235



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n-divisor provided in question.
// Space Complexity: O(1).	
// This algorithm is iteration and Modulo Arithmatic based. As we need nums comprising only '1's but divisible by k, we keep adding 1s and keep checking if 
// it's div by k. If we have a divisor which can't have any num with 1s divisibly by k, it would form a cycle of length<=k, as we can only produce k diff.
// remainders, if there is cycle it must be<=k length. So, we iter. k times and check if it's divisible by k/produces 0 remainder, if yes we return length 
// of string else we return -1, if we didn't find 0 in first k  iter. that means atleast one of the rem. remainders reoccurred once again making a cycle.
// As the length of the string can be huge and might not fit into any possible int types, we only track modulo remainders and keep adding next ints to it.
// As removing the part of the num which is divisible by k, doesn't affect our result as multiply any other num with it will once again lead to multiple of k.
// So we focus on extra part of verify if that's divisible by 5.



// Same approach as the above one, but here we used map to find the cycle.




class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // if(k==1) return 1;
        // bool occur[k+1];
        // memset(occur, false, sizeof(occur));
        // int num=0, len=1;
        // while(occur[num]==false) {										// As long as there is no cycle.
        //     occur[num]=true;
        //     num=(num*10+1)%k;											// Get modulo remainder of curr. num.
        //     if(num==0) return len;										// If divisible by k, return length of string.
        //     len++;
        // }
        // return -1;														// We return -1 if there is a cycle and we can't get 0 remainder.
        
        int num=0;
        for(int i=0;i<k;i++) {												// Iter. k times.
            num=(num*10+1)%k;												// Calc. modulo remainder for curr. num
            if(num==0) return i+1;											// If div by k, we return length of the string.
        }
        return -1;															// We return -1 if there is a cycle and we can't get 0 remainder.
    }
};

