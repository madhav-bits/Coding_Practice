/*

//*******************************************************MARBLES - Marbles.***********************************************************
https://www.spoj.com/problems/MARBLES/




Time Complexity:O(k).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(k).                                                  
// Space Complexity:O(1).                                                   
// This is Beggars method in permutations and combinations. Where we use (k-1) sticks to distribute n resources into k parts and give 
// it to k beggars. Here, since we give atleast one coin to each beggar in (n+k-1)c(k-1), we remove (k) from the numerator making it
// (n-1)c(k-1).



// This link has explanation of Beggars method algorithm:
// https://www.quora.com/What-is-the-Beggars-Method-in-permutation-and-combinations










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



long long int binomial(long long int n, long long int k){
    long long int res=1;
    if(k>n-k) k=n-k;
    for(int i=1;i<=k;i++){
        res*=(n-k+i);
        res/=i;
    }
    return res;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    int tests;
    cin>>tests;
    long long int n,k;
    for(int a=0;a<tests;a++){
        cin>>n>>k;
        cout<<binomial(n-1,k-1)<<endl;
    }

    return 0;
}