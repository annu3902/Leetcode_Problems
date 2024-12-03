#include <string>
#include <vector>
#include <cstddef>
class Solution {
public:
    string addSpaces(const std::string &s, const std::vector<int> &spaces) 
    {
        std::string result;
        result.reserve(s.size() + spaces.size());
        int pos = 0;
        for (auto n : spaces) {
            while (pos < n && pos < s.size()) {
                result += s[pos];
                ++pos;
            }
            result += ' ';
        }
        for (std::size_t i = pos; i < s.size(); ++i) {
            result += s[i];
        }
        return result;;
    }
};