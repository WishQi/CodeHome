//
//  main.cpp
//  208. Implement Trie (Prefix Tree)
//
//  Created by Maoqi Li on 2019/8/4.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    char data;
    vector<TrieNode *> children;
    bool isEndingChar;
    TrieNode(char _data) {
        data = _data;
        children = vector<TrieNode *>(26, NULL);
        isEndingChar = false;
    }
};

class Trie {
private:
    TrieNode *_root;
public:
    /** Initialize your data structure here. */
    Trie() {
        _root = new TrieNode('/');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = this->_root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!p->children[idx]) {
                p->children[idx] = new TrieNode(word[i]);
            }
            p = p->children[idx];
        }
        p->isEndingChar = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = this->_root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!p->children[idx]) {
                return false;
            }
            p = p->children[idx];
        }
        if (!p->isEndingChar) {
            return false;
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = this->_root;
        for (int i = 0; i < prefix.length(); i++) {
            int idx = prefix[i] - 'a';
            if (!p->children[idx]) {
                return false;
            }
            p = p->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
