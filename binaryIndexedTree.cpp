/*
*
//******************************************************BINARY INDEXED TREE(FENWICK TREE).***********************************************

This code describes the construction of the Binary Indexed Tree, which supports Update and extract Sum of start till that index functionalities.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


// Mentioned in the main function.



// Time Complexity: O(nlogn).  
// Space Complexity: O(nlogn).

//********************************************************THIS IS FOR INFORMATIVE PURPOSE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS FOR INFORMATIVE PURPOSE..***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(nlogn).	
// This algorithm speaks of Costructing, updating a node, getSum of indices starting from 0, till any index(Can be modified to RangeSum).

// For further clear explaination this geeksforgeeks would help: https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
// Tushar Roy's youtube video: https://www.youtube.com/watch?v=CWDQJGaN1gY



// Time Complexity: 
// Construct BIT: O(nlogn).
// getSum till certain index: (logn)
// update(add) value at an index: (logn)





#include <iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<cmath>


using namespace std;

int getSum(vector<int> &v, int index){										// Get sum of values in indices [0..index] in orig. array.
																			// Get sum of values in indices [1..index+1] in BIT.
  int len=v.size();
  index++;																	// Converting the int to suit BIT.
  int res=0;
  while(index>0){															// Updates all nodes, which covers curr. index's value.
    res+=v[index];
    index=index-(index & (-index));											// Finding the parent's index of curr. node.
  }
  return res;

}

void updateBIT(vector<int>&res, int index, int val){						// Updates BIT's value at index value-"index+1" 
  index++;      															// Index-i in orig. array would become (i+1) in BIT.
  while(index<res.size()){													// Updating index and it's parent's values.
    res[index]+=val;
    index=index+(index&(-index));       									// Finding parent's index number.
  }

}

vector<int> constructBIT(vector<int> arr){									// Construcuts BIT Tree.
  int len=arr.size();														// Gets len. of Give Array.
  vector<int> res(len+1,0);													// We create a BIT of length (len+1), index 0 is dummy.
																			// Node with index y with parent index-x, stores sum of values from
																			// index x to (y-1).[x,y-1] indices.
  for(int i=0;i<len;i++)													// Updating all nodes with array's values.
    updateBIT(res,i,arr[i]);

  return res;																// Returning the constructed BIT tree.
}



int main() {
  //int c=14;
  //cout<<"bits of c: "<<bitset<32>(c)<<endl;
  //cout<<"bits of c: "<<bitset<32>(-c)<<endl;
  //int parent= c-(c&-c);
  //cout<<"parent: "<<bitset<32>(parent)<<endl;
  vector<int>v;																// Orig. array.
  v.push_back(2);
  v.push_back(1);
  v.push_back(1);
  v.push_back(3);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  v.push_back(7);
  v.push_back(8);
  v.push_back(9);	
  vector<int> bTree=constructBIT(v);										// Constructs Binary Indexed Tree.
  for(auto num:bTree) cout<<num<<" ";cout<<endl;
  cout<<"Sum of first 6: "<<getSum(bTree,4)<<endl;							// Gets sum of [0..4](first 5) indices.			
  updateBIT(bTree,4,4);       // Passed indices are wrto original array.	// Update(add) arr[4] value by 4. 
  cout<<"New Sum of first 6: "<<getSum(bTree,4)<<endl;						// Get updated sum of [0..4] (first 5) indices.
  return 0;
}