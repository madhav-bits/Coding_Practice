/*
*
//******************************************************976. Largest Perimeter Triangle.***********************************************

https://leetcode.com/problems/largest-perimeter-triangle/description/

Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.

 

Example 1:

Input: [2,1,2]
Output: 5
Example 2:

Input: [1,2,1]
Output: 0
Example 3:

Input: [3,2,3,4]
Output: 10
Example 4:

Input: [3,6,2,3]
Output: 8
 

Note:

3 <= A.length <= 10000
1 <= A[i] <= 10^6




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1,2]


[1,2,1]


[3,2,3,4]

[3,6,2,3]

[3,6,2,3]


// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is observation based. The sides of a triangle has to satisfy three conditions with respect to sides, sum of two sides>
// third side. We sort the sides, and a,b,c are sides in observation where a<b<c. c+a>b, c+b>a as c is the greater num, adding anything
// to it, makes it even more larger. The only condition we have to worry is a+b>c. As, we are trying to maximize total sum. It would
// be maximized only if three nums are adjacent to each other.

// We can prove this adj. requirement by proof of contradiction, if largest total's elems are not consecutive, the pair closest and 
// less than it would also satisfy the a+b>c requirement and give a greater total, thus this would be the greatest total.






class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        sort(v.begin(), v.end());											// Sort the sides.
        for(int i=v.size()-1;i>1;i--){										// Iter. in dec. order of sides.
            if(v[i]<v[i-1]+v[i-2])											// If triplet found, return perimeter.
                return v[i]+v[i-1]+v[i-2];
        }
        return 0;															// If no triplets found.
    }
};

