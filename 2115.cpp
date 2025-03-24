class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, int> recipes_mp;
        map<string, int> recipes_sz;
        map<string, vector<string>> ingred_mp;
        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            recipes_mp[recipe] = 0;
            recipes_sz[recipe] = ingredients[i].size();
            for (int j = 0; j < ingredients[i].size(); j++) {
                string ingredient = ingredients[i][j];
                ingred_mp[ingredient].push_back(recipe);
            }
        }

        for (int i = 0; i < supplies.size(); i++) {
            string supply = supplies[i];
            for (auto recipe : ingred_mp[supply]) {
                recipes_mp[recipe]++;
                if (recipes_mp[recipe] == recipes_sz[recipe]) {
                    supplies.push_back(recipe);
                }
            }
        }


        vector<string> ans;
        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            if (recipes_mp[recipe] == ingredients[i].size()) 
                ans.push_back(recipe);
        }

        return ans;
         
    }
};
