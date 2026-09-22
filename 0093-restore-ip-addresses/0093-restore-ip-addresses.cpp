class Solution {
    int cnt;
    vector<string> ans;

    bool isValid(string s) {
        int n = s.length();
        if (n == 0 || n > 3)
            return false;

        
        if (n > 1 && s[0] == '0')
            return false;
        int num = stoi(s);
        return num <= 255;
    }

    void solve(string &s, int i, string &temp) {

        if (cnt < 0 || i >= s.length())
            return;
        if (cnt == 0) {
            string last = s.substr(i);
            if (isValid(last)) {
                ans.push_back(temp + last);
            }
            return;
        } 
        string part = "";

        for (int j = i; j < s.length() && j < i + 3; j++) {

            part.push_back(s[j]);

            if (!isValid(part))
                continue;

            // take
            temp += part;
            temp.push_back('.');

            cnt--;
            solve(s, j + 1, temp);
            cnt++;

        //  undo kro
            temp.pop_back();
            temp.erase(temp.size() - part.size());
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {

        if (s.length() < 4 || s.length() > 12)
            return ans;
        cnt = 3;
        string temp = "";
        solve(s, 0, temp);

        return ans;
    }
};