/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. 
For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given 
primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

//*****************************************THIS IS NOT LEET ACCEPTED CODE.*******************************************
//******************BUT WORKS FINE, IS A LINEAR TIME ALGORITHM. STILL NEED TO IMPROVE IT.****************************
*/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& v) {
        int count=0; int num=1;
        while(count<n){
            int factor=0;
            int temp=num;
            //cout<<"inside while loop: "<<temp<<endl;
            while(factor<v.size()){
                //cout<<"Inner while temp is: "<<temp<<"factor is: "<<v[factor]<<endl;
                if(temp%v[factor]==0)
                    temp=temp/v[factor];
                else
                    factor++;
                if(temp==1){
                    count++;
                    //cout<<"count is: "<<count<<" num is: "<<num<<endl;
                    break;
                }    
            }
            num++;
        }
        cout<<INT_MIN<<endl;
        cout<<"nth ugly number is: "<<num-1<<endl;
        return num-1;
    }
};