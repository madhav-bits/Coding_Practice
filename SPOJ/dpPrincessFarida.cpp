/*

//*******************************************************FARIDA - Princess Farida.***************************************************
https://www.spoj.com/problems/FARIDA/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(1).                                                   
// This is Dynamic Programing based solution. Here, we iterate over values, at each step we take decision based on whether coins are
// collected are from prev. monster, which we ttrack in two variables, where taken indicates max. sum that can be extracted till prev.
// monster with coins being collected from it, missed indicates max. sum till that monster with it being skipped. We update taken, 
// missed for curr. index based on prev. values and curr. index value. At the end,we return the max. of taken, missed.





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

    int tests;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        int elem;
        cin>>elem;
        if(elem==0){
            cout<<"Case "<<a<<": "<<0<<endl;
            continue;
        }
        long long int taken, missed=0;
        cin>>taken;
        long long int val;
        for(int i=2;i<=elem;i++){
            long long int temp=missed;
            cin>>val;
            missed=max(missed, taken);
            taken=temp+val;
        }
        cout<<"Case "<<a<<": "<<max(taken, missed)<<endl;
    }
    

    return 0;
}