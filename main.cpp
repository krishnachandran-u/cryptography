#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <functional>
#include <numeric>

bool is_prime(long long n);
void generate_key(long long& e, long long &d, long long& n);
long long encrypt(long long plaintext, long long e, long long n);
long long decrypt(long long ciphertext, long long d, long long n);
long long mod_pow(long long base, long long exponent, long long modulus);
long long mod_inverse(long long a, long long m);

int main(){
    std::srand(static_cast<long long>(std::time(0)));

    long long e, d, n;
    generate_key(e, d, n);

    long long plaintext; 
    std::cout << "plaintext: ";
    std::cin >> plaintext;

    long long ciphertext = encrypt(plaintext, e, n);
    std::cout << "ciphertext: " << ciphertext << "\n";

    long long decrypted_text = decrypt(ciphertext, d, n);
    std::cout << "decrypted text: " << decrypted_text << "\n";

    return 0;
}

bool is_prime(long long n){
    if(n <= 1) return false;
    for(long long i = 2; i <= std::sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

void generate_key(long long& e, long long &d, long long& n){
    long long p, q;
    do {
        p = std::rand() % 100 + 1;
    } while (!is_prime(p));

    do {
        q = std::rand() % 100 + 1;
    } while (!is_prime(q));

    n = p * q;
    long long phi = (p - 1) * (q - 1);

    do {
        e = std::rand() % (phi - 2) + 2;
    } while (std::gcd(e, phi) != 1);

    d = mod_inverse(e, phi);
}

long long mod_inverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

long long mod_pow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

#define ull unsigned long long

ull int gcd(int a, int b);

ull int lcm(int a, int b);

ull int encrypt(int m, int e, int n);

ull int decrypt(int
long long encrypt(long long plaintext, long long e, long long n) {
    return mod_pow(plaintext, e, n);
}

long long decrypt(long long ciphertext, long long d, long long n) {
    return mod_pow(ciphertext, d, n);
}

