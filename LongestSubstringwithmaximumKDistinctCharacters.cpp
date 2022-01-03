using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;

    unordered_map<char, int> char_freq;
    int start = 0;
    for(int end = 0; end < str.length(); end++) {
      char_freq[str[end]]++;
      while ((int)char_freq.size() > k) {
        char_freq[str[start]]--;
        if (char_freq[str[start]] == 0) {
          char_freq.erase(str[start]);
        }
        start++;
      }
      maxLength = max(end-start+1, maxLength);
    }
    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  cout << "Length of the longest substring (araaci, 2): " << LongestSubstringKDistinct::findLength("araaci", 2)
       << endl;
  cout << "Length of the longest substring: (araaci, 1)" << LongestSubstringKDistinct::findLength("araaci", 1)
       << endl;
  cout << "Length of the longest substring: (cbbebi, 3)" << LongestSubstringKDistinct::findLength("cbbebi", 3)
       << endl;
}