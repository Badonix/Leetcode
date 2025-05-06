class Solution {
public:
    vector<string> generate(string s) {
        vector<string> res;
        if (s == "0") {
            res.push_back("0");
        } else if (s[0] == '0') {
            if (s.back() != '0') {
                res.push_back("0." + s.substr(1));
            }
        } else {
            res.push_back(s);
            for (int i = 1; i < s.size(); ++i) {
                if (s.back() != '0') {
                    res.push_back(s.substr(0, i) + "." + s.substr(i));
                }
            }
        }
        return res;
    }

    vector<string> ambiguousCoordinates(string s) {
        string str = s.substr(1, s.size() - 2);
        vector<string> answ;
        for (int i = 1; i < str.size(); ++i) {
            string left = str.substr(0, i);
            string right = str.substr(i);
            vector<string> leftOptions = generate(left);
            vector<string> rightOptions = generate(right);
            for (const string& l : leftOptions) {
                for (const string& r : rightOptions) {
                    answ.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        return answ;
    }
};
