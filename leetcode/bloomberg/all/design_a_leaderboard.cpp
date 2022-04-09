// Hash map {players -> scores}, map {scores -> count}

// Time: O(K log n)
// Space: O(n)

class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (players.find(playerId) != players.end()) {
            scores[players[playerId]]--;
        }
        players[playerId] += score;
        scores[players[playerId]]++;
    }
    
    int top(int K) {
        int result = 0;
        
        for (auto it = scores.end(); K > 0; it--) {
            int count = min(K, it->second);
            result += it->first * count;
            
            K -= it->second;
            if (it == scores.begin()) {
                break;
            }
        }
        
        return result;
    }
    
    void reset(int playerId) {
        scores[players[playerId]]--;
        players.erase(playerId);
    }
private:
    // {playerId -> score}
    unordered_map<int, int> players;
    // {score -> # of players who have this score}
    map<int, int> scores;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
