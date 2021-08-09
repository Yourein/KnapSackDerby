#pragma once //INCLUDE GUARD

namespace Yourein{
    namespace random{
        unsigned long long xsrand(unsigned long long x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        unsigned long long xsrand(unsigned long long x, unsigned long long L = 0, unsigned long long R = 1e15){
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return ((x ^ (x >> 31)) % ((R+1)-L))+L;
        }
    }
}