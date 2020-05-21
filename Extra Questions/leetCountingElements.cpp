/*
*
//******************************************************1426. Counting Elements.*************************************************

https://leetcode.com/problems/counting-elements/description/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3]
[1,1,3,3,5,5,7,7]
[1,3,2,3,5,0]
[1,1,2,2]
[1,1,2]



// Time Complexity: O(n).  													// n- size of the given array.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- size of the given array.
// Space Complexity: O(n).	
// This algorithm is map based, which counts the #occurrences of each value. We iter. over map, at every step, we check next value is
// present in the map, if it is, we add the curr. #occurrences to the final result.





class Solution {
public:
    int countElements(vector<int>& v) {
        if(v.size()==1) return 0;
        unordered_map<int,int>m;											// Tracks #occurrences of each number.
        for(auto num:v) m[num]++;
        int res=0;
        for(auto it=m.begin();it!=m.end();it++){							// Iter. over map.
            if(m.count(it->first+1)==1) res+=it->second;					// If next num is in map, we add curr. #occur. to final res.
        }
        return res;															// Return the total count.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// m-range of values allowed in the array.
// Space Complexity: O(m).													// n- size of the given array.
// This algorithm is similar to first algorithm. But, here we store #occurrences in a int array, we define the size of the array based
// on the range of values allowed in the array. We iter. over array, if next number had occured in orig. array, we add curr. #occur. 
// to final result.





class Solution {
public:
    int countElements(vector<int>& v) {
        if(v.size()==1) return 0;
        vector<int>occur(1001,0);											// Track #occurrences of each value.
        int res=0;
        for(auto num:v) occur[num]++;
        for(int i=0;i<1000;i++){											// Iter. over occurrenes array.
            if(occur[i+1]!=0) res+=occur[i];								// If next num. had occurred, add curr. #occur. to final res.
        }
        return res;															// Return the total count.
    }
};

