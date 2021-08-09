#pragma once //INCLUDE GUARD

//INCLUDE DEPENDINGS
#include <string>
#include <iostream>
#include <map>
//INCLUDE DEPENDINGS

namespace Yourein{
    namespace debug{
        template <typename T>
        void debug_a(const T &a){
            for (auto x:a){
                std::cerr << x << " ";
            }
            std::cerr << std::endl;
        }

        template <>
        void debug_a(const std::string &a){
            std::cerr << a << std::endl;
        }

        template <typename T1, typename T2>
        void debug_a(const std::map<T1, T2> &a){
            for (auto x : a){
                std::cerr << x.first << " : " << x.second << std::endl;
            }
        }
    }
}