/*
*
//******************************************************635. Design Log Storage System.***********************************************

You are given several logs that each log contains a unique id and timestamp. Timestamp is a string that has the following 
format: Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59. All domains are zero-padded decimal numbers.

Design a log storage system to implement the following functions:

void Put(int id, string timestamp): Given a log's unique id and timestamp, store the log in your storage system.


int[] Retrieve(String start, String end, String granularity): Return the id of logs whose timestamps are within the range from start to end. Start 
and end all have the same format as timestamp. However, granularity means the time level for consideration. For example, 
start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", granularity = "Day", it means that we need to find the logs within the range from Jan. 
1st 2017 to Jan. 2nd 2017.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["LogSystem","put","put","put","retrieve","retrieve"]
[[],[1,"2017:01:01:23:59:59"],[2,"2017:01:01:22:59:59"],[3,"2016:01:01:00:00:00"],["2017:01:01:01:01:01","2017:01:01:23:00:00","Year"],["2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. We work on timestamps.We iterate over all keys, pick only those that are in the range of min. and max timestamps 
// allowed. We extract the substr of all keys till the granular part is covered, as rest str isn't required in calc. whether curr. key is in 
// range or not.








class LogSystem {
public:
    unordered_map<string,int>m;												// Links timestamp to id.
    unordered_map<string,int>rln;											// Links granular to their psn in timestamp.
    LogSystem() {
        rln["Year"]=4; rln["Month"]=7; rln["Day"]=10; rln["Hour"]=13; rln["Minute"]=16; rln["Second"]=19;
    }
    
    void put(int id, string timestamp) {
        m[timestamp]=id;													// Pushing the timestamp,id pair to map.
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int>res;														// Final result vector to store ids.
        int len=rln[gra];													// Extracting index of granular in timestamp.	
        string low=s.substr(0,len);											// Calc. str for lower limit.
        string high=e.substr(0,len);										// Calc. str for upper limit.
        // cout<<"low: "<<low<<endl;
        // cout<<"High: "<<high<<endl;
        for(auto it=m.begin();it!=m.end();it++){							// Iter. through entire array for suitable timestamps.
            string temp=it->first.substr(0,len);							// Extract timestamp till granular part from curr. iterator key.
            // cout<<"Extracted str: "<<temp<<endl;
            if(temp>=low && temp<=high){									// If curr. key is in date range.
                // cout<<"In the range timestamp: "<<it->first<<endl;
                res.push_back(it->second);									// Push id into final result vector.
            }
        }	
        return res;															// Returning the final result vector.
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */