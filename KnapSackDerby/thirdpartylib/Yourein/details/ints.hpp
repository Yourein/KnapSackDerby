#pragma once //include guard

//INCLUDE DEPENDINGS
#include <vector>
#include <algorithm>
//INCLUDE DEPENDINGS END

namespace Yourein{
    namespace ints{
        /*------------------------------------------------
        Root of getdivisors
        Return list of divisors of N.
        ------------------------------------------------*/
        std::vector<long long> getdivisors(long long n){
            std::vector<long long> divisors;

            for (int i = 1; i*i < n; i++){
                if (n%i == 0){
                    long long quotient = n/i;

                    divisors.push_back(i);
                    if (quotient != i){
                        divisors.push_back(quotient);
                    }
                }
            }

            std::sort(divisors.begin(), divisors.end());

            return divisors;
        }

        /*-------------------------------------------------------------
        Return Kth divisor of N.
        If Kth value is bigger than size of list of divisor, return -1.
        -------------------------------------------------------------*/
        long long kth_divisor(long long n, long long kth){
            std::vector<long long> divisors = getdivisors(n);

            if (kth <= divisors.size()){
                return divisors[kth-1];
            }
            else{
                return -1;
            }
        }

        /*------------
        Fast mod pow
        ------------*/
        long long modPow(long long a, long long n, long long p) {
            if (n == 0) return 1; //Base case for n^0
            if (n == 1) return a % p; //Base case for n^1

            if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;

            long long t = modPow(a, n / 2, p);
            return (t * t) % p;
        }
    }
}