/*
    Given n diff songs, goal # of songs, & an int k:
        Every song is played at least once
        Song can only be played again if k other songs have played
    Return the number of possible playlists that can be created
    Ex. n = 3, goal = 3, k = 1 -> 6 [1,2,3], [1,3,2], [2,1,3], ...

    For every prev song: either played a song for the 1st time or didn't
        If yes, we had dp[i-1][j-1] x (diffSongs) ways to choose it
        If no, repeat song, had dp[i][j-1] x (diffSongs - k) ways

    Time: O(n x goal)
    Space: O(n x goal)
*/

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        return (int) dfs(n, goal, k);
    }
private:
    int mod = pow(10, 9) + 7;
    // {(diff songs left, total songs listened to) -> # of playlists}
    map<pair<int, int>, long> dp;
    
    long dfs(int diffSongs, int total, int k) {
        if (diffSongs == 0 || total == 0) {
            return 0;
        }
        if (diffSongs == 1 && total == 1) {
            return 1;
        }
        if (dp.find({diffSongs, total}) != dp.end()) {
            return dp[{diffSongs, total}];
        }
        
        long songs = dfs(diffSongs - 1, total - 1, k) * diffSongs;
        if (diffSongs > k) {
            songs += dfs(diffSongs, total - 1, k) * (diffSongs - k);
        }
        dp[{diffSongs, total}] = songs % mod;
        return dp[{diffSongs, total}];
    }
};
