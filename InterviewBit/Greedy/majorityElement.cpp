/*
*
//**************************************************************Majority Element.*******************************************************

https://www.interviewbit.com/problems/majority-element/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3 2 1 2



4 2 1 2 2



// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is Voting based. Here, as it's said that majorityElement would be >(floor/2) times, the num. of maj. elem. would be rest of all
// nums. So, even if each of maj. nums in cancelled out by other nums. there would still be atleast 1 maj. elem. left out. So, we iterate over
// array and make the first eleme. as result, if we encounter same value, we inc. the count, if we encoun. diff. value, we dec. the count, if the
// count is <0, we udpate the result value and set it's count to 1. Thus, at the end of iteration, we get the result and it's uncancelled count.





int Solution::majorityElement(const vector<int> &v) {
    int res=v[0];															// Setting first value as result.
    int count=1;															// Tracks #occur. of result var.
    for(int i=1;i<v.size();i++){											// Iter. over array.
        if(v[i]==res) count++;												// If same num. occurs, we inc. the count.
        else{																// If diff. occurs, we dec. the count.
            count--;	
            if(count<0){													// If count<0, we udpate res var and set count to 1.
                count=1;
                res=v[i];
            } 
        }
    }
    return res;																// Returning the final result.
}
