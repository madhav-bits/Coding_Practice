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

//*****************************************THIS IST LEET ACCEPTED CODE.*******************************************
*/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& v) {
        vector<int> prime(v.size(),0);//Stores the index value of ugly number corresponding to the prime number to be multiplied.
        int count=1;
        int ans=1;
        int ugly[n];
        ugly[0]=1;//First ugly number is 1.
        if(n==1)
            return 1;
        while(count<n){
            int minm=INT_MAX;
            for(int i=0;i<v.size();i++){
                if(v[i]*ugly[prime[i]]<minm ){
                    minm=v[i]*ugly[prime[i]];
                    //cout<<"min is: "<<minm<<endl;
                }
            }
            for(int i=0;i<v.size();i++){// This increments indexes of all prime num. which are factors of new ugly number.
                if(minm%v[i]==0)
                    prime[i]++;
            }
            count++;
            //cout<<"Update count is: "<<count<<" and min is: "<<minm<<endl;
            //prime[index]++;
            ugly[count-1]=minm;
            ans=minm;
            //for(int i=0;i<v.size();i++)
              //  cout<<prime[i]<<endl;
        }
        //for(int i=0;i<n;i++)
          //  cout<<ugly[i]<<endl;
        cout<<endl<<endl;
        
        cout<<"answer is: "<<ans<<endl;
        return ans;
    }
};