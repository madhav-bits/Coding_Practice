/*
*
//******************************************************2332. The Latest Time to Catch a Bus.******************************************************

https://leetcode.com/problems/the-latest-time-to-catch-a-bus/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[10,20]
[2,17,18,19]
2
[20,30,10]
[19,13,26,4,25,11,21]
2
[10,20,30]
[2,3,4,5,7,13,15,16,18,19,23,24,26,27,32,35,36,37]
4
[3]
[2,4]
2
[10,20,30]
[9,20,28]
2
[3]
[4]
1
[20,30]
[15,16,19,20,21,25,27,28,29]
3
[20,30]
[12,14,15,16,21,25,27,28,29]
3






// Time Complexity: O(n+m).													// n-length of bus array, m-length of passenger array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// n-length of bus array, m-length of passenger array.
// Space Complexity: O(1).	
// This algorithm is Sorting+Iteration based. We first sort the Buses, Passengers. We iter. over buses and passengers in inner loop, for every bus, we cover
// all passengers it can accomodate, for every passenger we check if we can come a second before curr. passenger so that we can also be accomodated, in some 
// cases after iter. over all passengers who arrived before curr. bus there might still be empty space in the bus, so we check if we can come at the same time
// as bus to get a spot in the bus, if yes we update res, all the passengers who didn't get to board in curr. bus will wait and will board in next bus. We 
// return res at the end of iter.







class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& u, vector<int>& v, int cap) {
        sort(u.begin(), u.end());//Buses
        sort(v.begin(), v.end());// Passengers.
        int j=0, rem=cap, res=0;
        for(int i=0;i<u.size();i++) {
            while(j<v.size() && v[j]<=u[i] && rem>0) {
                if(j==0 || v[j-1]+1!=v[j]) res=v[j]-1;						// Check if prev. second can be used, if yes update res.
                j++;
                rem--;
            }
            // cout<<"j: "<<j<<" and: "<<u[i]<<" rem: "<<rem<<endl;
            if(rem>0 && 													// If space in bus still left.
               (j==0 || 													// If bus arriving time can be used, we come on that time.
                (j>0 && v[j-1]!=u[i]))) res= u[i];
            rem=cap;														// Resetting available space for next bus.
        }
        return res;															// Returning max. time at which we can come and board/(take a spot in) the bus.
    }
};

