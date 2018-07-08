/*
*
//**********************************************************244. Shortest Word Distance II.***************************************************

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return 
the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.


*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["WordDistance","shortest","shortest"]
[[["practice","makes","perfect","coding","makes"]],["coding","practice"],["makes","coding"]]



["WordDistance","shortest","shortest"]
[[["practice","makes","perfect","coding","makes"]],["coding","practice","coding"],["makes","coding","practice"]]


// Time Complexity: O(n*k).  												//k=no. of calls to function.
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k).													//k=no. of calls to function.
// Space Complexity: O(n^2).	
// This algorithm is HashMap based. We copy the given vector. If the min. dist for the given combi. of words is already calc., then  return it.
// If not calculated then we iterate the entire array, and calc. the min. dist b/w the strings and return it and update the min. dist in the map.
// We update the map with two combi. of strings (str1,str2) and (str2,str1).


// Despite using Cache, as here we are iterating through entire array to calc. the min. dist, it's time taken for execution is really high.But,
// asymptotically it's the same.





class WordDistance {
public:
    unordered_map<string,int>dist;											// Stores dist b/w strs indicated by key value.
    vector<string>v;														// Copy the string vector.
    WordDistance(vector<string> words) {
        v=words;															// Copying string vector.
    }
    
    int shortest(string word1, string word2) {
        if(dist.count(word1+'#'+word2)==1) return dist[word1+'#'+word2];	// If min. dist already calculated, return it.
        // cout<<"Returned after calculating dist. "<<endl;
        int res=INT_MAX;													// Default value of min. dist.
        int index1=-1, index2=-1;											// Default index values.
        for(int i=0;i<v.size();i++){
            if(v[i]== word1){												// If word1 had occured.
                if(index2!=-1) res=min(res,abs(i-index2));					// If word2 had prev. occured, calc. min. dist to it.
                index1=i;													// Update the latest occurance of word1.
            }
            else if(v[i]==word2){											// If word2 had occured.
                if(index1!=-1) res=min(res,abs(i-index1));					// If word1 had prev. occured, calc. dist to it.
                index2=i;													// Update the latest occurance of word2.
            }
        }
        dist[word1+'#'+word2]=res;											// Updating the cache(Map) with key=combi. of strs with dist.
        dist[word2+'#'+word1]=res;
        return res;															// Return the calc. shortest distance b/w strs provided.
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
 
 
 
 
 
 
 
 
 
 
 
 
//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k).													// k=#calls to the function.
// Space Complexity: O(n^2).	
// This algorithm is HashMap based. We store all occuring indices of all strings of the vector in a map. If the min. dist for the given combi. 
// of words is already calc., then  return it.
// If not calculated then we iterate the entire array, and calc. the min. dist b/w the strings and return it and update the min. dist in the map.
// We update the map with two combi. of strings (str1,str2) and (str2,str1).


// As, here we iterate through only indices in which these words occured. The time taken for execution(calc. min dist b/w strs) is very low. 
// This is the efficient one among two algos. 
 
 
class WordDistance {
public:
    unordered_map<string,int>dist;											// Stores min. dist. b/w strings.
    unordered_map<string,vector<int>>indices;								// Stores occuring indices of various strings in vector.
    WordDistance(vector<string> words) {
        for(int i=0;i<words.size();i++)
            indices[words[i]].push_back(i);									// Storing occuring indices of various strings in vector.
    }
    
    int shortest(string word1, string word2) {
        if(dist.count(word1+'#'+word2)==1) return dist[word1+'#'+word2];	// If already calc. return min. dist. b/w strings.
        // cout<<"Returned after calculating dist. "<<endl;
        int res=INT_MAX;
        int i=0,j=0;
        vector<int>str1,str2;
        str1=indices[word1];												// All occuring Indices of  word1.
        str2=indices[word2];												// All occuring Indices of  word2.
        while(i<str1.size() && j<str2.size()){								// Iterating through stored indices.
            if(str1[i]>=str2[j]){											// If index of word1>latest index of word2.
                res=min(res,str1[i]-str2[j]);
                j++;
            }
            else{
                res=min(res,str2[j]-str1[i]);								// If latest index of word2>latest index of word1.
                i++;
            }
        }
        dist[word1+'#'+word2]=res;											// Updating the map with min. dist. b/w strs with two combi. of strings.
        dist[word2+'#'+word1]=res;
        return res;															// Returning the min. dist b/w words given.
    }	
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */