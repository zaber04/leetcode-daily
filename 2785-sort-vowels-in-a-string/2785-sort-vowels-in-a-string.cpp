class Solution {
    bool isVowel(char ch) {
        char arr[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for(int i = 0; i < 10; i++) {
            if (arr[i] == ch) {
                return true;
            }
        }
        
        return false;
    }

public:
    // counting sort
    string sortVowels(string s) {
        int freq[128] = {0};
        int len = s.size();

        for(int i=0; i<len; i++) {
            if (isVowel(s[i])) {
                freq[(int)s[i]]++;
            }
        }
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                while(freq[idx]==0)idx++;
                s[i]=(char)idx;
                freq[idx]--;
            }
        }

        return s;
    }
};