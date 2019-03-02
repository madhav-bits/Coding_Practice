/*

//******************************************************HANGOVER - Hangover.***********************************************************
https://www.spoj.com/problems/HANGOVER/



Time Complexity:O(2^n).                                                                                                                                                                                                                 
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(2^n).                                                                
// Space Complexity:O(1).                                                   
// This is Mathbased. Here, we keep on adding cards, until we get the total>target, we return the cards contributing to that 
// total. These numbers are in harmonic progression.







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

    
    double target;
    cin>>target;
    while(target>0){
        int cards=0;
        double base=2;
        double total=0;
        // cout<<"target: "<<target<<endl;
        while(total<target){
            cards++;
            total+=(1/base);
            base++;
        }
        cout<<cards<<" card(s)"<<endl;
        cin>>target;
    }
    

    return 0;
}