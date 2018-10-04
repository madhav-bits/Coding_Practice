/*
*
//**************************************************************Hotel Reviews.********************************************************


https://www.interviewbit.com/problems/hotel-reviews/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



abc_abcd_bxy

3 ac_abd_abc_bxyz




// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Priority Queue and HashMap/Set based. Here,  I had pushed all Good Words in a HashMap. In the second iteration, we iter. over
// reviews, extracted each word, checked for it's presence in Good Words Set. If present inc. the count of good words for that review by one.
// At the end of every review, we push the sum, index of that review into Priority Queue(Sorted for Max. value in Count, if Counts match sort
// for Min. value of indices). After pushing all review's count, index into PQ, we pop all elem. from PQ and push into final result vector.









struct compare{
  
  bool operator()(pair<int,int>lt, pair<int,int>rt){						// Sort for Max. value on first, if Equal sort for Min. on second value.
      return (lt.first<rt.first ||(lt.first==rt.first && lt.second>rt.second));
  }  
};

vector<int> Solution::solve(string words, vector<string> &v) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>res;
    unordered_set<string>s;
    string temp="";
    for(int i=0;i<words.length();i++){										// ITer. good words list, push it into set.
        if(words[i]!='_') temp+=words[i];
        else{
            s.insert(temp);
            temp="";
        }
    }
    if(temp.length()>0) s.insert(temp);
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare>pq;		// To get indices in dec. order of count, if equal inc. order of indices.
    for(int i=0;i<v.size();i++){											// ITer. over all strings.
        string temp="";
        int occur=0;
        for(int j=0;j<v[i].length();j++){									
            if(v[i][j]!='_') temp+=v[i][j];
            else{
                if(s.count(temp)==1) occur++;								// Check curr. word is in set, inc. count.
                temp="";
            }
        }
        if(temp.length()>0 && s.count(temp)==1) occur++;					// Checking for last word in review.
        pq.push({occur,i});													// Pushing count, index pair into PQ.
    }
    while(!pq.empty()){														// Extract indices satisfying given cdns.
        pair<int,int>pr=pq.top();
        pq.pop();
        res.push_back(pr.second);
    }
    return res;																// Return the indices.
    
}









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Trie based. First, we build a Trie based on the Good words list provided. Later, we iterate over the Given reviews, for 
// every char we iter. through Trie, if next node of Trie not found, we break from Trie. When we reach end of string/'_', we check whether curr.
// node has an indication stating a Good word has ended here, if it is we inc. the count of Good words in this review. At the end of scanning each
// review, we push the {count, index}  pair into PQ(Sorted for Max. value in Count, if Counts match sort for Min. value of indices). At the end 
// of it, we extract indices from PQ in the order satisfying given cdns.








struct compare{
  
  bool operator()(pair<int,int>lt, pair<int,int>rt){
      return (lt.first<rt.first ||(lt.first==rt.first && lt.second>rt.second));
  }  
};


struct Trie{																// Declaring Trie Data Type.
  
  struct Trie* child[26];
  bool close;
  
  Trie(){
      close=false;
      for(int i=0;i<26;i++) child[i]=NULL;
  }
  
};

void buildTrie(string &s, Trie* root){										// Building Trie based on the Good words list provided.
    Trie*temp=root;
    for(int i=0;i<s.length();i++){
        if(s[i]!='_'){														// If valid chars present.
            if(temp->child[s[i]-'a']==NULL) temp->child[s[i]-'a']=new Trie();// If next node not present, create one.
            temp=temp->child[s[i]-'a'];										// Move to child node.
        }else{																// If delimiter reached.
            temp->close=true;												// Marking node that a Good word ended here.
            temp=root;														// Moving to root of Trie.
        }
    }
    temp->close=true;														// Marking for last word of Good Words list.
}

vector<int> Solution::solve(string words, vector<string> &v) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>res;
    Trie* root= new Trie();
    buildTrie(words,root);
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare>pq;
    for(int i=0;i<v.size();i++){
        Trie* rt=root;
        int occur=0;
        // cout<<"string: "<<v[i]<<endl;
        for(int j=0;j<v[i].length();j++){									// ITer. over each string.
            // cout<<" char; "<<v[i][j]<<endl;
            if(v[i][j]!='_'){												// If Valid char present.
                if(!rt) continue;											// If there is no node for curr. char in Trie, we skip.
                rt=rt->child[v[i][j]-'a'];									// If node present, we move to next/Child node.
            } 
            else{															// If delimiter found.
                if(rt && rt->close==true) occur++;							// If a Good Word ended here, inc.the count of Good words.
                rt=root;													// Moving to root again.
            }
        }
        if(rt&& rt->close==true) occur++;									// Checking for last word in Trie.
        // cout<<"Count: "<<occur<<endl;
        pq.push({occur,i});													// Push the {count, index} into PQ.
    }
    while(!pq.empty()){														// Extract indices and push into final result vector.
        pair<int,int>pr=pq.top();											// These indices satisfy the given cdns.
        pq.pop();
        res.push_back(pr.second);
    }
    return res;																// Return the final result vector.
    
}