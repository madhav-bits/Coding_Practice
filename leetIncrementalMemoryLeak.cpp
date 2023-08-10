/*
*
//******************************************************1860. Incremental Memory Leak.******************************************************

https://leetcode.com/problems/incremental-memory-leak/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
2
8
11
20
49
2147483647
2147483647
234366434
645867856
0
0
1
1
2
2
2
3



// Time Complexity: O(sqrt(m1+m2)).											// m1, m2-memory1, memory2 respectively.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(sqrt(m1+m2)).											// m1, m2-memory1, memory2 respectively.
// Space Complexity: O(1).	
// This algorithm is Brute Force Approach based. We use brute force as the number of times we go through loop is small and it falls within in the time compl.
// restraints we generally have here. We go through as long as the greatest memory available in a stick >memory needed in that time, in that loop we dec. 
// memory available from the chosen stick and we repeat the process. We return the time we break the loop, remaining memory in each of the sticks at the end.


// Time Complexity Analysis:
// 1+2+3+4+....+n=(mem1+mem2)-> n^2=(mem1+mem2)-> n=sqrt(mem1+mem2).






class Solution {
public:
    vector<int> memLeak(int mem1, int mem2) {
        int time=1;
        while(time<=max(mem1, mem2)) {										// As long as memory available>memory required in that moment.
            if(mem1>=mem2) mem1-=time;										// If mem1 is greater, it is chosen and it's memory is decreased.
            else mem2-=time;
            time++;															// We inc. the time for next loop.
        }
        
        return {time, mem1, mem2};											// Returning the crashTime, remaining memories in both the sticks.
    }
};

