/*
    Recipes are made from ingredients, which require supplies, return list of all receipts that can be made
    Ex. recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"] -> ["bread"]

    Ingredient -> recipes adj list, supplies queue, track indegree (availability)

    Time: O(r x i x s)
    Space: O(r + i + s)
*/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // track dependencies
        map<string, int> indegree;
        for (int i = 0; i < ingredients.size(); i++) {
            for (int j = 0; j < ingredients[i].size(); j++) {
                // this recipe needs this ingredient, add to adj list
                m[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        
        queue<string> q;
        for (int i = 0; i < supplies.size(); i++) {
            // supplies that are available to be used by others
            if (indegree[supplies[i]] == 0) {
                q.push(supplies[i]);
            }
        }
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            for (int i = 0; i < m[curr].size(); i++) {
                string recipe = m[curr][i];
                indegree[recipe]--;
                // all supplies retrieved, can now be used for others
                if (indegree[recipe] == 0) {
                    q.push(recipe);
                }
            }
        }
        
        vector<string> result;
        for (int i = 0; i < recipes.size(); i++) {
            // all recipes that can be made
            if (indegree[recipes[i]] == 0) {
                result.push_back(recipes[i]);
            }
        }
        return result;
    }
private:
    // {ingredient -> list of recipes that need this ingredient}
    unordered_map<string, vector<string>> m;
};
