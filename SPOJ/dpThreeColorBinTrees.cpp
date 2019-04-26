/*

//*******************************************THREECOL - Three-coloring of binary trees.**********************************************
https://www.spoj.com/problems/THREECOL/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, we calculate minm., maxm. possible coloring for each subtrees for each color.
// If we are working at an node, to get maxm. child with green color, we assign curr. node with three colors and assign it's child
// some color accordingly. Then, take the best possible sum to get maxm. assigning of that color in subtree and store it in DP 
// array. Same is the case with minm. coloring also.


// dpMax[currNodeIndex][0] indicates maxm. possible nodes with Red color in curr. subtree.
// dpMax[currNodeIndex][1] indicates maxm. possible nodes with Green color in curr. subtree.
// dpMax[currNodeIndex][2] indicates maxm. possible nodes with Blue color in curr. subtree.
// Same applies for minm. possible coloring also.






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



void formTree(vector<vector<int>>&tree, string &s, int &index){
    // cout<<"inside fn. with index: "<<index<<endl;
    if(index>=(int)s.length()) return ;
    // if(tree[treeIndex]==false) return ;
    int curr=index;
    index++;
    // cout<<"node with index: "<<curr<<endl;
    if(s[curr]=='1'){
        tree[curr][0]=index;
        // cout<<"node; "<<curr<<" and left child: "<<index<<endl;
        formTree(tree, s, index);
    }
    if(s[curr]=='2'){
        tree[curr][0]=index;
        formTree(tree, s, index);
        tree[curr][1]=index;
        formTree(tree, s,index);
    }
    return ;
}




void paintTree(vector<vector<int>>&tree, int treeIndex, vector<vector<int>>&dpMin, vector<vector<int>>&dpMax){
    if(treeIndex>=tree.size()) return ;
    int curr=treeIndex;
    if(tree[curr][0]!=-1)
        paintTree(tree,tree[curr][0], dpMin, dpMax);
    if(tree[curr][1]!=-1)
        paintTree(tree, tree[curr][1], dpMin, dpMax);

    int lt=tree[curr][0], rt=tree[curr][1];
    for(int i=0;i<=2;i++){
        int leftOther1=(lt!=-1)?dpMin[lt][(i+1)%3]:0, leftOther2=(lt!=-1)?dpMin[lt][(i+2)%3]:0;
        int rightOther1=(rt!=-1)?dpMin[rt][(i+1)%3]:0, rightOther2=(rt!=-1)?dpMin[rt][(i+2)%3]:0;
        dpMin[curr][i]=min(leftOther1+rightOther2, leftOther2+rightOther1);

        leftOther1=(lt!=-1)?dpMax[lt][(i+1)%3]:0; leftOther2=(lt!=-1)?dpMax[lt][(i+2)%3]:0;
        rightOther1=(rt!=-1)?dpMax[rt][(i+1)%3]:0; rightOther2=(rt!=-1)?dpMax[rt][(i+2)%3]:0;
        dpMax[curr][i]=max(leftOther1+rightOther2, leftOther2+rightOther1);
        if(i==1) dpMin[curr][i]++;
        if(i==1) dpMax[curr][i]++;
    }

}


void iterateTree(vector<bool>&tree, int treeIndex, vector<vector<int>>&dpMin, vector<vector<int>>&dpMax){// This fn. doesn't work.
    if(treeIndex>=tree.size()) return ;
    if(tree[treeIndex]==false) return ;

    iterateTree(tree,2*treeIndex+1, dpMin, dpMax);
    iterateTree(tree, 2*treeIndex+2, dpMin, dpMax);
    cout<<"treeIndex: "<<treeIndex<<endl;
    for(int i=0;i<2;i++){
        cout<<"max: "<<dpMax[treeIndex][i]<<" and min: "<<dpMin[treeIndex][i]<<endl;
    }
    
}






int node=0;                                                                 // Keeps track of each node's number in the tree formed.


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nodes;
    string s="";
    cin>>tests;
    for(int a=1;a<=tests;a++){
        vector<vector<int>>tree(10010, vector<int>(2,-1));
        vector<vector<int>>dpMin(10010,vector<int>(3,0)), dpMax(10010,vector<int>(3,0));
        cin>>s;
        // cout<<"string s: "<<s<<endl;
        int index=0;
        formTree(tree, s,index);
        // int treeIndex=0;
        paintTree(tree,0,dpMin, dpMax);
        // iterateTree(tree,0,dpMin, dpMax);
        cout<<max(dpMax[0][0], max(dpMax[0][1],dpMax[0][1]))<<" "<<min(dpMin[0][0], min(dpMin[0][1],dpMin[0][1]))<<endl;
    }

    return 0;
}
