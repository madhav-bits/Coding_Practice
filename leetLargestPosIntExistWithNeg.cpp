/*
*
//******************************************************2441. Largest Positive Integer That Exists With Its Negative.******************************************************

https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-1,2,-3,3]
[-1,10,6,7,-7,1]
[-10,8,6,7,-2,-3]
[-9,6,6,6,6,6,6,6,10]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Two Pointer based approach. Since we have to find pairs whose values are of different sign, we use two pointers, we move the pointer corresponding to the int which is 
// greater than the other number in search of lesser value and is of opp. sign to other num.

// Another approach I had used is to use arrays to mark all those nums which were already visited, the pos. and neg. values stored in two diff. arrays, while iteraitng for every number, we check
// for the opposite sign number in the corresponding array, if it is set to true, both signs with same value has occured so we try to maximize the res value and we return the max possible 
// res value, if we dont observe any such pairs with oppo. signs we return -1.







class Solution {
public:
    int findMaxK(vector<int>& v) {
        int res=-1;
		
		// This commented part is another approach in which I had used array to stored/mark all those values which we had already observed while iterating the array.
		// If curr. value is of opp. sign to a value which I had already occured, then we try to maximize the res value and return the max possible res value, if no such 
		// pair found, we return -1 at the end of iteration.
		// Time Complexity: O(n)
		// Space complexity: O(1)
        // vector<bool>posOccur(1001, false), negOccur(1001, false);
        // for(int&num:v) {
        //     if((num<0 && posOccur[-num]) || (num>0 && negOccur[num])) res=max(res, abs(num));
        //     if(num<0) negOccur[-num]=true;
        //     else posOccur[num]=true;
        // }
        // return res;
        
        
        sort(v.begin(), v.end());											// Sorting the array for the two pointer approach.
        int low=0, high=v.size()-1;
        while(low<high) {
            int num1=v[low], num2=v[high];
            if(-num1==num2) return num2;									// Opp. signs but same value, we return the value as this would be the greatest such value.
            if(-num1<=num2) high--;
            else low++;
        }
        return -1;															// No such desired pair of nums found.
    }
};



