/*
*
//******************************************************2367. Number of Arithmetic Triplets.******************************************************

https://leetcode.com/problems/number-of-arithmetic-triplets/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,1,4,6,7,10]
3
[4,5,6,7,8,9]
2
[2,6,8]
1



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Three Pointer based. Here, since the values in arrays in inc. order, we take three ptrs from 0, 1,2, resp. and in every iter. we inc. i by 1
// we further incresae j until v[j]-v[i]<diff, we also k until v[k]-v[j]<diff, if three indices are within bounds and the diff as required, we inc. res by 1.
// In the next iter. we inc. i by 1, we brake loop when any of the iterators are out of bounds, we inc. res at the end of iter.





class Solution {
public:
    int arithmeticTriplets(vector<int>& v, int diff) {
        int res=0;
		// The commented works even when the array is randomly arranged.
		// We use occur1 to store #occur. of each nums till now, occur2 to store #occur. of second number in triplet with it's corresponding first number in their
		// prev. indices. When at index 'i', we add occur2[v[i]-diff] to res this would represent number of triplets with curr. index being last in the triplet.
        // vector<int>occur(201,0), occur2(201, 0);
        // for(int&num:v) {
        //     if(num>=diff) {
        //         res+=occur2[num-diff];
        //         occur2[num]+=occur[num-diff];
        //     }
        //     occur[num]++;
        // }
        // return res;
        
        int i=0,j=1, k=2;
        while(i<v.size() && j<v.size() && k<v.size()) {						// If any of itrs are out of bounds break the loop.
            while(j<v.size() && v[j]-v[i]<diff) j++;						// Until the curr. diff<req. diff.
            while(j<v.size()&& k<v.size() && v[k]-v[j]<diff) k++;			// Until the curr. diff<req. diff.
            if(j<v.size() && k<v.size() && v[j]-v[i]==diff && v[k]-v[j]==diff) res++;// Inc. res if the triplet is found.
            // cout<<"i: "<<i<<" and j: "<<j<<" and k: "<<k<<endl;
            i++;															// Inc. the first iterator.
        }
        return res;															// Returning the total #triplets formed.
    }
};

