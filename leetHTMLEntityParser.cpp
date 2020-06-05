/*
*
//**************************************************1410. HTML Entity Parser.***********************************************

https://leetcode.com/problems/html-entity-parser/description/


HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters 
itself.

The special characters and their entities for HTML are:

Quotation Mark: the entity is &quot; and symbol character is ".
Single Quote Mark: the entity is &apos; and symbol character is '.
Ampersand: the entity is &amp; and symbol character is &.
Greater Than Sign: the entity is &gt; and symbol character is >.
Less Than Sign: the entity is &lt; and symbol character is <.
Slash: the entity is &frasl; and symbol character is /.
Given the input text string to the HTML parser, you have to implement the entity parser.

Return the text after replacing the entities by the special characters.

 

Example 1:

Input: text = "&amp; is an HTML entity but &ambassador; is not."
Output: "& is an HTML entity but &ambassador; is not."
Explanation: The parser will replace the &amp; entity by &
Example 2:

Input: text = "and I quote: &quot;...&quot;"
Output: "and I quote: \"...\""
Example 3:

Input: text = "Stay home! Practice on Leetcode :)"
Output: "Stay home! Practice on Leetcode :)"
Example 4:

Input: text = "x &gt; y &amp;&amp; x &lt; y is always false"
Output: "x > y && x < y is always false"
Example 5:

Input: text = "leetcode.com&frasl;problemset&frasl;all"
Output: "leetcode.com/problemset/all"
 

Constraints:

1 <= text.length <= 10^5
The string may contain any possible characters out of all the 256 ASCII characters.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"&amp; is an HTML entity but &ambassador; is not."
"and I quote: &quot;...&quot;"
"Stay home! Practice on Leetcode :)"
"x &gt; y &amp;&amp; x &lt; y is always false"
"leetcode.com&frasl;problemset&frasl;all"
" &frasl; &quot; &apos; ZooP)x:6~"
"&amp; is an HTML entity &ge; &gt; but &ambassador; is not."


// Time Complexity: O(n).  													// n-length of the array.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n-length of the array.
// Space Complexity: O(1).	
// This algorithm is Trie based. I had used Trie to find curr. char is part of a substring are not. If there is node that matches curr.
// node, we simply push the char into final result, if the movement on Trie stops abruptly, as we can't end of a special set of chars. we
// add the chars accumulated till then to final result, we also initialize the node to root, such that it will start looking for new
// set of special chars.







class Solution {
public:
    unordered_set<string>words;
    
    bool isSubstring(string s){
        // cout<<"s: "<<s<<endl;
        for(auto it=words.begin();it!=words.end();it++){
            if(s.length()<=(*it).length() && s==(*it).substr(0, s.length())) return true;
        }    
        return false;
    }
    
    struct Trie{															// Designing Trie structure.
        bool finish;
        unordered_map<char,Trie*>child;										// As allowed range of chars is huge.
        string word;
        Trie(){
            finish=false;
            child=unordered_map<char,Trie*>();
            word="";
        }
    };
    
    void insertWord(Trie* root, string s, string fin){						// Inserting words into Trie.
        Trie* node=root;
        int index=0;
        while(index<s.length()){
            if(node->child.count(s[index])==0) node->child[s[index]]=new Trie();
            node=node->child[s[index++]];
        }
        node->finish=true;
        node->word=fin;
    }
    
    string entityParser(string s) {
        // words.insert("&quot;");
        // words.insert("&apos;");
        // words.insert("&amp;");
        // words.insert("&gt;");
        // words.insert("&lt;");
        // words.insert("&frasl;");
        
        Trie* root=new Trie();
        
        
        insertWord(root, "&quot;", "\"");									// Pushing special words into Trie.
        insertWord(root, "&apos;", "\'");
        insertWord(root, "&amp;", "&");
        insertWord(root, "&gt;", ">");
        insertWord(root, "&lt;", "<");
        insertWord(root, "&frasl;", "/");
        // unordered_map<string,string>m;
        // m["&quot;"]="\"";
        // m["&apos;"]="\'";
        // m["&amp;"]="&";
        // m["&gt;"]=">";
        // m["&lt;"]="<";
        // m["&frasl;"]="/";
        
        string res="";
        bool start=false;
        string temp="";
        Trie* node=root;
        for(int i=0;i<s.length();i++){
            temp+=s[i];
            // if(isSubstring(temp)){
            //     if(m.count(temp)==1){
            //         res+=m[temp];
            //         temp="";
            //     } 
            // }else{
            //     // if(temp.length()>1) res+=temp;
            //     res+=temp;
            //     temp="";
            //     // temp+=s[i];
            // }
            
			if(root->child.count(s[i])){									// If we encounter start of the Trie.
				node=root;
				node=node->child[s[i]];
                temp.pop_back();											// Rem. curr. char.
                res+=temp;													// Storing chars till then.
                temp="";
                temp+=s[i];													// Storing curr. char.
			}
            else if(node->child.count(s[i])){								// Travelling over Trie to the end of set of special chars.
                node=node->child[s[i]];
                if(node->finish){
                    // cout<<"finished"<<endl;
                    res+=node->word;
                    temp="";
                    node=root;
                } 
            }else{															// If normal char is encoutnered.
                res+=temp;													// Storing temp str. till then.
                temp="";
				node=root;													// Set the node to root, to look for start of spec. chars.
            }
        }
        // if(node->finish) res+=node->word;
        return res;															// Return the parsed HTML.
    }
};
