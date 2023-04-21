/*
*
//******************************************************2517. Maximum Tastiness of Candy Basket.******************************************************

https://leetcode.com/problems/maximum-tastiness-of-candy-basket/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[13,5,1,8,21,2]
3
[1,3,1]
2
[7,7,7]
2
[4,7,6,5,2,12,13,16,20,34,18,16,14,19,10,6,5,2,7,29,31,36,31,40,42,46,25]
5



// Time Complexity: O(nlogn+n*logm).																	// n-length of nums array, m-range of nums in the nums array.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+n*logm).																	// n-length of nums array, m-range of nums in the nums array.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, we are trying to find largest tastiness of k candy basket. If the taste if too large, we might not be able to get K candies, if the taste is too small
// we get more than k fruits to choose from. We observe an monotonic decreasing nature in the number of candies found as the taste of group of candies increase. So, we do a binary search to find the 
// largest taste which can produce K candies atleast. For a given taste value, we calc. #candies that satisfies the given taste requirement(we iter over sorted array to greedily find the candies 
// where consec. candies have a gap>=curr. gap, then we inc the cnt of candies and make the curr. candy as the prev. candy. If the #candies>=k, we search in the upper half for greater gap value, else
// we search in lower half a suitable gap value resulting in K candies.	







class Solution {
public:
    
    int getParts(vector<int>&v, int gap) {																// Greedily calc. #candies that satifies the gap/taste condition.
        int cnt=1, prev=v[0];
        for(int i=1;i<v.size();i++) {
            if(v[i]-prev>=gap) {																		// We greedily pick the next closest candy with the specified dist. from curr. candy.
                prev=v[i];																				// Updating the prev. candy and inc. the cnt of #candies satisfying the gap condition.
                cnt++;
            }
        }
        // cout<<"gap: "<<gap<<" and cnt: "<<cnt<<endl;
        return cnt;																						// Returning the #candies.
    }
    
    int maximumTastiness(vector<int>& v, int k) {
        sort(v.begin(), v.end());																		// Sorting the candy prices array.
        int low=1, high=v.back()-v[0];
        
        while(low<=high) {																				// Bin. Search over least possible taste to max possible taste.
            int mid=(low+high)/2;
            if(getParts(v, mid)>=k) low=mid+1;															// Calc. #candies for the gien taste value, if it satisfies search in upper part for grtr taste.
            else high=mid-1;																			// If doesn't satisfy, search in lower half for smaller taste.
        }
        return low-1;																					// Returning the max possible taste for the K candy basket.
    }
};
