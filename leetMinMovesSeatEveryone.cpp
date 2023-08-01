/*
*
//********************************************2037. Minimum Number of Moves to Seat Everyone.********************************************

https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,1,5]
[2,7,4]
[4,1,5,9]
[1,3,2,6]
[2,2,6,6]
[1,3,2,6]
[3,6]
[1,2]
[4,7,12]
[2,5,9]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Greedy+Sorting based. Important observation is that if we assign students to seats in the increasing order, we avoid overlaps in the movement b/w the 
// students on their way to their assigned seat. In order to get min. #moves/dist., we need to minimize overlapping distance as much as possible, which is observed when we 
// asssign seats to students in inc. order of their resp. positions.





// Since the range of positions is small, we can use counting sort, we mark the occurrances of students, seats positions in two arrays, we iter. over both of them, skip empty 
// positions, when we find non-empty position of both, we calc. abs. diff and add to res, we repeat the same process until we reach the end of the array.






class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Sort both arrays and assign students to seats in inc. order.
        int res=0;
        sort(seats.begin(), seats.end());									// Sort students, seats by inc. order of positions.
        sort(students.begin(), students.end());
        for(int i=0;i<seats.size();i++) {
            res+=abs(seats[i]-students[i]);									// Calc. abs diff b/w sorted seats and students and add dist/moves to res.
        }
        return res;															// Returning min. #moves needed for all students to move to their assigned seats.
    }
};

