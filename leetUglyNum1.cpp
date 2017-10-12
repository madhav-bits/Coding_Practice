/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 
is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

//******************************************THIS IS LEET ACCEPTED CODE.*************************************************

*/
class Solution {
public:
    bool isUgly(int num) {
        if(num==0)
            return false;
        if(num==1)
            return true;
        vector<int> v;
        v.push_back(2);
        v.push_back(3);
        v.push_back(5);
        
        int count=0;
        int temp=num;
        while(temp!=1 && count<v.size()){
            while(temp% v[count]==0){// If the product of multiple multiplications of same number.
                temp=temp/v[count];
            }
            if(temp==1)
                break;
             count++;   
        }
        if(count==v.size())
            return false;
        else
            return true;
    }
};