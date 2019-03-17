/*

//***************************************************MINSTOCK - Minimum Stocks.*******************************************************
https://www.spoj.com/problems/MINSTOCK/




Time Complexity:O(nlogn).                                                    // logn per query(Readjusting the Bin Heap Tree).                                                                                                                                                                                        
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                // logn per query(Readjusting the Bin Heap Tree).
// Space Complexity:O(n).                                                   
// This is Priority Queue based solution. Here, since we need to get minm. score we will push it into Priority Queue where the player's
// name would be second elem. of pair. While updating the score of a player, we push new pair with {new score, player name} into PQ.
// While popping minm. score, we pop out elements which are older versions of a player's score(Score won't be equal to curr. score of
// player/ player might not be popped out of scoreboard) and return the first valid pair.







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




struct comp{

    bool operator()(pair<long long int,string>&lt, pair<long long int,string>&rt){
        return lt.first>rt.first;
    }
};




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int instructions;
    cin>>instructions;
    priority_queue<pair<long long int,string>, vector<pair<long long int,string>>, comp>pq;
    unordered_map<string,int>score, link;
    int num=1, instr=0, val;
    string stock="";
    for(int a=1;a<=instructions;a++){
        cin>>instr;
        if(instr==1 || instr==2){
            cin>>stock>>val;
            score[stock]=val;
            pq.push({val, stock});
        }else{
            cin>>stock;
            while(!pq.empty() && (score.count(pq.top().second)==0 || score[pq.top().second]!=pq.top().first)) pq.pop(); // Removing invalid pairs.
            cout<<pq.top().second<<" "<<a<<endl;
            // score[pq.top().second]=-1;
            score.erase(pq.top().second);
            pq.pop();
        }
    }
    return 0;
}
