/*

//******************************************************BRCKTS - Brackets.**********************************************************
https://www.spoj.com/problems/BRCKTS/




Time Complexity:O(logn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn).                                                  
// Space Complexity:O(n).                                                   
// This is Segment Tree based solution. Here, we break the string into different segments, where we track the unbalanced open, 
// close in that segment. At the end of process, #open, close segments in the entire string has to be 0. While merging we focus
// on left half's close parens and right half's open parens and merge the excess open parens right open parens or excess close 
// parens to left close parens.






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





struct Node{
    int open, close;

    Node(){
        open=0;
        close=0;
    }

    Node(int x, int y){
        open=x;
        close=y;
    }
};



Node merge(Node lt, Node rt){
    if(lt.open>=rt.close){
        return Node(rt.open+lt.open-rt.close, lt.close);
    }else{
        return Node(rt.open, rt.close-lt.open+lt.close);
    }
}


void buildTree(string &s, int index, vector<Node>&segTree,int low, int high){
    if(low>high) return ;

    int mid=(low+high)/2;
    if(low==high){
        segTree[index]=Node(0,0);
        if(s[low]=='(') segTree[index].open=1;
        else segTree[index].close=1;
        return ;
    }

    buildTree(s, 2*index+1, segTree, low, mid);
    buildTree(s,2*index+2, segTree, mid+1, high);

    segTree[index]=merge(segTree[2*index+1], segTree[2*index+2]);
    return ;
}



void updateTree(string &s, int index, vector<Node>&segTree,int low, int high, int target){
    if(low>high) return ;

    int mid=(low+high)/2;
    if(low==high && low==target){
        if(s[low]=='(') s[low]=')';
        else s[low]='(';
        segTree[index].open=0;segTree[index].close=0;
        if(s[low]=='(') segTree[index].open=1;
        else segTree[index].close=1;
        return ;
    }
    if(target<=mid){
        updateTree(s, 2*index+1, segTree, low, mid, target);
    }else updateTree(s, 2*index+2, segTree, mid+1, high, target);

    segTree[index]=merge(segTree[2*index+1], segTree[2*index+2]);
    return ;
}



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int length, queries, index;
    
    
    string s="";
    for(int a=1;a<=10;a++){
        cin>>length;
        // cout<<"The len: "<<length<<endl;
        cin>>s;
        // cout<<"str: "<<s<<endl;
        vector<Node>segTree(4*s.length()+5);
        buildTree(s,0,segTree, 0, s.length()-1);

        cin>>queries;
        // cout<<"Test "<<a<<":"<<endl;
        printf("Test %d:\n", a);
        for(int i=0;i<queries;i++){
            cin>>index;
            // cout<<"target index: "<<index<<endl;
            if(index==0){
                // cout<<"open: "<<segTree[0].open<<" and close: "<<segTree[0].close<<endl;
                if(segTree[0].open==0 && segTree[0].close==0) printf("YES\n");
                else printf("NO\n");
            }else{
                updateTree(s,0,segTree,0,s.length()-1, index-1);
                // cout<<"After updating index: "<<index-1<<" str: "<<s<<endl;
            }
        }
    }


    return 0;
}
