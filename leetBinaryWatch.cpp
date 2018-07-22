/*
*
//**************************************************************401. Binary Watch.******************************************************

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



0
1
2
4
5



// Time Complexity: O(n!).  
// Space Complexity: O(8cn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(8cn).	
// This algorithm is DFS based. We maintain a vector which tracks ones that have been set in Binary Clock.We pass number of ones still need to 
// used, curr.index starting from where, we can set one. In the fn. we set the curr. index  to one, if we have more ones to be set, and call
// fn. to set next ones, if it still has ones to be set. If at a particular fn. call, you have all ones set, we calc. hours/min and append those 
// strs to final result. If we get hours>=12 and mins>=60, we ignore those cases.








class Solution {
public:
    void findResult(vector<int>&v, int index, vector<string>&res, int allowed,int used){
        if(used==allowed){													// If allowed #bits set to one.
            int hour=0,min=0;
            hour=v[0]*8+v[1]*4+v[2]*2+v[3]*1;								// Calc. hour value.
            min=v[9]*1+v[8]*2+v[7]*4+v[6]*8+v[5]*16+v[4]*32;				// Calc. min value.
            if(hour>=12 || min>=60) return ;								// If hours>=12 or min>=60, as they aren't allowed, ignore them.
            string str=to_string(hour)+":"+to_string(min/10)+to_string(min%10);// Convert it to str format.
            res.push_back(str);												// Add the str to result vector of strs.
            return ;														// Return from this fn. call.
        }
        for(int i=index;i<v.size();i++){									// Setting the curr. index to 1.
            v[i]=1;															// Setting curr. bit to one.
            findResult(v,i+1,res,allowed,used+1);							// Call fn. to set other bits to one.
            v[i]=0;															// Bringing to default state.
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string>res;													// Stores the result str.
        vector<int>time(10,0);												// Tracks time to be extracted.
        findResult(time,0,res,num,0);										// Call. fn. to extract comb. of ones.
        // reverse(res.begin(), res.end());
        return res;															// Return the result str.
    }
};