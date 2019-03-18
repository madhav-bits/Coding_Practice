/*

//*************************************************RMID2 - Running Median Again.*****************************************************
https://www.spoj.com/problems/RMID2/




Time Complexity:O(logn).                                                    // Per Each instruction/query.                                                                                                                                                
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn).                                                 // Per Each instruction/query.                                              
// Space Complexity:O(n).                                                   
// This is Priority Queue based solution. Here, we use priority queues to track bottom, top halves of given array. We make sure that in case
// of odd nums, median stays in bottom half priority queue handled by a Max. heap. Top Half is handled by min. heap. When a new element is
// added, if pq1 is empty if curr. num is <=pq1.top(), we add it to bottom half else we add it to top half. Now, we call balance function,
// which makes sure bottom pq must have (equal or 1 elem.) more than that of top half's pq.







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




void balancePq(priority_queue<int>&pq1, priority_queue<int,vector<int>, greater<int>>&pq2){
    if(pq1.size()>pq2.size()+1){                                            // If new elem. is added to bottom half.(Odd #elem converted to even #elem)
        pq2.push(pq1.top());
        pq1.pop();
    }
    if(pq2.size()>pq1.size()){                                              // If new elem. is added to top half.(Even #elem converted to Odd #elem)
        pq1.push(pq2.top());
        pq2.pop();
    }
}


void workOnSequence(ifstream &cin){
    priority_queue<int>pq1;
    priority_queue<int,vector<int>, greater<int>>pq2;
    int num;
    // cin>>num;                                                            // Uncomment lines with cin to work locally.
    scanf("%d", &num);
    while(num!=0){
        // cout<<"num: "<<num<<endl;
        if(num==-1){
            // cout<<pq1.top()<<endl;
            printf("%d\n", pq1.top());
            pq1.pop();
            balancePq(pq1, pq2);
        }else{
            if(pq1.empty() || num<=pq1.top()) pq1.push(num);
            else pq2.push(num);
            balancePq(pq1, pq2);
        }
        // cin>>num;
        scanf("%d", &num);
    }
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    // cin>>tests;                                                          // Uncomment lines with cin to work locally.
    scanf("%d", &tests);
    for(int a=0;a<tests;a++){
        workOnSequence(cin);
        // cout<<endl;
    }

    return 0;
}
