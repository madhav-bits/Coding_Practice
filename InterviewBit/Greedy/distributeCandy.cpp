/*
*
//**************************************************************Distribute Candy.*******************************************************

https://www.interviewbit.com/problems/distribute-candy/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


6 4 2 9 3 4 8


8 5 9 2 10 3 2 4 6


4 3 5 9 2




457 -255 369 319 77 128 -202 -147 282 -26 -489 -443 -401 385 465 -134 126 304 179 16 112 473 -467 279 -233 66 76 408 148 -369 328 138 -164 492 -276 -326 170 168 189 13 383 341 426 219 337 -62 -197 263 338 -324 261 273 -74 -8 -133 318 -100 487 -196 -465 -495 -136 94 -201 491 204 323 156 -337 -99 115 179 184 -249 76 -396 265 500 -83 270 438 -418 401 -184 -247 -203 190 191 -282 -248 465 146 7 -381 326 -409 474 186 -206 447 17 156 -273 381 -307 -206 164 -147 58 -224 284 204 267 123 141 -8 225 -246 12 399 -261 -104 191 390 152 313 -91 8 -476 -363 -183 -280 -282 -431 366 89 -166 -257 132 98 -387 389 -219 -332 227 386 -33 361 -308 -494 -33 110 423 -465 -417 496 -333 -259 402 36 380 -385 -329 283 389 396 -161 466 -405 -293 442 259 377 -386 -386 329 204 438 346 -185 -401 -219 213 351 -18 -20 364 319 187 197 122 -182 -126 -211 -448 44 -360 -345 -147 480 -387 222 92 -262 -409 163 323 -291 -61 -431 -288 -309 -490 -494 328 -207 398 475 -228 -37 44 227 -371 -91 -440 220 39 -73 80 -189 37 94 -96 -400 -380 172 -179 -442 -119 411 -184 218 -18 170 430 -157 345 418 390 -39 -85 216 -197 -421 328 -311 160 432 104 -419 -140 -115 -202 58 415 473 -87 475 430 114 -314 430 -419 375 258 255 42 -63 54 -352 -337 -180 -31 441 -382 -176 209 -137 171 -89 155 421 308 -153 254 -210 -245 373 -435 -29 -398 326 297 81 -157 254 52 479 356 -497 -16 109 -353 -20 -122 -172 23 20 -344 203 372 -306 -9 238 -190 495 9 -2 125 150 -180 -340 -1 -347 -269 -181 -15 83 -304 -365 490 -475 161 422 440 -414 380 -446 -404 -352 -144 -297 -62 -23 -223 359 127 183 -20 93 -285 -477 223 1 131 -359 -74 321 197 452 -338 367 -337 183 -41 218 -75 -212 208 188 -38 91 332 388 -185 -247 405 -390 -371 313 -471 457 307 494 -467 -225 -3 -271 -164 -120 101 385 -12 234 -368 -317 167 241 -494 -279 -288 452 -499 372 464 234 16 40 264 -474 -400 429 33 495 -285 201 190 328 127 286 312 100 -24 409 -392 183 -69 -352 -56 -304 -261 -296 -140 453 253 -215 195 288 -300 10 -104 -491 275 -275 175 24 387 408


4 5 6 6 6




// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Greedy based algorithm. Here, since we are assigning chocolates based on rating, we sort the children based on their rating
// we first iter. from least to highest rated children. When, we are on child with rating 'k'  whose index is 'i', we check it's neighbors
// and compare the values, and try to assign higher value than neighbors, whose value is less than that of at curr. index.








struct comp{
    bool operator()(pair<int,int>lt, pair<int,int>rt){						// Sorts value based on their rating.
        return (lt.first>rt.first ||(lt.first==rt.first && lt.second<rt.second));
    }    
};

int Solution::candy(vector<int> &v) {
    vector<int>vals(v.size(), 0);											// Array to store values assigned at each index.
    priority_queue<pair<int,int>,vector<pair<int,int>>, comp>pq;			// To sort child based on their ratings.
    for(int i=0;i<v.size();i++){											// Push into PQ.
        pq.push({v[i], i});
    }
    int res=0;
    while(!pq.empty()){														// Till all ratings are assigned chocs.
        int val=pq.top().first;
        int index=pq.top().second;
        // cout<<"val: "<<val<<" and index: "<<index<<endl;
        pq.pop();
        int addn=0;															// The choc. we are gonna assign to curr. index.
        if(index>0 && v[index]>v[index-1]) addn=vals[index-1];				// If curr. index is >prev. index, then take it's value.
        
        if(index<v.size()-1 && v[index]>v[index+1]) addn=max(addn, vals[index+1]);// If curr. value>next value, then update value to be assigned.
        vals[index]=addn+1;													// Update the temp. array with #choc. to be given at that index.
    }
    // cout<<endl<<endl;
    for(int i=0;i<v.size();i++){											// Iter. the final array and adding the chocs distributed.
        // cout<<"val: "<<v[i]<<" and candy: "<<vals[i]<<endl;
        res+=vals[i];    
    } 
    return res;																// Returning the total #chocs distributed.
}











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Greedy based algorithm. Here, since we are assigning chocolates based on rating, we sort the children based on their rating
// we first iter. from least to highest rated children. When, we are on child with rating 'k'  whose index is 'i', we check it's neighbors
// and compare the values, and try to assign higher value than neighbors, whose value is less than that of at curr. index.




// This is the code, which i initially wrote, which is slightly modified/improvised in above algo.

// The main part, where we loose track of algo. is that, if for index if it's indices have same value as itself, then that index can be assigned 
// a value of '1. I had spent almost 1.5 hrs on this step(Illogical requirement).






struct comp{
    bool operator()(pair<int,int>lt, pair<int,int>rt){
        return (lt.first>rt.first ||(lt.first==rt.first && lt.second<rt.second));
    }    
};
 
int Solution::candy(vector<int> &v) {
    vector<int>vals(v.size(), 0);
    priority_queue<pair<int,int>,vector<pair<int,int>>, comp>pq;
    for(int i=0;i<v.size();i++){
        pq.push({v[i], i});
    }
    int res=0;
    while(!pq.empty()){
        int val=pq.top().first;
        int index=pq.top().second;
        // cout<<"val: "<<val<<" and index: "<<index<<endl;
        pq.pop();
        vals[index]=1;														// Defaultly assigns value of 1 to every index. This covers equal
																			// values in adj. indices cases.
        if(index==0 && vals[1]==0) vals[0]=1;
        else if(index==0 && v[0]>v[1]) vals[0]=vals[1]+1;
        
        if(index>0 && index<v.size()-1 && v[index]>v[index+1]) vals[index]=max(vals[index], vals[index+1]+1);
        if(index>0 && index<v.size()-1 && v[index]>v[index-1]) vals[index]=max(vals[index], vals[index-1]+1);
        
        
        if(index==v.size()-1 && vals[index-1]==0) vals[index]=1;
        else if(index==v.size()-1 && v[index-1]<v[index]) vals[index]=vals[index-1]+1;
    }
    // cout<<endl<<endl;
    for(int i=0;i<v.size();i++){
        // cout<<"val: "<<v[i]<<" and candy: "<<vals[i]<<endl;
        res+=vals[i];    
    } 
    return res;
}