/*
*
//***************************************************1664. Ways to Make a Fair Array.*************************************************

https://leetcode.com/problems/ways-to-make-a-fair-array/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[2,1,6,4]
[1,2,3]
[1,1,1]
[3,4,2,6,3,7,4,3,7]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation and iteration based. Here,we store the sum of all values in even, odd indices in evenTotal, oddTotal.
// In second iter., at every step we also gather sum of values in even, odd indices, we add EvenSumTillNow+oddSum after curr. index
// and comapre it with oddSumTillNow+EvenAfterCurrIndex, we won't value of curr. index as we are checking for a possibility where
// curr. index is deleted. If both those values are equal, we inc. the res.








class Solution {
public:
    int waysToMakeFair(vector<int>& v) {
        int evenTotal=0, oddTotal=0;
        for(int i=0;i<v.size();i++){										// Calc. sum of even, odd indices.
            if(i%2==0) evenTotal+=v[i];
            else oddTotal+=v[i];
        }
        int currEven=0, currOdd=0,res=0;
        for(int i=0;i<v.size();i++){
            // cout<<"leftEven: "<<currEven<<" and rightEven: "<<endl;
            if(i%2==0 && currEven+oddTotal-currOdd==currOdd+evenTotal-currEven-v[i]) res++;// Calc. odd, even indices total.
            if(i%2==1 && currEven+oddTotal-currOdd-v[i]==currOdd+evenTotal-currEven) res++;
            if(i%2==0) currEven+=v[i];										// Updating even indices total till now.
            else currOdd+=v[i];
        }
        return res;															// #Indices where sum of rest even, odd ind. vals are equal.
    }
};