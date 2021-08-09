#pragma once //include guard

//INCLUDE DEPENDINGS
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
//INCLUDE DEPENDINGS END

namespace Yourein{
    namespace sets{
        std::set<long long> nset(std::set<long long> *baseset, long long rangeL = 0, long long rangeR = 0){
            long long smax = *(baseset->rbegin());
            long long smin = *(baseset->begin());

            if (smin > smax){
                std::swap(smin, smax);
            }

            if (rangeL == 0 && rangeR == 0){
                rangeL = smin;
                rangeR = smax;
            }

            std::set<long long> rset;

            if (smin > rangeL){
                for (long long i = rangeL; i < smin; i++){
                    rset.insert(i);
                }
            }
            if (smax < rangeR){
                for (long long i = smax+1; i <= rangeR; i++){
                    rset.insert(i);
                }
            }

            for (long long i = smin; i < smax; i++){
                if (i < rangeL) i = rangeL;
                else if (i > rangeR) break;

                if ((baseset->find(i)) == baseset->end()){
                    rset.insert(i);
                }
            }

            return rset;
        }

        std::set<int> nset(std::set<int> *baseset, int rangeL = 0, int rangeR = 0){
            int smax = *(baseset->rbegin());
            int smin = *(baseset->begin());

            if (smin > smax){
                std::swap(smin, smax);
            }

            if (rangeL == 0 && rangeR == 0){
                rangeL = smin;
                rangeR = smax;
            }

            std::set<int> rset;
            if (smin > rangeL){
                for (int i = rangeL; i < smin; i++){
                    rset.insert(i);
                }
            }
            if (smax < rangeR){
                for (long long i = smax+1; i <= rangeR; i++){
                    rset.insert(i);
                }
            }

            for (int i = smin; i < smax; i++){
                if (i < rangeL) i = rangeL;
                else if (i > rangeR) break;

                if ((baseset->find(i)) == baseset->end()){
                    rset.insert(i);
                }
            }

            return rset;
        }

        std::set<long long> aset(std::set<long long> *s1, std::set<long long> *s2){
            long long ss1 = s1->size();
            long long ss2 = s2->size();

            std::set<long long> rset;
            if (ss1 <= ss2){
                for (auto x : *s1){
                    if (s2->find(x) != s2->end()){
                        rset.insert(x);
                    }
                }
            }
            else{
                for (auto x : *s2){
                    if (s1->find(x) != s1->end()){
                        rset.insert(x);
                    }
                }
            }

            return rset;
        }

        std::set<int> aset(std::set<int> *s1, std::set<int> *s2){
            int ss1 = s1->size();
            int ss2 = s2->size();

            std::set<int> rset;
            if (ss1 <= ss2){
                for (auto x : *s1){
                    if (s2->find(x) != s2->end()){
                        rset.insert(x);
                    }
                }
            }
            else{
                for (auto x : *s2){
                    if (s1->find(x) != s1->end()){
                        rset.insert(x);
                    }
                }
            }

            return rset;
        }

        template<typename T> std::vector<std::vector<T>> getsubset(std::vector<T> basevec){
            std::vector<std::vector<T>> rv;

            int vs = basevec.size();
            
            for (int setcounter = 0; setcounter < 1<<vs; setcounter++){
                std::vector<T> rvece;

                for (int elements = 0; elements < vs; elements++){
                    if (setcounter & (1<<elements)){
                        rvece.push_back(basevec[elements]);
                    }
                }
                rv.push_back(rvece);
            }

            return rv;
        }

        template<typename T> std::vector<std::vector<T>> getsubset(std::string basevec){
            std::vector<std::vector<T>> rv;

            int vs = basevec.size();
            
            for (int setcounter = 0; setcounter < 1<<vs; setcounter++){
                std::vector<T> rvece;

                for (int elements = 0; elements < vs; elements++){
                    if (setcounter & (1<<elements)){
                        rvece.push_back(basevec[elements]);
                    }
                }
                rv.push_back(rvece);
            }

            return rv;
        }
    }
}