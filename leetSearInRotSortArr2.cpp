/*

//*********************************************************81. Search in Rotated Sorted Array II.*****************************
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.

//**********************************************************THIS IS LEET ACCEPTED CODE.**************************************
//*************************THIS QUESTION HAD FRUSTATED ME NO QUESTION TILL NOW.**********************************************
*/
class Solution {
public:
    
    bool findIndex(vector<int> v, int target, int begin, int end){
      int mid=(begin+end)/2;
      bool a=false;
      //cout<<"Target value is: "<<target<<endl;
        while(begin<=end){
            mid=(begin+end)/2;
            //cout<<"begin is: "<<begin<<" and end is: "<<end<< " mid is: "<<mid<< "mid value is: "<<v[mid]<<endl;
          if(v[mid]==target)
            return true;
          if(v[mid]==v[begin])// Making sure that duplicates are avoided.
              begin++;
          else if((v[begin]<=target && target<v[mid] ) ||  (v[begin]<=target &&  v[begin]>v[mid] )|| (target<=v[mid] && v[begin]>v[mid]))
                end=mid-1;// This is just listing down all possible scnerios for the target to be in the left half-
            else//- of vector.
                begin=mid+1;
        }
      return a;
    }
    
    bool search(vector<int>& v, int target) {
        if(v.size()==0)
            return false;
        int begin=0, end=v.size()-1;
        bool result=findIndex(v,target,begin, end);
        //cout<<"result is: "<<result<<endl;
        return result;
    }
};