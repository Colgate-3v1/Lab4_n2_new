#include <iostream>
#include <compare>
#include <regex>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include "Massa.h"
#include "Radiation_frequency.h"
#include "Temperature.h"
#include "Wave_length.h"
#include "Energy.h"
#include "Base.h"
#include <memory>
/*Классы физических величин: масса, энергия, длина волны, частота излучения,
температура, мощность излучения.
Определить для них операторы сложения (+) и вычитания (-) с учетом
физического смысла.
Для каждого класса определить литералы для обозначения размерности:
масса – kg, энергия – J, длина волны – m, частота излучения – Hz,
температура – K, мощность излучения – W.
Для массы и энергии определить взаимнооднозначные операторы преобразования
по формуле E=mc2
, также определить операторы преобразования энергии к
частоте, и частоты к длине волны
*/
using namespace std;
shared_ptr<Base> create_factory(string arg)
{

    std::smatch res;
    std::regex reg("[1-9]\\d*(\\.){1}[1-9]\\d*");
    double c = 0;
    if (std::regex_search(arg, res, reg))
    {
        string s = res[0];
        c = stod(s);
        arg = std::regex_replace(arg.c_str(), std::regex("[1-9]\\d*(\\.){1}[1-9]\\d*"), "");
    }
    else
    {
        throw exception("Некорректный аргумент передан в функцию");
    }
    if (arg == "kg") return make_shared<Massa>(c);
    else {
        if (arg == "m") return make_shared<Wave_length>(c);
        else {
            if (arg == "Hz") return make_shared<Radiation_frequency>(c);
            else {
                if (arg == "K") return make_shared<Temperature>(c);
                else {
                    if (arg == "J") return make_shared<Energy>(c);
                    else
                        throw exception("Нет данного литерала");
                }
            }
        }
    }

}



int main()
{
    Massa n(4);
    vector<shared_ptr<Base>> p;
    p.push_back(create_factory("45.4kg"));
    p.push_back(create_factory("4.4K"));
    p.push_back(create_factory("3.4J"));
    p.push_back(create_factory("45.4Hz"));
    p.push_back(create_factory("5.4m"));
    for (const auto& i : p)
        cout << i->get_string() << endl;
}