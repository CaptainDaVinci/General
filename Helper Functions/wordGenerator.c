#include <iostream>
#include <string>

void generate(const std::string set, const std::string prefix, const unsigned int n, const unsigned int k);
bool isVowel(char c);

const std::string vowel = "aeiou";
const std::string consonant = "bcdfghjklmnpqrstvwxz";
int j, k;

int main()
{
    const std::string set = vowel + consonant;

    int n;
    std::cin >> n;

    generate(set, "", set.size(), n);
}

void generate(const std::string set, const std::string prefix, const unsigned int n, const unsigned int len)
{
    if (len == 0)
    {
        std::cout << prefix + '\n';
        return ;
    }

    for(size_t i = 0; i < n; ++i)
    {
        std::string newPrefix;

        if(prefix.empty())
            newPrefix = prefix + set[i];
        
        else if(isVowel(prefix[prefix.size() - 1]))
        {
            if(j > 19) j = 0;
            newPrefix = prefix + consonant[j++];
        }

        else
        {
            if(k > 4) k = 0;
            newPrefix = prefix + vowel[k++];
        }

        if(isVowel(newPrefix[newPrefix.size() - 1]))
            generate(set, newPrefix, 20, len - 1);
        else
            generate(set, newPrefix, 5, len - 1);
    }
}

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}