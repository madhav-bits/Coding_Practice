/*
*
//*************************************************1656. Design an Ordered Stream.****************************************************

https://leetcode.com/problems/design-an-ordered-stream/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on test cases provided with the question.



// Time Complexity: O(1).													// Avg. tiem for an update.  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// Avg. time for an update.
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we store the id and value pairs in an array and update it. If during an update, if the 
// ptr is equal to curr. updating index, we gather all values which are udpated, also update the ptr.








class OrderedStream {
public:
    vector<string>v;
    int ptr=0;
    OrderedStream(int n) {
        v=vector<string>(n,"#");
    }
    
    vector<string> insert(int id, string value) {
        id--;
        v[id]=value;
        vector<string>res;
        if(ptr!=id) return res;
        while(ptr<v.size() && v[ptr]!="#"){
            res.push_back(v[ptr++]);
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */