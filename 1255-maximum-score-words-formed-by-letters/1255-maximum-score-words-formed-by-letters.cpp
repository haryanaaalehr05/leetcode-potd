class Solution {
public:
    void backtrack(vector<string>& words, vector<int>& score, vector<int>& count, vector<int>& actualCount, int pos,int tmp,int &ans) {
        for(int i=0;i<26;i++) 
        if(actualCount[i]>count[i]) {
            return;
        }
        ans=max(ans,tmp);
        for(int i=pos;i<words.size();i++ ) {
            for(auto& c:words[i]) {
                actualCount[c-'a']++;
                tmp+=score[c-'a'];
            }
            backtrack(words,score,count,actualCount,i+1,tmp,ans);
            for(auto &c : words[i]) {
                actualCount[c-'a']--;
                tmp-=score[c-'a'];
            }
        }
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>count(26,0),actualCount(26,0); 
        for(auto &c :letters) {
            count[c-'a']++;
        }
        int ans=0;
        backtrack(words,score,count,actualCount,0,0,ans);
        return ans;
    }
};