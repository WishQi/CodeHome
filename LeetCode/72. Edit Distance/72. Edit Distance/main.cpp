//
//  main.cpp
//  72. Edit Distance
//
//  Created by Maoqi Li on 2019/2/24.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int D[1000][1000] = {0};

class Solution {
public:
    void generate_D(string& word1, string& word2) {
        for (int i = 0; i <= word1.size(); i++) {
            for (int j = 0; j <= word2.size(); j++) {
                if (i == 0) {
                    D[i][j] = j;
                }
                if (j == 0) {
                    D[i][j] = i;
                }
                if (i > 0 && j > 0) {
                    int tmp = word1[i - 1] == word2[j - 1] ? D[i - 1][j - 1] : D[i - 1][j - 1] + 1;
                    D[i][j] = min(min(D[i - 1][j], D[i][j - 1]) + 1, tmp);
                }
            }
        }
    }
    int minDistance(string word1, string word2) {
        generate_D(word1, word2);
        if (word1.size() == 0) {
            return (int)word2.size();
        }
        if (word2.size() == 0) {
            return (int)word1.size();
        }
        return D[word1.size()][word2.size()];
    }
};

int main(int argc, const char * argv[]) {
    string word1 = "intention";
    string word2 = "execution";
    cout << Solution().minDistance(word1, word2) << endl;
    return 0;
}
