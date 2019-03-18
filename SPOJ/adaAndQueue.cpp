/*

//***************************************************ADAQUEUE - Ada and Queue.*******************************************************
https://www.spoj.com/problems/ADAQUEUE/




Time Complexity:O(1).                                                       // Per Each query.                                                                                                                                                                                      
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                    // Per Each query.   
// Space Complexity:O(n).                                                   
// This is Deque based solution. Here, since we need to push, pop elem. from both sides of queue. We use Deque, since we have reverse instruc.
// where we work on the back of the queue if requested to work on front and viceversa. If #reverses are odd, we work on opposite drn, in case
// of even swaps, we work on same side as requested.







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
#include<deque>




using namespace std;






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int queries;
    cin>>queries;
    deque<int>q;
    bool flip=false;
    string instr="";
    int val;
    for(int a=0;a<queries;a++){
        cin>>instr;
        if(instr=="toFront"){
            cin>>val;
            if(flip) q.push_back(val);
            else q.push_front(val);
        }else if(instr=="push_back"){
            cin>>val;
            if(flip) q.push_front(val);
            else q.push_back(val);
        }else if(instr=="front"){
            if(q.empty()){
                cout<<"No job for Ada?"<<endl;
                continue;    
            } 
            if(flip){
                cout<<q.back()<<endl;
                q.pop_back();
            }else{
                cout<<q.front()<<endl;
                q.pop_front();
            }
        }else if(instr=="back"){
            if(q.empty()){
                cout<<"No job for Ada?"<<endl;
                continue;    
            } 
            if(flip){
                cout<<q.front()<<endl;
                q.pop_front();
            }else{
                cout<<q.back()<<endl;
                q.pop_back();
            }
        }else{
            flip=!flip;
        }
    }

    return 0;
}
