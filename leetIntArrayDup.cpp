#include<cstdlib>
#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice 
in the array, and it should return false if every element is distinct.

** This code make use of maps. When it finds that an element it present twice in the array, it returns "1" from the function. Else "0".
*/

int maxProfit(vector<int> v){
  unordered_map<int, int> m;
  for(int i=0;i<v.size();i++){
    if(m.find(v[i])== m.end())// Creates a key on the element in the array, when no such key exists prior.
      m[v[i]]=1;
    else// When a key had already existed, it returns "1", indicating the presence of a duplicate.
    return 1;
  }
  return 0;
}


int main(){
    cout<<"Hi"<<endl;
    int arr[]={1, 7, 2, 3, 6, 17, 8, 9};// These are stock values for a certain days.
    vector<int> v;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
      v.push_back(arr[i]);
    int dup=maxProfit(v);
    if(dup==1)
      cout<<"There are duplicates in the array."<<endl;
    else
      cout<<"No duplicates in the array."<<endl;
    return 0;
}