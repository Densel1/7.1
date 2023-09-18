
#include "timer.h"
#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

float sum(vector<int> &v1, vector<int>& v2, int startElement, int endElement)
{
    vector<int> v3(4'000'000);
    auto mstime = chrono::high_resolution_clock::now();
    for (auto it = startElement; it != endElement; ++it)
    {
        v3.at(it) = v1.at(it) + v2.at(it);
    }
    auto metime = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> rtime = metime - mstime;
    return rtime.count();
}


int main()
{
    const int thousend = 1000;
    const int tenT = thousend * 10;
    const int hundredT = thousend * 100;
    const int thousendT = thousend * 1000;

    vector<int> V1(thousendT*2);
    vector<int> V2(thousendT*2);
    mt19937 gen;
    uniform_int_distribution<int> dis(0, thousendT);
    auto rand_num([=]() mutable {return dis(gen); });
    generate(V1.begin(), V1.end(), rand_num);
    generate(V2.begin(), V2.end(), rand_num);



    for (int j = thousend; j <= thousend * 1000; j *= 10) { cout << "\t\t" << j; }
    cout << endl;

     for (int k = 1; k <= 16; k *= 2)
    {
        vector<thread> VT3;

        cout << endl << k << " potoka:";
        for (int i = thousend; i <= thousend * 1000; i *= 10)
        {
            float sum1 = 0.0;
            for (int j = 0; j < k; ++j)
            {

                if (j * (i / k) >= i) cout << "big_first_number" << endl;
                if ((j * (i / k) + i / k) > i) cout << "big_second_number" << endl;

                VT3.push_back(thread([&]() {sum1 += sum(ref(V1), ref(V2), j * (i / k), j * (i / k) + i / k); }));
            }
            this_thread::sleep_for(150ms); // please increase if your PC to slow
            cout << '\t' << fixed << setprecision(4) <<sum1 / k << 's' << '\t';

        }
        for (auto& t1 : VT3)
        {
            if (t1.joinable()) t1.join();
        }
    }

}

