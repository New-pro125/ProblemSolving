class Solution {
public:
    int minimumPushes(string word) {
        std::vector<int>start(4),freq(26);
        int cnt = 0;
        int res = 0;
        for(size_t i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        for(int i=0;i<26;i++){
            if(freq[i])
                res +=freq[i] *(cnt/8+1),cnt++;
        }
        return res;
    }
};