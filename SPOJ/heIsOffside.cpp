/*

//*******************************************************OFFSIDE - He is offside!.********************************************************
https://www.spoj.com/problems/OFFSIDE/




Time Complexity:O(n).                                                       // We can get the first 2 defenders in an iteration.                                                                                                                                                                                           
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    // We can get the first 2 defenders in an iteration.                                                  
// Space Complexity:O(1).                                                   
// This is Sorting based solution. Sort the given psns of attackers and defenders. If the first attacker's psn is less than second 
// defender, then print "Y", else print "N".







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


    while(true){
        int at,def;
        cin>>at>>def;
        if(at==0 && def==0) break;
        vector<int>attack(at),defend(def);
        for(int i=0;i<at;i++) cin>>attack[i];
        for(int i=0;i<def;i++) cin>>defend[i];
        sort(attack.begin(), attack.end());
        sort(defend.begin(), defend.end());
        if(attack[0]<defend[1]){
            cout<<"Y"<<endl;
        }else{
            // if(attack[0]<defend[1]) cout<<"Y"<<endl;
            cout<<"N"<<endl;
        }
    }
    return 0;
}