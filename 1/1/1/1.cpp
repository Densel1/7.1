// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "timer.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <execution>
#include <chrono>
#include <thread>
#include <windows.h>

using namespace std;

void set_cursor(int x = 0, int y = 0)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(handle, coordinates);
}

void virtual_client(int& q)
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(1s);
        q++;
        set_cursor(14, 1);
        cout << " " << q << " ";
    }
}

void virtual_emploe(int& q)
{
    for (int i = 0; i < 10; i++) 
    {
        this_thread::sleep_for(2s);
        q--;
        set_cursor(14, 1);
        cout << " " << q << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int que = 0;

    std::cout <<  "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
    
    cout << "Длина очереди:";
    thread t_c(virtual_client, ref(que));
    thread t_e(virtual_emploe, ref(que));
    t_c.join();
    t_e.join();



    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
