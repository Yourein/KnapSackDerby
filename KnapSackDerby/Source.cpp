//Disable MIN/MAX macros in <Windows.h> since this program needs to use <Windows.h> and std::max in the source.
#define NOMINMAX 

//INCLUDING DEPENDINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <cstdio>

//INCLUDING THIRDPARTY DEPENDINGS(thirdparty include my own, for this project, headers.)
#include "thirdpartylib/localesetting.hpp"
#include "thirdpartylib/cosdef.hpp"
#include "thirdpartylib/json.hpp"
#include "thirdpartylib/Yourein/details/Yourein.hpp"

using json = nlohmann::json;

//Get console output handler
const HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

//ILLEGAL GLOBALS. It contains what skill can be choosed, how much costs, and how much score it gives to assessment. 
std::vector<std::string> avail;
std::vector<long long> cost;
std::vector<long long> skillscore;

//[ILLEGAL GLOBALS (2).int] Anyways, it memorys how much score had added by Priority Choice.
int editedsum = 0;

//Show WARNING MESSAGE for Skill input, for each.
void Ginput_warning() {
    Yconsole::ConsoleWrite(Console, "距離/脚質適正がないスキルは選ばないでください", CON_LRED);
    std::cout << "取得可能なスキルID(スキル横の番号)をスペース区切りで選択してください(ない場合はそのままEnter)" << std::endl;
}

void Ninput_warning() {
    Yconsole::ConsoleWrite(Console, "距離/脚質適正がないスキルは選ばないでください。二段階あるスキル(○、◎系のやつ)は○前提で計算します。", CON_LRED);
    Yconsole::ConsoleWrite(Console, "また、取得可能な金スキルの前提スキルも選ばないでください(金スキルのみで計算をします)", CON_LRED);
    std::cout << "取得可能なスキルID(スキル横の番号)をスペース区切りで選択してください(ない場合はそのままEnter)" << std::endl;
}

//Input getter for skills.
void availgetter(json& jdata) {
    std::string in;
    std::vector<std::string> formatedinput;
    std::getline(std::cin, in);
    formatedinput = Yourein::strs::pinput(in, ' ');

    for (int i = 0; i < formatedinput.size(); i++) {
        int ind = stoi(formatedinput[i]);
        avail.push_back(jdata["Skill"][ind]["name"]);
        skillscore.push_back(jdata["Skill"][ind]["score"]);
    }
}

void input_avail() {
    json jdata;
    std::fstream* iifs = new std::fstream;

    iifs->open("../Library/ccharacter.json");

    if (iifs->is_open()) {
        jdata = json::parse(*iifs);
        
        Yconsole::ConsoleWrite(Console, "固有スキル\n", CON_LYELLOW);

        for (auto& x : jdata["Skill"].items()) {
            std::cout << Yourein::strs::strformat(x.key(), ' ', 3, true);
            std::cout << ":" << Yourein::strs::strformat(x.value()["name"], ' ', 60) << std::endl;
        }
        Ginput_warning();
        availgetter(jdata);
    }
    
    iifs->close(); delete iifs; iifs = new std::fstream; jdata.clear(); Yconsole::CLEAR();
    iifs->open("../Library/cgoldspeed.json");

    if (iifs->is_open()) {
        jdata = json::parse(*iifs);

        Yconsole::ConsoleWrite(Console, "金加速スキル\n", CON_LYELLOW);

        for (auto& x : jdata["Skill"].items()) {
            std::cout << Yourein::strs::strformat(x.key(), ' ', 3, true);
            std::cout << ":" << Yourein::strs::strformat(x.value()["name"], ' ', 60) << std::endl;
        }
        Ginput_warning();
        availgetter(jdata);
    }

    iifs->close(); delete iifs; iifs = new std::fstream; jdata.clear(); Yconsole::CLEAR();
    iifs->open("../Library/cgoldheal.json");

    if (iifs->is_open()) {
        jdata = json::parse(*iifs);

        Yconsole::ConsoleWrite(Console, "金回復スキル\n", CON_LYELLOW);

        for (auto& x : jdata["Skill"].items()) {
            std::cout << Yourein::strs::strformat(x.key(), ' ', 3, true);
            std::cout << ":" << Yourein::strs::strformat(x.value()["name"], ' ', 60) << std::endl;
        }
        Ginput_warning();
        availgetter(jdata);
    }

    iifs->close(); delete iifs; iifs = new std::fstream; jdata.clear(); Yconsole::CLEAR();
    iifs->open("../Library/cgolddebuf.json");

    if (iifs->is_open()) {
        jdata = json::parse(*iifs);

        Yconsole::ConsoleWrite(Console, "金デバフスキル\n", CON_LYELLOW);

        for (auto& x : jdata["Skill"].items()) {
            std::cout << Yourein::strs::strformat(x.key(), ' ', 3, true);
            std::cout << ":" << Yourein::strs::strformat(x.value()["name"], ' ', 60) << std::endl;
        }
        Ginput_warning();
        availgetter(jdata);
    }

    iifs->close(); delete iifs; iifs = new std::fstream; jdata.clear(); Yconsole::CLEAR();
    iifs->open("../Library/cnormalspeed.json");

    if (iifs->is_open()) {
        jdata = json::parse(*iifs);

        Yconsole::ConsoleWrite(Console, "通常加速スキル\n", CON_LYELLOW);

        for (auto& x : jdata["Skill"].items()) {
            std::cout << Yourein::strs::strformat(x.key(), ' ', 3, true);
            std::cout << ":" << Yourein::strs::strformat(x.value()["name"], ' ', 60) << std::endl;
        }
        Ninput_warning();
        availgetter(jdata);
    }

    iifs->close(); delete iifs; iifs = new std::fstream; jdata.clear(); Yconsole::CLEAR();
    iifs->open("../Library/cnormalheal.json");

    if (iifs->is_open()) {
        jdata = json::parse(*iifs);

        Yconsole::ConsoleWrite(Console, "通常回復スキル\n", CON_LYELLOW);

        for (auto& x : jdata["Skill"].items()) {
            std::cout << Yourein::strs::strformat(x.key(), ' ', 3, true);
            std::cout << ":" << Yourein::strs::strformat(x.value()["name"], ' ', 60) << std::endl;
        }
        Ninput_warning();
        availgetter(jdata);
    }

    iifs->close(); delete iifs; iifs = new std::fstream; jdata.clear(); Yconsole::CLEAR();
    iifs->open("../Library/cnormaldebuff.json");

    if (iifs->is_open()) {
        jdata = json::parse(*iifs);

        Yconsole::ConsoleWrite(Console, "通常デバフスキル\n", CON_LYELLOW);

        for (auto& x : jdata["Skill"].items()) {
            std::cout << Yourein::strs::strformat(x.key(), ' ', 3, true);
            std::cout << ":" << Yourein::strs::strformat(x.value()["name"], ' ', 60) << std::endl;
        }
        Ninput_warning();
        availgetter(jdata);
    }

    iifs->close(); delete iifs; iifs = new std::fstream; jdata.clear(); Yconsole::CLEAR();
    iifs->open("../Library/cgreens.json");

    if (iifs->is_open()) {
        jdata = json::parse(*iifs);

        Yconsole::ConsoleWrite(Console, "緑スキル\n", CON_LYELLOW);

        for (auto& x : jdata["Skill"].items()) {
            std::cout << Yourein::strs::strformat(x.key(), ' ', 3, true);
            std::cout << ":" << Yourein::strs::strformat(x.value()["name"], ' ', 60) << std::endl;
        }
        Ninput_warning();
        availgetter(jdata);
    }
}

void cost_getter() {
    int len = avail.size();
    cost.assign(avail.size(), 0);

    for (int i = 0; i < len; i++) {
        Yconsole::CLEAR();
        std::cout << avail[i] << "の必要コストを入力してください : ";

        std::string costtemp;
        std::cin >> costtemp;

        bool only_digit = true;
        for (auto d : costtemp) {
            if (d > '9' || d < '0') only_digit = false;
        }

        if (!only_digit) {
            Yconsole::ConsoleWrite(Console, "数字のみを入力してください!", CON_LRED);
            system("PAUSE");
            i--;
        }
        else {
            cost[i] = stoi(costtemp);
        }

        int priority;
        std::cout << avail[i] << "の優先度はどの程度ですか? [1:欲しい, 2(1,3以外):普通, 3:そこまで] : ";
        std::cin >> priority;

        if (priority == 1) {
            editedsum += 50;
            skillscore[i] += 50;
        }
        else if (priority == 3) {
            skillscore[i] -= 50;
        }
    }
    Yconsole::CLEAR();
}

void solve() {
    int N = avail.size(); // long W = Skillpoint;
    int Skillpoint = 0;
    std::cout << "現在使用可能なスキルポイントを入力してください : ";
    std::cin >> Skillpoint;

    std::vector<std::vector<long long>> dp(avail.size() + 1, std::vector<long long>(Skillpoint + 1, 0));
    std::vector<std::vector<std::vector<std::string>>> skills(N + 1, std::vector<std::vector<std::string>>(Skillpoint + 1));

    for (int i = 0; i < N; i++) {
        for (int w = 0; w <= Skillpoint; w++) {
            if (w - cost[i] >= 0) {
                dp[i + 1][w] = std::max(dp[i + 1][w], dp[i][w - cost[i]] + skillscore[i]);
                if (dp[i + 1][w] == dp[i][w - cost[i]] + skillscore[i]) {
                    skills[i + 1][w] = skills[i][w - cost[i]];
                    skills[i + 1][w].push_back(avail[i]);
                }
            }
            dp[i + 1][w] = std::max(dp[i + 1][w], dp[i][w]);
            if (dp[i + 1][w] == dp[i][w]) {
                skills[i + 1][w] = skills[i][w];
            }
        }
    }

    for (auto x : skills[N][Skillpoint]) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "上のスキル獲得で   " << dp[N][Skillpoint] - editedsum << "   程度の評価点が獲得可能です。\n(実際の評価点から±50くらいすることがあります。)" << std::endl;
}

int main() {
    Ylocale::set_utf8();
    input_avail();
    cost_getter();
    solve();
}