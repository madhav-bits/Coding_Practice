/*

//***************************************************GSS1 - Can you answer these queries I.**********************************************
https://www.spoj.com/problems/GSS1/




Time Complexity:O(n).                                                       
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    
// Space Complexity:O(n).
// This is Segment Tree based problem. Where in each node we store prefix, suffix, overall  conse. max. vals. While buliding the
// tree we merge the results at the parent node. While querying if the curr. inverval completely overlaps we merge the results from
// the children. Here, we split the calls to children based on query. At the end we get the result from the result from the call 
// given to root node.


// This solution is facing Time Limit Exceeding error. Which can be handled by using Segment Tree array. This solution is in below
// link:  https://w84iit.wordpress.com/2017/06/23/can-you-answer-these-queries-1-gss1spoj-solution/









#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>


using namespace std;



vector<int>v;

struct Node{
    int sum;
    int low=0;
    int high=0;

    int total=0;
    int maxm=0;
    int pref=0;      //INT_MIN
    int suff=0;

    Node* left;
    Node* right;

    Node(int x, int l,int h){
        sum=x; low=l;high=h;
        maxm=x; total=x;pref=x; suff=x;
        left=NULL; right=NULL;

    }

    Node(int v){
        // sum=0;
        maxm=INT_MIN; total=INT_MIN;pref=INT_MIN; suff=INT_MIN;
        left=NULL; right=NULL;
    }


    Node* merge(Node* left, Node* right){
            total=left->total+right->total;
            pref=max(left->pref, left->total+right->pref);
            suff=max(right->suff,right->total+left->suff);
            maxm=max(left->suff+right->pref,max(pref,max(suff,max(left->maxm,right->maxm))));
    }

};





Node* formSegTree(int low,int high){
    if(low>high) return new Node(-1);
    if(low==high) return new Node(v[low],low,high);
    Node* node=new Node(0,low,high);
    int mid=(low+high)/2;
    node->left=formSegTree(low,mid);
    node->right=formSegTree(mid+1,high);
    node->merge(node->left, node->right);
    // cout<<"low: "<<low<<" and high: "<<high<<" and values: "<<node->maxm<<endl;
    return node;
}


int getSum(Node* node, int l, int h){
    if(!node) return 0;
    // if(l<=node->low && node->high<=h) cout<<"compl. overlap and low: "<<node->low<<" and high: "<<node->high<<" and sum: "<<node->sum<<endl;
    if(l<=node->low && node->high<=h) return node->sum;
    int mid=(node->low+node->high)/2;
    int res=0;
    if(l<=mid) res+=getSum(node->left, l,h);
    if(h>=mid+1) res+=getSum(node->right,l,h);
    // cout<<"low: "<<node->low<<" and high: "<<node->high<<" and sum: "<<res<<endl;
    return res;   
}



int getMax(Node* node, int l, int h){
    if(!node) return 0;
    // if(l<=node->low && node->high<=h) cout<<"compl. overlap and low: "<<node->low<<" and high: "<<node->high<<" and sum: "<<node->sum<<endl;
    if(l<=node->low && node->high<=h) return node->sum;
    int mid=(node->low+node->high)/2;
    int lt=INT_MIN,rt=INT_MIN;
    if(l<=mid) lt=getSum(node->left, l,h);
    if(h>=mid+1) rt=getSum(node->right,l,h);
    return max(lt, rt);
    // cout<<"low: "<<node->low<<" and high: "<<node->high<<" and sum: "<<res<<endl;
    // return res;   
}



Node* getSeq(Node* node, int l, int h){
    Node* res= new Node(-1);
    if(node->low>node->high || h<node->low || node->high<l) return res;
    // cout<<"Inside fn. with low: "<<node->low<<" and high: "<<node->high<<endl;
    if(l<=node->low && node->high<=h) return node;
    int mid=(node->low+node->high)>>1;
    if(h<=mid) return getSeq(node->left, l,h);
    if(l>mid) return getSeq(node->right,l,h);
    // Node* lt=getSeq(node->left, l,h);
    // Node* rt=getSeq(node->right, l,h);
    
    res->merge(getSeq(node->left, l,h),getSeq(node->right, l,h));
    return res;
    // cout<<"low: "<<node->low<<" and high: "<<node->high<<" and sum: "<<res<<endl;
}



int main() {
    // your code goes here

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    
    int nums;
    cin>>nums;
    v=vector<int>(nums);
    for(int i=0;i<nums;i++) cin>>v[i];
    Node* root=formSegTree(0,nums-1);
    int queries;
    cin>>queries;
    // cout<<"queries: "<<queries<<endl;
    for(int i=0;i<queries;i++){
        int elem1,elem2;
        cin>>elem1>>elem2;
        // cout<<"e1: "<<elem1-1<<" e2: "<<elem2-1<<endl;
        Node* n=getSeq(root,elem1-1,elem2-1);
        cout<<n->maxm<<endl;
    }
    
    return 0;
}











//*****************************************************************Solution 2.*************************************************************
// Time Complexity:O(n).                                                    
// Space Complexity:O(n).



// This solution is using Segment Tree array from this link:
// https://w84iit.wordpress.com/2017/06/23/can-you-answer-these-queries-1-gss1spoj-solution/







#include <bits/stdc++.h>
using namespace std;
 
const int N=100005;
 
int arr[N];
 
struct segment{
    int _presum,_sufsum,_totalsum,_maxsum;
 
    void mergee(segment left,segment right)
    {
        _presum=max(left._presum,left._totalsum+right._presum);
        _sufsum=max(right._sufsum,right._totalsum+left._sufsum);
        _totalsum=left._totalsum+right._totalsum;
        _maxsum=max(_presum,max(_sufsum,max(left._maxsum,max(right._maxsum,left._sufsum+right._presum))));
    }
}seg[4*N];
 
void build(int low,int high,int node)
{
    if(low>high)
    return;
    if(low == high)
    {
        seg[node]._presum=seg[node]._sufsum=seg[node]._totalsum=seg[node]._maxsum=arr[low];
        return;
    }
    int mid=low+high>>1;
    build(low,mid,2*node+1);
    build(mid+1,high,2*node+2);
    seg[node].mergee(seg[2*node+1],seg[2*node+2]);
}
 
segment query(int low,int high,int lq,int hq,int node)
{
    segment ans;
    ans._presum=ans._sufsum=ans._totalsum=ans._maxsum=INT_MIN;
    if(low>high || low>hq || high<lq)
    return ans;
    if(lq<=low && high<=hq)
    return seg[node];
    int mid=low+high>>1;
    if(lq>mid)
    return query(mid+1,high,lq,hq,2*node+2);
    if(hq<=mid)
    return query(low,mid,lq,hq,2*node+1);
    ans.mergee(query(low,mid,lq,hq,2*node+1),query(mid+1,high,lq,hq,2*node+2));
    return ans;
}
 
int main() {
    int n;
    scanf("%d",&n);
    register int i;
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    build(0,n-1,0);
    int m;
    scanf("%d",&m);
    int x,y;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",query(0,n-1,x-1,y-1,0)._maxsum);
    }
    return 0;
}