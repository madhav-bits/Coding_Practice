/*
//******************************************************162. Find Peak Element***********************************************
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
//**************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//********************************THIS CODE REQUIRES TOO MUCH THINKING.*******************************************************
*/
class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int a=0;
        int begin=0, end=v.size()-1, mid=0;
        while(begin<end){
            mid=(begin+end)/2;// if means peak of mid value can be itself or elem. in the left half, so as safe side we move to left half.
            if(v[mid]>v[mid+1])// we are chasing a peak, in the next iteration we might ecounter another peak, but the main issue-
                end=mid;// is to find one of the peaks. So, we are on track.
            else// This means peask to mid is in right half, so shifting to the right half.
                begin=mid+1;
        }
        cout<<"One of the peaks is: "<<v[begin]<<endl;
        return begin;// As loops passes by we boil down to two/ one element for coside. whatever might be res. left always hold 
        // the peak. as during exit, left, right get initiated but mid won't get initialized properly. So, return left.
    }
};