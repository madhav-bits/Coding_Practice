s/*
*
//******************************************************2446. Determine if Two Events Have Conflict.******************************************************

https://leetcode.com/problems/determine-if-two-events-have-conflict/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["01:15","02:00"]
["02:00","03:00"]
["01:00","02:00"]
["01:20","03:00"]
["10:00","11:00"]
["14:00","15:00"]
["10:00","14:00"]
["14:00","15:00"]



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is comparison based. We check for overlapping condition and return true if overlaps else return false.







class Solution {
public:
    
    int getTime(string&s) {																				// Converting 24 hrs format string to minutes in integers.
        int hr1=(s[0]-'0')*10+(s[1]-'0'), min1=(s[3]-'0')*10+(s[4]-'0');
        return hr1*60+min1;
    }
    
    bool haveConflict(vector<string>& u, vector<string>& v) {
//         vector<int>u, v;
//         u.push_back(getTime(event1[0]));																// Converting 24hrs format string to minutes in integers.
//         u.push_back(getTime(event1[1]));
        
//         v.push_back(getTime(event2[0]));
//         v.push_back(getTime(event2[1]));
        
//         return max(u[0], v[0])<=min(u[1], v[1]);														// Checking for overlapping condition using minutes.


		// This is one type of solution.
        // if(v[1]<u[0] || u[1]<v[0]) return false;														// Checking for Non-Overlapping condition.
        // return true;
		
		// This is another type of solution.
		return (u[1]>=v[0] && v[1]>=u[0]);																// Checking for overlapping condition.
    }
};

