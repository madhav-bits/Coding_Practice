/*
*
//**********************************************2550. Count Collisions of Monkeys on a Polygon.**********************************************

https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/ence.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


7
10
11
3
4
5
6
1000000000
10000000
927383471



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is observation based. For a polygon of n sides, on each vertex we have 2 drns to move, so we have 2^n ways to move, out of it only two ways
// avoid collision, it is when all of them move in same drn, that is either CW or ACW. So, we calc. (2^n-2)%mod and return it.







class Solution {
public:
    int monkeyMove(int n) {
        int res=1, mod=1000000007;
        int prod=2;
        while(n) {															// Calc. #ways available to move, that is (2^n)%mod
            if((n%2)==1) res=(1ll*res*prod)%mod;
            n>>=1;
            prod=(1ll*prod*prod)%mod;
        }
        res=(res-2+mod)%mod;												// subtracting 2, as 2 ways would prevent collision(All moving in CW/ACW drn).
        return res;															// Returning total #ways which causes atleast one collision.
    }
};

