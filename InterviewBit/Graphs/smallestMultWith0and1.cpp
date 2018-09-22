/*
*
//********************************************************Smallest Multiple With 0 and 1.*************************************************


https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



4234


55



// Time Complexity: O(A).  													// Depends on the number taken.
// Space Complexity: O(A).

//********************************************************THIS IS NOT IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT IB ACCEPTED CODE.***********************************************
// Time Complexity: O(A).													// Depends on the number taken.					
// Space Complexity: O(A).	
// This algorithm is BFS based. We start from the base of '1', we calc. the rem. and store this rem. in map, such that in the process, whenver
// we get same remainder, we won't push that into the Queue. We push this new remainder into Queue, map tracking visited rems, val array tracking
// char responsible for that rem. We extract rem. from the Queue, append '1'/'0' and calc. new rems, check whether they are visited or not? If 
// not push new rem. into Queue. Also, store the relation b/w rems in visited map. When rem. 0 is reached we call a fn. which travels in 
// reverse direction from rem '0' to rem '1' using visited maps and create result string using val array, after accumulating entire string, we
// reverse it and return it.


// I had tried out Quite a few variations in the solutions, don't know what else does OJ expects. This is the best solution I can come up with.










int isDiv(char ch, int prev, int divi){										// Calc. rem and return it.
    long int rem=0;
    // char s=curr.first;
    rem=prev;
    rem=(rem*10)+(ch-'0');
    rem=rem%divi;
    return rem;
}

string findStr(int rem, unordered_map<int,int>&parent, unordered_map<int,char>&val){// Traversr from rem '0' to rem '1'.
    string res="";        
    // cout<<"rem: "<<rem<<endl;
    while(rem!=1){															// Until source rem '1' is reached.
        // cout<<"Appending char: "<<val[rem]<<endl;
        res+=val[rem];//to_string(val[rem]);
        rem=parent[rem];
        // cout<<"Updated rem: "<<rem<<endl;
    }
    res+='1';																// Append char related to rem '1'.
    // cout<<"Final res: "<<res<<endl;	
    reverse(res.begin(), res.end());										// Reverse the accumulated string.
    return res;																// Return it.
}

string Solution::multiple(int num) {
    if(num==1) return "1";
    queue<int>q;
    set<int>st;
    unordered_map<int,int>parent;											// Stores relation between curr. rem. and next rem.
    unordered_map<int,char>val;												// Stores rln b/w remainder and char resp. for it.
    q.push(1);
    st.insert(1);
    val[1]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        // cout<<"curr: "<<curr<<endl;
        int rem=0;
        rem=isDiv('0', curr, num);											// Append '0' to prev. rem and calc. new rem.
        // parent[rem]=curr;
        if(st.count(rem)==0){												// If remainder not visited.
            parent[rem]=curr;												// Form rln b/w curr. rem and next rem.
            val[rem]='0';													// Stores rln b/w next rem. and char.
            st.insert(rem);													// Mark the remainder as visited.
            q.push(rem);													// Push into Queue.
        }
        if(rem==0) return findStr(rem, parent, val);						// If '0' remainder obtained, then return result string.
        
        rem=isDiv('1', curr, num);
        if(st.count(rem)==0){
            parent[rem]=curr;
            val[rem]='1';
            st.insert(rem);
            q.push(rem);
        }
        if(rem==0) return findStr(rem, parent, val);
    }
    
}












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT IB ACCEPTED CODE.***********************************************
// Time Complexity: O(A).													// Depends on the number taken.					
// Space Complexity: O(A).	
// This algo. is same as the above one, except that here, I had used vectors instead of maps for faster execution to store rln b/w curr. rem
// and next rem and also to store rln b/w next rem. and char responsible for it. Despite using vector, it's throwing TLE errors.

// Don't know what else optimization is OJ expecting.








int isDiv(char ch, int prev, int divi){
    long int rem=0;
    // char s=curr.first;
    rem=prev;
    rem=(rem*10)+(ch-'0');
    rem=rem%divi;
    return rem;
}

string findStr(int rem, vector<int>&parent, vector<char>&val){
    string res="";        
    // cout<<"rem: "<<rem<<endl;
    while(rem!=1){
        // cout<<"Appending char: "<<val[rem]<<endl;
        res+=val[rem];//to_string(val[rem]);
        rem=parent[rem];
        // cout<<"Updated rem: "<<rem<<endl;
    }
    res+='1';
    // cout<<"Final res: "<<res<<endl;
    reverse(res.begin(), res.end());
    return res;
}

string Solution::multiple(int num) {
    if(num==1) return "1";
    queue<int>q;
    set<int>st;
    // unordered_map<int,int>parent;//unordered_map<int,int>&parent, unordered_map<int,char>&val
    // unordered_map<int,char>val;
    vector<int>parent(num,-1);												// Vectors are used instead of maps.
    vector<char>val(num,'a');
    q.push(1);
    st.insert(1);
    val[1]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        // cout<<"curr: "<<curr<<endl;
        int rem=0;
        rem=isDiv('0', curr, num);
        // parent[rem]=curr;
        if(st.count(rem)==0){
            parent[rem]=curr;
            val[rem]='0';
            st.insert(rem);
            q.push(rem);
        }
        if(rem==0) return findStr(rem, parent, val);
        
        rem=isDiv('1', curr, num);
        if(st.count(rem)==0){
            parent[rem]=curr;
            val[rem]='1';
            st.insert(rem);
            q.push(rem);
        }
        if(rem==0) return findStr(rem, parent, val);
    }
    
}

