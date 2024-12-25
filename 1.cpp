#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0, start = 0;

    for (int end = 0; end < s.length(); ++end) {
        if (charIndexMap.find(s[end]) != charIndexMap.end()) {
            start = max(start, charIndexMap[s[end]] + 1);
        }
        charIndexMap[s[end]] = end;
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = lengthOfLongestSubstring(input);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}
