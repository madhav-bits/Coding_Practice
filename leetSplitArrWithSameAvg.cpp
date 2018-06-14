/*
*
//******************************************************805. Split Array With Same Average.***********************************************

In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)

Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C 
are both non-empty.

Example :
Input: 
[1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
Note:

The length of A will be in the range [1, 30].
A[i] will be in the range of [0, 10000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[11,20,18,12,16,19,3,43,2,4,23,3,6,2,2,6,2,1,4,2,1,5,22,3]


[60,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30]


[33,86,88,78,21,76,19,20,88,76,10,25,37,97,58,89,65,59,98,57,50,30,58,5,61,72,23,6]





// Time Complexity: O(2^n).  
// Space Complexity: O(2^n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).
// Space Complexity: O(2^n).	
// This algorithm is DFS based. At each step, one of the two lists take the curr. num and pass the udpated sum to the fn. to choose b/w the next
// on reaching the end of the vector. We, check whether the avgs of two lists are equal or not. The logic is correct, but little pruning is 
// done, so it throws TLE errors.








class Solution {
public:
    float avg;
    bool findSplit(vector<int>&v, int index, float sum1, float sum2, float len1, float len2){
        if(index==v.size()){												// On reaching end of array, check avgs are equal or not?
            if (len1!=0 && len2!=0  && sum1/len1==sum2/len2) return true;
            return false;
        }
        
        if(len1==0 || sum1/len1<=avg)										// Curr. num is chosen by list1.
             if(findSplit(v,index+1, sum1+v[index], sum2, len1+1, len2)) return true;
        if(len2==0 || sum2/len2<=avg)										//  Curr. num is chosen by list2.
             return findSplit(v,index+1, sum1, sum2+v[index], len1, len2+1)?true:false;
        return false;
        
    }
    
    bool splitArraySameAverage(vector<int>& v) {
        if(v.size()<=1) return false;
        bool res=false;
        int sum=0;
        for(int i=0;i<v.size();i++) sum+=v[i];								// Calc. sum of array.
        avg=sum/v.size();
        sort(v.begin(), v.end());											// Sorted in desc. order.
        return findSplit(v,0,0,0,0,0);										// Call. fn. to find list of elem.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).
// Space Complexity: O(2^n).	
// This algorithm is DFS based. We have done pruning, array is sorted, we push into list the values from the back. The avg of the list is the 
// avg of the whole array. 



class Solution {
public:
    
    bool findSplit(vector<int>&v, int index, int len, int target){
        if(target>len*v[index]) return false;							// IF the curr. elem. is <rem. elem. avg, then it can't fit in list.
        if(len==0) return target==0;									// If list is filled and avg. is same as array, return false.
        for(int i=index;i<=v.size()-len;i++){							// Chose curr. value and call. fn. to extract further values.
            if(v[i]<=target && findSplit(v,i+1,len-1,target-v[i])) return true;
        }
        return false;
    }
    
    
    bool splitArraySameAverage(vector<int>& v) {
        if(v.size()<=1) return false;
        int sum=0;
        for(int i=0;i<v.size();i++) sum+=v[i];
        sort(v.rbegin(), v.rend());											// Sorted in Descending Order.
        for(int i=1;i<=v.size()/2;i++){										// Making sure, avg is same as whole array. Leng of list is chosen.
            if((sum*i)%v.size()==0 && findSplit(v,0,i,sum*i/v.size())) return true;	// Call. fn to find elem. in list.
        }
        return false;														// If no such list of found, return false.
    }
};







//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3M).
// Space Complexity: O(n^3M).	
// This algorithm is DFS based. We have done pruning. We form lists of length<=n/2. For each list of size ranging from 1 to n/2. We check, whether
// it's avg. is same as whole avg, if true, we return true.





class Solution {
public:
    
    
    bool splitArraySameAverage(vector<int>& v) {
        if(v.size()<=1) return false;
        int mid=v.size()/2;
        int sum=accumulate(v.begin(), v.end(),0);
        // cout<<"Sum is: "<<sum<<endl;
        bool possi=false;
        for(int i=1;i<=mid && !possi;i++)									// Checking whether split of any len is possib. or not?
            if(sum*i%v.size()==0) possi=true;
        if(!possi) return false;											// If not possible, return false.
        vector<unordered_set<int>> dp(mid+1);								// DP vector of size len of vector /2.
        dp[0].insert(0);													// Sum of zero elem. from array.
        for(auto num:v){													// Iterates through all elem.
            for(int i=mid;i>=1; i--)										// As, len of "k" depend on len of "k-1", we go from back.
                for(int mem: dp[i-1])										// If elem. in len "k-1", we add curr. num to them, push in curr.
                    dp[i].insert(mem+num);
        }
            
        for(int i=1;i<=mid;i++)												// Iter. through all len., check avg. of sums is same as array?
            if(sum*i%v.size()==0 && dp[i].find(sum*i/v.size())!=dp[i].end()) return true;
        return false;														// If no such sum found, return false.
    }
};

