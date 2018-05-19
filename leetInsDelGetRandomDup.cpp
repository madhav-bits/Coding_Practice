/*
*
//***********************************************381. Insert Delete GetRandom O(1) - Duplicates allowed.*****************************************

Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related 
to the number of same value the collection contains.
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]
[[],[1],[1],[2],[],[1],[]]


["RandomizedCollection","insert","remove","insert"]
[[],[1],[1],[1]]



["RandomizedCollection","insert","remove","insert","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[0],[0],[-1],[0],[],[],[],[],[],[],[],[],[],[]]



["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[10],[10],[20],[20],[30],[30],[10],[10],[30],[30],[],[],[],[],[],[],[],[],[],[]]


["RandomizedCollection","insert","insert","insert","insert","insert","remove","remove","remove","remove"]
[[],[4],[3],[4],[2],[4],[4],[3],[4],[4]]



["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[1],[1],[2],[1],[2],[2],[1],[2],[2],[2],[],[],[],[],[],[],[],[],[],[]]




// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//******************************************************THIS IS LEET ACCEPTED CODE.**************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Data Structure based question. We maintain two Data structures a map and a vector(to give equal likely random values).
// map contains inserted values as keys and their indices in vector as value pair. Vector contents has pair values as it's members, with first 
// part- the inserted value, the second part, this index's value's index in the value pair of the map. When deleted we update the vector contents
// and the index of that value in the value pair in the map. We maintain stable Data Structure. While inserting just add value to vector- with 
// value and it's index in value pair as contents and push the value into value pair of map.







class RandomizedCollection {
public:
    unordered_map<int,vector<int>>m;										// Value and their indices in vector as contents.
    vector<pair<int, int>> v;												// Value, index in map's value pair as content.
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res=(m.count(val)==0);											// Setting the return bool value.
        m[val].push_back(v.size());											// Pushing into map.
        v.push_back(make_pair(val, m[val].size()-1));						// Pushing pair values into vector.
            
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool res=(m.count(val)==1);
        if(res){
            int index=m[val].back();
            pair<int, int> lastElem=v.back();								// Updating the last index's pair contents.
            m[lastElem.first][lastElem.second]=index;						// Updating the last index's pair contents.
            v[index]=lastElem;												// Updating the vector.
            m[val].pop_back();												// Deleting the map's value's contents.
            if(m[val].size()==0) m.erase(val);								// If no values present, delete key.
            v.pop_back();													// Deleting the val. from the vector.
        }
        return res;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        
        return v[rand()%v.size()].first;									// Returning the random number.
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is same as above one, but the contents of vector contains just the inserted values. This algo. passed 27/28 test cases. Misses
// the largest at few spots, as it's a lengthy test case, I am not able to determine the reason behind the failure.







class RandomizedCollection {
public:
    unordered_map<int,set<int>>m;
    vector<int> v;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        //cout<<"Start of insert."<<endl;
        if(m.count(val)==0){
            //cout<<"New key insert."<<endl;
            m[val].insert(v.size());
            v.push_back(val);
            return true;
        }
        else{
            //cout<<"Old key-value insert."<<endl;
            m[val].insert(v.size());
            //cout<<"Size of set is: "<<m[val].size()<<endl;
            v.push_back(val);
            return false;
        } 
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.count(val)==0) return false;
        //cout<<"Inside remove and The size of vector is: "<<m[val].size()<<endl;
        //int index=m[val][m[val].size()-1];
        auto it=m[val].begin();
        int index=*it;
        //cout<<"Index is: "<<index<<"for value: "<<val<<" and size is: "<<m[val].size()<<endl;
        
        //m[v[index]][m[v[index]].size()-1]=index;
        
        
        int a=0;
        if(v[index]!=v.back()){
            //m[v.back()].erase(v.size()-1);
            //cout<<"1 and size is: "<<m[v.back()].size()<<endl;
            //m[v.back()].insert(index);
            //cout<<"2 and size is: "<<m[v.back()].size()<<endl;
        }
        else if(v.size()>1 && v[index]==v.back()) a=1;
        v[index]=v[v.size()-1];
        m[v[index]].erase(v.size()-1);
        //cout<<"1 and size is: "<<m[v.back()].size()<<endl;
        m[v[index]].insert(index);
        //cout<<"2 and size is: "<<m[v[index]].size()<<endl;
        //cout<<"a: "<<a<<endl;
        if(a==0 && m[val].size()==1){
            //cout<<"Removing the key."<<endl;
            //m[val].pop_back();
            m[val].clear();
            m.erase(val);
        } 
        else{
            //m[val].pop_back();
            
            //cout<<"Deleting val: "<<*it<<" and size is: "<<m[val].size()<<endl;
            if(a==0)
                m[val].erase(index);
            //cout<<"Inside remove and The new size of vector is: "<<m[val].size()<<endl;
        }
        
        
        
        v.pop_back();
        // for(auto num2:m[v[index]]) cout<<"INdex is: "<<num2<<endl;
        //for(auto num:v) cout<<"NUm: "<<num<<" ";
        //cout<<endl;
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        // cout<<"The vector size is: "<<v.size()<<endl;
        // cout<<"Elem1: "<<v[0]<<endl;
        // cout<<"Elem2 is: "<<v[1]<<endl;
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */