// ============================================================
//  mod.h · Modular Arithmetic (Modular Inverse, Fast Pow)
//  模加減乘除 + 快速冪 + 模逆元 · pow/div O(log mod)
//  @author   Andy-0614 <andytest.0908@gmail.com>
//  @modified 2026-06-14 by aionyx
//  @history
//    2026-06-14 Andy-0614 初版（自 GitHub 匯入）
//    2026-06-14 aionyx 修改
// ============================================================
#pragma once

long long add_mod(long long a, long long b, long long mod) {
    a %= mod; if (a < 0) a += mod;
    b %= mod; if (b < 0) b += mod;
    
    if (a >= mod - b) {
        return a - (mod - b);
    } else {
        return a + b;
    }
}

long long sub_mod(long long a, long long b, long long mod) {
    a %= mod; if (a < 0) a += mod;
    b %= mod; if (b < 0) b += mod;
    
    if (a < b) {
        return a + mod - b;
    } else {
        return a - b;
    }
}

long long mul_mod(long long a, long long b, long long mod) {
    a %= mod; if (a < 0) a += mod;
    b %= mod; if (b < 0) b += mod;
    
    return (long long)((__int128_t)a * b % mod);
}

long long pow_mod(long long base, long long exp, long long mod) {
    if (exp == 0) return 1 % mod;

    base %= mod;
    if (base < 0) base += mod;

    if (exp < 0) {
        base = pow_mod(base, mod - 2, mod); 
        exp = -exp;                         
    }

    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = mul_mod(res, base, mod);
        base = mul_mod(base, base, mod);
        exp /= 2;
    }
    return res;
}

long long div_mod(long long a, long long b, long long mod) {
    a %= mod; if (a < 0) a += mod;
    b %= mod; if (b < 0) b += mod;
    
    long long b_inverse = pow_mod(b, -1, mod);
    
    return mul_mod(a, b_inverse, mod);
}
