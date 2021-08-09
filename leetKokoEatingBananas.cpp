/*
*
//*************************************************************875. Koko Eating Bananas.*********************************************************


https://leetcode.com/problems/koko-eating-bananas/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[3,6,7,11]
8
[30,11,23,4,20]
5
[30,11,23,4,20]
6


// Time Complexity: O(mlogn).												// n-highest pile of bananas in the array, m-length of array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlogn).												// n-highest pile of bananas in the array, m-length of array.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, to find the minm. speed 'k', there is no particular way to get exact number. We use Binary Search in the
// possible range of speeds. Here, since array size<=h, max. sensible speed which satisfies this condition is the highest pile size valued speed. We do
// Binary Search in this range, for every mid value, we calc. the time taken, if time taken<=h, then this speed satisfies, we search in lower half in
// search of lower satisfying speeds else we search in upper half in search of higher valued satisfying speeds.











class Solution {
public:
    
    int getTime(vector<int>&piles, int speed){								// Calc. time taken for curr. speed.
        int res=0;
        for(int num:piles){
            res+=num/speed;
            if(num%speed!=0) res++;
        }
        return res;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=piles[0];
        for(int num:piles) high=max(high, num);								// Max. sensible speed that satisfies condition is the highest pile size.
        while(low<high){													// We do Bin. Search in given range.
            int mid=(low+high)/2;
            int time=getTime(piles, mid);
            if(time<=h) high=mid;											// If time taken<=h, we search in lower half for lower satisfying speeds.
            else low=mid+1;													// If time>h, we search in upper half for satisfying speeds.
        }
        return low;															// Return the least possible speed that satisfies condition.
    }
};

