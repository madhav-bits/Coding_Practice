/*
//**********************************************************************************************************************************
//*****************************************************397. Integer Replacement*****************************************************
//**********************************************************************************************************************************



Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1



Test Cases: 






8

120

2131

7

2147483647






//**************************************************THIS IS LEET ACCEPTED CODE.************************************************
*/
//*********************************************************Solution 1.*********************************************************
// Time Complexity: (2^16).													// If every alternate bit is set.
// Space Complexity: O(1).
// This is a Dynamic Programming mode. This version using the recursion as lot of memeory is used and lot of memory accesses are done
// in case of large input values.








class Solution {
public:
    int subFn(int n){
        if(n==1) return 0;
        if(n==2) return 1;
        if(n>=INT_MAX) return 32;  // This is returned as INT_MAX is; 2^32.
        if(n%2==0)
            return 1+subFn(n/2);
        else
            return min(subFn(n+1)+1, 1+subFn(n-1));
    }
    int integerReplacement(int n) {
        if(n==1) return 0;
        if(n==2) return 1;
        int result= subFn(n);
        cout<<"The answer is: "<<result<<endl;
        return result;
        
    }
};





//*************************************************This sln is based on memoization process, won't be efficient in case of large input values.
//So, it throws memory error. So, recursion method is applied here in the final solution.

/*


class Solution {
public:
    int integerReplacement(int n) {
        int arr[n+2];
        if(n==1) return 0;
        if(n==2) return 1;
        arr[1]=0; arr[2]=1;
        for(int a=3;a<=n;a+=2){
            arr[a+1]=arr[(a+1)/2]+1;
            arr[a]=min(arr[a-1]+1, arr[a+1]+1);
        }
        //cout<<"The answer is: "<<arr[n]<<endl;
        //for(int i=1;i<=n;i++)
            //cout<<"i is: "<<i<<"array value is: "<<arr[i]<<endl;
        return arr[n];
    }
};

*/











//*********************************************************Solution 2.*********************************************************
//**************************************************THIS IS LEET ACCEPTED CODE.************************************************
// Time Complexity: O(1).
// Space Complexity: O(1).
// This solution is Bit Manipulation based. Here, since we need minm. steps, we divide by 2, whenever the num is div. by 2. Else,
// if the second LSB is 0/ num is 3 by then, we dec. the value by 1, if the second LSB is!=0, inc. the num by 1. Keep track of the 
// number of steps taken and return them. Here, in each step we are trying to decrease the number.







class Solution {
public:
    int integerReplacement(int m) {
        int res=0;
        long long int n=m;													// To avoid integer overflows.
        bool seq=false;
        while(n>1){
            // cout<<bitset<16>(n)<<endl;
            int digit=(n&1);												// Extracting the LSB.
            if(digit==0){													// If it is zero, remove it.
                n>>=1;
            }else{															// If it is one.
                if(n==3 || ((n&2)==0)) n-=1;								// If the second LSB is 0/ num is 3 dec. by 1.
                else n+=1;													// If the second LSB is not zero, inc. num by one.
            }
            res++;															// Inc. the number of steps taken.
            
        }
        return res;															// Return the number of steps taken.
    }
};


