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
#include <functional>

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


auto new_vector(function<Massa(const vector<Massa>&)> fun,const vector<Massa>& m)
{
    vector<Massa> new_m(0);
    for (auto& i : m)
    {
        Massa c = fun(m);
        if (c > i) new_m.push_back(Massa(c+i));
        else new_m.push_back(Massa(i));
    }
    return new_m;
}

int main()
{
    vector<shared_ptr<Base>> p;
    p.push_back(create_factory("45.4kg"));
    p.push_back(create_factory("4.4K"));
    p.push_back(create_factory("3.4J"));
    p.push_back(create_factory("45.4Hz"));
    p.push_back(create_factory("5.4m"));
    for (const auto& i : p)
        cout << i->get_string() << endl;
    vector<Massa> m(10);
    for (auto& i : m)
    {
        i.set((double)rand()/100);
    }
    // 1 случай
    auto print = [](const vector<Massa>& v_m) {
        for (const auto& i : v_m)
            cout << i << " "; };
    cout << "Massiv: "<<endl;
    print(m);
    // 2 случай
    auto func_max = [](const vector<Massa>& v_m, Massa massa) {
        cout << "mass more than given: "<<endl;
        for (const auto& i : v_m)
            if (i > massa) cout << i<<" ";
    };
    cout << endl;
    Massa m1(150.6);
    func_max(m, m1);
    cout << endl;
    // 3 случай
    auto func_average = [](const vector<Massa>& v_m)
    {
        double sum = 0.0;
        for (const auto& i : v_m)
            sum+=i.get();
        return Massa(sum / v_m.size());
    };
    cout <<"Average massa:  "<<endl<< Massa(func_average(m))<<endl;
    // 4 случай
    vector<Massa> vector1= new_vector(func_average, m);
    cout << "New massiv:" << endl;
    print(vector1);
    cout << endl;
    // 5 случай
    auto func_min = [](const vector<Massa>& v_m)
    {
        Massa min = v_m[0];
        for (const auto& i : v_m)
            if (min > i) min = i;
        return min;
    };
    cout << "Min element: " <<endl<<func_min(m) << endl;
    vector<Massa> vector2 = new_vector(func_min, m);
    cout << "New massiv 1:" << endl;
    print(vector2);
        cout << i->get_string() << endl;
}