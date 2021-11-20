#include <iostream>

bool IsKPeriodic(std::string &str, int k)
{
    if(k <= 0 || str.size() % k != 0 || k == (int)str.size())
        return false;

    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j < (int)str.size() / k; j++)
        {
            if (str[i] != str[i+k*j])
                return false;
        } 
    }

    return true;
}

void StrPeriodic(std::string &str)
{
    bool isPeriodic = false;

    for (int k = 1; k <= (int)str.size() / 2; k++)
    {
        if(IsKPeriodic(str, k))
        {
            std::cout << str << " period : " << k << std::endl;
            isPeriodic = true;
        }
    }

    if (!isPeriodic)
        std::cout << str << " period : 0" << std::endl;
}

int main()
{
    std::string str = "abcabcabcabc";
    int k = 3;

    std::cout << str << " period " << k << " : " << (IsKPeriodic(str, k) ? "true" : "false") << std::endl;

    StrPeriodic(str);

    str = "qweqwa";
    k = 6;

    std::cout << str << " period " << k << " : " << (IsKPeriodic(str, k) ? "true" : "false") << std::endl;

    StrPeriodic(str);

    return 0;
}