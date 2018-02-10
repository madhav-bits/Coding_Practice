/*
*
//*************************************************117. Populating Next Right Pointers in Each Node II.****************************************

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[7,2,10,null,4,8,14]

[20,10,40,5,15,20,null,null,null,14,18,null,25,11,14,17,19]

[0,2,4,1,null,3,-1,5,1,null,6,null,8]








// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm is BFS, it maintains the left and right most nodes reached till now in the next level. Leftmost is used to move into the
// next level, and the right most node is the curr. node's child's next node.








class Solution{
public: 
    
    void connect(TreeLinkNode *root) {
        TreeLinkNode *now, *tail, *head;

        now = root;
        head = tail = NULL;
        while(now)
        {
            if (now->left)
                if (tail) tail = tail->next =now->left;
                else head = tail = now->left;
            if (now->right)
                if (tail) tail = tail->next =now->right;
                else head = tail = now->right;
            if(!(now = now->next))
            {
                now = head;
                head = tail=NULL;
            }
        }
    }
};















//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This is Level Order Traversal done using Recursion and Queues and I don't see any reason behind the execution getting failed, as there is no
// option to debug(Test run the code) for this code.






/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    
    void rightConnect(TreeLinkNode* temp){											// This algo. recursive Level Order Traversal.
        if(temp==NULL) return ;
        cout<<"Inside the rightConnect with node value is: "<<temp->val<<endl;
        TreeLinkNode* temp2=temp->next;
        while(temp2!=NULL && temp2->left==NULL && temp2->right==NULL)
            temp2=temp2->next;
        if(temp2!=NULL&& (temp2->left!=NULL || temp2->right!=NULL)){
            if(temp->right!=NULL){
                temp->right->next=(temp2->left!=NULL)?temp2->left:temp2->right;
                if(temp->left!=NULL)
                    temp->left->next=temp->right;
            }
            else if(temp->left!=NULL)
                temp->left->next=(temp2->left!=NULL)?temp2->left:temp2->right;
        }
        else{
            if(temp->right!=NULL && temp->left!=NULL)
                temp->left->next=temp->right;
        }
        
        if(temp->left!=NULL) rightConnect(temp->left);									    // Calling the left child.
        if(temp->right!=NULL) rightConnect(temp->right);									// Calling the right child.
        
    }
    
    
    void connect(TreeLinkNode *root) {
        if(root==NULL) return ;										// If the root is NULL, return the NULL.
        //rightConnect(root);
        queue<TreeLinkNode*> q;
        q.push(root);
        int count=1;
        while(!q.empty()){											// This algorithm does Level Order Traversal.
            count=q.size();
            TreeLinkNode* temp=q.front();							// Extracting the first node of a level.
            q.pop();
            count--;
            while(!q.empty()){										// Saving the next level tree nodes.
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                if(count==0)										// Makes sure only elem. of same level are extract in one exec. of while. loop
                    break;
                TreeLinkNode* temp2=q.front();
                temp->next=temp2;									// Setting the next ptrs of curr. level's nodes.
                temp=q.front();										// Iterating through nodes at a level.
                q.pop();
                count--;
            }
        }
    }
};














