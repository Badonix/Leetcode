typedef long long ll;
class Solution {
public:
    string toBaseKRev(ll num, int k){
        string s;
        while(num){
            s.push_back(num % k + '0');
            num /= k;
        }
        return s;
    }
    bool isPalindrome(string s){
        int l = 0, r = s.size() - 1;
        while(l < r){
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    vector<ll> generatePalindromes(int length){
        int halfLength = (length + 1)/2;
        ll start = pow(10, halfLength - 1);
        ll end = pow(10, halfLength);
        vector<ll> res;
        for(ll i = start;i<end;i++){
            string left = to_string(i);
            string right = left;
            if(length % 2) right.pop_back();
            reverse(right.begin(), right.end());
            string pal = left + right;
            res.push_back(stoll(pal));
        }
        return res;
    }
    ll kMirror(int k, int n){
        ll sum = 0;
        int length = 1;
        while(n){
            vector<ll> pals = generatePalindromes(length);
            for(ll num: pals){
                string revsInK = toBaseKRev(num, k);
                if(isPalindrome(revsInK)){
                    sum += num;
                    n--;
                }
                if(n == 0)
                    return sum;
            }
            length++;
        }
        return sum;
    }
};