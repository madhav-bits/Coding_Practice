/*
*
//******************************************************719. Find K-th Smallest Pair Distance.***********************************************

Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute 
difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,7,10,3,2,17,22,52,33]
23

[4,7,10,3,2,17,22,52,33]
36




// Time Complexity: O(n*log(Max_Diff)+nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2*logn).
// Space Complexity: O(1).	
// This algorithm is Priority Queue based. We push all possible pairs leading to diff. into priority queue and extract the min. of them, once 
// extracted,we push the next min. diff. that pair's first digit can generate with some other number. This algo. had got TLE, so as to overcome
// that I had planned of using maps where I count the #occurances of each num, but I was unable to write the custom comaprator where it accepts 
// global/local vars into it( I had gone through many atricles on it, but still couldn't find any proper result.








class Solution {
public:
    struct comp{
        bool operator()(const auto&lt,const auto&rt){
            return lt.first>rt.first;
        }    
    };
    
    int smallestDistancePair(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        for(int i=0;i<v.size()-1;i++){
            pq.push({v[i+1]-v[i],i+1});
        }
        
        int count=0;
        pair<int,int>curr;
        while(count<k){
            count++;
            curr=pq.top();
            // cout<<"CUrr. area: "<<curr.first<<" and second: "<<curr.second<<endl;
            // if(count==k) return curr.first;
            pq.pop();
            if(curr.second<v.size()-1)
                pq.push({curr.first-v[curr.second]+v[curr.second+1],curr.second+1});
        }
        return curr.first;
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*log(Max_Diff)+nlogn).
// Space Complexity: O(1).	
// This algo. is binary search based. Here, we implement two layers of Binary Search. In the first layer, we choose the diff. and binary search 
// for one, which has k or greater num. of pairs with diff lesser to equal to curr. diff. While calc. the #pairs with diff lesser or equal, we do
// a linear search. That's why it has got higher execution time.
// We also use Sliding Window here. In calc. the #pairs with smaller/equal diff. to curr. diff.




class Solution {
public:

    int smallestDistancePair(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int low=0, high=v.back()-v[0], mid;									// Doing binary search on diff.
        while(low<high){
            int mid=low+(high-low)/2;
            // cout<<"mid: "<<mid<<endl;
            int count=0;
            for(int i=0;i<v.size();i++){									// Calc. #pairs with lesser or equal diff.
                int j=i+1;													// Iterating through pairs satisfying cdn.
                while(j<v.size() && v[j]-v[i]<=mid) j++;
                // cout<<"Added pairs: "<<j-i-1<<endl;
                count+=(j-i-1);												// Extracing count of #pairs with smaller/equal diff.
            }
            // cout<<"Count: "<<count<<endl;
            if(count>=k) high=mid;											// If the #pairs is gretaer or equal our result might be in those set.
            else low=mid+1;													// Else, our result might be in other half(right half).
        }
        return low;
    }
};









//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*log(Max_Diff)+nlogn).
// Space Complexity: O(1).	
// This algo. is binary search based. Here, we implement two layers of Binary Search. In the first layer, we choose the diff. and binary search 
// for one, which has k or greater num. of pairs with diff lesser to equal to curr. diff. While calc. the #pairs with diff lesser or equal, we do
// a binary search for num, which forms diff. greater than curr. diff. Exception case is handles separately(When all pairs it can form are of diff.
// <=k).(Upper bound would have taken care of.) 
// We also use Sliding Window here. In calc. the #pairs with smaller/equal diff. to curr. diff.




class Solution {
public:

    int smallestDistancePair(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int low=0, high=v.back()-v[0], mid;
        while(low<high){
            int mid=low+(high-low)/2;
            // cout<<"mid: "<<mid<<endl;
            int count=0;
            for(int i=0;i<v.size();i++){
                int k=v.size()-1,j=i+1, mid2;
                if(v.back()-v[i]<=mid){										// All possible pairs are of diff. <=k.
                    count+=(v.size()-i-1);
                    continue;
                }
                while(j<k){
                    mid2=j+(k-j)/2;
                    if(v[mid2]-v[i]>mid) k=mid2;
                    else j=mid2+1;
                }
                // cout<<"Added pairs: "<<k-i-1<<endl;
                count+=(k-i-1);
            }
            if(count>=k) high=mid;
            else low=mid+1;
        }
        return low;
    }
};









//************************************************************Solution 4:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*log(Max_Diff)+nlogn).
// Space Complexity: O(1).	
// This algo. is binary search based. Here, we implement two layers of Binary Search. In the first layer, we choose the diff. and binary search 
// for one, which has k or greater num. of pairs with diff lesser to equal to curr. diff. While calc. the #pairs with diff lesser or equal, we do
// a binary search for num, which forms diff. greater than curr. diff. Exception case is handles separately(When all pairs it can form are of diff.
// <=k).(Upper bound would have taken care of.) 
// We also use Sliding Window here. In calc. the #pairs with smaller/equal diff. to curr. diff.


class Solution {
public:

    int smallestDistancePair(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int low=0, high=v.back()-v[0], mid;
        while(low<high){
            int mid=low+(high-low)/2;
            // cout<<"mid: "<<mid<<endl;
            int count=0;
            for(int i=0;i<v.size();i++){
                int lower=0;
                while(lower<v.size() && v[i]-v[lower]>mid) lower++;
                count+=(i-lower);
            }
            if(count>=k) high=mid;
            else low=mid+1;
        }
        return low;
    }
};