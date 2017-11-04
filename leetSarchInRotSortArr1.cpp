/*
33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
//********************************************************THIS IS LEET ACCEPTED CODE.***********************************************

*/
class Solution {
public:
    
int findIndex(vector<int> v, int target, int begin, int end){
  int mid=(begin+end)/2;
  int a=-2;
  //cout<<"Target value is: "<<target<<endl;
  //cout<<"begin is: "<<begin<<" and end is: "<<end<< " mid is: "<<mid<< "mid value is: "<<v[mid]<<endl;
  if(v[mid]==target)
    return mid;
  if(begin<end){
      //cout<<"Inside if condition."<<endl;
    if((v[begin]<=target && target<=v[mid]) ||  (v[begin]<=target &&  v[begin]>v[mid]) || (target<v[mid] && v[begin]>v[mid]))
      a=findIndex(v,target,begin, mid-1);// This is just listing down all possible scnerios for the target to be in the left half-
    else// - of vector.
      a=findIndex(v,target,mid+1, end);
  }
  
  if(a==-2)
    return -1;
  else
    return a;
}    
         
int search(vector<int>& v, int target) {
    if(v.size()==0)
        return -1;
    int begin=0, end=v.size()-1;
    int result=findIndex(v,target,begin, end);
    //cout<<"result is: "<<result<<endl;
    return result;
    }
};