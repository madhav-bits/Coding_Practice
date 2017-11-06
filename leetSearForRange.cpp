/*
***********************************************34. Search for a Range***********************************************
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
//*************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& v, int target) {
        vector<int>::iterator start, close;
        if(v.size()==0)
            return{-1,-1};
        start=lower_bound(v.begin(),v.end(), target);
        close=upper_bound(v.begin(),v.end(), target);
        cout<<"the start is: "<<start-v.begin()<<endl;// Gives the psn of first int violating less than target condition.
        cout<<"the close is: "<<close-v.begin()-1<<endl;//// Gives the psn of first int violating less than target condition.
        //cout<<"end val is: "<<*start<<endl;// For the exception that val at v.end() is 0, this might clash with tartget-
        if(  start!=v.end() &&*start==target)//- 0 when not in array.
            return { start-v.begin(), close-v.begin()-1};// This covers all conditions when target is in vector.
        
        else
            return {-1,-1};
        //return u;
    }
};