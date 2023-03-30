/*
*
//******************************************************2070. Most Beautiful Item for Each Query.******************************************************

https://leetcode.com/problems/most-beautiful-item-for-each-query/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2],[3,2],[2,4],[5,6],[3,5]]
[1,2,3,4,5,6]
[[1,2],[1,2],[1,3],[1,4]]
[1]
[[10,1000]]
[5]



// Time Complexity: O(nlogn+m*logn).																	// n-#{price,beauty} provided, m-#queries.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+m*logn).																	// n-#{price,beauty} provided, m-#queries.
// Space Complexity: O(1).	
// This algorithm is Sorting+Bin Search based. Here, as we are trying to get max. beauty with price <=query. We sort the given array based on price value. We iter. over array and update the maximum
// beauty till that price along the way. We iter. over queries and we find the greatest index whose price<=query price, we get the max. price till that price in the index-[i][1] and update the res
// accordingly, if there is no such index, we push 0 into res and we return res at the end of the iteration.


// The commented part is what I came up with originally as I was not able to do upper_bound on array of pairs(Should have done Bin. Search), slightly more time complex and space complex but the sln
// was accepted.




class Solution {
public:
    
    int getMaxBeautyIndex(vector<vector<int>>&v, int target) {											// Bin. Search to find max. price<=query price and return the index.
        int low=0, high=v.size()-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(v[mid][0]<=target) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // vector<pair<int,int>>v;
        // for(int i=0;i<queries.size();i++) v.push_back({queries[i], i});								// Creating {query, index} pairs which will be helpful while pushing beauty values into res.
        // sort(v.begin(), v.end());																	// We sort the given {price, beauty} array.
        // sort(items.begin(), items.end());															// We sort the queries to iter. over inc. query values.
        // vector<int>res(queries.size(),0);
        // int maxm=0, j=0;
        // for(pair<int,int>&pr:v) {																	// Based on the queries, we iter. over prices<=query and track max. among them.
        //     while(j<items.size() && items[j][0]<=pr.first) {
        //         if(items[j][1]>maxm) maxm=items[j][1]; 												// Tracking max beauty value among lesser price values.
        //         j++;
        //     }       
        //     res[pr.second]=maxm;																		// Pushing max. beauty value into res.
        // }
        
        sort(items.begin(), items.end());																// Sort the given array.
        for(int i=1;i<items.size();i++) {
            if(items[i-1][1]>items[i][1]) items[i][1]=items[i-1][1];									// Tracking the max. beauty value till index 'i' and storing it in index 'i'.
        }
        vector<int>res;// Observation can't apply default lower_bound function searches over 2D vectors, pair vectors. 
        for(int&query: queries) {
            int ind=getMaxBeautyIndex(items, query);													// Get index of max. price<=query and get max beauty from that index.
            ind--;
            if(ind>=0) res.push_back(items[ind][1]);													// Pushing max. beauty value into res.
            else res.push_back(0);																		// If no price with value <=query found, we push '0'.
        }
        return res;																						// Returning the max. beauty values for the queries.
    }
};

