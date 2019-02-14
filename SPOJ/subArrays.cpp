/*

//*******************************************************ARRAYSUB - subarrays.***********************************************************
https://www.spoj.com/problems/ARRAYSUB/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(m).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(m).                                                   
// This is Priority Queue based solution. Here, we maintain a PQ of elements, as window slides on, if the top of PQ is with in the range 
// of window, then ignore it, if not pop the top elements until the top elem. is with in window range. Print these top values onto STDOUT
// for all the subarrays.







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

    bool operator()(pair<int,int>&lt, pair<int,int>&rt){
        return lt.first<rt.first;
    }
};

int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int len;
    cin>>len;

    vector<int>v(len,0);
    for(int i=0;i<len;i++) cin>>v[i];
    int width;
    cin>>width;
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
    for(int i=0;i<v.size();i++){
        pq.push({v[i],i});
        while(pq.top().second<=i-width) pq.pop();
        if(i>=width-1) cout<<pq.top().first<<" ";    
    }
    cout<<endl;




    

    return 0;
}























//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Segment Tree based solution. Here, we form the tree based on the array values which are already gathered. Later we iter. over
// subarrays and make requests for each of those subarrays from the Segment Tree. Whenever there is complete overlap, we return directly
// from the tree, if not we return max from the calls given to both child.













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





void formTree(vector<int>&segTree,vector<int>&v,int index, int low, int high){
    if(low>high) return ;
    if(low==high){ 
        segTree[index]=v[low];
        return ;
    }
    int mid=(low+high)/2;
    // cout<<" Forming low: "<<low<<" and high: "<<high<<endl;
    formTree(segTree,v,2*index+1,low, mid);
    formTree(segTree, v, 2*index+2, mid+1, high);
    segTree[index]=max(segTree[2*index+1], segTree[2*index+2]);
    return ;
}


int getMax(vector<int>&segTree,int index, int qStart, int qClose, int low, int high){
    // cout<<"low: "<<low<<" and high: "<<high<<endl;
    if(low>high || qStart>high || qClose<low) return INT_MIN;
    if(qStart<=low && high<=qClose) return segTree[index];
    int mid=(low+high)/2;
    return max(getMax(segTree, 2*index+1,qStart, qClose, low, mid), getMax(segTree, 2*index+2, qStart, qClose, mid+1, high));
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int len;
    cin>>len;

    vector<int>v(len,0);
    for(int i=0;i<len;i++) cin>>v[i];
    int width;
    cin>>width;
    vector<int>segTree(4*len+1,0);
    formTree(segTree,v ,0 , 0, len-1);

    for(int i=0;i<=len-width;i++){
        cout<<getMax(segTree,0, i,i+width-1,0, len-1)<<" ";
    }
    cout<<endl;



    

    return 0;
}