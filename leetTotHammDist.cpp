/*

//*********************************************************477. Total Hamming Distance.****************************************************

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.



//Time Complexity: O(nlogk).   k= log(LargestNum)+1;
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

// Solution 1: 

class Solution {
public:
    int totalHammingDistance(vector<int>& v) {
        int len= v.size();
        if(v.size()<2)
            return 0;
        int zeroCount=0;								// Says no. of numbers reduced to zeroes
        int zeros=0, ones=0, totalDist=0;				// Saves toatlHamDist of all numbers.
        while(zeroCount!=v.size()){						//When all the digits all reduced to zero, it comes out of loop.
            zeros=0; ones=0;zeroCount=0;
            for(int i=0;i<v.size();i++){				//LSB- Least Significant Bit.
                if(v[i]==0)								// Counts no. of digits reduced to zero in every scan of all digits.
                    zeroCount++;
                if(v[i]%2==0)							// Scans through all elem. saves no. of elem have their LSB as "0".
                    zeros++;
                else 									// Scans through all elem. saves no. of elem have their LSB as "1".
                    ones++;
                v[i]=v[i]>>1;
            }
            totalDist+=(zeros*ones);
        }
        return totalDist;								// Returning the totalHamDist of the array(vector).
    }
};