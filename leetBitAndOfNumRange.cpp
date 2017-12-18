/*

//***************************************************201. Bitwise AND of Numbers Range.***********************************************

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.


//Time Complexity: O(logk) k=logN, N is the largest of the two numbers.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

// Solution 1: 
//We come from the MSB, move until the MSB in both the 


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        if(m>n)
            swap(n,m);
        int len=log2(n);
        while(len>=0){
            int a=m&1<<len, b=n&1<<len;
            if(a==b){											//If the MSB of the two numbers are equal then summing the val. to the total.
                if(a!=0)										//Even though MSB is same, if it is 1, then sums up to total.
                    count+=pow(2,len);
            }
            else												//Whenever there is a mismatch, we have to break away.
                return count;									//Returning the total, if there is mismatch of a bit.
            len-=1;
        }
        return count;											//Returns the total, if there is complete match of numbers.
    }
};