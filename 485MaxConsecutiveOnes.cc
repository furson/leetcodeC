#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int FMCO(vector<int>& nums)
{
    int maxone = 0;
    int one = 0;

    for (auto num : nums)
    {
        if (num & 1)
        {
            ++one;
        }
        else
        {
            if (one > maxone)
                maxone = one;
            one = 0;
        }
    }
    if (one > maxone)
        maxone = one;

    return maxone;
}

int main()
{
    vector<int> num = {1, 1, 0, 1, 1, 1};

    cout << FMCO(num) << endl;

    return 0;
}
