/*
*
//******************************************************315. Count of Smaller Numbers After Self.***********************************************

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number 
of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,2,6,1]


[2,3,7,5,6,4]

[1,2,3,4]

[4,3,2]

[4]

[]

[6,3,10,9,12,4,16,17]


// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*************************************************THIS IS A CRAZY SOLUTION, MINDBLOWING ONE THIS IS.*******************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Merge Sort based. Here we do a merge sort, extract our required count for each index while merging two subarrays. The 
// trick is that we place indices of values in given array, in the array on which we perform merge sort. While merging subarrays we merge from 
// the back. If the subarr1's curr. index's value is>subArr2's curr. index's value, then it's that all the indices in subArr2(which are greater
// than indices in subArr1) have values <curr. subArr1's index's value, we get the #indices in subArr by subtracing curr. index with mid+1
// We do this for entire mergeSort process. At the end, we get our answer in result vector.






class Solution {
public:
    int count=0;
    vector<int>res;
    void mergeSort(vector<int>&v,vector<int> &rep,int start,int end){
        // cout<<"Inside the fn. with start: "<<start<<" and end: "<<end<<endl;
        if(start==end) return ;															// If single elem. in subArr, just return.
        int mid=start+(end-start)/2;													// Calc. mid index, split subArr into two parts.
        mergeSort(v,rep, start,mid);													// Call the mergeSort on first half.
        mergeSort(v,rep, mid+1,end);													// Call the mergeSort on second half.
        // for(int a=start;a<=mid;a++) cout<<v[rep[a]]<<" ";cout<<endl;
        // for(int a=mid+1;a<=end;a++) cout<<v[rep[a]]<<" ";cout<<endl;
        int i=mid,j=end,k=end-start;													// Setting indices for merge Process.
        vector<int>temp(end-start+1,0);													// Temp. array to store the merge Results.
        while(i>=start || j>=mid+1){													// If any of two subArrays have valid index.
            if((i>=start && j==mid) || i>=start &&  v[rep[i]]>v[rep[j]]){				// If first subArr. have valid index/greater value.
                temp[k]=rep[i];															// Storing the curr. index in temp merge Result.
                // cout<<"Inc. the value at index: "<<rep[i]<<" by: "<<j-(mid+1)+1<<endl;
                res[rep[i]]+=j-(mid+1)+1;										// Extract. the #indices in subArr2 with value<curr. index's value.
                i--;																	// Updating the scanning index.
            }
            else{																		// If the subArr2's curr. index has greater value.
                temp[k]=rep[j];
                j--;
            }
            k--;																		// Updating the mergeSort Result vector's index.
        }
        
        for(int i=0;i<=end-start;i++){
            // cout<<"Pushing in rep at index: "<<start+i<<"value: "<<temp[i]<<endl;
            rep[start+i]=temp[i];														// Copying the result to original given vector.
        }
        // cout<<"Returning the fn. with start: "<<start<<" and end: "<<end<<endl;    
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0) return res;        											// If size=0, return empty vector.
        res=vector<int>(nums.size(),0);													// Init. the result  vector.
        vector<int> rep(nums.size(),0);													// Init. the vector to store indices of all nums.
        for(int i=0;i<nums.size();i++) rep[i]=i;										// Storing indices of nums in  vector.
        mergeSort(nums,rep, 0,nums.size()-1);											// Calling fn. to get count at all indices.
        return res;																		// Returning the result vector.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Binary Search Tree based. We iterate from the back. We take each node, and push into BST, in the process, extract #prev.
// values <curr. value. Each node maitains, #left subtree nodes+1(itself). The thing is that this tree allows dup. nodes(Nodes with same value 
// in the left child). This doesn't break tree Structure or it doesn't effect final result(As, result gets effected by nodes with values<curr.
// value). 





class Solution {
public:
    struct TreeNode{												// Node structure.
        int val;
        int count;													// # nodes in left subtree+1(itself).
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), count(1),left(NULL), right(NULL){};
    };
    vector<int>res;													// Final result vector.
    
    void findCount(TreeNode* node, int curr,int index){
        int sum=0;
        if(curr<=node->val){										// If curr. val<=node's val, go into left subtree in search of target values.
            node->count++;											// We. inc. the count as a node will be made with curr. value 
            if(node->left!=NULL) findCount(node->left,curr,index);	// If left child exists, traverse it, else create it.
            else
                node->left=new TreeNode(curr);
        }
        else{
            res[index]+=node->count;							// If the curr. val>node->val, all the leftChild values+1(node) would add to ans.
            //if(node->left!=NULL) findCount(node->left,curr,index);	
            if(node->right!=NULL) findCount(node->right,curr,index);// If right child exists,trav. it in search of target values,else create it.
            else
                node->right=new TreeNode(curr);
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0) return res;     							// If empty vector provided, return empty vector.
        res=vector<int>(nums.size(),0);								// Init. the result vector.
        TreeNode* root= new TreeNode(nums.back());					// Init. the tree's rooot.
        for(int i=nums.size()-2;i>=0;i--){							// Pushing all values into BST.
            findCount(root, nums[i],i);
        }
        return res;													// Returning the result vector.
    }
};











//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// **************************************************THIS IS A CREATIVE ALGORITHM.***********************************************
// Time Complexity: O(nlogn).						// nlogn to Construct Tree, logn to get the count.
// Space Complexity: O(m).							// Max. value in array.	
// This algorithm is Binary Indexed Tree based. We calculate the minm of the contents of the array, inc. the whole array by that value+1, to
// prevent zero value in BIT. Our BIT's index "i" indicates few #numbers less than "i". Similar to the way, we ask for sum of values in indices 
// from 0 to 'i' in Range Sum Queries in ordinary BIT, in this BIT, we ask for #numbers less than 'i'.


// We modify this problem slightly so that BIT can be used,we construct a BIT of length maxm. value of array's contents,after padding all values
// with minm. value.(As, BIT involves only positive values).





class Solution {
public:
    
    void update(vector<int>&v,int ind){										 
        while(ind<v.size()){												// Updating index and it's parent's values.
            v[ind]++;
            ind+=ind&(-ind);												// Finding parent's index number.
        }
    }
    int getCount(vector<int>&v, int ind){
        int res=0;
        while(ind>0){														// Extracts values from all correspoding indices.
            res+=v[ind];
            ind-=(ind &(-ind));												// Finding the index number of it's parent.
        }
        return res;															// Returns the sum.
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>res;
        if(nums.size()==0) return res;
        int minm=INT_MAX;
        for(int i=0;i<nums.size();i++) minm=min(minm, nums[i]);				// Gets the minm. value of the array.
        int maxm=INT_MIN;
        for(int i=0;i<nums.size();i++){
            nums[i]+=-minm+1;
            maxm=max(maxm,nums[i]);											// Gets the maxm. value after padding.
        } 
        vector<int>bITree(maxm+1,0);										// Construct a Binary Indexed Tree.
        for(int i=nums.size()-1;i>=0;i--){
            res.push_back(getCount(bITree, nums[i]-1));						// Extract #nums < curr. value.
            update(bITree,nums[i]);											// Push curr. value into BIT.
        }
        reverse(res.begin(), res.end());									// As, values are accumulated from last to first index. 
        return res;															// Returning the result vector.
    }
};