// ============================================================
//  prime.h · Sieve of Eratosthenes / Primality Test
//  單一質數判定 + 區間質數篩 · isPrime O(√n), sieve O(R log log R)
//  @author   Andy-0614 <andytest.0908@gmail.com>
//  @modified 2026-06-14 by aionyx
//  @history
//    2026-06-14 Andy-0614 初版（自 GitHub 匯入）
//    2026-06-14 aionyx 修改
// ============================================================
#pragma once

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

vector<int> primeRangeNumber(int L, int R) {
    vector<int> primes;
    if (R < 2 || L > R) return primes;
    if (L < 0) L = 0;
    
    vector<bool> isPrimeBucket(R + 1, true);
    isPrimeBucket[0] = false;
    isPrimeBucket[1] = false;
    
    for (int p = 2; p * p <= R; p++) {
        if (isPrimeBucket[p]) {
            for (int i = p * p; i <= R; i += p) {
                isPrimeBucket[i] = false;
            }
        }
    }
    
    int start = (L < 2) ? 2 : L;
    for (int i = start; i <= R; i++) {
        if (isPrimeBucket[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}
