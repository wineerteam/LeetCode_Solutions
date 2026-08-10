class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> RightHandside(n + 1, 0);

        int rightmatch = 0;
        int i = n - 1;
        int j = m - 1;

        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                rightmatch++;
                j--;
            }

            RightHandside[i] = rightmatch;
            i--;
        }

        vector<int> seq;

        bool change = true;

        i = 0;
        j = 0;

        while (i < n && j < m) {

            if (word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            }
            else if (change == true &&
                     RightHandside[i + 1] >= m - j - 1) {
                seq.push_back(i);
                j++;
                change = false;
            }

            i++;
        }

        return j == m ? seq : vector<int>();
    }
};