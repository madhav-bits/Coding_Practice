/*
*
//***********************************************************779. K-th Symbol in Grammar.*******************************************

On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and 
each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
Note:

N will be an integer in the range [1, 30].
K will be an integer in the range [1, 2^(N-1)].


//These are the examples I had created, tweaked and worked on.
23, 45
3,2
9,29


// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//*********************************************THIS IS TRICKY AND OBSERVATION ORIENTED QUESTION.*****************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// This algorithm is highly observational. If the no. of flips is odd by the time no. of elem. is 2, then the odd indexed(1) will contain "1"
// and even index(0) will contain-"0", if the flips are even and reverse if flips are odd. This observation starting from second row. 



class Solution {
public:
    int kthGrammar(int N, int K) {
        long s = pow (2, N - 1), flips = 0;

        while (s > 2) {
            //cout<<"K is: "<<K<<" and s is: "<<s<<endl;
            if (K > s / 2) { K -= s / 2; flips++; }						//Counts the no. of flips to reach the target index.
            //cout<<"After change K is: "<<K<<" and s is: "<<s<<endl;
            s /= 2;
        }

        K--; // change 1 to 0, 2 to 1

        if (flips % 2 == 1) K = ((K + 1) % 2); // if flips is odd, switch 1 to 0, 0 to 1

        return K;
    }
};


//************************************************************Solution s:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).
// This algorithm is costliter Time Complexity wise. It throws Time Limit Exceeding Error. But logicwise correct entirely.


class Solution {
public:
    int kthGrammar(int N, int K) {
        string s,t;
        s="0";
        for(int i=1;i<N;i++){
            t="";
            for(int j=0;j<s.length();j++){			//Scanning the string till then, and inverting all the bits and appending it to final result.
                if(s.compare(j,1,"0")==0)
                    t+="01";
                else
                    t+="10";
            }
            //cout<<"string at end of line: "<<i+1<<" is: "<<t<<endl;
            s=t;
        }
        if(s.compare(K-1,1,"1")==0)					//Finding the value at that index and returning it.
            return 1;
        else
            return 0;
    }
};







