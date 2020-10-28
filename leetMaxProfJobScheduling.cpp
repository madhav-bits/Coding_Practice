/*
*
//***********************************************1235. Maximum Profit in Job Scheduling.***********************************************

https://leetcode.com/problems/maximum-profit-in-job-scheduling/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on test cases provided with the question.

[1,2,3,3]
[3,4,5,6]
[50,10,40,70]
[1,2,3,4,6]
[3,5,10,6,9]
[20,20,100,70,60]
[1,1,1]
[2,3,4]
[5,6,4]



// Time Complexity: O(m+nlogn).  											// m- Range of job end times, n- #jobs.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+nlogn).												// m- Range of job's end times, n- #jobs.
// Space Complexity: O(m).	
// This algorithm is Dynamic Programing based. The approach is same as Solution 2, except that we create a DP array of size m, we
// iter. over it, if we have jobs whose end is 'i', we iter. over all of them and try to maximize profit by time 'i' involving all 
// available jobs which end<='i'. Thus by the end of iter. dp[m] stores maxm. profit by m time(maxm end time possible).








class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& close, vector<int>& profit) {
        vector<vector<int>>v;
        for(int i=0;i<start.size();i++){									// Storing the restructure jobs data.
            v.push_back({close[i], start[i], profit[i]});
        }
        sort(v.begin(), v.end());											// Sorting jobs based on end data.
        int fin=v.back()[0],j=0;
        vector<int>dp(fin+1,0);
        for(int i=1;i<=fin;i++){											//  Iter. over all possible end dates.
            dp[i]=dp[i-1];													// dp[i] stores maxm. profit by time 'i'.
            while(j<start.size() && v[j][0]==i){							// Iter. over all jobs ending at 'i'.
                dp[i]=max(dp[i], dp[v[j][1]]+v[j][2]);						// Using jobs ending at 'i'.
                j++;
            }
        }
        
        // for(int i=0;i<=fin;i++)
        //     cout<<"i: "<<i<<" and val: "<<dp[i]<<endl;
        return dp.back();													// Returning the maxm. profit by maxm. end time 'm'.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2+nlogn).											// n- #jobs.
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, we create DP array of the length of jobs. We sort jobs based on end times, for 
// every job, we find the job whose end is<=start of curr. job, we add the profit till then and profit of curr. job and update curr.
// job's index. We also try to maximize the profit till this job storing maxm. of profit because of curr. job and also profit bec. of
// jobs till prev. job. Thus the last index stores maxm. profit involving all jobs.










class Solution {
public:
    
    int getClosestLowerIndex(vector<vector<int>>&v, int i){					// Find largest job's close<=curr. job's start.
        int j=i;
        while(j>=0 && v[j][0]>v[i][1]) j--;
        return j;
    }
    
    int jobScheduling(vector<int>& start, vector<int>& close, vector<int>& profit) {
        vector<vector<int>>v;
        for(int i=0;i<start.size();i++){									// Stores restructured Job's data in new array.
            v.push_back({close[i], start[i], profit[i]});
        }
        sort(v.begin(), v.end());
        vector<int>dp(v.size(),0);
        dp[0]=v[0][2];
        for(int i=1;i<v.size();i++){
            dp[i]=dp[i-1];													// Stores maxm. profit involving jobs till curr. job.
            int ind=getClosestLowerIndex(v,i);								// Find job whose end<= curr. job.
            int prev=(ind==-1)?0:dp[ind];
            dp[i]=max(dp[i], prev+v[i][2]);									// Using curr. job's profit.
        }
        // for(int i=0;i<=fin;i++)
        //     cout<<"i: "<<i<<" and val: "<<dp[i]<<endl;
        return dp.back();													// Return maxm. profit involving all jobs.
    }
};