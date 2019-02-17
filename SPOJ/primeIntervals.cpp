/*

//*******************************************************PRINT - Prime Intervals.***********************************************************
https://www.spoj.com/problems/PRINT/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n).                                                   
// This is Sieve based solution. Here, we first form a sieve of primes till 1000001, which would help us determining prime numbers till
// 10^12, which is till INT_MAX. Later for every given range of intervals we will do a SEGMENTED SIEVE APPROACH. Here, we take these 
// primes values and mark those numbers between L and R which are multiples of Primes in the array. Later, we will iterate over the array
// and get all the prime numbers in the range(L,R).


// This video link has detailed explanation of the SEGMENTED SIEVE algorithm:
// https://www.youtube.com/watch?v=fByR5N-TseY&t=650s







#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>




using namespace std;



void getSieve(vector<bool>&v, vector<long long int>& primes){
    for(int i=4;i<v.size();i+=2) v[i]=false;
    for(int i=3;i*i<v.size();i+=2){
        if(v[i]==true){
            for(int j=i*i;j<v.size();j+=i){
                v[j]=false;
            }
        }
    }
    for(int i=2;i<v.size();i++){
        if(v[i]) primes.push_back(i);
    }
    return ;
}





void fillSegmentedSieve(vector<bool>&v,vector<long long int>&primes, long long int low){
    long long int high=low+v.size()-1;
    // cout<<"inside fn. with low: "<<low<<" and high: "<<high<<endl;
    for(int i=0;i<primes.size() && primes[i]*primes[i]<=high;i++){
        long long int num=primes[i];
        long long int base=(low/num)*num;
        if(base<low) base+=num;
        // cout<<"num: "<<num<<endl;
        base=max(base, num*(long long int)num);
        for(long long j=base;j<=high;j+=num){
            // cout<<"j: "<<j<<endl;
            v[j-low]=false;
        }
        // if(base==num) v[base-low]=true;

    }

    for(int i=0;i<v.size();i++){
        if(v[i]) printf("%lld \n", i+low);
    }
    return ;
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;

    vector<bool>v(1000001, true);
    vector<long long int>primes;
    getSieve(v, primes);
    for(int a=0;a<tests;a++){
        long long int low, high;
        cin>>low>>high;
        // cout<<"low: "<<low<<" and high: "<<high<<endl;
        vector<bool>dp(high-low+1,true);
        fillSegmentedSieve(dp, primes, low);
    }
    

    return 0;
}