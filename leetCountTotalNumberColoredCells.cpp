/*
*
//******************************************************2579. Count Total Number of Colored Cells.******************************************************

https://leetcode.com/problems/count-total-number-of-colored-cells/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
2
3
4
7
8
13
15
78
67
54
6
45
100000
98656
85834



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. Upon drawing and observing the squares expansion pattern, the recurrence relation: T(n)=T(n-1)+(n-2)*4+4 holds true. Expanding this relation results in this 
// formula. So, we can use this formula to get the #squares for any 'n'.







class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        return 1ll+((long int)(n-2)*(n-1))*2+(n-1)*4;
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Upon drawing and observing the squares expansion pattern, the below formula depicts the pattern. So, we can use this formula to get the #squares.






class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        // return 1ll+((long int)(n-2)*(n-1))*2+(n-1)*4;
        long long int res=1;
        for(int i=2;i<=n;i++) {
            res+=(i-1)*4;
        }
        return res;
    }
};


