/*
*
//************************************************************42. Trapping Rain Water.***************************************************

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap 
after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being 
trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[10,0,4,0,6,0,10]

[1,2]
[1]
[]
[3,4,2,5,3,6,3,2,3,6,5,3,65]
[10,0,4,0,6,0,10]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is observation based. We observe that water storage at a index depends on the min. of the Max. Heights of indices on it's both 
// sides. This is calculated by making two iterations, in one iter. we calc. and store max. height to left of all indices and in the other we store
// the max. height to the right of all indices by starting iterating from start/end and maintaining a var. maxHeight starting from start/end and
// assigning it to that index.

// In the third iteration, we iterate over the entire array, at each index, we know the max. Height to the left and right, we get min. of them and
// subtract the curr. height from the min. to get the stored water.





class Solution {
public:
    int trap(vector<int>& v) {
        if(v.size()<=2) return 0;													// A Dip to store water can't be formed.
        int res=0;
        vector<int>maxL(v.size(),0),maxR(v.size(),0);								// Stores Max. Height to left and right of all indices.
        maxL[0]=v[0]; maxR[v.size()-1]=v[v.size()-1];								// Assigning values to end indices/start case.
        
        for(int i=1, j=v.size()-2;i<v.size();i++, j--){								// Calc. Max Height to left and right of all indices.
            maxL[i]=max(v[i], maxL[i-1]);											// Calc. Max. Height to the left side.
            maxR[j]=max(v[j],maxR[j+1]);											// Calc. Max. Height to the right side.
        }
        //cout<<"Done with max. left and right."<<endl;
        for(int i=0;i<v.size();i++){												// Calc. the water storage at each index and adding them.
            //cout<<"max left is: "<<maxL[i]<<" and max right: "<<maxR[i]<<endl;
            res+=min(maxL[i], maxR[i])-v[i];
        }
        return res;																	// Returning the tota. stored water.
    }
};