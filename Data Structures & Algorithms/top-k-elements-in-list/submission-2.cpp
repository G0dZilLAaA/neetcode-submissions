class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> sol;
        unordered_map<int, int> hash;

        priority_queue<int, vector<int>, greater<int>> heap;

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        for (auto curr : hash) {
            int freq = curr.second;

            if (heap.size() < k) {
                heap.push(freq);
            }
            else if (heap.top() < freq) {
                heap.pop();
                heap.push(freq);
            }
        }

        int minFreq = heap.top();

        for (auto curr : hash) {
            if (curr.second >= minFreq) {
                sol.push_back(curr.first);
            }
        }

        return sol;
    }
};