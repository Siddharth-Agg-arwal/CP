#include <iostream>
#include <algorithm> // For std::max

void solve() {
    long long k, a, b, x, y;
    std::cin >> k >> a >> b >> x >> y;
    long long max_portions = 0;
    long long t1f = 0;
    long long currk = k;
    if (currk >= a) {
        long long num_type1 = (currk - a) / x + 1;
        t1f += num_type1;
        currk -= num_type1 * x;
        if (currk >= b) {
            long long num_type2 = (currk - b) / y + 1;
            t1f += num_type2;
        }
    }
    max_portions = std::max(max_portions, t1f);
    long long t2f = 0;
    currk = k;
    if (currk >= b) {
        long long num_type2 = (currk - b) / y + 1;
        t2f += num_type2;
        currk -= num_type2 * y;
        if (currk >= a) {
            long long num_type1 = (currk - a) / x + 1;
            t2f += num_type1;
        }
    }
    max_portions = std::max(max_portions, t2f);
    std::cout << max_portions << std::endl;
}

int main() {
    int t;
    std::cin >> t; 
    while (t--) {
        solve(); 
    }
    return 0;
}