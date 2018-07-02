/*
*
//**************************************************************582. Kill Process.*****************************************************

Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process 
has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.

We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains 
the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. 
You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.

Example 1:
Input: 
pid =  [1, 3, 10, 5]
ppid = [3, 0, 5, 3]
kill = 5
Output: [5,10]
Explanation: 
           3
         /   \
        1     5
             /
            10
Kill 5 will also kill 10.
Note:
The given kill id is guaranteed to be one of the given PIDs.
n >= 1.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,10,5]
[3,0,5,3]
3


[1,3,10,5]
[3,0,5,3]
5


[1,3,10,5]
[3,0,5,3]
1



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. We create a map which stores the link parent process and child process, we start from the kill process
// asked in the question, we extract the processes depending on it from the map we created and push them into queue. Thus, we iterate till
// queue gets empty, to get all processes depending on the target kill process.








class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int>res;
        unordered_map<int,vector<int>>m;									// Stores parent and child processes.
        for(int i=0;i<pid.size();i++){										// Creates link b/w parent and child processes.
            m[ppid[i]].push_back(pid[i]);
        }
        queue<int>q;
        q.push(kill);														// We start from the target kill process.
        while(!q.empty()){
            int curr=q.front();												// Extracting curr. process to be scanned.
            q.pop();
            res.push_back(curr);											// Push curr. process into final result vector.
            for(int i=0;i<m[curr].size();i++)								// Extract the processes depending on curr. proc. and push into queue.
                q.push(m[curr][i]);
        }
        // cout<<"The result size is: "<<res.size()<<endl;
        return res;															// Returning the final result vector.
    }
};