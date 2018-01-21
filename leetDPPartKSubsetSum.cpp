/*
*
//*****************************************************698. Partition to K Equal Sum Subsets.*************************************************

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array 
into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.


// Time Complexity: O(2^n).
// Space Complexity: O(2^n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(2^n).
// Space Complexity: O(2^n).
// This algorithm tries all possible inputs into a bucket and recursively tries to fills the other buckets. If it's not possible to fill all
// buckets after the iterations. Then it's not possible to fill the buckets.

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& v, int k) {
        if(k==1)							//If only single buckets is required to fill, then return true, as the given vector is a bucket.
            return true;
        int len=v.size();
        if(k>len)							//If #buckets is more than no. of elements in vector, it's not possible. So, return false.
            return false;
        int sum=0;
        for(auto num:v) sum+=num;
        if(sum%k!=0) return 0;           	//Achieving such break(integer) is not possible.
        
        int subset=sum/k;
        vector<int>subsetSum(k,0);			//These are buckets intitialized to zero.
        vector<bool>taken(len,false);		//Says whether paricular indexed value is taken into a bucket or not.
        subsetSum[0]=v[len-1];
        taken[len-1]=true;
        
        //return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0, N - 1);
        return PartitionKSubsets(v, subsetSum, taken, subset, k,len, 0, len-1);
    }
    
    bool PartitionKSubsets(vector<int> v, vector<int> subsetSum, vector<bool>taken, int subset, int k, int len, int currIdx, int lastIdx){
        if(subsetSum[currIdx]==subset){		//If the bucket is filled, then we will move to fill the next bucket.
            if(currIdx==k-1)				//If k-1's buckets are filled, then it implies the rem. 1 bucket is also filled. So, return true.
                return true;
            return PartitionKSubsets(v, subsetSum, taken, subset, k,len, currIdx+1, len-1);
        }
        
        for(int i=lastIdx;i>=0;i--){
           if(taken[i]) continue;
            
            if(subsetSum[currIdx]+v[i]<=subset){	//Putting possible values into the bucket and recur. try to fill buckets.
                taken[i]=true;						//Indicating that the curr. value is taken into a bucket.
                subsetSum[currIdx]+=v[i];
                bool nxt=PartitionKSubsets(v,subsetSum, taken, subset, k, len,currIdx, i-1);
                
                //As we are putting all the possible values in the bucket, and chekcing whether it fits or not.
                taken[i]=false;
                subsetSum[currIdx]-=v[i];
                if(nxt) return true;	//If by filling this bucket with this val. leads to filling all buckets, then return true.
            }
        }
        
        return false;					//It's not possible to fill all buckets.
    }
};