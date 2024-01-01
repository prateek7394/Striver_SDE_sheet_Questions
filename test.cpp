#include <bits/stdc++.h>
using namespace std;

char findMostFrequentChar(const std::string& s) {
    std::unordered_map<char, int> charFrequency;
    int maxFrequency = 0;
    char result = 'z' + 1; // Initializing with a character greater than 'z'

    for (int i = 0; i < s.size(); ++i) {
        int frequency = 0;
        std::unordered_map<char, bool> charExists;

        for (int j = i; j < s.size(); ++j) {
            if (!charExists[s[j]]) {
                charExists[s[j]] = true;
                ++frequency;
            }

            if (frequency > maxFrequency || (frequency == maxFrequency && s[j] < result)) {
                maxFrequency = frequency;
                result = s[j];
            }
        }
    }

    return result;
}

int main() {
    // string s(3, 'a');
    // cout<<s<<endl;

    std::string inputString;
    std::cout << "Enter the string: ";
    std::cin >> inputString;

    char mostFrequentChar = findMostFrequentChar(inputString);

    std::cout << "The character that appears most often across all substrings is: " << mostFrequentChar << std::endl;

    return 0;
}
