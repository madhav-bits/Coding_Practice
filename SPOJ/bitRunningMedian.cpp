/*

//*****************************************************RMID - Running Median.*********************************************************
https://www.spoj.com/problems/RMID/




Time Complexity:O(logn).                                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
//***********************************THIS WOULD BE GOOD EXAMPLE OF USING BINARY INDEXED TREES(BIT)***********************************
// Time Complexity:O(logn).                                                                                                      
// Space Complexity:O(n).                                                   
// This is Binary Indexed Tree Solution. Here, we need to find mediam of the array. Which can be also be viewed as an index, where #elem. 
// prior and including that index would be total #elem/2. This is sort of prefix sum. While searching for median, We are looking for index,
// where #elem prior and including it would be #elem/2. For that we can use Segment Tree/Binary Tree since we know that #elem. in the vector
// would be maxm. of 10000. Here, we are using Binary Indexed Tree. Once, we find the index using Binary Search. We update that index is removed
// by updating it's value to (-1), as a result all the BIT indices covering that index, would not consider that index in their prefix(Making it 
// non-existent), so it won't be visible in the next searches(Since, we would be searching leftmost index where #elem. prior and including it
// would be total #elem/2).So, a valid index would be found each time. 

// While taking new values into vector, we update that index with (1), it updates all indices in BIT covering that index, thus making that index 
// valid.







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





int getSum(vector<int>&bit, int index){                                     // Gets prefix sum till provided index.
    int res=0;
    while(index>0){
        res+=bit[index];
        index-=(index&(-index));

    }
    return res;
}


void updateTree(vector<int>&bit, int index, int val){                       // Updates all indices that covers provided index.
    while(index<bit.size()){
        bit[index]+=val;
        index+=(index&(-index));
    }
    return ;
}


int searchMid(vector<int>&bit, int target){
    int low=1, high=100000;
    while(low<high){
        int mid=(low+high)/2;
        int ans=getSum(bit,mid);                                            // Get prefix sum(#valid elem. including curr. index) of curr. index.
        if(ans<target) low=mid+1;
        // else if(ans==target) low=mid;
        else high=mid;
    }
    return low;

}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    vector<int>v;
    vector<int>bit(100001,0);
    int nums=0, num, index=1;                                               // As, we need 1 indexed array for BIT.
    while(scanf("%d", &num)!=EOF){                                          // use cin>>num fot working locally.
        if(num==0){
            nums=0;
            v.clear();
            bit=vector<int>(100001,0);
            index=1;
            // cout<<endl;
            printf("\n");
        }else{
            if(num==-1){
                int mid;
                if(nums%2==1) mid=nums/2+1;
                else mid=nums/2;
                // cout<<"nums: "<<nums<<" and mid: "<<mid<<endl;
                int ind=searchMid(bit,mid);
                // cout<<"ind: "<<ind<<endl;
                printf("%d \n", v[ind-1]);
                updateTree(bit,ind,-1);
                nums--;
            }else{
                updateTree(bit,index,1);
                v.push_back(num);
                nums++;
                index++;
            }
        }
    }

    return 0;
}


