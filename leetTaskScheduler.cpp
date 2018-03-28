/*
*
//**************************************************************621. Task Scheduler.*****************************************************

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks 
could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing 
different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["A","A","B","B","A","B","B","D", "D"]
2




// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).	
// Space Complexity: O(n).	
// ******************************************************THIS IS GREEDY ALGORTIHM.******************************************************
// This algorithm is Greedy based, here we first find the char with max #occurances, we use the other chars to fill the cooling period, this way
// we use all the chars in the string satisfying the condition. Here as we can put, >n chars b/w two same chars. So, we first fill all spaces,
// if we still more chars to be filled, then we can append them to the each cooling interval(without violating the cooling window).





class Solution {
public:
    int leastInterval(vector<char>& v, int n) {
        vector<int> count(26);													//Vector to keep the count the #occurances of all chars.
        int maxm=0, res;
        for(int i=0;i<v.size();i++){
            count[v[i]-'A']++;
            //cout<<"The count of: "<<v[i]-'A'<<" is; "<<count[v[i]-'a']<<endl;
            maxm=max(maxm, (int)count[v[i]-'A']);								// Maintaining the maxm. char
        }
        res=(n+1)*(maxm-1);														// Count of intervals except for last occurance of max. rep chars.
        //cout<<"The intital result is: "<<res<<endl;
        for(int temp:count)														// Adding all max. repeat chars for the last occurance.
            if(temp==maxm) res++;
        //cout<<"The result is: "<<res<<endl;
        return max((int)v.size(), res);											// Considers the case, when there are chars left to be placed.
        
    }
};