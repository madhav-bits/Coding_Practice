/*

//*******************************************************QUEUEEZ - Easy Queue.***********************************************************
https://www.spoj.com/problems/QUEUEEZ/




Time Complexity:O(1).                                                       // Per each query.                                                                                                                                                                                      
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                    // Per each query. 
// Space Complexity:O(n).                                                   
// This is Queue based solution. This is straight forward queue implementation with push, pop, front fucntionalities to be called based on 
// instruction provided.







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
    scanf("%d", &tests);
    // cin>>tests;                                                          // Uncomment the lines with cin stream to work locally.
    queue<int>q;
    int instr, val;
    for(int a=0;a<tests;a++){
        // cin>>instr;
        scanf("%d", &instr);
        if(instr==1){
            // cin>>val;
            scanf("%d", &val);
            q.push(val);
        }else if(instr==2){
            if(!q.empty()) q.pop();
        }
        else{
            // if(q.empty()) cout<<"Empty!"<<endl;
            // else cout<<q.front()<<endl;
            if(q.empty()) printf("Empty!\n");
            else printf("%d\n", q.front());
        } 
    }

    return 0;
}
