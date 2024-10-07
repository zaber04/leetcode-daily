class Solution {
public:
    static int minLength(string& s) {
        const int n=s.size();
        if (n<2) return n;
        string t=string(1, s[0]);
        for(int i=1; i<n; i++){
            if (!t.empty() &&((t.back()=='A' && s[i]=='B') ||
                (t.back()=='C' && s[i]=='D'))) t.pop_back();
            else t.push_back(s[i]);
        }  
        return t.size();  
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();