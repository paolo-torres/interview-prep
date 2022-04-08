// Deque for snake + visited hash set for collisions

// Time: O(1)
// Space: O(w x h + n) -> w = width, h = height, n = food size

class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        foodIndex = 0;
        this->food = food;
        snake.push_back({0, 0});
    }
    
    int move(string direction) {
        int xHead = snake.front()[0];
        int yHead = snake.front()[1];
        
        vector<int> tail = snake.back();
        int tailPos = tail[0] * width + tail[1];
        
        snake.pop_back();
        visited.erase(tailPos);
        
        if (direction == "U") {
            xHead--;
        } else if (direction == "D") {
            xHead++;
        } else if (direction == "L") {
            yHead--;
        } else if (direction == "R") {
            yHead++;
        }
        
        int headPos = xHead * width + yHead;
        if (xHead < 0 || xHead >= height || yHead < 0 || yHead >= width || visited.find(headPos) != visited.end()) {
            return -1;
        }
        
        snake.push_front({xHead, yHead});
        visited.insert(headPos);
        
        if (foodIndex < food.size() && food[foodIndex][0] == xHead && food[foodIndex][1] == yHead) {
            snake.push_back(tail);
            visited.insert(tailPos);
            foodIndex++;
        }
        
        return snake.size() - 1;
    }
private:
    int width;
    int height;
    int foodIndex;
    vector<vector<int>> food;
    unordered_set<int> visited;
    deque<vector<int>> snake;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
