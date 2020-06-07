/*
*
//****************************************************1472. Design Browser History.***********************************************

https://leetcode.com/problems/design-browser-history/description/


You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or 
move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x 
steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward 
only x steps. Return the current url after forwarding in history at most steps.
 

Example:

Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
 

Constraints:

1 <= homepage.length <= 20
1 <= url.length <= 20
1 <= steps <= 100
homepage and url consist of  '.' or lower case English letters.
At most 5000 calls will be made to visit, back, and forward.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


["BrowserHistory","visit","visit","visit","back","back","visit","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],["xyz.com"],[1],["linkedin.com"],[2],[2],[7]]


["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]


// Time Complexity: O(1).													// Per each operation.
// Space Complexity: O(n).													// Max. #websites visited.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// Per each operation.
// Space Complexity: O(n).													// Max. #websites visited.
// This algorithm is array based. Here, we maintain the Browser History in an array. We use currIndex, topIndex to point to the curr.
// window we are in. TopIndex indicates the most forward visted website in history. We init. the array with homepage and set both ptrs
// to 0. When we visit a new website, we inc. the currIndex, if it is equal to array size, we have to push new webiste into using 
// push_back, else we have indices which are deleted as part of browsing, so we just add the new website to new currIndex. We also
// update the topIndex=currIndex indicating that this is the most latest website we visited, if there are any websites visited, they are
// deleted(ignored).
// When requested to move back, we can move atmost to zero index, similar to moving forward we can move atmost upto topIndex. We move
// currIndex to this revisted new index and display website name stored.







class BrowserHistory {
public:
    vector<string>v;														// Tracks the Browser history.
    int currIndex=0, topIndex=0;;											// Tracks curr. psn and most forward visited website psn.
    BrowserHistory(string homepage) {
        v.clear();
        v.push_back(homepage);												// Init. with given homepage.
        currIndex=0;														// Init. both ptrs.
        topIndex=0;
    }
    
    void visit(string url) {
        if(++currIndex==v.size()) v.push_back(url);							// If no space to store new webiste, we use push_back.
        else v[currIndex]=url;												// If space exists, we simply store the website.
        // topIndex=max(topIndex, currIndex);
        topIndex=currIndex;													// We assign currIndex to topIndex, as this is most forward visited psn. 
        return ;
    }
    
    string back(int steps) {
        if(currIndex-steps<0) currIndex=0;									// If going out of bounds, stop at zero index.
        else currIndex-=steps;
        return v[currIndex];												// Return the website at the curr. psn.
    }
    
    string forward(int steps) {
        if(currIndex+steps>topIndex) currIndex=topIndex;					// If going out of bounds, stop to topIndex.
        else currIndex+=steps;			
        return v[currIndex];												// Return the website at the curr. psn.
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);

 */