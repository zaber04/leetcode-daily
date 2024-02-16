static int speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	return 0;
}();

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> hashmap;

        for (int num : arr) {
            hashmap[num]++;
        }

        priority_queue<int, vector<int>, greater<int>> minheap;
        for (auto it : hashmap) {
            minheap.push(it.second);
        }

        int removed = 0;

        while (!minheap.empty()) {
            removed += minheap.top();

            if (removed > k) {
                return minheap.size();
            }

            minheap.pop();
        }

        return 0;
    }
};