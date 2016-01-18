#include <vector>

using namespace std;


vector<vector<int> > csk(vector<int>& candidates, int k, int target) {
    vector<vector<int> > ans;
    int size = candidates.size();
    if (target < candidates[k] ) return ans;
    for (int i = k; i < size; i++) {
        if (target < candidates[i]) break;
        if (target == candidates[i]) {
            vector<int> now;
            now.push_back(candidates[i]);
            ans.push_back(now);
            break;
        } else {
            int dif = target - candidates[i];
            vector<vector<int> > now2 = csk(candidates, i,dif);
            for (int j = 0; j< now2.size(); j++) {
                now2[j].push_back(candidates[i]);
                ans.push_back(now2[j]);
            }
        }
    }
    
    return ans;
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<vector<int>>ans = csk(candidates, 0, target);
  for (int i = 0; i < ans.size(); i++) {
    sort(ans[i].begin(), ans[i].end());
  }
  return ans;
}
