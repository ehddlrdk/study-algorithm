class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        map<int, int> M;
        int edible = candyType.size() / 2;

        for(auto iter = candyType.begin(); iter != candyType.end(); iter++) {
            M[*iter]++;
        }
        
        int typeN = M.size();
        int answer = typeN > edible ? edible : typeN;
        
        return answer;
    }
};