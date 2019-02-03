/*
*
//******************************************************756. Pyramid Transition Matrix.***********************************************

We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.

For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of 
color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.

We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed 
triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:
Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  D   E
 / \ / \
X   Y   Z

This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
Example 2:
Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
Note:
bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"XXYX"
["XXX", "XXY", "XYX", "XYY", "YXZ"]


"XYZ"
["XYD", "YZE", "DEA", "FFF"]



// Time Complexity: O(n^3).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n).	
// This algorithm is backtracking/Recursion/DFS based. Here, at every step we form allowed chars in curr. level based on chars from prev. 
// level and forward the allowed chars to use in forming it's above level. In this way, we iterate till we have only one char in bottom 
// level, indicating that we reached top of Pyramid. 
// Here, in each recursion, we iter. over bottom string and form each top char and update
// the index in bottom string to be processed, if we reach end of bottom str, we make curr. str as bottom str for next iter and set index
// to be scanned as 0.








class Solution {
public:
    
    bool formPyr(string bottom, string curr, int i, unordered_map<string,vector<char>>&m){
        if(bottom.length()==1) return true;									// If top of pyramid is reached, return true.
        // cout<<"Inside fn with bottom: "<<bottom<<" and curr: "<<curr<<endl;
        string s="";
        s+=bottom[i]; s+=bottom[i+1];										// Forming the mini str out of bottom str.
        if(m.count(s)==0) return false;										// If that str isn't allowed then return false.
        for(int j=0;j<m[s].size();j++){										// Iter. over all possible top chars for curr. bottom char pair.
            // cout<<"bottom: "<<bottom<<" temp str: "<<curr+*it<<"with i: "<<i<<endl;
            if(i==bottom.length()-2){										// If we reached end of bottom, set curr. as bottom str.
                if(formPyr(curr+m[s][j],"",0,m)) return true;				// If top reached with this combi., return true.
            } 
            else{
                if(formPyr(bottom,curr+m[s][j],i+1,m)) return true;			// Give recur. call with updated index in bottom to be scanned.
            }    
        }
        return false;														// If top not found in any possib. combi. return false.
    }
    
    bool pyramidTransition(string bottom, vector<string>& v) {
        unordered_map<string,vector<char>>m;								// Stores allowed triplets.
        for(int i=0;i<v.size();i++) m[v[i].substr(0,2)].push_back(v[i][2]);	// Push triplets into map.
        return formPyr(bottom, "",0,m);										// Give call to find way to top of pyramid.
    }
};

