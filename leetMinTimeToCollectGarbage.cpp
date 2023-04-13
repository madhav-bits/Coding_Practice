s/*
*
//******************************************************2391. Minimum Amount of Time to Collect Garbage.******************************************************

https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["G","P","GP","GG"]
[2,4,3]
["MMM","PGM","GP"]
[3,10]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm  is iteration based. Here, since we only add the time needed to reach those indices which have resp. items to be collected, we only travel until the last occurance of these items.
// So, we iter. over the array and track the last occur. of each of the item, as we would be adding the time to travel along all the indices in the path from the start, we do a prefixSum and add
// the prefixSum at the last but index to the res for all three items along with the number of items picked and return the res.







class Solution {
public:
    int garbageCollection(vector<string>& v, vector<int>& travel) {
        int res=0;
		
		// The commented part is an elaborated version of the below code, so I had commented this part.
        // int prevM=0, prevP=0, prevG=0;
        // for(int i=0;i<v.size();i++) {
        //     int mCount=0, pCount=0, gCount=0;
        //     for(char&ch:v[i]) {
        //         if(ch=='M') mCount++;
        //         else if(ch=='P') pCount++;
        //         else if(ch=='G') gCount++;
        //     }
        //     if(mCount>0) {
        //         res+=prevM;
        //         prevM=0;
        //     }
        //     if(pCount>0) {
        //         res+=prevP;
        //         prevP=0;
        //     }
        //     if(gCount>0) {
        //         res+=prevG;
        //         prevG=0;
        //     }
        //     res+=v[i].length();
        //     if(i<travel.size()) {
        //         prevM+=travel[i];
        //         prevP+=travel[i];
        //         prevG+=travel[i];
        //     }
        // }
        
        int lastM=0, lastP=0, lastG=0;
        for(int i=0;i<v.size();i++) {																	// Iter. over array and tracking last occur. of each of the three items.
            res+=v[i].length();																			// Adding the time needed to collect the items at this index.
            for(char&ch:v[i]) {
                if(ch=='M') lastM=i;
                if(ch=='P') lastP=i;
                if(ch=='G') lastG=i;
            }
        }
        
        for(int i=1;i<travel.size();i++) {																// Calc. prefixSum for each of the indices.
            travel[i]+=travel[i-1];
        }
        if(lastM>0) res+=travel[lastM-1];																// Adding the time needed to reach all occurances of each of the three items.
        if(lastP>0) res+=travel[lastP-1];
        if(lastG>0) res+=travel[lastG-1];
        return res;																						// Returning the total time needed.
    }
};

