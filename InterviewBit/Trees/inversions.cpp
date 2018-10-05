/*
*
//****************************************************************INVERSIONS.*******************************************************


https://www.interviewbit.com/problems/inversions/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




35 84  2  37  3  67  82  19  97  91  63  27  6  13  90  63  89  100  60  47  96  54  26  64  50  71  16  6  40  84  93  67  85  16  22  60



15 84  2  37  3  67  82  19  97  91  63  27  6  13  90  63 



18 84  2  37  3  67  82  19  97  91  63  27  6  13  90  63 89 100 60


5 2 4 1 3 5


6 2 4 4 1 3 5


// Time Complexity: O(n^2).  												// Ammortized Complexity: O(nlogn).
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).													// Ammortized Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Binary Search Tree based. We construct a Binary Search Tree. We construct a Tree based on prev. values, where each node
// stores #right children to it. For every node, we iter. over tree, get #Greater values than it. After that, we push that value into BST.
// If we get a duplicate value, they go into left child of BST.












struct Tree{																// Tree where we track #Greater elem.(Right Child) of every node.
    int val;																// Curr. node's value.
    int count;																// No. of Right children.
    Tree* left;
    Tree* right;
    Tree(int i){
        val=i;
        count=0;
        left=NULL; 
        right=NULL;
    }
    
};


void insertNode(Tree* root, int num){										// Insert a node into the Tree.
    Tree*temp=root;
    Tree* prev=root;														// Stores last visited node.
    while(temp){															// Until leaf is reached.
        if(num>temp->val){													// If curr. val is >node's val, we move to right child.
            prev=temp;
            temp->count++;													// INc. the right child count by one.
            temp=temp->right;
        }
        else{																// Else, move to left child.
            prev=temp;
            temp=temp->left;
        }
    }
    if(num>prev->val) prev->right=new Tree(num);							// If last visited node is < curr. val, we create a right child.
    else prev->left=new Tree(num);											// Else, we create a new right child.
    
}


int getCount(Tree* root, int num){											// Get #values greater than curr. value.
    Tree* temp=root;
    int res=0;																// Tracks greater values.
    while(temp){															// Until leaf is reached.
        if(num<temp->val){													// If cur. val<node's val, we move to left child to find any other
            res+=temp->count+1;												// -greater values.
            temp=temp->left;
        }
        else{																// Else, we move to right child.
            temp=temp->right;
        }
    }
    return res;																// We return the count of greater values.
}

int Solution::countInversions(vector<int> &v) {
    
    if(v.size()<=1) return 0;
    int res=0;
    Tree* root=new Tree(v[0]);												// Make first value as root of tree.
    for(int i=1;i<v.size();i++){											// Iter. over entire array.
        int ans=0;
        ans=getCount(root, v[i]);											// Get prev. greater values count.
        // cout<<"num: "<<v[i]<<" and ans: "<<ans<<endl;
        res+=ans;															// Add to final count.
        insertNode(root, v[i]);												// Insert curr. val into Tree.
    }
    return res;																// Return the total count of inverse values.
    
}








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).													// Ammortized Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Binary Search Tree based. We construct a Binary Search Tree. We construct a Tree based on prev. values, where each node
// stores #right children to it. For every node, we iter. over tree, get #Greater values than it. After that, we push that value into BST.
// If we get a duplicate value, we inc. the duplicate values count in that node(pres value).










struct Tree{
    int val;
    int count;
    int pres=0;
    Tree* left;
    Tree* right;
    Tree(int i){
        val=i;
        count=0;
        pres=1;
        left=NULL; 
        right=NULL;
    }
    
};


void insertNode(Tree* root, int num){
    Tree*temp=root;
    Tree* prev=root;
    while(temp){
        if(num>temp->val){
            prev=temp;
            temp->count++;
            temp=temp->right;
        }
        else if(num==temp->val){											// If Dupli. values occur.
            temp->pres++;													// Inc. the occurance(Duplicate) count.
            return ;
        }
        else{
            prev=temp;
            temp=temp->left;
        }
    }
    if(num>prev->val) prev->right=new Tree(num);
    else prev->left=new Tree(num);
    
}


int getCount(Tree* root, int num){
    Tree* temp=root;
    int res=0;
    while(temp){
        if(num<temp->val){
            res+=temp->count+temp->pres;									// Add #Right child and # Curr. values(Dup).
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return res;
}

int Solution::countInversions(vector<int> &v) {
    
    if(v.size()<=1) return 0;
    int res=0;
    Tree* root=new Tree(v[0]);
    for(int i=1;i<v.size();i++){
        int ans=0;
        ans=getCount(root, v[i]);
        // cout<<"num: "<<v[i]<<" and ans: "<<ans<<endl;
        res+=ans;
        insertNode(root, v[i]);
    }
    return res;
    
}
