/*
*
//**********************************************************699. Falling Squares.***************************************************

On an infinite number line (x-axis), we drop given squares in the order they are given.

The i-th square dropped (positions[i] = (left, side_length)) is a square with the left-most point being positions[i][0] and sidelength 
positions[i][1].

The square is dropped with the bottom edge parallel to the number line, and from a higher height than all currently landed squares. We wait 
for each square to stick before dropping the next.

The squares are infinitely sticky on their bottom edge, and will remain fixed to any positive length surface they touch (either the number line 
or another square). Squares dropped adjacent to each other will not stick together prematurely.


Return a list ans of heights. Each height ans[i] represents the current highest height of any square we have dropped, after dropping squares 
represented by positions[0], positions[1], ..., positions[i].

Example 1:
Input: [[1, 2], [2, 3], [6, 1]]
Output: [2, 5, 5]
Explanation:

After the first drop of positions[0] = [1, 2]:
_aa
_aa
-------
The maximum height of any square is 2.


After the second drop of positions[1] = [2, 3]:
__aaa
__aaa
__aaa
_aa__
_aa__
--------------
The maximum height of any square is 5.  
The larger square stays on top of the smaller square despite where its center
of gravity is, because squares are infinitely sticky on their bottom edge.


After the third drop of positions[1] = [6, 1]:
__aaa
__aaa
__aaa
_aa
_aa___a
--------------
The maximum height of any square is still 5.

Thus, we return an answer of [2, 5, 5].


Example 2:
Input: [[100, 100], [200, 100]]
Output: [100, 100]
Explanation: Adjacent squares don't get stuck prematurely - only their bottom edge can stick to surfaces.
Note:

1 <= positions.length <= 1000.
1 <= positions[i][0] <= 10^8.
1 <= positions[i][1] <= 10^6.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2],[2,3],[6,1]]


[[2,1],[2,9],[1,8]]






// Time Complexity: O(nlogn).  												-(logn) for each query.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												-(logn) for each query.
// Space Complexity: O(n).	
// This algorithm is Segment Tree based with Coordinate Compression. Here, as the range of intervals is quite large, We use coordinate compression.
// We form a segment tree where the interval edges are it's elements. Each node has max. value in the given range, it stores two edge values, point
// -ers to left, right children. First, we init. an entire tree with zero as max. height values with proper edge values. While querying, for 
// each query, we extract the max. height from all intervals which are completely overlapped by the curr. query interval. We return that value, and
// update the Segment tree with updated greatest height in the query interval. In the update function, we try to update the max. height in 
// all intervals, which overlaps with the current interval. We recursively travel in the child if there are overlaps. 
// Thus, for a query we reach 4 or 2 nodes at each level of tree. Thus, O(logn) for each query.






class Solution {
public:
    
    struct Node{															// Tree Node structure.
        int val;															// Max. height in the interval.
        Node* left;
        Node* right;
        int lt;																// Min. val of interval.
        int rt;																// Max. val of interval.
        Node(int x, int y, int z): val(x),left(NULL), right(NULL), lt(y), rt(z) {}
    };
    
    int initTree(Node* node, vector<int>&v, int low, int high){				// Initializes tree with zeros at every node.
        if(low>high) return 0;
        if(low==high){														// Leaf node.
            node->val=0;
            return node->val;
        }
        node->left=NULL;
        node->right=NULL;
        //int minm=INT_MAX;													
        if(low<=(low+high)/2){												// If left child exists.
            node->left=new Node(0, v[low], v[(low+high)/2]);				// Creating left child.
            initTree(node->left, v,low,(low+high)/2);
        } 
        if((low+high+2)/2<=high){											// If right child exists(Interval exists).
            node->right=new Node(0, v[(low+high+2)/2], v[high]);
            initTree(node->right, v,(low+high+2)/2,high);
        } 
        node->val=0;														// Init. curr. node to 0.
        return node->val;													// Returning the init. value(Not neccessary infact).
    }
    
    int getMax(Node* node, int low, int high){								// Get Max. from overlapped intervals.
        if(low>high) return -1;												// Interval doesn't exist.
        // cout<<"lt: "<<node->lt<<" and rt: "<<node->rt<<endl;
        if(node->lt>=low && node->rt<=high) return node->val;				// Complete overlap.
        int maxm=INT_MIN;													// Tracks maxm. from both child.
        if(node->left && max(node->left->lt,low)<=min(node->left->rt,high))	// If left child exists and call recur. to extract max. from it.
            maxm=max(maxm, getMax(node->left, low, high));
        
        if(node->right && max(node->right->lt,low)<=min(node->right->rt,high))// If right child exists and there is overlap b/w query and itnerval.
            maxm=max(maxm, getMax(node->right, low, high));
        
        return maxm;														// Return maxm from both child.
    }
                 
    void update(Node* node, int low, int high, int newVal){					// Update max. height in overlapping intervals. 
        if(low>high) return;
        if(max(node->lt,low)<=min(node->rt,high)) node->val=max(node->val, newVal);// If there is overlap b/w query and curr. Node's interval.
        
        if(node->left && max(node->left->lt,low)<=min(node->left->rt,high))	// If left child exists and there is a overlap.
            update(node->left, low, high, newVal);
        
        if(node->right && max(node->right->lt,low)<=min(node->right->rt,high))// If right child exists and there is a overlap.
            update(node->right, low, high, newVal);
        
    }
                 
    void printVal(Node* node){												// For debugging purposes, prints val. in each node.
        if(!node) return ;
        cout<<"lt: "<<node->lt<<" and rt: "<<node->rt<<" and val: "<<node->val<<endl;
        printVal(node->left);
        printVal(node->right);
    }
    
    vector<int> fallingSquares(vector<pair<int, int>>& v) {			
        vector<int>edges;
        set<int>s;
        for(auto p:v){
            s.insert(p.first);
            s.insert(p.first+p.second-1);
        }
        for(auto num:s) edges.push_back(num);								// Formed an array with only edges in it.
        Node* root=new Node(0, edges[0], edges.back());						// Created a root node for the entire range of intervals.
        initTree(root,edges,0,edges.size()-1);								// Initializes tree.
        // printVal(root);
        vector<int>res;														// Final result vector.
        int maxm=-1;														// Tracks max. height obtained.
        for(int i=0;i<v.size();i++){										// Iter. through queries.
            int l=v[i].first;												// Extracting left, right side of intervals.
            int r=v[i].second+v[i].first-1;
            // cout<<"current l: "<<l<<" and current r: "<<r<<endl;
            int ans=getMax(root,l,r);										// Extract max. value from overlapping intervals.
            // cout<<"ans: "<<ans<<endl;
            update(root, l,r, ans+v[i].second);								// Update all overlapping intervals.
            // cout<<"After updating."<<endl;
            // printVal(root);
            maxm=max(maxm, ans+v[i].second);								// Trying to update the maxm. var.
            res.push_back(maxm);											// Pushing the maxm. till now to final result vector.
        }
        return res;															// Returning list containing max. height at each stage of querying.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												-(logn) for each query.
// Space Complexity: O(n).	
// This algorithm is Segment Tree based with COORDINATE COMPRESSION and LAZY PROPAGATION. The Lazy propagation, in case of overlaps, if the curr. 
// node's interval is completely overlapped by query interval, the newheight is stored in lazy vector, when there is a query made overlapping 
// this interval, then the value in lazy vector for this node is update to this node in Tree and the updated value is propagated to it's children. 
// Thus, unnecessary updates are avoided.
// This algo. is same as the above one, but it's implemented using array unlike a Tree as in previous one.  Here, the Tree structure is 
// maintained through indices 'i' index has '2*i', '2*i+1' as children. First init. all of them to zeros. We extract max. value from overlapping
// intervals, at each step first updating the intervals if there is a update stored in lazy array for that node. While updating if there is
// complete intervals, we store that update value in lazy array and return from node, if there is partial overlap, we update that node's value
// and recur. iterate it's children.


// This link has even better explanation of Lazy propagation.
// https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/


// The lazy propagation code is inspired from here:
// https://leetcode.com/problems/falling-squares/discuss/112678/Treemap-solution-and-Segment-tree-(Java)-solution-with-lazy-propagation-and-coordinates-compression








class Solution {
public:
    
    int getMax(vector<int>&tree, vector<int>&lazy, vector<int>&edges, int index, int low, int high, int start, int close){
        if(low>high) return 0;
        // cout<<"low: "<<low<< " and high: "<<high<<" and val: "<<tree[index]<<endl;
        if(lazy[index]!=0){													// If there is an update awaiting.
            int change=lazy[index];
            lazy[index]=0;
            tree[index]=max(tree[index], change);							// Update the node value.
            if(low!=high){													//  Update the children's lazy indices.
                lazy[2*index]=max(lazy[2*index], change);
                lazy[2*index+1]=max(lazy[2*index+1], change);
            }
        }
        // if(max(edges[low], start)<=min(edges[high], close)) return tree[index];
        if(edges[low]>=start && edges[high]<=close) return tree[index];		// If there is complete overlap return max. from it.
        int res=0;
        int mid=(low+high)/2;
        if(low<=mid && max(edges[low], start)<=min(edges[mid], close)) 		// If left child exist and there is overlap, extract max. from it.
            res=max(res, getMax(tree,lazy, edges, 2*index, low, mid, start, close));
			
        if(mid+1<=high && max(edges[mid+1], start)<=min(edges[high], close))// If right child exists and there is overlap.
            res=max(res, getMax(tree, lazy, edges, 2*index+1, mid+1, high, start, close));
        return res;															// Returning the max. of vals. from both child.
    }
    
    
    void update(vector<int>&tree, vector<int>&lazy, vector<int>&edges, int index, int low, int high, int start, int close, int newVal){
        if(low>high) return ;
        // cout<<"Update low: "<<low<< " and high: "<<high<<" and val: "<<tree[index]<<endl;
        if(edges[low]>=start && edges[high]<=close){						// If there is complete overlap, just update the lazy index and return.
            lazy[index]=newVal;
            return ;
        }
        if(max(edges[low],start)<=min(edges[high], close)){					// If there is partial overlap, update curr. node's val.
            tree[index]=max(tree[index], newVal);
        }
        if(low==high) return ;
        int mid=(low+high)/2;
        if(low<=mid && max(edges[low], start)<=min(edges[mid], close)) 		// Left child exists and there is overlap, visit and try to update val.
            update(tree, lazy, edges, 2*index, low, mid, start, close, newVal);
        if(mid+1<=high && max(edges[mid+1], start)<=min(edges[high], close))// If right child exists and there is overlap, visit and try to update val.
            update(tree, lazy, edges, 2*index+1, mid+1, high, start, close, newVal);
        
    }
    
    
    vector<int> fallingSquares(vector<pair<int, int>>& v) {
        vector<int>edges;
        set<int>s;
        for(auto p:v){
            s.insert(p.first);
            s.insert(p.first+p.second-1);
        }
        for(auto num:s) edges.push_back(num);
        vector<int>res;
        int maxm=0;
        int num=ceil(log2(edges.size()))+1;
        int len=(1<<num);
        // cout<<"The len: "<<len<<endl;
        vector<int>tree(len,0);												// Init. Segment Tree.
        vector<int>lazy(len,0);												// Init. Lazy Tree.
        for(int i=0;i<v.size();i++){
            // cout<<"index: "<<i<<endl;
            int start=v[i].first;
            int close=start+v[i].second-1;
            int ans=getMax(tree,lazy,edges, 1, 0, edges.size()-1, start, close);// Extract max. height from overlapping intervals.
            update(tree,lazy,edges,1, 0,edges.size()-1, start, close, ans+v[i].second);// Update max. height in overlapping intervals.
            // cout<<"The max; "<<ans<<endl;
            maxm=max(maxm, ans+v[i].second);								// Track max. height reached till now.
            res.push_back(maxm);											// Push max. height into final result vector.
        }
        return res;															// Returning the list of max. heights reachable after every query.
    }
};





//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is iteration based algorithm. Here, for every query, we iterate over all intervals placed in the game, of the overlapping
// intervals we return the maxm. height. After extracting max. height, we insert the curr. interval into the list with max. height+it's height
// as it's height. So, in the following queries, the new interval would overwrite the lower heights caused by earlier intervals. Thus, leading to
// consistent max. height values.







class Solution {
public:
    struct Interval{														// Interval data structure.	
        int start;															// Start of the interval.
        int close;															// Close of the interval.
        int val;															// Max height in this interval.
        Interval(int x,int y,int hei): start(x),close(y),val(hei){};
    };
    
    int getHeight(vector<Interval>&v,int lt,int rt,Interval curr){			// Extract max. height from overlapping intervals.
        int maxm=0;
        // cout<<"vector size: "<<v.size()<<endl;
        for(int i=0;i<v.size();i++){										// Iterate over all intervals used till now.
            if(v[i].start>curr.close) continue;								// Non overlapping intervals.
            if(v[i].close<curr.start) continue;								// Non overlapping intervals.
            maxm=max(maxm,v[i].val);										// Try to update max. var on using vals from overlapping intervals.
        }
        curr.val+=maxm;														// Update the max. height reachable from this interval.
        // cout<<"Maxm: "<<curr.val<<endl;
        v.push_back(curr);													// Push this interval into vector.
        return curr.val;													// Return the max. height reachable from this interval.
    }
    
    vector<int> fallingSquares(vector<pair<int, int>>& v) {
        vector<int>res;
        vector<Interval>u;													// Stores all interavals used.
        int maxHeight=0;													// Tracks max. height reachable at every stage of querying.
        for(int i=0;i<v.size();i++){										// Iter. over all queries.
            int height=0;
            Interval*curr= new Interval(v[i].first,v[i].first+v[i].second-1,v[i].second);// Create interval object for curr. range of interval.
            maxHeight=max(maxHeight,getHeight(u,v[i].first,v[i].first+v[i].second-1,*curr));// Tracks Max. height reachble till now.
            res.push_back(maxHeight);										// Pushing max. height into vector.
        }
        return res;															// Returning the list of max. heights reachable after every query.
    }
};
