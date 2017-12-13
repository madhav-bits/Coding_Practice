/*

//**************************************************************78. Subsets.*********************************************************

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

//Time Complexity: O(2^n).
// Space Complexity: O(2^n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/



// Solution 1: 
// Iterating through values from 000.. to 111... which represents nums at resp. index in the vector and inserting them into array of vectors.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        set<vector<int>> s;
        vector<vector<int>> w;
        int elem=pow(2,v.size());
          //cout<<"Elem. is: "<<elem<<endl;
          for(int i=0;i<elem;i++){					// Iterating through the range of nums 0 to 2^v.size()-1.
            vector<int> u;							// Temp. vector to store corres. nums of a particular integer in the above range.
            for(int j=v.size()-1;j>=0;j--){
              int num1=pow(2,j);					
              if(num1& i)							// Checking whether jth elem. from the last is in the current subset or not.
                u.push_back(v[v.size()-1-j]);		//Pushing the corres. nums of anything b/w 0000.... to 1111.... into a vector.
            }
              w.push_back(u);						//Pushing the vector into final result.
          }
        return w;									// Returning the final result.
    }
};