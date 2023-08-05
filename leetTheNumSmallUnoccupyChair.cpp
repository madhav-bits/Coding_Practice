/*
*
//**********************************************1942. The Number of the Smallest Unoccupied Chair.*****************************************

https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,4],[2,3],[4,6]]
1
[[3,10],[1,5],[2,6]]
0
[[2,5],[6,20],[5,15]]
2
[[1,3],[2,4],[6,8],[3,6],[5,9],[7,12],[4,14],[9,20],[11,12]]
5



// Time Complexity: O(nlogn).  												// Loose Upper Bound Time Complexity.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// Loose Upper Bound Time Complexity.
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. Here, we maintain two PQs, one to store the chairs which are being used, other is for chairs available for seating. We sort the times 
// based on start times, for us to be able to find the targetFriend, we append index to each entry of times and sort it. While we iter. over times array, for every entry, we 
// pop all used chairs whose end time<=curr. time and them to available chairs. If there are no available chairs after this step, that means all issued are being used and are 
// in other PQ, so we takenPQ.size() to get the next chair number and assign it to curr. index and append it to used Chairs PQ, else we take the top of PQ/least seat number
// from available chairs and assign it to curr. index and append it to used Chairs PQ. The moment we encounter targetFriend, we get the chair number being assigned based on 
// above explanation and return the chair number.







class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for(int i=0;i<times.size();i++) times[i].push_back(i);
        sort(times.begin(), times.end());
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>taken;// {EndTime, Chair Number}Stores all chairs currently in use.
        priority_queue<int, vector<int>, greater<int>>available;			// {Chair Number}, Stores chair numbers available to use.
        for(vector<int>&v:times) {
            while(!taken.empty() && taken.top().first<=v[0]) {				// Pop all used chairs whose endTimes<=curr. startTime.
                available.push(taken.top().second);							// Add the pop chairs to available chairs.
                taken.pop();
            }
            if(v[2]==targetFriend)											// If curr. friend is targetFriend.
                return (available.empty())?taken.size():available.top();	// Return the chair being assigned.
            if(!available.empty()) {										// If there are no available chairs/all chairs issued are in use.
                taken.push({v[1], available.top()});						// Assigning the least numbered available chair to curr. index.
                available.pop();
            } else taken.push({v[1], (int)taken.size()});					// We assign a new chair to curr. index.
            
        }
        return -1;															// Default return value.
    }
};

