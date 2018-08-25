/*
*
//******************************************************631. Design Excel Sum Formula.***********************************************

Your task is to design the basic function of Excel and implement the function of sum formula. Specifically, you need to implement the following 
functions:

Excel(int H, char W): This is the constructor. The inputs represents the height and width of the Excel form. H is a positive integer, range from 
1 to 26. It represents the height. W is a character range from 'A' to 'Z'. It represents that the width is the number of characters from 'A' to W. 
The Excel form content is represented by a height * width 2D integer array C, it should be initialized to zero. You should assume that the first 
row of C starts from 1, and the first column of C starts from 'A'.


void Set(int row, char column, int val): Change the value at C(row, column) to be val.


int Get(int row, char column): Return the value at C(row, column).


int Sum(int row, char column, List of Strings : numbers): This function calculate and set the value at C(row, column), where the value should be 
the sum of cells represented by numbers. This function return the sum result at C(row, column). This sum formula should exist until this cell is 
overlapped by another value or another sum formula.

numbers is a list of strings that each string represent a cell or a range of cells. If the string represent a single cell, then it has the 
following format : ColRow. For example, "F7" represents the cell at (7, F).

If the string represent a range of cells, then it has the following format : ColRow1:ColRow2. The range will always be a rectangle, and ColRow1 
represent the position of the top-left cell, and ColRow2 represents the position of the bottom-right cell.


Example 1:
Excel(3,"C"); 
// construct a 3*3 2D array with all zero.
//   A B C
// 1 0 0 0
// 2 0 0 0
// 3 0 0 0

Set(1, "A", 2);
// set C(1,"A") to be 2.
//   A B C
// 1 2 0 0
// 2 0 0 0
// 3 0 0 0

Sum(3, "C", ["A1", "A1:B2"]);
// set C(3,"C") to be the sum of value at C(1,"A") and the values sum of the rectangle range whose top-left cell is C(1,"A") and bottom-right 
cell is C(2,"B"). Return 4. 
//   A B C
// 1 2 0 0
// 2 0 0 0
// 3 0 0 4

Set(2, "B", 2);
// set C(2,"B") to be 2. Note C(3, "C") should also be changed.
//   A B C
// 1 2 0 0
// 2 0 2 0
// 3 0 0 6
Note:
You could assume that there won't be any circular sum reference. For example, A1 = sum(B1) and B1 = sum(A1).
The test cases are using double-quotes to represent a character.
Please remember to RESET your class variables declared in class Excel, as static/class variables are persisted across multiple test cases. Please 
see here for more details.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Excel","get","set","get","sum","set","set","get"]
[[3,"C"],[1,"A"],[1,"A",1],[1,"A"],[3, "C", ["A1", "A1:B2"]],[2,"B",2],[1,"A",3],[3,"C"]]







// Time Complexity: O((r*c)^2).  
// Space Complexity: O(((r*c)^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(((r*c)^2).
// Space Complexity: O(((r*c)^2).	
// This algorithm is Topological Sort-DFS version based. This algo. makes get() very faster, in the sense all the dependencies are recalculated upon
// every set,sum fns. In recalc. dependencies, we first take the index, that's changed now. Iter. over all indices find indices which directly 
// depend on this changed index, now we do recur. search to find indices which depend on this depedning indices, thus, we do recur. until we 
// find an index, which doesn't have any indices depedning on it,(we keep on pushing indices onto stack).We first eval. this free index, then 
// calc. value for indices depending on it.Thus, we 

// Set: O(((r*c)^2).
// Get: O(1).
// https://leetcode.com/problems/design-excel-sum-formula/solution/
// This link has thorough explanation of this algo.




class Excel {
public:
    vector<vector<int>>v;													// Stores values in different indices.
    unordered_map<int,unordered_map<int,int>>m;								// Tracks depending indices for each index.
    stack<int>st;															// Useful in Topological Sort.
    
    Excel(int H, char W) {													// Setting the grid of given dimentsions.
        int width=W-'A';	
        width++;
        v=vector<vector<int>>(H,vector<int>(width));
        
    }
    
    void set(int r, char c, int val) {										// Setting the given index to given value.
        int rep=r*27+(c-'A'+1);												// A rep. num to indicate both rows and clmns.
        v[r-1][c-'A']=val;													// Setting the value.
        if(m.count(rep)==1){												// If we have a depending indices, remove them.
            m.erase(rep);
        }
        updateDepend(r*27+(c-'A'+1));										// Set the indices on stack based on their dependency.
        executeStack();														// Update the values of all depending indices.
    }
    
    int get(int r, char c) {
        return v[r-1][c-'A'];												// Return the value in grid.
    }
    
    int sum(int r, char c, vector<string> rln) {							// Assign sum/value at given index.
        int total=0;
        m.erase(r*27+(c-'A'+1));											// Removing any previous dependcy list.
        createDepend(r,c,rln);												// Create new dependency list.
        total=calculateSum(r*27+(c-'A'+1));									// Calc. sum from indices on which curr. depend on.
        v[r-1][c-'A']=total;												// Assigning total value.
        updateDepend(r*27+(c-'A'+1));										// Update all depending indices.
        executeStack();
        return total;														// Return the new value in that index.
    }
    
    void createDepend(int row, char clmn,vector<string>&rln){				// Create new dependency list.
        
        for(int i=0;i<rln.size();i++){										// Iter. through dependency vector.
            // cout<<"Curr. index: "<<i<<endl;
            string s=rln[i];
            auto pos=s.find(':');
            if(pos==s.npos){												// If it's only a single index.
                // cout<<"single cell"<<endl;
                char col=s[0];
                int r=stoi(s.substr(1,s.length()-1));
                // cout<<"row: "<<r<<" and col: "<<col<<endl;
                m[row*27+(clmn-'A'+1)][r*27+(col-'A'+1)]++;
            }
            else{															// If it's a range of indices.
                int r1,r2;	
                char c1,c2;
                c1=s[0];
                c2=s[pos+1];
                r1=stoi(s.substr(1,pos-1));
                // cout<<"r1: "<<r1<<endl;
                r2=stoi(s.substr(pos+2,s.length()-2-pos));
                // cout<<"r2: "<<r2<<endl;
                for(int i=r1;i<=r2;i++){
                    for(char c=c1;c<=c2;c++){
                        // cout<<"row: "<<i<<" and col: "<<c<<endl;
                        m[row*27+(clmn-'A'+1)][i*27+(c-'A'+1)]++;
                    }
                }
            }
        }    
    }
    
    
    void updateDepend(int rep){												// Push indices onto stack based on dependency.						
        // cout<<"updateDepend"<<endl;
        // int rep=row*27+(clmn-'A'+1);
        for(auto it=m.begin();it!=m.end();it++){							// Iter. over all dependency formulas.
            if(it->second.count(rep)==1) updateDepend(it->first);    		// If we find curr. rep, recur. update the depending index.
            st.push(it->first);												// Push curr. index onto top of stack.
        }
        // st.push(rep);
        
    }
    
    void executeStack(){													// Reevaluate values of indices based on dependency.
        while(!st.empty()){													// Until stack is empty.
            int curr=st.top();
            st.pop();
            if(m.count(curr)==1){											// If we have a depending list, calc. sum and update the index.
                calculateSum(curr);
            }
        }
        
    }
    
    int calculateSum(int rep){												// Calc. the sum/value of given index.
        // cout<<"inside the calc. sum"<<endl;
        int row=rep/27;
        int clmn=rep%27;
        // cout<<"row: "<<row<<" and clmn: "<<clmn<<endl;
        int total=0;
        for(auto it=m[rep].begin();it!=m[rep].end();it++){					// Iter. over all indices on which curr. index depends on.
            // cout<<"curr. cell row: "<<(it->first)/27<<" and clmn: "<<(it->first)%27<<endl;
            total+=v[it->first/27-1][it->first%27-1]*it->second;
        }
        // cout<<"total: "<<total<<endl;
        v[row-1][clmn-1]=total;												// Assigning the calc. sum.
        return total;														// Returning the calc. sum.
    }
    
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */