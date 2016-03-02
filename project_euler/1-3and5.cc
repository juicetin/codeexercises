#include <iostream>
using namespace std;

uint64_t divisible_by_3_or_5(int num) {
    return num % 5 == 0 || num % 3 == 0;
}

uint64_t ari_sum_with_skip(int num, int skip) {
    uint64_t d = (long long)(num-1)/skip;
    uint64_t f = skip;
    uint64_t l = f + (d-1) * skip;
    uint64_t sum = d * (f + l) >> 1;
    return sum;
}

void fizz_buzz(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (divisible_by_3_or_5(i)) {
            sum += i;
        }
    }
    cout << sum << endl;
}

void fizz_buzz_better(int n) {
    int sum = 0;
    sum += ari_sum_with_skip(n, 3);
    sum += ari_sum_with_skip(n, 5);

    if (n > 15) {
        sum -= ari_sum_with_skip(n, 15);
    }

    cout << sum << endl;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        uint64_t n;
        cin >> n;
        fizz_buzz_better(n);
    }
}
