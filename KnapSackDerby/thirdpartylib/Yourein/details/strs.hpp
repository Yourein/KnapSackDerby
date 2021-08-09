#pragma once //include guard

//INCLUDE DEPENDINGS
#include <string>
#include <vector>
//INCLUDE DEPENDINGS END

namespace Yourein{
    namespace strs{
        std::vector<std::string> pinput(std::string s, char spliter){
            std::vector<std::string> r;
            std::string buf;
            for (int i = 0;  i < s.size(); i++){
                if (s[i] == spliter){
                    while (buf[0] == ' ') {
                        buf.erase(buf.begin()+0);
                    }
                    r.push_back(buf);
                    buf.clear();
                }
                else{
                    buf.push_back(s[i]);
                }
            }

            if (buf.size() != 0){
                while (buf[0] == ' ') {
                    buf.erase(buf.begin()+0);
                }
                r.push_back(buf);
                buf.clear();
            }

            return r;
        }

        int strcount(std::string s, std::string counter){
            int count = 0;
            for (long long i = 0; i < s.size(); i++){
                if (s.substr(i, counter.size()) == counter){
                    count++;
                    i+=counter.size()-1;
                }
            }
            return count;
        }

        bool sfind(std::string s, std::string finder){
            std::vector<int> findex;        
            
            for (int i = 0; i < s.size(); i++){
                if (s[i] == finder[0]){
                    findex.push_back(i);
                }
            }

            if (findex.size() == 0){
                return false;
            }
            else{
                for (int x : findex){
                    if (s.substr(x, finder.size()) == finder){
                        return true;
                    }
                }
                
                return false;
            }
        }

        std::string strformat(std::string base, char filler, int length, bool Lspace = false){
            std::string formated;
            int spaced = length - base.size();

            if (spaced >= 0){
                std::string spacer;
                for (int appender = 0; appender < spaced; appender++) spacer += filler;

                if (Lspace) formated = spacer + base;
                else formated = base + spacer;
            }
            else{
                if (Lspace){
                    formated = base.substr(base.size()-length, length);
                }
                else{
                    formated = base.substr(0, length);
                }
            }

            return formated;
        }
    }
}