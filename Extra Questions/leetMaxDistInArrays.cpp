/*
*
//******************************************************624. Maximum Distance in Arrays.***********************************************

Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) 
and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the 
maximum distance.

Example 1:
Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation: 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Note:
Each given array will have at least 1 number. There will be at least two non-empty arrays.
The total number of the integers in all the m arrays will be in the range of [2, 10000].
The integers in the m arrays will be in the range of [-10000, 10000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,3],[4,5],[1,2,3]]


[[1],[1]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. In this algo. at each step, we try to extract the top 2 min. and top 2 max. of all values encountered,we 
// also save their indices.At the end of iteration, if the indices of top max. and top min. value doesn't match, then that pair gives the 
// desired result. If not, max of diff b/w (max2, min1) or (max1,min2) gives the desired result.








class Solution {
public:
    int maxDistance(vector<vector<int>>& v) {
        pair<int,int>min1,min2,max1,max2;									// Tracks top 2 minm, maxm. values.
        min1.first=INT_MAX; min2.first=INT_MAX;
        max1.first=INT_MIN; max2.first=INT_MIN;
        for(int i=0;i<v.size();i++){										// Iterate the entire array.
            if(v[i][0]<min1.first){											// If curr. row has least value, then update min1, min2.
                min2.first=min1.first;
                min2.second=min1.second;
                min1.first=v[i][0];
                min1.second=i;
            }
            else if(v[i][0]<min2.first){									// If curr. value<min2 and value>=min1.
                min2.first=v[i][0];
                min2.second=i;
            }
            
            
            if(v[i].back()>max1.first){										// If curr. row has highest value, then update max1, max2.
                max2.first=max1.first;
                max2.second=max1.second;
                max1.first=v[i].back();
                max1.second=i;
            }
            else if(v[i].back()>max2.first){								// If curr. value>max2, but value<=max1.
                max2.first=v[i].back();
                max2.second=i;
            }
        }
        // cout<<"max1: "<<max1.first<<" max2: "<<max2.first<<endl;
        // cout<<"min1: "<<min1.first<<" min2: "<<min2.first<<endl;
        if(min1.second!=max1.second)										// If indices of max1,min1 doesn't match they give answer.
            return max1.first-min1.first;						
        else return max(max1.first-min2.first,max2.first-min1.first);		// If not one of the combi. gives the answer.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Since, max,min shouldn't be from same index. We extract the minm, maxm. from all prev. rows and store them.
// At a row, we compare diff of currRow's max-minTillNow and maxTillNow-currRow's min. In this way, we avoid comparing minm, maxm values from
// same index. 



// Here, we are not trying to get minm, maxm. and compare them at the end. We use minm, maxm in such a way, that they aren't compared direclty. 
// They are compared to the minm, maxm. of currRow. Thus, avoiding comparing minm, maxm from same rows. As part of the comparisions, calc. 
// diff of global min, global max would have occured somewhere.

// This algo. is a trickier and better one.





class Solution {
public:
    int maxDistance(vector<vector<int>>& v) {
        int minm=v[0][0], maxm=v[0].back();									// Tracks minm, maxm 
        int res=0;															// Track max. diff.
        for(int i=1;i<v.size();i++){
            res=max(res,max(maxm-v[i][0], v[i].back()-minm));				// Extr. max of maxTillNow-currRowMin, currRowMax-minTillNow
            maxm=max(maxm,v[i].back());										// Updating the maxm. encountered till now.
            minm=min(minm,v[i][0]);											// Updating the mimm. encountered till now.
            // cout<<"maxm: "<<maxm<<" and minm: "<<minm<<endl;
        }
        return res;															// Returning the max. diff.
    }
};