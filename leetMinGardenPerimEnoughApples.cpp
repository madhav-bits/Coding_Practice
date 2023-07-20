/*
*
//***********************************************1954. Minimum Garden Perimeter to Collect Enough Apples.**********************************************

https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
13
1000000000
1000000000000000



// Time Complexity: O(logm).												// m-maxm. #apples allowed in the question.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logm).												// m-maxm. #apples allowed in the question.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, since we are working on squares centred on origin of axis. For optimum perimeter we only takes sides of 
// length take perimeters in multiples of 8, that is integer coordinates on 45 degrees line(x,x) would be our top right corners of the square.
// While calc. #apples on a square where (x,x) is top right: we observed perimeter to be: 8*x, #apples on the square: 4*3*x*x, sum of all apples in the enclosed
// squares including the current one is 4*3*x*(x+1)*(2*x+1)/6=2*x*(x+1)*(2*x+1)

// As we observe monotonic nature in the total #apples in a square as perimeter increases, we use binary search, if for a mid, we see that total #apples>target
// we search in lesser perimeters, if total #apples<target, we search in higher perimeters. We return the low value at the end of Binary Search.





class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        int low=1, high=100000;
        while(low<high) {
            int mid=(low+high)/2;
            long long int apples=1ll*12*mid*(mid+1ll)*(2ll*mid+1);			// Calc. total #apples for a square with (mid, mid) as top right corner.
            apples/=6;
            if(apples<neededApples) low=mid+1;								// If #apples<target, search in bigger squares.
            else high=mid;													// Else search in lesser perimeters for lowest perimeter as possible.
        }
        return 8*low;														// Returning the minm. perimeter of square which has >= target #apples.
    }
};

