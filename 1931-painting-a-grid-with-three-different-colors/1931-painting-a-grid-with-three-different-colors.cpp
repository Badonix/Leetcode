const int mod = 1e9 + 7;
using matrix = vector<vector<int>>;
static matrix I;

matrix Id(int sz) {
    matrix I(sz, vector<int>(sz, 0));
    for (int i = 0; i < sz; i++)
        I[i][i] = 1;
    return I;
}

matrix operator*(const matrix& A, const matrix& B) {
    const int n=A.size(), p=A[0].size(), q=B.size(), m=B[0].size();
    if (p != q) return {};
    matrix C(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int k=0; k < p; k++) {
            for (int j=0; j < m; j++) {
                C[i][j]=(C[i][j]+1LL*A[i][k]*B[k][j]) % mod;
            }
        }
    }
    return C;
}

// modular matrix power (MSBF)
matrix modPow(const matrix& M, unsigned n, int sz) {
    if (n == 0) return I;
    bitset<32> B(n);
    int bMax = 31-countl_zero(n);
    matrix ans = M;
    for (int i = bMax-1; i >= 0; i--) {
        ans = ans*ans;
        if (B[i])
            ans = ans * M;
    }
    return ans;
}

// integer modular exponentiation
int modPow(int base, unsigned n) {
    if (n == 0) return 1;

    bitset<32> B(n);
    int bMax = 31 - countl_zero(n);
    long long ans = 1;
    long long b = base % mod;

    for (int i = bMax; i >= 0; i--) {
        ans = (ans * ans) % mod;
        if (B[i])
            ans = (ans * b) % mod;
    }
    return ans;
}


void print(const vector<vector<int>>& M) {
    int s=M.size(), i=0;
    cout << "\nM={";
    for (const auto& row : M) {
        cout<<"\n\t{";
        int j=0, sz=row.size();
        for (int v : row){
            cout << v;
            if (++j<sz) cout<<",";
            else cout<<"}";
        }
        if (++i<s) cout<<",";
    }
    cout << "\n};\n";
}

class Solution {
public:
    matrix M;
    vector<string> Type;
    int i0 = 0;
    int n, m;
    int map[27]; // encode number -> Type Id

    void build_Type(int i, string& pattern) {
        if (i == 0) {
            int key = 0;
            for (int j = 2; j < m; j++)
                key = key*3+(pattern[j]-'0');
            map[key]=i0;
            Type.push_back(pattern);
            //cout << i0 << ":" << pattern << " key=" << key << " | ";
            i0++;
            return;
        }
        for (int x = '0'; x <= '2'; x++) {
            if (x == pattern.back())
                continue;
            pattern += x;
            build_Type(i - 1, pattern);
            pattern.pop_back();
        }
    }

    void find_typeId(const string& col, int colIndex) {
        char x = col[0], y = col[1], z;
        for (char c : {'a', 'b', 'c'}) {
            if (c == x || c == y) continue;
            z = c;
        }
        int f[128] = {};
        f[x]=0, f[y]=1, f[z]=2;

        int key = 0;
        for (int j = 2; j < m; j++)
            key = key * 3 + f[col[j]];
        if (map[key] != -1)
            M[map[key]][colIndex]++;
    }

    // transition matrix M operates on the column vector
    void build_M(int i, string& curr, const string& col0, int colIndex) {
        if (i < 0) {
            find_typeId(curr, colIndex);
            return;
        }
        for (char x = 'a'; x <= 'c'; x++) {
            if (x == (col0[i] - '0' + 'a'))
                continue;
            if (!curr.empty() && x == curr.back())
                continue;
            curr += x;
            build_M(i - 1, curr, col0, colIndex);
            curr.pop_back();
        }
    }

    int colorTheGrid(int m, int n) {
        this->m = m, this->n = n;
        if (m == 1) return 3LL * modPow(2, n - 1) % mod;
        if (m == 2) return 6LL * modPow(3, n - 1) % mod;

        int sz = 1<<(m-2); // number of patterns
        I = Id(sz);
        memset(map, -1, sizeof(map));
        Type.clear();

        string pattern = "01"; // first two colors
        build_Type(m - 2, pattern);

        M.assign(sz, vector<int>(sz, 0));

        for (int i = 0; i < sz; ++i) {
            const string& s = Type[i];
            string curr = "";
            build_M(m - 1, curr, s, i);
        }

    //    print(M);
        matrix A = modPow(M, n - 1, sz);
        long long ans = 0;
        for (int i = 0; i < sz; i++) {
            long long rowSum=reduce(A[i].begin(), A[i].end(), 0LL)% mod;
            ans=(ans+(6LL*rowSum) % mod) % mod;//each Type has 6 combinations
        }
        return ans;
    }
};