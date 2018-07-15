/*
*
//************************************************************259. 3Sum Smaller.*****************************************************

Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition 
nums[i] + nums[j] + nums[k] < target.

Example:

Input: nums = [-2,0,1,3], and target = 2
Output: 2 
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3]
Follow up: Could you solve it in O(n2) runtime?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-2,1,0,3]
2


[3,2,-2,6,2,-2,6,-2,-4,2,3,0,4,4,1]
3


[-2,-4,-2,-2,1,0,2,2,4,3,3,4,2,6,7,6]
5


// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is 2 Pointer based. We iterate through all the nums, we set two ptrs each time, one next to curr. index and the other is len-1.
// We, dec. the index-3 when total sum>=k, after that if index->2<index>3(then we got a proper triplet) and all the numbers from index->2+1 to 
// index->3 would suit as the third num of triplet making the sum<target. After, adding these values to count, we inc. the index->2, further 
// exploring possibilities to form triplets, with different second and third nums in triplets.



// Here, we need not worry about, i<j<k condition as any triplet would saisfy this condiiton.




class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;											// If <3 nums exist, we can't form triplet.
        int count=0;														// Num. of triplets satisfying the given condition.
        sort(nums.begin(), nums.end());										// Sort the array.
        for(int i=0;i<nums.size()-2;i++){									// Iterate for first num. of triplet.
            int j=i+1,k=nums.size()-1;										// Base indices of second and third nums. of triplet.
            while(j<k){														// index->2<index->3.
                // cout<<"j: "<<j<<" and k: "<<k<<endl;
                while(j<k && nums[i]+nums[j]+nums[k]>=target)				// If sum>=target, dec. the index of third num.
                    k--;	
                if(j<k){													// If second and third num are distinct.
                    // cout<<"i: "<<i<<" and j: "<<j<<" and k: "<<k<<" and sum: "<<nums[i]+nums[j]+nums[k]<<endl;
                    count+=(k-j);											// Add #in-between nums to count, as would fit as third num in triplet.
                    j++;													// Further exploring possibilities of num2, num3 in triplet.
                }
            }
        }
        
        return count;														// Returning the #triplets satisfying the given condition.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is 1 Pointer based. We iterate through different combinations of 2 nums in triplet, find the last one accordigly. For every diff.
// first num, we start from two ends first num+1, len-1, we find diff. values of num3 satisfying the given cdn. Then, we change the num2, to 
// further explore diff. combinations of num2, num3 with same num1. As, for a value of num1, we iterate from index of num1+1 till end of vector, 
// so , as a whole we iterate n times making it O(n^2).


// I made small mistake not reassigning base values to index3 to len-1, and got the wrong answer.




class Solution {
public:
    int threeSumSmaller(vector<int>& v, int target) {
        sort(v.begin(), v.end());
        int index=v.size()-1, count=0;
        for(int i=0;i<v.size();i++){										// Scanning through diff. combinations of num1, num2.
            index=v.size()-1;												// Starting index of iteration for finding num3.
            for(int j=i+1;j<v.size();j++){									// Diff. combi. of num2, num3 with same num1.
                int sum=v[i]+v[j];
                if(index<=j) break;											// Avoids duplicates.
                while(index>j && sum+v[index]>=target) index--;				// Reaching num3 satisfying above cdn.
                if(index>j && sum+v[index]<target){							// Satisfying above cdn.
                    // cout<<"i: "<<i<<" and j: "<<j<<" and curr. index: "<<index<<" and sum: "<<sum+v[index]<<endl;
                    count+=(index-j);										// Adding all nums(satisfies cdn) b/w index2 and index3 to final count.
                }
            }
        }
        return count;														// Returning #triplets satisfying given cdn.
    }
};