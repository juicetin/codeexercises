#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class BigInteger {
public:
    BigInteger(int value) {
        std::stringstream ss;
        ss << value;
        m_value = ss.str();
    }

    BigInteger(std::string str) {
        m_value = str;
    }

    void print_value() {
        for (auto it = m_value.begin(); it != m_value.end(); ++it) {
            // cout << (int)*it - 96;
            cout << *it;
        }
        cout << endl;
    }

    std::string get_value() {
        return m_value;
    }

    void add_big_integer(BigInteger bigInt) {
        std::string larger = bigInt.get_value().length() > m_value.length() ? bigInt.get_value() : m_value;
        std::string smaller = bigInt.get_value().length() <= m_value.length() ? bigInt.get_value() : m_value;
        std::reverse(larger.begin(), larger.end());
        std::reverse(smaller.begin(), smaller.end());
        std::string sum = "";
        for (int i = 0; i < smaller.length(); ++i) {
            sum += (smaller[i] + larger[i]);
        }
        for (int i = smaller.length(); i < larger.length(); ++i) {
            sum += larger[i] + '0';
        }
        std::reverse(sum.begin(), sum.end());
        m_value = sum;
    }

    void multiply_big_integer(BigInteger bigInt) {
        std::string larger = bigInt.get_value().length() > m_value.length() ? bigInt.get_value() : m_value;
        std::string smaller = bigInt.get_value().length() <= m_value.length() ? bigInt.get_value() : m_value;
        std::reverse(larger.begin(), larger.end());
        std::reverse(smaller.begin(), smaller.end());

        cout << larger << " " << smaller << endl;

        std::string total_prod;
        std::string prev_sum = "";
        int leading_zeroes = 0;
        // For each digit in A, multiply by all digits in B
        for (auto it_s = smaller.begin(); it_s != smaller.end(); ++it_s) {
            int carry_over = 0;
            std::string this_digit_prod = "";

            // Add on leading zeroes onto sub-product as required
            for (int i = 0; i < leading_zeroes; ++i) {
                this_digit_prod += '0';
            }

            // Go through each digit in B
            for (auto it_b = larger.begin(); it_b != larger.end(); ++it_b) {

                // Multiply digit in A by B
                int this_prod = (*it_s) * (*it_b);

                // Get units digit
                int this_digit = this_prod % 10;

                // Add carry over
                if (carry_over > 0) {
                    this_digit += carry_over;
                }

                // Get new carry over if necessary
                if (this_digit > 9) {
                    carry_over = this_digit/10;
                    this_digit = this_digit % 10;
                }

                // Append new digit as char onto string
                this_digit_prod += (char)this_digit;
            }

            cout << "here" << this_digit_prod << endl;

            BigInteger BI_this_digit_prod = BigInteger(this_digit_prod);
            BI_this_digit_prod.add_big_integer(prev_sum);
            prev_sum = BI_this_digit_prod.get_value();

            leading_zeroes++;
        }

        m_value = prev_sum;
    }
    
private:
    std::string m_value;
};

void fib_mod(istream& cin) {
    long long nums[2];
    int n;
    cin >> nums[0] >> nums[1] >> n;
    if (n <= 2) {
        cout << nums[n-1] << endl;
        return ;
    }

    for (int i = 3; i <= n; ++i) {
        long long next = nums[1]*nums[1] + nums[0];
        nums[0] = nums[1];
        nums[1] = next;
    }

    cout << nums[1] << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // fib_mod(cin);
    BigInteger a = BigInteger(100);
    BigInteger b = BigInteger(10);
    a.multiply_big_integer (b);
    a.print_value();

    return 0;
}

