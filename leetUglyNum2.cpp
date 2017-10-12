/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 
is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

//*******************************************THIS IS LEET ACCEPTED CODE.*********************************************
//*****This code is basically same as Super Ugly Numbers, except for the fact that , there are only prime numbers to be considered.********
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(2);
        v.push_back(3);
        v.push_back(5);
        vector<int> prime(v.size(),0);
        int count=1;
        int ans=1;
        int ugly[n];
        ugly[0]=1;
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