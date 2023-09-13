/*
*
//******************************************************923. 3Sum With Multiplicity.******************************************************

https://leetcode.com/problems/3sum-with-multiplicity/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,2,2,3,3,4,4,5,5]
8
[1,1,2,2,2,2]
5
[2,1,3]
6
[1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,7]
8
[76,53,49,86,87,75,93,73,53,33,97,84,93,34,4,99,7,49,23,54,45,83,3,43,22,3,45,6,36,94,9,33,3,26,6,32,33,89,44,23,5,3,72,75,95,33,8,53,5,43,3,5]
299




// Time Complexity: O(m^2).													// m-range of nums in the array.
// Space Complexity: O(m).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2+nlogn)=O(n^2).									//n-length of the array.
// Space Complexity: O(1).	
// This algorithm is Sorting+2 Sum based. We sort the given array, as we have to pick three diff indices it doesn't affect final result if we sort the array.
// We iter. over the array and we use 2 sum technique to find rem. two nums which when combined with curr. num eqls target number. If there are multiple 
// instances of second, third num we count #occur of each of the nums and multiply their product to get total #combinations which includes curr. first num.
// One exception here is that second, third num are of same value then we track #occur of num and use nc2 to get #combinations and add this to res, now we 
// move first num iter. to next inex. We return res at the end of iter.








class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int res=0, mod=1000000007, prev=0;
        sort(arr.begin(), arr.end());
        for(int i=0;i+2<arr.size();i++) {
            prev=0;
            int j=i+1, k=arr.size()-1, req=target-arr[i];
            while(j<k) {
                if(arr[j]+arr[k]==req) {									// If sum of three nums is =target.
                    int left=j++, right=k--;
                    while(j<arr.size() && arr[j]==arr[j-1]) j++;			// Track #occur of second num.
                    while(k>=0 && arr[k]==arr[k+1]) k--;					// Track #occur of third num.
                    int len1=j-left, len2=right-k;
                    if(j-k>1)prev=(0ll+prev+1ll*(len1*(len1-1))/2)%mod; 	// If second, third num are eql, we use nc2 to get #combi.
                    else prev=(0ll+prev+1ll*len1*len2)%mod;					// Else we multiply #occur to get total #combi with curr. first num.
                } else if(arr[j]+arr[k]<req) j++;							// If sum of three num<target, we move left ptr.
                else k--;													// If sum>target, we move right ptr.
            }
            // cout<<"i: "<<i<<" and cnt: "<<prev<<endl;
            res=(0ll+res+prev)%mod;											// We add curr. num's contribution to res.
        }
        return res;															// Returning total #triplets whose sum=target.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m^2).													// m-range of nums in the array.
// Space Complexity: O(m).	
// This algorithm is observation based. Here, we track #occur of each of the nums in the array. Since we need triplets, there are types to form triplets,
// whose sum=target. When all of them are of same value, when two of them are of same value and none of them are of same value. We iter. over all occur. 
// nums and we get #combi. where sum of 3 nums=target, where curr. num is part of eql valued triplet, curr. num occurs twice in triplet and none of tripet
// are of same value, as we check for triple, double presence of curr. num and only counting them if total=target, we won't have duplicate combi. as we move 
// to greater values.









class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int res=0, mod=1000000007, prev=0;
        int occur[101];
        memset(occur, 0, sizeof(occur));
        for(int&num:arr) occur[num]++;										// Tracking #occur. of each num.
        for(int i=0;i<=100;i++) {											// Iter. over all nums in inc. order.				
            if(occur[i]==0) continue;
            for(int j=i;i+j<=target;j++) {									// Iter. over nums>curr./first num.
                int k=target-i-j;
                if(k>100) continue;
                if(i==j && j==k && occur[i]>2) res=(0ll+res+(1ll*occur[i]*(occur[i]-1)*(occur[i]-2))/6)%mod;// If sum=target and three nums=first num.
                else if(i==j && j!=k) res=(0ll+res+(1ll*occur[i]*(occur[i]-1)*occur[k])/2)%mod;// If sum=target and two eql nums=first num.
                else if(i<j && j<k) res=(0ll+res+occur[i]*occur[j]*occur[k])%mod;// If sum=target and none of vals are same.
            }
        }
        return res;															// Returning total #triplets whose sum=target.
    }
};

