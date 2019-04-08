/*
*
//**********************************************************Min Swaps to sort an array.***************************************************

https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[4, 5, 2, 1, 5]

[5,1,2,4,3]

[1, 5, 4, 3, 2]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is BFS based. Here, the swaps to get numbers on to their original position would form independent cycles. To swap all 
// elem. in a cycle, we would need #elem. -1 swaps to sort them. We will add #swaps contributed by each cycle and add them to final count.

// Here, we are getting sorted values to their positions in the given array. In the process we will count the #swaps made.






#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>


using namespace std;


int swapSortArray(vector<int>&v){
  vector<pair<int,int>>link;
  for(int i=0;i<v.size();i++){
    // cout<<" val: "<<v[i]<<" and index: "<<i<<endl;
    link.push_back({v[i],i});
  }
  sort(link.begin(), link.end());											// Sort based on their true, where second value would be psn
																			// in given array.
  
  int count=0;
  for(int i=0;i<v.size();i++){
    // cout<<"i: "<<i<<" and val: "<<link[i].first<<" and index: "<<link[i].second<<endl;
    if(link[i].second==i) continue;											// If already swapped, skip it.
    
    while(link[i].second!=i){												// Sorting all elem. in a cycle.
      // cout<<"swapping with index: "<<link[i].second<<endl;
      count++;																// #Swaps made.
      swap(link[link[i].second], link[i]);
    }
  }
  return count;
}

int main() {
  
  vector<int>v({1, 5, 4, 3, 2});// 4, 5, 2, 1, 5
  int moves=swapSortArray(v);// 5,1,2,4,3
  cout<<"moves: "<<moves<<endl;
  return 0;

}