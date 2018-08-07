/*
*
//**************************************************668. Kth Smallest Number in Multiplication Table.*******************************************

Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?

Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number in 
this table.

Example 1:
Input: m = 3, n = 3, k = 5
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th smallest number is 3 (1, 2, 2, 3, 3).
Example 2:
Input: m = 2, n = 3, k = 6
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6

The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
Note:
The m and n will be in the range [1, 30000].
The k will be in the range [1, m * n]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
3
6



22
34
45



// Time Complexity: O(n*logm*n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*logm*n).
// Space Complexity: O(1).	
// This algorithm is Binary Search based. We extract the num. which has K smaller/equal values to it's value. IN this solution, we perform two
// levels of binary search, in the first level, we binary search for final result, in the second(innner Binary Search), we go through all nums
// and extract it's #multiples <=curr. value. If we attain #multiples >=K, then curr. value might be answer, so reduced search span to high=mid;
// else, we reduce the search to low=mid+1.


// Here,we perform Binary Search to find first number which has K smaller/equal values.





class Solution {
public:
    
    int findCount(int target, int minm, int maxm){							// Calc. #elem. with values<=itself(curr. value).
        int count=0,num=0;
        for(int i=0;i<minm;i++){											// Extract #multiples with values<=itself(curr. value) from each number.
            num++;
            count+=min(target/num,maxm);									// Extract values <=itself.
        }
        return count;														// Return total #smaller/equal values.
    }
    
	
    int findKthNumber(int m, int n, int k) {
        int low=1, high=m*n,mid;											// Two extreme values in the range provided.
        while(low<high){													
            // cout<<"low: "<<low<<" and high: "<<high<<endl;
            mid=low+(high-low)/2;
            int res=findCount(mid,m, n);									// Find #vlaues <=curr. value(mid).
            // cout<<"The count for mid: "<<mid<<" is: "<<res<<endl;
            if(res>=k) high=mid;											// If #values>=K, we focus on left half.
            else low=mid+1;													// Else, we focus on right half.
        }
        return low;															// Returning the result.
    }
};