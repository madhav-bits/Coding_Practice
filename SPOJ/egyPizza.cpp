/*

//*******************************************************EGYPIZZA - Pizza.***********************************************************
https://www.spoj.com/problems/EGYPIZZA/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Observation based. Here, we try to get minm. pizzas by matching appropriate pieces which would make up a complete pizza.
// 1/4s are matched with 3/4 extra pieces till then. 3/4ths are matched extra 1/4 pieces till then. 1/2s are matched with themselves, 
// so at the end of iter. we have 0/1 extra half pieces. Now, we consolidate all extra 3/4 into each full pizza for each 3/4th request.
// We match extra 1/2 if any, with 2 extra 1/4s each. Now, we consolidate 4 extra 1/4s into single pizza and inc. the final full 
// pizzas count and return the count.







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

    int users;
    cin>>users;
    int fourths=0, halves=0, threeFourths=0,full=0;
    string s="";
    for(int i=0;i<users;i++){
        cin>>s;
        if(s=="1/2"){
            if(halves>0){
                halves--;
                full++;
            }else halves++;
        }else if(s=="1/4"){
            if(threeFourths>0){
                threeFourths--;
                full++;
            }else fourths++;
        }else if(s=="3/4"){
            if(fourths>0){
                fourths--;
                full++;
            }else threeFourths++;
        }
    }
    // cout<<"fourths: "<<fourths<<" and 1/2: "<<halves<<" and threeFourths: "<<threeFourths<<" and full: "<<full<<endl;
    while(threeFourths>0){
        threeFourths--;
        full++;
    }

    if(halves>0){
        if(fourths>0) fourths-=2;
        full++;
    }

    while(fourths>0){
        full++;
        fourths-=4;
    }
    cout<<full+1<<endl;

    

    return 0;
}