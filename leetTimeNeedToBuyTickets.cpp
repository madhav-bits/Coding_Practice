/*
*
//******************************************************2073. Time Needed to Buy Tickets.******************************************************

https://leetcode.com/problems/time-needed-to-buy-tickets/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,3,2]
2
[5,1,1,1]
0
[6,5,4,3,6,5,4,3,2,7,6,5,4,8,12,14,3,7,6,8,9,12,10,5]
7
[6,5,4,3,6,5,4,3,2,7,6,5,4,8,12,14,3,7,6,8,9,12,10,5]
9
[6,5,4,3,6,5,4,3,2,7,6,5,4,8,12,14,3,7,6,8,9,12,10,5]
4



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Since every person after his turn go to the end of queue to get more tickets, we can say that all the people infront of target index
// would always get tickets before him in every loop and the indices after target index would get tickets after target index. So, we only count min(v[i], v[k]) seconds for
// indices <= index k and add min(v[k]-1, v[i]) for indices > index k.







class Solution {
public:
    int timeRequiredToBuy(vector<int>& v, int k) {
        int res=0;
        for(int i=0;i<v.size();i++) {
            if(i<=k)  res+=min(v[i], v[k]);									// Adding this for indices before 'k' index.
            else res+=min(v[i], v[k]-1);									// Adding this for indices after 'k' index as these get tickets after 'k' in every loop.
        }
        return res;															// Returning the total time taken for 'k' index to get all tickets.
    }
};

