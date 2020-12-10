/*
//************************************This is an Expedia Interview Question.****************************************************

https://leetcode.com/discuss/interview-question/494381/Expedia-Assessment

Problem of minimum divisor:

Given an array of integers, each element is set to be divided by an integer so that the sum of the results is less than or equal to 
a threhold integer. Each non-integer result of division is rounded up before it is added to the sum. For example, 1/9 = 0.111..., 
round up to 1. Determine the minimum divisor to make the sum less than or equal to the threhold.

Example
arr = [1,5,7]
threhold = 8

If the divisor is 1, the results are arr' = [1,5,7] which sums to 13. If the divisor is 2, the results are arr' = [1,3,4] which sums 
to 8. Since the result witht he divisor of 2 is less than or equal to the threhold, the minimum divisor is 2.

minimumDivisor has the following parameters:
int arr[n]: an array of integers
int threshold: maximum value of the sum
Returns:
int: an integer that denotes the minimum divisor.


// Time Complexity: O(nlogm).  												// n- length of the array, m-max. value of rem sum.
// Space Complexity: O(1).

*/

// Time Complexity: O(nlogm).  
// Space Complexity: O(1).
// This Solution is Binary Search based. We search in the range of 1, max(array contents). If the mid gives rem. total<=target, we
// have to search in lower half, as there might be smaller divisors which satisfy given requirement. Else, we search in upper half,
// as there might be greater value whose rem sum would be <=target.




#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Compare{
    public:
    Compare(){
        
    }
    
    static bool compare(int a, int b){
        return a==b;
    }    
    
};


int getMinDivisor(vector<int>&v, int target){
    int low=1, high=low;
    for(auto num:v) high=max(high, num);									// Calc. upper limit for Bin. Search.
    if(target==0) return high+1;											// Edge cases.
    if(high==0) return -1;
    while(low<high){
        int mid=(low+high)/2;
        int rem=0;
        for(auto num:v){
            rem+=num/mid;
            if(num%mid>0) rem++;
        }
        if(rem<=target) high=mid;
        else low=mid+1;
    }
    return low;
}


int main() {
    std::cout << "Hello, world!"<<endl;
    // Compare obj=Compare();
    // cout<<Compare::compare(2,2)<<endl;
    
    vector<int>v({1,5,7});
    int threshold=8;
    int minDivisor=getMinDivisor(v, threshold);
    cout<<"minDivisor: "<<minDivisor<<endl;
    
    return 0;
}