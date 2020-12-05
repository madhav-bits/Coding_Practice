/*
*
//***********************************************1665. Minimum Initial Energy to Finish Tasks.*******************************************

https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

Worked on test cases provided with question.
[[1,2],[2,4],[4,8]]
[[1,3],[2,4],[10,11],[10,12],[8,9]]
[[1,2],[1,7],[2,3],[5,9],[2,2]]



// Time Complexity: O(nlogn).
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Greedy based. Here, we sort tasks based on diff b/w minm. req and actual energy required. We sort as such,
// if the diff. is maxm. the remaining enery would be more for the rest of the tasks to be done with minm. extra enery addition. 
// We iter. over the tasks, at every step we add the energy if the curr. energy is <minm. req. and subtract energy after performing
// tasks, in this way we only add energy to temp init. enery when required, as the addn will be least. We get the least init. energy.







class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>&lt, vector<int>&rt){// Sort on diff. b/w minm. req. and actual(rem. energy).
            return (lt[1]-lt[0]>rt[1]-rt[0]);
        });
        int res=tasks[0][1], curr=res;
        for(int i=0;i<tasks.size();i++){
            if(tasks[i][1]>curr){											//  If curr. energy is<minm. required energy
                res+=tasks[i][1]-curr;										// Add req. energy deficit to init. energy
                curr=tasks[i][1];											// Update the curr. energy to minm. required energy.
            } 
            curr-=tasks[i][0];												// Energy spent for this task.
            // cout<<"res: "<<res<<" and curr: "<<curr<<endl;
        }
        return res;															// Returning the minm. init energy
    }
};
