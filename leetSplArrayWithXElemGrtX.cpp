/*
*
//**************************************1608. Special Array With X Elements Greater Than or Equal X.*************************************

https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,5]
[0,0]
[0,4,3,0,4]
[0]
[7,0,3,6,7]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is sorting based. Here, since we want to get #nums greater than given num. We sort the nums which makes countinng easy.
// Here, we iter. over arr., for every index. we get #nums to right=num, if num<=curr. index's stored value, which makes x values >=x and
// prev. value is <#nums, as the values of the set>=#nums and we return the length of the set of values. If we no value 
// found, we return -1.








class Solution {
public:
    int specialArray(vector<int>& v) {
        sort(v.begin(), v.end());											// Sort the given array.
        for(int i=0;i<v.size();i++){
            if(i>0 && v[i]==v[i-1]) continue;								// As conti. nums can't be partially put into set.
            if(i==0 && v.size()<=v[0]) return v.size();						// For entire set of nums.
            int num=v.size()-i;
            if(i>0 && v[i-1]<num && num<=v[i]) return num;					// For set starting at index "i".
        }	
        return -1;															// No set found, return -1.
    }
};
