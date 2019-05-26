//
// Created by so_go on 2019/5/26.
//

#ifndef SRC_WORDBREAK2_H
#define SRC_WORDBREAK2_H

#include<vector>
#include<string>
#include<stack>
using namespace std;

class WordBreak2 {
public:
    //    定义break[i]为前i位是否可拆分的bool数组， 默认空字符串可拆分，即break[0] = 1
    //    break[i] = OR{ break[j] and match(string[j:i)) for j in range[0, i)
    // 定义previous 为前一个可拆分位的位置,
    vector<string> wordBreak2(string s, vector<string>& wordDict) {
        vector<bool> breakable;
        vector<vector<int>> previous;
        breakable.push_back(true);
        bool tmp = true;
        vector<int> tmp_prev;
        previous.push_back(tmp_prev);
        for(unsigned int i = 1; i <= s.size(); i++){
            tmp = false;
            tmp_prev.clear();
            for( unsigned int j = 0; j < i; j++){
                if(breakable[j] && match(s, j, i, wordDict)){
                    tmp = true;
                    tmp_prev.push_back(j);
                }
            }
            breakable.push_back(tmp);
            previous.push_back(tmp_prev);
        }
        // 回溯
        vector<string> sentence;
        vector<string> results;
        if(breakable.back())
            trace(previous, s.size(), s, sentence, results);

        return results;
    }

    bool match(string &s, int start, int end, const vector<string> &wordDict){
        string word;
        for(int i = 0; i < wordDict.size(); i++){
            word = wordDict[i];
            bool ismatch = true;
            if( word.size() != ( end - start ) ){
                ismatch = false;
            }
            else{
                for(int j = 0; j < word.size(); j++)
                    if( word[j] !=  s[start + j] )
                        ismatch = false;
            }

            if(ismatch)
                return true;
        }
        return false;
    }

    void trace(const vector<vector<int>> &prev_node_list, int ind, string &s, vector<string> &sentence, vector<string> &results)
    {
        // 对于当前位置i和前一位置j，将两个位置之间的单词[j, i)列入句子列表，并进入下一轮递归。
        // 截止条件

        if(ind == 0){;
            results.push_back(convert(sentence));
        }
        vector<int> prev_nodes = prev_node_list[ind];
        int prev_ind;
        for(int i = 0; i < prev_nodes.size(); ++i ){
            prev_ind = prev_nodes[i];
            sentence.push_back(s.substr(prev_ind, ind - prev_ind));
            trace(prev_node_list, prev_ind, s, sentence, results);
            sentence.pop_back();
        }
    }

    string convert(vector<string> vec){
        string res = "";
        for(int i = vec.size() - 1; i >= 0; --i) {
            res.append(vec[i] + " ");
        }
        res.pop_back();
        return res;
    }
//    回溯法代码
    /*  超时
    void wordBreak_(const string &s, int ind, const vector<string> &wordDict, vector<string> sentence, vector<string> &results){
//        截止条件
        if(ind == s.size()){
            string res = convert(sentence);
//            cout << res << endl;
            results.push_back(res);
        }

        string word;
//        递归过程
        for(int i = 0; i < wordDict.size(); i++){
            word = wordDict[i];
            if(match(s, ind, word)){
//    		    cout << s << ' ' << ind << ' ' << word << endl;
                sentence.push_back(word);
                wordBreak_(s, ind + word.size(), wordDict, sentence, results);
                sentence.pop_back();
            }
        }
    }


    bool match(const string &s, int start, string &word){
        if(start + word.size() <= s.size()){
            for(int i = 0; i < word.size(); i++){
                if(word[i] != s[start + i])
                    return false;
            }
        }
        else
            return false;
        return true;
    }
    */
};
#endif //SRC_WORDBREAK2_H
