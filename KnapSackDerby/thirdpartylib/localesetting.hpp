#pragma once

//INCLUDE DEPENDINGS
#include <iostream>
#include <cstdlib>

namespace Ylocale {
    void set_japanese() {
        system("CHCP 931");
        system("CLS");

        setlocale(LC_ALL, "japanese");
        std::wcout.imbue(std::locale("ja"));
        std::wcout.imbue(std::locale("japanese"));
    }

    void set_utf8() {
        system("CHCP 65001");
        system("CLS");
    }
}