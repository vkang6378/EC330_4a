#include <string>
#include <vector>
#include "sorta.h"

using namespace std;

std::string sortByFreq(std::string s) {
    vector<int> freq(128, 0);

    // Count character frequencies
    for (char count : s) {
        freq[count]++;
    }

    // Group the ones with same frequency 
    vector<vector<char> > group(s.size() + 1);

    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            group[freq[i]].push_back(static_cast<char>(i));
        }
    }

    // Sort characters in each group
    for (auto &group : group) {
        vector<int> count(128, 0);
        for (char c : group) {
            count[c]++;
        }
    }
    // Rewirte the string
    string sorted_str;
    for (size_t i = 0; i < group.size(); i++) {
        for (char c : group[i]) {
            sorted_str.append(i, c);
        }
    }

    return sorted_str;
}
