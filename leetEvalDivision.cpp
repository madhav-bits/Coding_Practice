/*
*
//**********************************************************399. Evaluate Division.***************************************************

Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). 
Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , 
where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[ ["a","b"],["b","c"] ]
[2.0,3.0]
[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]




[["a","b"],["e","f"],["b","e"]]
[3.4,1.4,2.3]
[["b","a"],["a","f"],["f","f"],["e","e"],["c","c"],["a","c"],["f","e"]]



[["a","b"],["c","d"]]
[1.0,1.0]
[["a","c"],["b","d"],["b","a"],["d","c"]]


[["x1","x2"],["x2","x3"],["x1","x4"],["x2","x5"]]
[3.0,0.5,3.4,5.6]
[["x2","x4"],["x1","x5"],["x1","x3"],["x5","x5"],["x5","x1"],["x3","x4"],["x4","x3"],["x6","x6"],["x0","x0"]]




// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).	Edges=N^2

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	Edges=N^2	
// This algorithm is DFS oriented. We start from the beginning(Numerator), we travel through it's all adjacent nodes in Depth First way. If we 
// encounter a Numer/Denom. pair which has been calculate, then we return the value directly. This way we reach the dest./Denom in query. If we 
// unable to reach the Denom., then we return INT_MAX. We save into Map, calc. which are not INT_MAX(As they are hinderances in the earlier iter.
//  based on the travelled path). After exiting from the entire recursion, if the extracted val. is INT_MAX, we return -1, if not we return 
// the obtained value.




class Solution {
public:
    
    double calcValue(map<string, vector<string>> &graph, map<pair<string, string>, double> &m,string p, string q, map<string, int> travel){
        //cout<<"INside the fn. with p: "<<p<<" and q: "<<q<<endl;
        travel[p]=1;																		// Updating the travelled curr. path map.
        pair<string, string> qsn=make_pair(p,q);
        if(graph.count(p)==1 && p==q) return 1.0;											// If Numer/Denom. are same, return 1.
        if(m.count(qsn)==1){																// If pair exists in map, return that value.
            //cout<<"Query in map."<<endl;
            return m[qsn];
        } 
        if(m.count(make_pair(q,p))==1){														// If inv. pair exists, then return inv. value.
            //cout<<"Reverse found."<<m[make_pair(q,p)]<<endl;
            return 1.0/m[make_pair(q,p)];
        } 
           
        double minm=INT_MAX;
        //cout<<"NO. of edges is: "<<graph[p].size()<<endl;
        for(int i=0;i<graph[p].size();i++){													// DFS way iterating through all edges.
            if(p==graph[p][i] || travel.count(graph[p][i])==1) continue;					// Avoiding loop in the curr. path travelled.
            double val1=m[make_pair(p,graph[p][i])];
            double val2=calcValue(graph, m,graph[p][i], q, travel);
            if(val2!=INT_MAX)
                minm=min(minm,  val1* val2);												// Maintaining the min. value.
        }
        if(minm!=INT_MAX)																	// Updating the Hash Map with values.
            m[make_pair(p,q)]=minm;
        //cout<<"Returning minm where src: "<<p<<" is: "<<minm<<endl;
        return minm;																		// Returning the minm. value.
    }
    
    vector<double> calcEquation(vector<pair<string, string>> eq, vector<double>& val, vector<pair<string, string>> quer) {
        vector<double> res;
        map<pair<string, string>, double> m;												// Keeps track of edges values.
        map<string, vector<string>>graph;													// Maintains the graph.
        map<string, int> travel;															// Keeps tracks of path travelled.
        for(int i=0;i<val.size();i++){
            //cout<<"Pushing val. of first: "<<eq[i].first<<" and second: "<<eq[i].second<<" with val: "<<val[i]<<endl;
            m[eq[i]]=val[i];																// Forming the val. of edges.
            //if(eq[i].first !=eq[i].second)
            graph[eq[i].first].push_back(eq[i].second);										// Forming the graph with edges.
            graph[eq[i].second].push_back(eq[i].first);										// Forming the graph with edges opp. drn(Undire.).
            m[make_pair(eq[i].second, eq[i].first)]=1.0/val[i];								// Forming the val. of edges.
        }
        
        //cout<<"Starting queries: "<<endl;
        for(int i=0;i<quer.size();i++){														// Going through all queries.
            //cout<<"Query number: "<<i<<endl;
            double ans=calcValue(graph, m,quer[i].first, quer[i].second, travel);
            if(ans==INT_MAX) res.push_back(-1);												// If answer not found, return -1.
            else 																			// If answer found, return the value.
                res.push_back(ans);
        }
        return res;
        
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(N^2).	Edges=N^2	
// This algorithm is based on forming sets of related values(SETS). But, was not able to implement with more than 1 set. This passes 10/11 test
// cases. Here, we assign values to all variables in a set w.r.to a particular variable. If we have >1 sets, I am not able to find out a way to
// handle that scenario.





class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> eq, vector<double>& val, vector<pair<string, string>> quer) {
        vector<double> res;
        map<string, double>m, pres, occur;
        queue<vector<string>> q;															// Stores pairs to resolved/ assigned values later.
        for(int i=0;i<val.size();i++){
            pres[eq[i].first]+=1; pres[eq[i].second]+=1;
            occur[eq[i].first]+=1; occur[eq[i].second]+=1;									// Keeps track of no. of occurances of node.
            
        }
        
        if(val.size()!=0){																	// Setting up all values wrto this value.
            m[eq[0].first]=val[0];
            m[eq[0].second]=1;
        }
        
        for(int i=1;i<val.size();i++){
            if(m.count(eq[i].first)==1){
                m[eq[i].second]=m[eq[i].first]/val[i];
            }
            else if(m.count(eq[i].second)==1){
                m[eq[i].first]=m[eq[i].second]*val[i];
            }
            else if(occur[eq[i].first]>1 || occur[eq[i].second]>1){							// Wait for denom. to get assigned first.
                q.push({eq[i].first, eq[i].second, to_string(val[i])});
            }
            else if(occur[eq[i].first]==1 && occur[eq[i].second]==1){
                m[eq[i].first]=val[i];
                m[eq[i].second]=1;
            }
        }
        
        while(!q.empty()){																	// Assigning the rem. queue values.
            vector<string> p;
            p=q.front();
            //cout<<"Assigning value to: "<<p[0]<<" and "<<p[1]<<" and value: "<<stod(p[2])<<endl;
            if(m.count(p[0])==1){
                //cout<<"Assigning val. to "<<p[1]<<endl;
                m[p[1]]=m[p[0]]/stod(p[2]);
            }
            else if(m.count(p[1])==1){
                //cout<<"Assigning val. to "<<p[0]<<endl;
                m[p[0]]=m[p[1]]*stoi(p[2]);
            }
            q.pop();
        }
        
        
        // for(auto it=m.begin();it!=m.end();it++){
        //     cout<<"The char is: "<<it->first<<" and the value is: "<<it->second<<endl;
        // }
        
        for(int i=0;i<quer.size();i++){														// Going through queries.
            //cout<<"Curr. strings are numer: "<<quer[i].first<<" and denom: "<< quer[i].second<<endl;
            double numer, denom;
            if(m.count(quer[i].first)==0 || m.count(quer[i].second)==0) res.push_back(-1.0);
            else{																			// Calc. result from Numer./Denom. stored in map.
                numer=m[quer[i].first];
                denom=m[quer[i].second];
                res.push_back(numer/denom);
            }
        }
        
        return res;
    }
};















//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+elogn).												//  Since, we only done path compression, query would take logn time.
// Space Complexity: O(n).	Edges=N^2
// This is Union-Find solution. Where, node is numerator and parent is the denominator where vals array stores value that child is greater than 
// parent node. child val=parent node*vals[child]
// Here, the cost of a node to it's core-parent is re-evaluted while making path compression while searching for core-parent of a 
// node(getParent function).







class Solution {
public:
    
    
    string getParent(unordered_map<string,string>&parent, unordered_map<string,double>&vals, string node){
        if(parent[node]==node) return node;
        string par=parent[node];
        parent[node]=getParent(parent, vals, parent[node]);
        vals[node]=vals[node]*vals[par];
        return parent[node];
    }
    
    vector<double> calcEquation(vector<pair<string, string>> v, vector<double>& u, vector<pair<string, string>> queries) {
        vector<double>res;
        unordered_map<string,string>parent;
        unordered_map<string,double>vals;
        for(int i=0;i<v.size();i++){
            if(parent.count(v[i].first)==0){
                parent[v[i].first]=v[i].first;
                vals[v[i].first]=1;
            }
            if(parent.count(v[i].second)==0){
                parent[v[i].second]=v[i].second;
                vals[v[i].second]=1;
            }
            string parA=getParent(parent, vals, v[i].first);
            string parB=getParent(parent, vals, v[i].second);
            parent[parA]=parB;
            vals[parA]=vals[v[i].second]*u[i]/vals[v[i].first];
        }
        
        for(int i=0;i<queries.size();i++){
            if(parent.count(queries[i].first)==0 || parent.count(queries[i].second)==0){
                res.push_back(-1.0);
                continue;
            }
            string parA=getParent(parent, vals, queries[i].first);
            string parB=getParent(parent, vals, queries[i].second);
            if(parA!=parB){
                res.push_back(-1.0);
                continue;
            }
            // cout<<"number: "<<vals[queries[i].first]<<" and denom: "<<vals[queries[i].second]<<endl;
            res.push_back(vals[queries[i].first]/vals[queries[i].second]);
        }
        return res;
    }
};


/*


[ ["a","b"],["b","c"],["c","a"] ]
[2.0,3.0,1.0]
[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]



[ ["a","b"],["b","c"] ]
[2.0,3.0]
[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]

*/