/*
*
//**********************************************************353. Design Snake Game.***************************************************

Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:
Given width = 3, height = 2, and food = [[1,2],[0,1]].

Snake snake = new Snake(width, height, food);

Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|

snake.move("R"); -> Returns 0

| |S| |
| | |F|

snake.move("D"); -> Returns 0

| | | |
| |S|F|

snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|

snake.move("U"); -> Returns 1

| |F|S|
| | |S|

snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|

snake.move("U"); -> Returns -1 (Game over because snake collides with border)

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["SnakeGame","move","move","move","move","move","move"]
[[3,2,[[1,2],[0,1]]],["R"],["D"],["R"],["U"],["L"],["U"]]



["SnakeGame","move","move","move","move","move","move"]
[[6,4,[[1,2],[0,1]]],["R"],["D"],["R"],["U"],["L"],["U"]]




["SnakeGame","move","move","move","move","move","move","move","move","move","move"]
[[6,4,[[2,0],[4,2]]],["R"],["D"],["L"],["D"],["D"],["D"],["R"],["U"],["R"],["D"]]




["SnakeGame","move","move","move","move","move","move","move","move","move","move"]
[[6,4,[[2,0],[3,1],[4,2]]],["R"],["D"],["L"],["D"],["D"],["D"],["R"],["U"],["R"],["D"]]



["SnakeGame","move","move","move","move","move","move","move","move","move","move","move","move","move","move"]
[[6,4,[[2,0],[3,1],[3,2],[3,3],[2,3],[2,2],[3,2]]],["R"],["D"],["L"],["D"],["D"],["D"],["R"],["U"],["R"],["R"],["R"],["U"],["L"],["D"]]


["SnakeGame","move","move","move","move","move","move","move","move","move","move","move","move","move","move"]
[[6,4,[[2,0],[3,0],[3,1],[3,2],[3,3],[2,3],[2,2],[3,2]]],["R"],["D"],["L"],["D"],["D"],["D"],["R"],["U"],["R"],["R"],["R"],["U"],["L"],["D"]]


["SnakeGame","move","move"]
[[3,2,[]],["D","R"]]


["SnakeGame","move"]
[[3,2,[]],["U"]]


["SnakeGame","move","move"]
[[2,2,[[0,1]]],["R"],["D"]]




// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is Queue, HashMap based. We store the indices of the snake in a queue and also in Map(Indices are stored in string form). 
// Whenever a move is made, we check there exists a food to look for. If the next indices are out of boundary or if the next move crosses/bites
// the body of the snake, then we return -1. When a normal move is made, we pop the tail of snake(Queue's front) and insert the next move. If food 
// found, we don't pop the tail(As, snake's length inc. by 1). If their exists no food to look for we make the move as usual and return curr. 
// score.








class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    int hei,wid;															// The height and width of board.
    queue<pair<int,int>>q;													// Stores snake's body's indices.
    unordered_map<string,int>m;												// Stores snake's body's indices in string format.
    vector<pair<int,int>>v;													// Stores the food indices.
    int index=0,score=0;													// Track next food's index and score of the game.
    pair<int,int>curr;														// Curr. location of the head of snake.
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        hei=height;
        wid=width;
        q.push({0,0});
        string s="0#0";														// Stored in map in row+"#"+clmn format.
        m[s]=1;
        v=food;
        curr=make_pair(0,0);												// Initiaizing start.
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int,int>target;
        if(index<v.size())													// If next food exists.
            target=v[index];
        pair<int,int>next;													// Stores next move's index.
        // cout<<"Curr. row: "<<curr.first<<" and clmn: "<<curr.second<<endl;
        if(direction=="U") next=make_pair(curr.first-1,curr.second);		// 4 moves as mentioned in qsn.
        else if(direction=="D") next=make_pair(curr.first+1,curr.second);
        else if(direction=="L") next=make_pair(curr.first,curr.second-1);
        else if(direction=="R") next=make_pair(curr.first,curr.second+1);
        string str=to_string(next.first)+"#"+to_string(next.second);		// String rep. of next move's index.
        // cout<<"next str: "<<str<<endl;
        if(index<v.size() && next.first==target.first && next.second==target.second){// If food found.
            // cout<<"Food found at row: "<<target.first<<" and clmn: "<<target.second<<endl;
            index++;														// Inc. the next food iterator.
            score++;														// Inc. the score.
        }
        else{																// Nomral move is made.
            int row=q.front().first, clmn=q.front().second;                 // Tail of the snake.
            string s=to_string(row)+"#"+to_string(clmn);
            m.erase(s);                                                     // Removing tail from map.
            q.pop();														// Removing tail from queue.
        }
		if(next.first<0 || next.first>=hei || next.second<0 || next.second>=wid|| m.count(str)==1) return -1;// If invalid index/bite snake.
        q.push({next.first,next.second});									// Push next move's index into queue.
        // cout<<"CUrr. updated to next."<<next.first<<" and clmn: "<<next.second<<endl;
        curr=next;															// Updating curr. var.
        m[str]=1;															// Pushing next move into map.
        return score;														// Return the score.
    }
};  

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */