/*
*
//*******************************************1599. Maximum Profit of Operating a Centennial Wheel.****************************************

https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/description/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Worked with test cases provided with question.


// Time Complexity: O(n).													#len. of customers array.  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													#len. of customers array.
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter over. the given sequence of trips, we try to maximize the money collected and store the 
// minm. rotation where maxm. collection is obtained.



#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>




using namespace std;


class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans=-1, maxm=0, avail=0, cost=0, i=0;
        while(i<(int)customers.size() || avail>0){
            if(i<customers.size()) avail+=customers[i];
            int curr=min(avail, 4);
            avail-=curr;
            cost-=runningCost;
            cost+=curr*boardingCost;
            if(cost>maxm){
                maxm=cost;
                ans=i+1;
            }
			// cout<<"i: "<<i+1<<" and cost: "<<cost<<" and avail: "<<avail<<endl;
			i++;
        }
        return ans;
    }
	
};

int main(){
	Solution s;
	vector<int>customers({10,10,6,4,7});
	int boardingCost=3;
	int runningCost=8;
	int res=s.minOperationsMaxProfit(customers, boardingCost, runningCost);
	cout<<"res: "<<res<<endl;
	return 0;
}


