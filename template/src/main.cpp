#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert> // For assertions

using namespace std;

// --- Debugging Utilities ---
#ifndef ONLINE_JUDGE
#define DEBUG 1
#else
#define DEBUG 0
#endif

#if DEBUG
#include <chrono>
#include <iostream>

#define dbg(...) do { \
    std::cerr << "DBG: " << __LINE__ << ": "; \
    debug_out(__VA_ARGS__); \
} while(0)

template<typename T> void debug_out(T val) { std::cerr << val << std::endl; }
template<typename T, typename... Args> void debug_out(T val, Args... args) { std::cerr << val << " | "; debug_out(args...); }

#define timer() Timer timer
class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start(std::chrono::high_resolution_clock::now()) {}
    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cerr << "Time: " << diff.count() << " s" << std::endl;
    }
};

#else
#define dbg(...)
#define timer()
#endif
// --- Debugging Utilities End ---


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    #if DEBUG
    dbg("Input n:", n);
    dbg("Input vector a:", a);
    #endif

    // Your solution logic here
    long long sum = 0;
    for (int x : a) {
        sum += x;
        assert(x >= 0); // Example assertion - ensure elements are non-negative
    }
    cout << "Sum of elements: " << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    timer(); // Start timer (only in debug mode)

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}