/*
*
//**********************************************1552. Magnetic Force Between Two Balls.***********************************************

https://leetcode.com/problems/magnetic-force-between-two-balls/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[1,2,3,4,7]
3
[5,4,3,2,1,1000000000]
2



// Time Complexity: O(nlogn+nlogm).											// n-#elem. in array, m-#largest possible gap b/w balls.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+nlogm).											// n-#elem. in array, m-#largest possible gap b/w balls.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, we do Bin. Search in the range of possible gaps with the given balls. If all alls can be placed
// with curr. gap, we look in upper half for largest gaps where balls can be placed. Else, we place in lower half looking for smaller gaps.










class Solution {
public:
    
    bool isPossible(vector<int>&v, int gap, int balls){						// Checking if balls can be spread with given gap.
        int currBall=v[0];balls--;
        for(int i=1;i<v.size() && balls;i++){
            if(v[i]-currBall>=gap){											// If gap b/w prev. and curr. ball>=gap, we put a ball.
                balls--;
                currBall=v[i];
            }
        }
        return (balls==0);													// If all balls can be placed, return true.
    }
    
    int maxDistance(vector<int>& position, int m) {
        int low=1, high=0;
        sort(position.begin(), position.end());
        high=(position.back()-position[0])/(m-1);							// Maxm. possible gap b/w balls.
        int res=0;
        while(low<=high){
            // cout<<"low: "<<low<<" and high: "<<high<<endl;
            int mid=(low+high)/2;
            if(isPossible(position, mid, m)){								// If balls can be placed with curr. gap.
                res=mid;													// Store the curr. gap value.
                low=mid+1;													// Then Search in upper half for greater gaps b/w balls.
            }
            else high=mid-1;												// Search in lower half for smaller gaps b/w balls.
        }
        return res;															// Returning the largest possible minm. gap.
        // return isPossible(position, low, m)?low:low-1;
    }
};

