/*
*
//******************************************************2105. Watering Plants II.******************************************************

https://leetcode.com/problems/watering-plants-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,2,3,3]
5
5
[2,2,3,3]
3
4
[5]
10
8
[4,4,6,3,4]
10
8
[4,4,6,3,4]
9
9
[4,4,6,3,4]
14
9



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we iter. over array from both the sides, when both ptr dont collide, we check if each of them have enough water for the curr. respective plant, if not
// we refill the can and inc. the refill count, then water the plant. When two ptrs collide, we find the max volume container, if it is <curr. plant requirement, we inc. the refill count and water
// the plant. We return the refill count at the end of iter.








class Solution {
public:
    int minimumRefill(vector<int>& arr, int capA, int capB) {
        int res=0, waterA=capA, waterB=capB;															// Two ptrs, tracks water in two containers.
        for(int left=0, right=arr.size()-1;left<=right;left++, right--) {								// Iter. from both drns towards center.
            if(left==right) {																			// When ptrs collide.
                if(waterA>=waterB && waterA<arr[left]) res++;											// If canA has greater vol. and is < curr. plant, we inc. the refill count.
                else if(waterB>waterA && waterB<arr[left]) res++;
            }else {
                if(waterA<arr[left]) waterA=capA, res++;												// If canA<curr. plant, we inc. the refill count and refill the can.
                if(waterB<arr[right]) waterB=capB, res++;
                waterA-=arr[left];																		// Dec. the can volume as we water the curr. plant.
                waterB-=arr[right];
            }
        }
        return res;																						// Returning the total #refills done.
    }
};

