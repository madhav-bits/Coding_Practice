/*
*
//************************************************************251. Flatten 2D Vector.*****************************************************

Implement an iterator to flatten a 2d vector.

Example:

Input: 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
Output: [1,2,3,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,2,3,4,5,6].
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2],[],[4,5,6],[],[4],[]]

[]

[[]]

[[],[],[2],[],[],[3],[]]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the given vector. At each step, it checks whether next val. exists or not by moving iterator ahead, until it reaches
// a val. or end of vector. If end of vector is reached, we set pres=false, else pres=true.








class Vector2D {
public:
    bool pres=false;														// Says whether next int exist or not?
    vector<vector<int>>v;													// Stores the given vector as global vector.
    int row=0, clmn=0;														// Rows and Coloumns iterator.
    Vector2D(vector<vector<int>>& vec2d) {
        v=vec2d;
        while(row<v.size() && v[row].size()==0) row++;						// Reaching the first value.
        pres=(row==v.size())?false:true;									// If first val. doesn't exist, set pres=false, else pres=true.
    }

    int next() {
        // cout<<"Inside the next with row: "<<row<<" and clmn: "<<clmn<<endl;
        int res=v[row][clmn];												// Accessig the curr. val.
        clmn++;
        while(row<v.size() && clmn==v[row].size()){							// Reaching the next value.
            row++;clmn=0;
        }
        pres=(row==v.size())?false:true;									// If next val. doesn't exist, set pres=false, else pres=true.
        // cout<<"Pres: "<<pres<<endl;
        return res;
    }

    bool hasNext() {
        return pres;														// Returns next value exists or not?
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */