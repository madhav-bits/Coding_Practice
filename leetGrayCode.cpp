/*

//**********************************************************89. Gray Code********************************************************

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.



//Time Complexity: O(n).
// Space Complexity: O(n).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/

//This output follows a sequence of changes. For example the changes it follows for n=2: i.e: 0,1,3,2 are exactly reversed with a new integer-
//- of highest value(here 2^(3-1)) added to it's value.


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        int a=2, b=0;
        if(n==0)
            return v;
        while(n>0){//The output follows a sequence, the way it changes the digits for n=2->0,1,3,2, for n=3 reverses the order for n=3.
            int size=v.size();
            int num=pow(a,b);
            for(int i=size-1;i>=0;i--)
                v.push_back(v[i]+num);//num is the value because of bit at nth psn(value: 2^(n-1)).
            n--;// Decreasing the count.
            b++;// Raising the exponenet/index for the next iteration.
        }
        return v;
    }
};