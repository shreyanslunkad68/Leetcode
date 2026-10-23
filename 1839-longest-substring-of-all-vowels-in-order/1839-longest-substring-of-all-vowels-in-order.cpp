class Solution {
public:
    int longestBeautifulSubstring(string word) {
        if (word.size() < 5) return 0;

        int maxLen = 0;
        int currentLen = 1;
        int distinctVowels = 1;

        for (int i = 1; i < word.size(); ++i) {
            if (word[i] >= word[i - 1]) {
                currentLen++;
                if (word[i] > word[i - 1]) {
                    distinctVowels++;
                }
            } else {
                currentLen = 1;
                distinctVowels = 1;
            }

            if (distinctVowels == 5) {
                maxLen = max(maxLen, currentLen);
            }
        }

        return maxLen;
    }
};