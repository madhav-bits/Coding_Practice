/*
*
//******************************************************406. Queue Reconstruction by Height.***********************************************

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of 
the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct 
the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2],[4,2]]




// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).	
// Space Complexity: O(n).	
// ****************************************************This is GREEDY ALGORITHM.******************************************************
// This is GREEDY Algorithm, first sorting the vector based on height, if height is equal, then sort based on #people above infront of him. Next
// in the second iteration, we start from the beginning and insert the numbers(height) into the final result based on #infront of him. 





class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& v) {
        //vector<pair<int, int>> v;
        sort(v.begin(), v.end(), [](const auto& lt, const auto& rt){				//Sort numbers based on height if equal based on #infront of him.
           return lt.first>rt.first || (lt.first== rt.first && lt.second<rt.second); 
        });
        
        vector<pair<int, int>> res;
        for(int i=0;i<v.size();i++){												// Iterating the sorted array.
            res.insert(res.begin()+v[i].second, v[i]);								// Inserting the pair into the final res based on #infront of him.
        }
        return res;																	// Returning the final queue of persons.
    }
};