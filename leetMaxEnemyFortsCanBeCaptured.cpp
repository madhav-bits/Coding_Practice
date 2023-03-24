/*
*
//******************************************************2511. Maximum Enemy Forts That Can Be Captured.******************************************************

https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,0,0,-1,0,0,0,0,1]
[0,0,1,-1]
[0,0,1,0,0,1,0,0,0,-1,0,0,1,0,0,1,0,0,0,-1,1,0,1,0,-1,0,1,-1,1]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is itertaion+observation based. Here, since we are trying to move from a our position to empty positions only. We are trying to find longest gap b/w adjacent our to empty psn.
// If the latest non-enemy index is our psn, and the curr. index is our psn, we update the index to curr. index as the earlier our psn cant jump over curr. index, same is the case with empty psn.
// Whenever we see that our latest non-enemy and curr. index which is non-enemy are different, that means we can make a move from latest non-enemy to curr. index, we calc. the dist and try to
// maximize it and return it at end of iter.(This is one another approached than coded below)


// I came up with algorithm in the commented part, where I stored the latest our psn, and calc. dist. form latest non-enemy to curr. index, which is non-enemy. 
// We get dist. from our psn to empty and maximize res with this distance. We iter. from left to right and from right to left in the process to cover movements in both the drns.




class Solution {
public:
    int captureForts(vector<int>& arr) {
//         int res=0, startIndex=-1;
//         for(int i=0;i<arr.size();i++) {
//             if(arr[i]==1) startIndex=i;
//             else if(arr[i]==-1) {
//                 if(startIndex!=-1 && i-startIndex-1>res) res=i-startIndex-1;
//                 startIndex=-1;
//             }
//         }
        
//         startIndex=-1;
//         for(int i=arr.size()-1;i>=0;i--) {
//             if(arr[i]==1) startIndex=i;
//             else if(arr[i]==-1) {
//                 if(startIndex!=-1 && startIndex-i-1>res) res=startIndex-i-1;
//                 startIndex=-1;
//             }
//         }
//         return res;
        
        int prev=0, cnt=0, res=0;
        for(int i=0;i<arr.size();i++) {
            if(arr[i]==0) cnt++;																		// Updating the dist. b/w consec. non-enemy indices.
            else {
                if((prev==-1 && arr[i]==1) || (prev==1 && arr[i]==-1)) res=max(res, cnt);				// If the prev. non-enemy and curr. non-enemy are diff. we calc. dist and maximize res.
                prev=arr[i];																			// Storing the curr. non-enemy value.
                cnt=0;																					// Updating the dist. from curr. non-enemy index.
            }
        }
        return res;																						// Returning Maximum jump possible.
    }
};

