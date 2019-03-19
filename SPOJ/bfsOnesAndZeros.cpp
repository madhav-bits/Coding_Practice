/*

//***************************************************ONEZERO - Ones and zeros.*******************************************************
https://www.spoj.com/problems/ONEZERO/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is BFS based solution. Here, since we need smallest number which is divisible by given num. Here, instead of working on all
// nums. we only work on digits with 0/1s using BFS, we get smallest value with 0/1s and divisible by given num. Here, since
// the number can be very long we store it in the form of string in a map. While adding next 0/1 to curr. num, is same as adding
// 0/1 to remainder of curr. num/k, as dividing (curr.num*10+(0/1)) with k is concerned, we only push (curr. num*10)%rem. into queue.
// One more optimization is that, since we are working on rems we use rem as key and string obtained till then as value. We dont 
// rems which we have already visited, if it is already visited and curr. key might lead to divisible integer, then the smallest
// integer would be obtained from integer, where we had observed this rem. for first time. If we encounter '0' remainder for first 
// time, we return string till then.






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




string getNum(int num){
    queue<int>q;
    q.push(1);
    unordered_map<int,string>m;
    m[1]="1";
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        int fol, rem;
        fol=curr*10;
        rem=fol%num;
        if(m.count(rem)==0){
            m[rem]=m[curr]+"0";
            // cout<<"fol: "<<fol<<" and m[rem]: "<<m[rem]<<endl;
            if(rem==0) return m[rem];
            q.push(rem);
        }
        fol=curr*10+1;
        rem=fol%num;
        if(m.count(rem)==0){
            m[rem]=m[curr]+"1";
            // cout<<"fol: "<<fol<<" and m[rem]: "<<m[rem]<<endl;
            if(rem==0) return m[rem];
            q.push(rem);
        }
    }
    return "";
}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;
    int num;
    string res="";
    for(int a=0;a<tests;a++){
        cin>>num;
        if(num==1){                                                         // Base case.
            cout<<1<<endl;
            continue;
        }
        res=getNum(num);
        cout<<res<<endl;
    }

    return 0;
}
