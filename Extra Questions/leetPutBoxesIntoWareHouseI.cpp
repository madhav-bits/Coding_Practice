/*
*
//****************************************************1564. Put Boxes Into the Warehouse I.*********************************************

https://leetcode.com/problems/put-boxes-into-the-warehouse-i/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with test cases provided with the question.

[4,3,4,1]
[5,3,3,4,1]
[1,2,2,3,4]
[3,4,1,2]
[1,2,3]
[1,2,3,4]
[4,5,6]
[3,3,3,3,3]



// Time Complexity: O(nlogn).												// n- #boxes provided.  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n- #boxes provided.
// Space Complexity: O(1).	
// This algorithm is Sorting and Observation based. Here, we sort the boxes, we set two ptrs one on longest box and other at
// warehouse left index, if we can fit curr. box in warehouse index, we fit it there, if not it can't be fit into warehouse, as 
// warehouse only allows boxes from the left and few lengthier boxes got their warehouse spots to the left of curr. index and they 
// can't fit into curr. index as this is smaller than curr. box and as it can't pass through curr. smaller spot to next possible 
// fittable warehouse spots. Whenever we can fit boxes, we inc. the count and return it at the end of iteration.








class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int res=0;
        sort(boxes.begin(), boxes.end());									// Sorting the boxes array.
        int i=boxes.size()-1, j=0;
        while(i>=0 && j<warehouse.size()){									// Until boxes and spots are available.
            if(boxes[i]<=warehouse[j]){										// If curr. box is fittable.
                res++;														// Inc. the fittable boxes count.
                j++;
            }
            i--;															// Moving the boxes ptr irrespective of fittable or not.
        }
        return res;															// Return the #fittable boxes count.
    }
};