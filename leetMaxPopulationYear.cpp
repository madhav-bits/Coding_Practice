/*
*
//*********************************************************1854. Maximum Population Year.**************************************************

https://leetcode.com/problems/maximum-population-year/


You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the 
inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.

 

Example 1:

Input: logs = [[1993,1999],[2000,2010]]
Output: 1993
Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
Example 2:

Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
Output: 1960
Explanation: 
The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.
 

Constraints:

1 <= logs.length <= 100
1950 <= birthi < deathi <= 2050



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[1993,1999],[2000,2010]]
[[1950,1961],[1960,1971],[1970,1981]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, as we have to give the year with max population alive. As we are working on year range of 100, we take an 
// array of size 100 where in each corres. index, we place #people took birth or dead in that year. We map a year to an index by index=year-1950. In the
// second iter. we iter. over array and maintain #people alive in curr. year and track the year where max. people are alive and return it.








class Solution {
public:
    int maximumPopulation(vector<vector<int>>& v) {
        vector<int>aliveCount(101,0);										// Keeps tracks of #people alive/dead in that year.
        for(vector<int>&u:v){
            aliveCount[u[0]-1950]++;
            aliveCount[u[1]-1950]--;
        }
        int maxYear=-1, maxAlive=-1, currAlive=0;							// Tracks curr. alive people, maxAlive people till now, maxYear.
        for(int i=0;i<=100;i++){
            currAlive+=aliveCount[i];										// Updating curr. alive based on curr. year
            // if(i==10)   cout<<"year: "<<i+1950<<" and cnt: "<<aliveCount[i]<<endl;	
            if(currAlive>maxAlive) maxAlive=currAlive, maxYear=i+1950;		// If Curr. alive>maxAlive till now, update maxYear and maxAlive.
        }
        return maxYear;														// Returning year where max people are alive.
    }
};

