class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {

            // Find how many words fit in one line
            int letters = words[i].size();
            int j = i + 1;

            while (j < n && letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Last line OR only one word
            if (j == n || gaps == 0) {

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k != j - 1)
                        line += " ";
                }

                while (line.size() < maxWidth)
                    line += " ";
            }
            else {

                int totalSpaces = maxWidth - letters;

                int eachGap = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k == j - 1)
                        continue;

                    for (int s = 0; s < eachGap; s++)
                        line += " ";

                    if (extra > 0) {
                        line += " ";
                        extra--;
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};