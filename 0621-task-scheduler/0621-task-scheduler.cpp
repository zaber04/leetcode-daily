class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25] - 1;

        int idleSlots = maxFreq * n;

         // Iterate over the frequency array from the second highest frequency to the lowest frequency
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            // Subtract the minimum of the maximum frequency and the current frequency from the idle slots
            idleSlots -= min(maxFreq, freq[i]);
        }

        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};