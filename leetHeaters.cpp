/*
*
//**************************************************************475. Heaters.*******************************************************

Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered 
by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,5,6]
[10,13,19]



[10,12]
[1,3,9]

[1,2,7,9]
[1,4,5,12,16,17]


[1,2,7,9]
[]

[]
[1]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array, at each step, we extract a heater, with index greater than curr.house. If that heater doesn't exists,
// we get the dist. of curr. house to prev. heater. If prev. heater doesn't exist, we just get the dist. of curr. house to curr. heater. If both
// of them exists,get the minm. of two distances to curr. house and get the maxm. of all those minm. distances to all houses.








class Solution {
public:
    int findRadius(vector<int>& u, vector<int>& v) {
        if(u.size()==0) return 0;
        if(v.size()==0) return INT_MAX;
        sort(u.begin(), u.end());											// Sort both the arrays.
        sort(v.begin(), v.end());
        int res;
        int prev=INT_MIN, curr,j=0, maxm=0;
        for(int i=0;i<u.size();i++){
            // cout<<"Inside the for with i: "<<i<<endl;
            while(j<v.size() && v[j]<u[i]) j++;								// Reaches heater with index greater than curr. house.
            // cout<<"Obtained J value: "<<j<<endl;
            if(j==v.size()){												// If curr. heater doesn't exist.
                prev=v[j-1];												// Get index of prev. heater.
                // curr=INT_MAX;
                maxm=max(maxm, u[i]-prev);									// Extracting dist. from prev. heater to curr. house.
            }
            else if(j==0){													// If prev. heater doesn't exist.
                curr=v[j];													// Get index of curr. heater.
                maxm=max(maxm, curr-u[i]);									// Extracting dist. from curr. heater to curr. house.
                // prev=(j==0)?INT_MAX: v[j-1];
            }
            else{
                curr=v[j];													// If both prev. and curr. heaters exists.
                prev=v[j-1];
                maxm=max(maxm, min(u[i]-prev, curr-u[i]));	// Get the minm. of two dist. to curr. house & get the maxm. of all min. dist to houses.
            }
            // cout<<"Maxm at index: i: "<<i<<" is; "<<maxm<<endl;
        }
        return maxm;														// Returning the min. radius.
    }
};