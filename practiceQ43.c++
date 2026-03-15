#include <iostream>
#include <vector>
using namespace std;

class Fancy {
public:
    
    long long mod = 1e9 + 7;
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long power(long long a, long long b) {
        
        long long res = 1;

        while (b) {
            
            if (b & 1)
                res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }

    Fancy() {
        
    }
    
    void append(int val) {
        
        long long inv = power(mul, mod - 2);

        long long x = ((val - add + mod) % mod * inv) % mod;

        arr.push_back(x);
    }
    
    void addAll(int inc) {
        
        add = (add + inc) % mod;
    }
    
    void multAll(int m) {
        
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }
    
    int getIndex(int idx) {
        
        if (idx >= arr.size())
            return -1;

        return (arr[idx] * mul + add) % mod;
    }
};

int main() {
    
    Fancy fancy;

    fancy.append(2);
    fancy.addAll(3);
    fancy.append(7);
    fancy.multAll(2);

    cout << fancy.getIndex(0) << endl; 

    fancy.addAll(3);
    fancy.append(10);
    fancy.multAll(2);

    cout << fancy.getIndex(0) << endl; 
    cout << fancy.getIndex(1) << endl; 
    cout << fancy.getIndex(2) << endl; 

    return 0;
}