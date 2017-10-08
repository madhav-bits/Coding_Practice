#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Input: numbers={1,4,7,9,11,14,17,21}, target=9
Output: index1=4, index2=6
// Leetcode accepted solution.
*/
//This solution uses the two pointer method, that was discussed at the google session.

vector<int> twoSum2(vector<int> v, int target){
  int size= v.size();
  vector<int> w;
  int a=0; int b=v.size()-1;
  while(a<b){
    if((v[a]+v[b])==target)
      break;
    if((v[a]+v[b])>target)
      b--;
    if((v[a]+v[b])<target)
      a++;
  }
  w.push_back(a+1);
  w.push_back(b+1);
  return w;
}


int main(){
    cout<<"Hi"<<endl;
    int arr[]={1,4,7,9,11,14,17,21};// These are stock values for a certain days.
    vector<int> v,w;
    int target=23;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
      v.push_back(arr[i]);
    w=twoSum2(v,target);
    cout<<"The starting position is: "<<w[0]<<endl;
    cout<<"The Ending position is: "<<w[1]<<endl;
    return 0;
}