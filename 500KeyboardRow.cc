#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector<string> findWords(vector<string> &words)
{
    const std::unordered_set<char> dict1 = {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P'};
    const std::unordered_set<char> dict2 = {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L'};
    const std::unordered_set<char> dict3 = {'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'};

    vector<string> ans;

    //cout << "before for" << endl;
    for (auto &str : words)
    {
        //cout << "inside for" << endl;
        bool line1, line2, line3;
        line1 = line2 = line3 = true;

        for (auto &ch : str)
        {
            //cout << "inside for" << endl;
            if (line1)
            {
                auto it = dict1.find(ch);
                if (it == dict1.end()) line1 = false;
            }

            if (line2)
            {
                auto it = dict2.find(ch);
                if (it == dict2.end()) line2 = false;
            }

            if (line3)
            {
                auto it = dict3.find(ch);
                if (it == dict3.end()) line3 = false;
            }
        }

        if (line1 || line2 || line3)
            ans.push_back(str);
    }

    return ans;
}

int main()
{
    vector<string> ans;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};

    ans = findWords(words);
    vector<string>::iterator iter = ans.begin();
    for (; iter != ans.end(); ++iter)
        cout << *iter << endl;

    return 0;
}
