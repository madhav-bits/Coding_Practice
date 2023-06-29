/*
*
//******************************************************1870. Minimum Speed to Arrive on Time.******************************************************

https://leetcode.com/problems/minimum-speed-to-arrive-on-time/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,2]
6
[1,3,2]
2.7
[1,3,2]
1.9
[5,6,4,3,8,9,14,15,13,16,19,18,16,24,27,45,37]
25.6
[5,6,4,3,8,9,14,15,13,16,19]
25.6
[5,6,4,13,8,19,14,15,23,8,7,16,19]
46
[4,2,3]
2.03
[1,1,100000]
2.01
[1,4,5,7]
2
[3,2,3,1]
12.5



// Time Complexity: O(nlogk).												//n-#rides, k-range of speeds allowed.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogk).												//n-#rides, k-range of speeds allowed.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, we use binary search to find the least speed for which cumulative time taken<=targetTime, we return least time
// as this was asked in question and this would bring the time taken as close to targetTime as possible.






class Solution {
public:
    
    double getTime(vector<int>&v, int speed) {
        double time=0.0;
        for(int i=0;i<v.size();i++) {
            double temp =(0.0+v[i])/speed;
            time+=(i==v.size()-1)?temp:ceil(temp);
            // cout<<"dist: "<<dist<<" and temp time: "<<time<<endl;
        }
        return time;
    }
    
    int minSpeedOnTime(vector<int>& dist, double target) {
        
        int res=-1;
        int low=1, high=10000000;											// range of speeds allowed.
        while(low<=high) {
            int mid=(low+high)/2;
            double time=getTime(dist, mid);									// Calc. time taken for this speed.
            // cout<<"mid: "<<mid<<" and time: "<<time<<" and target: "<<target<<endl;
            if(time<=target) {												// Satisfies the given condition.
                res=mid;													// We store this speeds as possible answer and searc for lesser speeds.
                high=mid-1;
            }
            else low= mid+1;												// We search in greater speeds as they might satisfy the condition.
        }
        return res;															// Returning the least possible speed for which cumul. time<=targetTime.
    }
};

