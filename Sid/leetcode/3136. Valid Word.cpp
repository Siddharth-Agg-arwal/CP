class Solution
{
public:
    bool isValid(string word)
    {
        int vowel = 0, consonants = 0;
        vector<int> vowels = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};

        if (word.size() < 3)
            return false;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] >= 48 && word[i] <= 57)
                continue;
            bool vowel_ = false;
            for (int j = 0; j < 10; j++)
            {
                if (word[i] == vowels[j])
                {
                    vowel += 1;
                    vowel_ = true;
                    break;
                }
            }
            if (vowel_)
                continue;
            if (word[i] >= 65 && word[i] <= 90)
            {
                consonants += 1;
                continue;
            }
            if (word[i] >= 97 && word[i] <= 122)
            {
                consonants += 1;
                continue;
            }

            return false;
        }

        // cout << vowel << " " << consonants;
        if (vowel > 0 && consonants > 0)
            return true;
        return false;
    }
};