/*
*
//**************************************************************146. LRU Cache.*******************************************************

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the 
least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /capacity );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]


["LRUCache","put","put","get","put","get","put", "get", "get", "get", "get", "put", "get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[2],[3],[4],[1],[5,5],[4]]


["LRUCache","put","get","put","get","get"]
[[1],[2,1],[2],[3,2],[2],[3]]



// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is same as the Solution 2. Except that it didn't use Psuedo Nodes, as a result handling corner nodes got messed up and it 
// doesn't pass few test cases.
 
 
 
 
 
 
 
class LRUCache {
public:
    struct ListNode{
        int val;
        int k;
        ListNode* next;
        ListNode* prev;
        ListNode(int x,int y): k(x),val(y), prev(NULL), next(NULL){}
    };
    
    
    unordered_map<int, ListNode*>m;
    int count=0, cap;
    ListNode *root, *last;
    LRUCache(int capacity) {
        root= new ListNode(0,0);
        cap=capacity;
    }
    
    int get(int key) {
        //cout<<"Get key: "<<key<<endl;
        if(m.count(key)==0) return -1;
        if(count==1 || m[key]==root) return m[key]->val;
        if(m[key]==last){
            //cout<<"Get the last node and last but one node: "<<last->prev->val<<endl;
            int ans=m[key]->val;
            ListNode* temp=last;
                                                       // Removing the last node.
            last->prev->next=NULL;
            last=last->prev;
            
            temp->prev=NULL;
            temp->next=root;
            root->prev=temp;
            root=temp;
            //cout<<"Inside get with access last, new last is: "<<last->val<<" and new root: "<<root->next->val<<endl;
            return ans;
        }
        int ans=m[key]->val;
        //cout<<"Ans is: "<<ans<<endl;
        ListNode* curr= m[key];
        m[key]->prev->next=m[key]->next;
        curr->prev=NULL;
        curr->next=root;
        root-curr;
        return ans;
    }
    
    void put(int key, int value) {
        //cout<<"Put key: "<<key<<endl;
        if(m.count(key)==1) return ;
        if(count==cap){
            //count--;
            //cout<<"cap is full." <<" removing: "<<last->k<<endl;
            m.erase(last->k);
            if(root==last){
                root=new ListNode(key, value);
                last=root;
                m[key]=root;
            }
            else{
                last=last->prev;                                        // Removing the last node.
                last->next=NULL;

                ListNode* first= new ListNode(key, value);
                first->next=root;
                root->prev=first;
                root=first;
                m[key]=root;
            }
            //cout<<"New last is: "<<last->val<<endl;
        }
        else if(count==0){
            count++;
            root->k=key;
            root->val=value;
            m[key]= root;
            root->prev=NULL; root->next=NULL;
            last=root;
        }
        else{
            count++;
            ListNode* first= new ListNode(key, value);
            first->next=root;
            root->prev=first;
            root=first;
            m[key]=root;
            //cout<<"New Last is: "<<last->val<<endl;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
 
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is Data Structure based. It uses Map, Linked List. Map which stores keys and value's address in LinkedList. Each node of LL
// stores keys, values and addresses of it's prev. and next LLs. This also includes the concpet of Psuedo Nodes(Nodes used for simplific. purp.)
// When a key is added/updated/get it's removed from curr. psn(if exists) and added at the beginning of LL(Next node of head node). 
// When capacity is filled, the last node of LL(prev. node of tail node).
 
 
 
 
 
 
 
 class LRUCache {
public:
    struct ListNode{																	// Linked List Node Structure.
        int val;																		// Stores value.
        int k;																			// Stores key.
        ListNode* next;																	// Stores address of prev. and next node.
        ListNode* prev;
        ListNode(int x,int y): k(x),val(y), prev(NULL), next(NULL){}					// Constructor.
    };
    
    void remNode(ListNode* node){														// Removing a node.
        node->prev->next=node->next;													// Updating next of curr. node's prev. node.
        node->next->prev=node->prev;													// Updating prev. of curr. node's next node.
    }
    
    void addNode(ListNode* node){
        head->next->prev=node;															// Adjusting prev. and next ptrs in next and previous nodes.
        node->next=head->next;
        node->prev=head;
        head->next=node;
    }
    
    unordered_map<int, ListNode*>m;														// Maps key to it's address in LL.
    int count=0, cap;
    ListNode *head, *tail;
    LRUCache(int capacity) {
        //root= new ListNode(0,0);
        cap=capacity;																	// Initializing cap variable.
        head= new ListNode(0,0);														// Initializing head and tail nodes.
        tail= new ListNode(0,0);
        
        
        head->prev=NULL;																// Linking head and tail nodes(Begin case).
        head->next=tail;
        
        tail->next=NULL;
        tail->prev=head;
        
        
    }
    
    int get(int key) {																	// When key is queried.
        //cout<<"Inside the get with key: "<<key<<endl;
        if(m.count(key)==0) return -1;													// If key doesn't exist, return -1.
        
        ListNode* temp=m[key];															// Addr. of key in LL.
        remNode(temp);																	// Removing and placing it at the beginning(next of head).
        addNode(temp);
        
        return m[key]->val;																// Returning val. of the key.
        
    }
    
    void put(int key, int value) {
        //cout<<"Inside the put with key: "<<key<<endl;
        //cout<<"Put key: "<<key<<endl;
        if(m.count(key)==1){															// If key exists updating val. and pushing it to beginning.
            m[key]->val=value;															// Updating val.
            remNode(m[key]);															// Pushing it to beginning.
            addNode(m[key]);
        }
        else{
            ListNode* temp= new ListNode(key, value);									// Creating a node for new key, value.
            
            if(m.size()==cap){															// If cap. reached, removing last node and add new node-
                m[key]= temp;															//- at the beginning of the LL and also add to map.
                //cout<<"The removing node: "<<tail->prev->k<<endl;
                m.erase(tail->prev->k);													// Removing last of LL from map.
                remNode(tail->prev);                                            		// Removing the node before tail node.
                addNode(temp);															// Adding new node at the beginning of LL.
            }
            else{
                m[key]= temp;															// Adding key, Address to map.
                addNode(temp);															// Adding new node at the beginning of LL.
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
 
 
 