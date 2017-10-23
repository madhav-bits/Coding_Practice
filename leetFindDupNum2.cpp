/*
287. Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

//**********************************************************THIS IS LEET ACCEPTED CODE.***************************************
//*******************************************USING BINARY SEARCH METHOD/ TWO POINTERS METHOD.*********************************
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return -1;
        int mid, begin=1,end=nums.size();
        int count;
        while(begin<=end){
            count=0;
            mid=(begin+end)/2;
            for(const auto& num:nums){
                if(num<=mid)
                    count++;
            }
            cout<<" Count is: "<<count<<" and mid is: "<<mid<<endl;
            if(count<=mid)
                begin=mid+1;
            else
                end=mid-1;
        }
        cout<<"The repeating elem. is: "<<begin<<endl;
        return begin;
    }
};