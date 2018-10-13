/*
*
//******************************************************871. Minimum Number of Refueling Stops.***********************************************

A car travels from a starting position to a destination which is target miles east of the starting position.

Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0] miles east of the starting position, and 
has station[i][1] liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.

When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

What is the least number of refueling stops the car must make in order to reach its destination?  If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  If the car reaches the destination with 0 fuel 
left, it is still considered to have arrived.

 

Example 1:

Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
Example 2:

Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can't reach the target (or even the first gas station).
Example 3:

Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: 
We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
 

Note:

1 <= target, startFuel, stations[i][1] <= 10^9
0 <= stations.length <= 500
0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


115
30
[[10,40],[20,50],[30,30],[50,60],[90,30]]


// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming/Greedy and Heap based. This is similar to Min Jumps Question. Here, by the time we reach end of 
// fuel filled at prev. step, we collect all the petrol bunks encountered, once out of fuel, we extract the visited bunks in dec. order of fuel.
// This would reduce num. of station's fuel used. If we are unable to reach station despite using all prev. station's fuel,we return -1. After
// visiting all stations, we extract/use stations in dec. order till we reach target distance.








class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& v) {
        int res=0;															// Num. of station's fuel used.
        int curr=startFuel;													// Max. dist travelled using prev. used station's fuel.
        priority_queue<int>pq;												// Tracks max. volume sized station of all visited stations.
        if(startFuel>=target) return 0;										// Base case.
        for(int i=0;i<v.size();i++){										// Iter. over all stations.
            // cout<<"index i: "<<i<<endl;
            if(v[i][0]<=curr) pq.push(v[i][1]);								// If curr. stations reachable with curr. fuel, push vol into PQ.
            else{															// If not reachable.
                while(!pq.empty() && curr<v[i][0]){							// We used prev. reachable stations and use them in dec. order.
                    res++;													// INc. the used stations count.
                    curr+=pq.top();
                    pq.pop();
                    if(curr>=target) return res;							// If after reachable dist>=target, return stations count.
                }
                if(curr<v[i][0]) return -1;									// Despite using all prev. reachable stns, not reachable, return -1.
                pq.push(v[i][1]);											// As, curr. station's reachable, add it to PQ.
            }
            // cout<<"curr: "<<curr<<" and fol: "<<fol<<" and res: "<<res<<endl;
        }
        while(!pq.empty() && curr<target){									// Using prev. reachable stns till target is reached/ PQ is empty.
            res++;
            curr+=pq.top();
            pq.pop();
            if(curr>=target) return res;
        }
        return -1;															// If target not reachable, then return -1.
    }
};