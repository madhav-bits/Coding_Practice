/*
*
//************************************1953. Maximum Number of Weeks for Which You Can Work.****************************************

https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3]
[5,2,1]
[4,8,10]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. Since, we can work on a milestone alternately, we can center our approach around the max.value milestone. If for every 
// instance of working on milestone, we work on rest other milestones before working on max. milestone once again. We will be able to cover non-max milestones
// without any issues, but if max. milestone value>sum(non-max milestone values), in this case even if we only non-max milestone in b/w two max. milestones,
// we still have max. milestones left, in this case, #worked milestones=(2*non-max milestones)+1.
// If sum(non-max milestone values)>=max. milestone value, we can move any of the non-max milestones from intervals where we used >1 non-max milestone to 
// intervals there is no non-max milestone, since sum of non-max>max. milestone value, all max. milestones+non-max milestones will be covered, we return sum
// of all milestones.





// This discussion forum link has a detailed explanation for a similar approach:
// https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/discuss/1375390/Python-Solution-with-detailed-explanation-and-proof-and-common-failure-analysis








class Solution {
public:
    long long numberOfWeeks(vector<int>& v) {
        // int maxm=0, rep=0;
        // long long int total=0;
        // for(int&num:v) {
        //     total+=num;
        //     if(num>maxm) {
        //         maxm=num;
        //         rep=1;
        //     } else if(num==maxm) rep++;
        // }
        // if(rep>1) return total;
        int maxm=*max_element(v.begin(), v.end());							// Max. milestone value.
        long long int total=accumulate(v.begin(), v.end(), 0ll);			// Sum of all milestones.
        long long int sumRest=total-maxm;									// Sum of non-max milestone values.
        if(sumRest<maxm) return 2ll*sumRest+1;								// If sum of non-max<max value, return 2*sum of non-max+1.
        return total;														// Return sum of all milestones as all milestones will be completed.
    }
};

