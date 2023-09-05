/*
*
//******************************************2170. Minimum Operations to Make the Array Alternating.***************************************

https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,1,3,2,4,3]
[1,2,2,2,2]
[3,3,3,3]
[2,2,2,2,2]
[5,4,2,4,6,7,7,8,5,4,3,12,3,2,3,4,2,6,6,8,5,5,3,2,2,4,5,7,7,6,3,2,2,4,5,4,7,6,4,3,5]
[5,4,2,4,6,7,7,8,5,4,3]



// Time Complexity: O(n).													// n-length of the array, m-range of nums in the array.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n-length of the array, m-range of nums in the array.
// Space Complexity: O(m).	
// This algorithm is Map+Iteratoin based. Based on the conditions specified all even indices should have same value and odd indices should have same value and 
// that even, odd indices shouldn't have same value. For us to make minm changes and ensure this condition holds, in even, odd indices separately we have to 
// convert all nums!=maxOccur num in that part to max num so that #changes would be minm. As we have to ensure that even, odd indices don't have same value 
// after the changes. We track top 2 max occur nums in even,odd indices. If max occurring num in both parts are the same then when we choose second max in the 
// other part, as there are two ways to do it, we pick the way that gives the least moves. If max occur nums are different in both parts, we use this pair and 
// change rest nums, calculate #changes and return it.







class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int evenOccur[100001], oddOccur[100001], even1=0, even2=0, odd1=0, odd2=0;
        int len=v.size();
        memset(evenOccur, 0, sizeof(evenOccur));
        memset(oddOccur, 0, sizeof(oddOccur));
        for(int i=0;i<v.size();i++) {
            if(i%2==0) {
                int occur=++evenOccur[v[i]];								// Tracking #occur. of each num in even indices.
                if(occur>=evenOccur[even1] && v[i]!=even1) {				// If #occur of a num>=maxOccur and if it's a diff. num we change it.
                    even2=even1;
                    even1=v[i];
                } else if(v[i]!=even1 && occur>evenOccur[even2]) even2=v[i];// If #occur of a num>second maxOccur and diff from first max, we change it.
            } else {														// We use the same max tracking approach with odd indices too.
                int occur=++oddOccur[v[i]];
                if(occur>=oddOccur[odd1] && v[i]!=odd1) {
                    odd2=odd1;
                    odd1=v[i];
                } else if(v[i]!=odd1 && occur>oddOccur[odd2]) odd2=v[i];
            }
        }
//         cout<<"even1: "<<even1<<" and even2: "<<even2<<endl;
//         cout<<"odd1: "<<odd1<<" and odd2: "<<odd2<<endl;
        
//         cout<<"even1 occur: "<<evenOccur[even1]<<" and even2 occur: "<<evenOccur[even2]<<endl;
//         cout<<"odd1 occur: "<<oddOccur[odd1]<<" and odd2 occur: "<<oddOccur[odd2]<<endl;
        if(even1!=odd1) return (len-evenOccur[even1]-oddOccur[odd1]);		// If first max in two parts are diff, we use them and calc. #changes.
        return min((len-evenOccur[even1]-oddOccur[odd2]), (len-evenOccur[even2]-oddOccur[odd1]));// If first maxs match, we use the best combi of maxs and 
																								// return least #changes of the two combinations.
    }
};

