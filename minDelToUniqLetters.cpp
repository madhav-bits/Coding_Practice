/*
*
//*******************************************Min Deletions to Make Frequency of Each Letter Unique.************************************

url: https://leetcode.com/discuss/interview-question/398035


Given a string s consisting of n lowercase letters, you have to delete the minimum number of characters from s so that every letter 
in s appears a unique number of times. We only care about the occurrences of letters that appear at least once in result.

Example 1:

Input: "eeeeffff"
Output: 1
Explanation:
We can delete one occurence of 'e' or one occurence of 'f'. Then one letter will occur four times and the other three times.
Example 2:

Input: "aabbffddeaee"
Output: 6
Explanation:
For example, we can delete all occurences of 'e' and 'f' and one occurence of 'd' to obtain the word "aabbda".
Note that both 'e' and 'f' will occur zero times in the new word, but that's fine, since we only care about the letter that appear 
at least once.
Example 3:

Input: "llll"
Output: 0
Explanation:
There is no need to delete any character.
Example 4:

Input: "example"
Output: 4




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

"geeksforgeeks"

"eeeefffff"


"aabbffddeaee"

"llll"


"example"


// Time Complexity: O(n).  
// Space Complexity: O(sqrt(n)).												// This is max. #uniq. #occurances possible.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(sqrt(n)).												// This is max. #uniq. #occurances possible.
// This algorithm is Map based agorithm. In the first iteration, we get the occurances of each char. We push this occurances into
// a map, here, since we have to delete chars to get uniq. #occurances, we iter. map in the reverse direction. At each step, we gather 
// extra chars(it->second-1). We also calculate the gap b/w curr. value and it's immediate higher value and try to push the extra
// chars gathered till then into this gap. Push all the extra chars into the same #occurances as curr. occurance. We also push '0'
// into the map, as we have to push the remaining extra chars into gap b/w least #occurances and '0' and completely deleting rest of 
// the chars which didn't fit into gap. 









#include <iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int getMinDeletions(string s){
  int res=0;
  vector<int>occur(26,0);													// Tracks the #occurances of each type of char.
  for(auto ch: s) occur[ch-'a']++;											// Tracks the #occurances of each char.
  map<int,int>m;
  for(auto num:occur){
    if(num!=0) m[num]++;													// Tracks #uniq. occurances and their count.
  }
  m[0]=1;
  int prev=-1, extra=0;
  for(auto it=m.rbegin();it!=m.rend();it++){								// We iter. from largest to smallest occurance value.
    int old=(it!=m.rbegin())?std::prev(it)->first:it->first+1;				// Finding the closest key >=curr. key value.
    int spots= old-it->first-1;												// Calc. gap/spots b/w prev. and curr. key.
    int minm=min(extra, spots);												// Finding #extra chars could be fit into the spots present.
    res+=(minm*(minm+1))/2;													// Placing the chars in the gaps.
    extra-=minm;															// Removing the extra chars count.
    res+=(spots+1)*extra;													// Adding the rem. extra chars to curr. key level.
    // cout<<"minm: "<<minm<<" and spots: "<<spots<<" and addn: "<<(minm*(minm+1))/2<<" buff. inc: "<<(spots+1)*extra<<endl;
    extra+=it->second-1;													// Adding extra chars. from #occurances(key) level.
  }
  return res;																// Returning the minm. #deletions.
}



int main() {
  string s="example";
  int res=getMinDeletions(s);												// Calling the function.
  cout<<"Res; "<<res<<endl;	
  return 0;
}


