/*

//***************************************************TDKPRIME - Finding the Kth Prime.***************************************************
https://www.spoj.com/problems/FCTRL/




Time Complexity:O(nloglogsqrt(n)).                                                                                                                                                                                             
Space Complexity:O(m).                                                      // Max. query num. that can be asked.                  

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nloglogsqrt(n)).                                                  
// Space Complexity:O(m).                                                   // Max. query num. that can be asked.                                       
// This is Sieve of Erathosthense problem. Just fill out Sieve using normal proceudure. Later iterate over array and gathat prime
// numbers in an array. Now, we can return the queries in constant time directly from the array.






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



void fillSieve(vector<bool>&primes, vector<int>&pr){
    int len=primes.size();
    // pr.push_back(2);
    primes[0]=false; primes[1]=false;
    for(int i=4;i<=len;i+=2) primes[i]=false; 

    for(int i=3;i*i<=len;i+=2){
        if(primes[i]==false) continue;
        for(int j=i*i;j<=len;j+=i){
            primes[j]=false;
        }
    }
    return ;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    vector<bool>primes(86028123,true);
    vector<int>pr;
    fillSieve(primes, pr);
    for(int i=0;i<primes.size();i++){
        if(primes[i]) pr.push_back(i);
    }
    int queries;
    cin>>queries;
    for(int i=0;i<queries;i++){
        int index;
        cin>>index;
        // cout<<"index: "<<index<<endl;
        cout<<pr[index-1]<<endl;
    }
    return 0;
}