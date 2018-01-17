/*
*
//**********************************************************66. Plus One.******************************************************

Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.


//Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//Time Complexity: O(n).
// Space Complexity: O(n).
//This is bit expensive Time and Space Complexity wise.

class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int sum=0, len=v.size(), len2=v.size(), carry=1;
        vector<int> u;
        for(int i=v.size()-1;i>=0;i--){
            u.push_back((v[i]+carry)%10);
            carry=(v[i]+carry)/10;
        }
        if(carry!=0)										//If non-zero carry exists, then it gets inserted into the vector.
            u.push_back(carry);
        
        //for(auto num:u)
        //    cout<<"The vector elements are: "<<num<<endl;
        
        len=u.size();
        //cout<<"The length of new vector  is: "<<u.size()<<endl;
        for(int i=0, j=len-1;i<j;i++, j--)					//Swap elem. as MSB is at index zero.
            swap(u[i], u[j]);
        
        return u;
    }
};





//************************************************************Solution 2:************************************************************
//Time Complexity: O(n).
// Space Complexity: O(1).
//This solution is optimal Time and Space Complexity wise.



class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int sum=0, len=v.size(), len2=v.size(), carry=1;
        vector<int> u;
        for(int i=v.size()-1;i>=0;i--){
            v[i]+=carry;
            if(v[i]>=10){
                carry=v[i]/10;//carry=1, can be used.
                v[i]%=10;//v[i]=0 can be used directly, but this equation I had come up with I just stick with them as Time complex. is the same.
            }
            else
                carry=0;
        }
        
        if(carry!=0)						//If non-zero carry exists, then it gets inserted in the beginning.
            v.insert(v.begin(), carry);
        
        //for(auto num:v)
        //    cout<<"The vector elements are: "<<num<<endl;
        return v;
    }
};
