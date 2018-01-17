/*
*
//**********************************************************27. Remove Element.******************************************************

Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.


//These are the examples I had created and worked on.
1) [4,6,2,2,3,5,3,6,3,8,4,2,8]
3

2) [3,2,2,3]
3


//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//Time Complexity: O(n^2).
// Space Complexity: O(n^2).


class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int count=0, len=v.size();
        for(int i=0;i<len;i++){
            //cout<<"Inside for loop with i: "<<i<<" and value is: "<<v[i]<<endl;
            if(v[i]==val){				//Once a target val. is found, moving the entire array and replacing the target val. by it's adj. value.
                count++;				//Moving the entire array to left one more step everytime target vlaue is found.
                for(int j=i;j<=len-1-count;j++)
                    v[j]=v[j+1];
                v[len-count]=val+1;
                i--;
            }
            
        }
        int result=len-count;
        //cout<<"The result is: "<<result<<endl;
        return result;
    }
};



//************************************************************Solution 2:************************************************************
//This algorithm is inspired by some other person's algorithm.
//Time Complexity: O(n).
// Space Complexity: O(n).
//This code optimizes in the case  the req. val is observed in the array. But, Still stick to the code which I formulated, but this one is
// a new clever method.



class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int count=0, len=v.size();
        for(int i=0;i<len;i++){
            //cout<<"Inside for loop with i: "<<i<<" and value is: "<<v[i]<<endl;
            if(v[i]==val)
                count++;
            else									//Pushing elem. != target value are pushed index wise no. of wise target values is found,-
				v[i-count]=v[i];					//- thus replacing the target value and avoiding iterating through the array unneccesarily.
            
        }
        int result=len-count;
        //cout<<"The result is: "<<result<<endl;
        return result;
    }
};