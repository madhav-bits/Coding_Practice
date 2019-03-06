/*

//**************************************************GIRLSNBS - Girls and Boys.*******************************************************
https://www.spoj.com/problems/GIRLSNBS/




Time Complexity:O(1).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                  
// Space Complexity:O(1).                                                   
// This is Greedy/ Observation based solution. Here, we need to split larger group into smaller groups based on #people of other
// gender. If we have remainders in the groups after dividing, we add into few of the mini-groups formed.







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

    
    int m,n;
    cin>>m>>n;

    while(m!=-1 && n!=-1){
        int l=max(m,n);
        int s=min(m,n);
        // cout<<"l: "<<l<<" and s: "<<s<<endl;
        int div=l/(s+1);
        int rem=l%(s+1);
        if(rem!=0){
            cout<<div+1<<endl;
        }else cout<<div<<endl;
        cin>>m>>n;

    }

    return 0;
}