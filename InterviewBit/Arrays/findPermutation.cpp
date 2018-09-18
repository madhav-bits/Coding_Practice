/*
*
//************************************************************Find Permutation.*****************************************************

https://www.interviewbit.com/problems/find-permutation/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


DDI
4


IDDIDDI
8


IIDDIIDDIDDI
13




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, for every curr. index-'i', the value which we are gonna put into depends on the next index also. So,
// for every index, we will look at curr. index and also next index. The special cases are the very first index, last index. As, for the first
// index, we don't have any prev. value to inc/dec upon. As, the last index is concerned, we don't have any next index, based on which to take 
// a decision upon. We deal with them separately(Took a decision, without depending on next index).








vector<int> Solution::findPerm(const string s, int num) {
    if(num==1) return vector<int>({1});										// Base case.
    vector<int>res;															// Final result vector.
    int low=1,high=num;														// Setting the low, high values.
    if(s[0]=='D') res.push_back(high--);									// If first index is 'I', use the low value.
    else if(s[0]=='I') res.push_back(low++);								// If second index is 'D', use the high value.
    for(int i=0;i<s.length()-1;i++){										// Iter. over entire array, except last.
        if(s[i]=='I'){														// If curr. index has 'I'.
            if(s[i+1]=='I') res.push_back(low++);							// If next index has 'I'.
            else res.push_back(high--);										// If next index has 'D'.
        }                
        else if(s[i]=='D'){													// If curr. index has 'D'.
            if(s[i+1]=='D') res.push_back(high--);
            else res.push_back(low++);
        }
    }
    if(s.back()=='D') res.push_back(high);									// If last index has 'D', use high value.
    else res.push_back(low);												// Else, use low value.
    return res;																// Returning the final result vector.
}
