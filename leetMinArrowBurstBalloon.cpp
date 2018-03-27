/*
*
//**************************************************452. Minimum Number of Arrows to Burst Balloons.*********************************************

There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates 
of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x 
if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem 
is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,10],[2,11],[4,12],[6,9]]
[[1,10],[2,6],[7,8],[9,12]]
[[]]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
//***********************************************************GREEDY ALGORITHM.********************************************************
// This algorithm is GREEDY ALGORITHM. At any point of time we keep a single interval, deleting all it's overlapping intervals at any instant. The
// essence is that, we keep the interval with the shortest end, as the overlapping interval with the longer end might include other intervals 
// which doesn't overlap with the shortest overlapping encountered till now. Thus, optimizing #arrows at any instant.When an other interval 
// doesn't overlap curr. interval, we inc. the count(As all intervals of
// previous set can be shot by single arrow) and move to the next interval. At the end of iteration, we inc. the count by one, as the last set of 
// intervals is not accounted for(can be shot by single arrow).




class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& v) {
        if(v.size()==0) return 0;
        //if(v.size()==1) return 1;
        int count=0;
        sort(v.begin(), v.end(), [](const auto&lt, const auto& rt){			// Sorts the vector based on the interval beginning values.
            return lt.first<rt.first;
        });
        
        int prev=0;															// Chosing the fisrt interval.
        for(int i=1;i<v.size();i++){
            if(v[i].first<=v[prev].second){									// If the other interval overlaps current interval.
                if(v[i].second<v[prev].second)								// If the other interval has shorter close, then updating the close.
                    prev=i;													// Updating to curr. scanning interval.
            }
            else{															// If the curr. scan interval not overlaps, with the curr. interval, 
                count++;													// then move to other interval, while all previous set of intervals,
                prev=i;														// can be shot by a single arrow, we inc. the count.
            }
        }
        return count+1;														// Inc. by one, as last set of ballons can be shot by one arrow.
    }
};