/*
*
//*******************************1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.******************************

https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/


Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i] 
is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the 
left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts 
and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.

 

Example 1:



Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the 
cake, the green piece of cake has the maximum area.
Example 2:



Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the 
cake, the green and yellow pieces of cake have the maximum area.
Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9
 

Constraints:

2 <= h, w <= 10^9
1 <= horizontalCuts.length < min(h, 10^5)
1 <= verticalCuts.length < min(w, 10^5)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
It is guaranteed that all elements in horizontalCuts are distinct.
It is guaranteed that all elements in verticalCuts are distinct.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.



5
4
[1,2,4]
[1,3]



5
4
[3,1]
[1]


5
4
[3]
[3]



// Time Complexity: O(mlogm+nlogn).											// m-#hori. cuts, n- #vertical cuts.
// Space Complexity: O(mlogm+nlogn).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlogm+nlogn).											// m-#hori. cuts, n- #vertical cuts.
// Space Complexity: O(mlogm+nlogn).	
// This algorithm is observation based. Every cut either row wise or column wise would touch other type of cut. So, it forms small
// rectangle with other type of cut. Max. cake piece would need to have largest length and largset breadth possible to have greater 
// area. So, we iter. over all vetical cuts and extract max. breadth and over hori. cuts and extract maxm. length. We multiply these
// two to get maxm. area of cake piece and return it.







class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& vert) {
        sort(hori.begin(), hori.end());										// Sorting two types of cuts.
        sort(vert.begin(), vert.end());
        if(hori.back()!=h) hori.push_back(h);								// To calculate length/breadth of last piece in row/col.
        if(vert.back()!=w) vert.push_back(w);
        int res=0;
        int prevRow=0, prevCol=0;											// Tracks prev. cut psn.
        int maxRow=0, maxCol=0;												// Tracks maxm. length and breadth.
        long int mod=1000000007;
        for(int i=0;i<hori.size();i++){										// Iter. over hori. cuts.
            maxRow=max(maxRow, hori[i]-prevRow);							// Maximizing length of the cake piece.
            prevRow=hori[i];
        }
        for(int j=0;j<vert.size();j++){										// Iter. over vertical cuts.
            maxCol=max(maxCol, vert[j]-prevCol);							// Maximizing breadth of the cake piece.
            prevCol=vert[j];
        }
        res=(1ll*maxRow*maxCol)%mod;										// Calc. the maxm. area of the cake piece.
        return res;															// Return the maxm. area of cake piece.
    }
};
