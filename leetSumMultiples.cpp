/*
*
//******************************************************2652. Sum Multiples.******************************************************

https://leetcode.com/problems/sum-multiples/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


7
10
9
999
990
1000
143
112
105
36
945



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Math(Union-Intersection) based. We calc. the unions of the divisible numbers and subtract the intersections so that each divisible number gets counted only once. 

// The commented part is the brute force solution, where we iterate over all possible nums and count only those which are divisible by either of the three nums and return the total of the divisible
// nums.





class Solution {
public:
    
    int calc(int n, int num) {
        int len=n/num;
        return num*((len*(len+1))/2);																	// Sum of all multiples of num less than n.
    }
    
    int sumOfMultiples(int n) {
        int res=0;
        // for(int i=1;i<=n;i++) {																		// Brute force iteration based solution.
        //     if(i%3==0 || i%5==0 || i%7==0) res+=i;													// Adding all divisible nums.
        // }
        // return res;
        
        
        return calc(n,3)+calc(n,5)+calc(n,7)-calc(n,15)-calc(n,21)-calc(n,35)+calc(n,105);				// Returning the total of divisible nums which are less than n.
    }
};

