class Solution {
    int firstApproach(string text, string form = "balloon") {
        int lenP = text.length();
        int lenC = form.length();

        if (lenP < lenC) {
            return 0;
        }

        unordered_map<char, int> consumer;
        for (int i = 0; i < lenC; i++) {
            consumer[form[i]]++;
        }

        unordered_map<char, int> producer;
        for (int i = 0; i < lenP; i++) {
            producer[text[i]]++;
        }

        int ret = INT_MAX;

        for (auto it:consumer) {
            if (producer.find(it.first) != producer.end()) {
                int temp = producer.find(it.first)->second / it.second;
                ret = min(ret, temp);
            } else {
                return 0;
            }
        }


        return ret;
    }

    int secondApproach(string text, string form = "balloon") {
        int lenP = text.length();
        int lenC = form.length();

        if (lenP < lenC) {
            return 0;
        }

        vector<int> consumer(26, 0);
        for (int i = 0; i < lenC; i++) {
            consumer[form[i] - 'a']++;
        }

        vector<int> producer(26, 0);
        for (int i = 0; i < lenP; i++) {
            producer[text[i] - 'a']++;
        }

        int ret = INT_MAX;

        for (int i = 0; i < 26; i++) {
            // avoid zero division
            if (consumer[i]) {
                ret = min(ret, producer[i] / consumer[i]);

                // if ret is ever 0 --> we can return
                if (ret == 0) {
                    return 0;
                }
            }
        }

        return ret;
    }
public:
    int maxNumberOfBalloons(string text) {
        return firstApproach(text);
        // return secondApproach(text);
    }
};