/*

//***************************************************ALWFACT - Allowed Factors.*******************************************************
https://www.spoj.com/problems/ALWFACT/




Time Complexity:O(m*n).                                                                                                                                                                                             
Space Complexity:O(m+n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(m+n).                                                   // m-#prime numbers, n-psn of result number in sequence.                                                   
// This is Dynamic Programming based solution. Here, we want the number, which when decomposed gives only the provided prime numbers,
// and it will be in nth psn if all numbers satisfying this condition are placed in sorted format. 

// We can solve this using map to keep track of nums, that had been already consumed in the process and priority queue to extract min.
// value of all probable nums in BFS fashion.


// Here, we maintained pointers over all prime numbers which are factors of probable result value. For extracting each next value,
// we iter. over all prime numbers and multiply them with results array's pointer value to get next number in this sequence with 
// curr. prime number as one of factors. We extract all pointers which gives next smallest number, we inc. pointer values in all of 
// them and assign the next smallest value to the final result array. When required psn number is also obtained, we stop the 
// process and return the required number. 












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







int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int nums, psn;
    cin>>nums>>psn;
    while(nums!=0 || psn!=0){
        vector<long long int>primes(nums,0);
        for(int i=0;i<nums;i++) cin>>primes[i];
        vector<long long int>results(psn+1,1);
        vector<int>indices(nums,0);
        int index=1;
        while(index<=psn){
            vector<int>chosen(1,0);
            for(int i=1;i<nums;i++){
                if((primes[i]*results[indices[i]])<(primes[chosen.back()]*results[indices[chosen.back()]])){
                    chosen=vector<int>(1,i);
                }
                else if((primes[i]*results[indices[i]])==(primes[chosen.back()]*results[indices[chosen.back()]])){
                    chosen.push_back(i);
                }
            }
            results[index]=primes[chosen.back()]*results[indices[chosen.back()]];
            // cout<<"val: "<<primes[chosen.back()]*results[indices[chosen.back()]]<<endl;
            for(int i=0;i<chosen.size();i++) indices[chosen[i]]++;
            // indices[chosen]++;
            index++;
        }
        cout<<results.back()<<endl;
        cin>>nums>>psn;
    }

    return 0;
}
