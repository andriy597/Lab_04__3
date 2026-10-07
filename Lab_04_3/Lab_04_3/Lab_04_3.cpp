// Лабораторна робота № 4, завдання 4.3. Табуляція функції з параметрами.
// Варіант 14.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, x, xp, xk, dx, F;
    bool defined;   // false, якщо у точці x виникає ділення на нуль

    cout << "a = ";  cin >> a;
    cout << "b = ";  cin >> b;
    cout << "c = ";  cin >> c;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "-------------------------------" << endl;
    cout << "|" << setw(6) << "x" << "    |"
        << setw(12) << "F" << "     |" << endl;
    cout << "-------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        defined = true;
        F = 0;

        if (x + c < 0 && a != 0)
            F = -a * x * x - b;
        else
            if (x + c > 0 && a == 0)
            {
                if (x - c != 0)
                    F = (x - a) / (x - c);
                else
                    defined = false;       // x = c: ділення на нуль
            }
            else
            {
                if (c != 0 && x != 0)
                    F = x / c + c / x;
                else
                    defined = false;       // c = 0 або x = 0: ділення на нуль
            }

        if (F == 0) F = 0;      // щоб замість "-0.0000" виводилось "0.0000"

        cout << "|" << setw(8) << setprecision(2) << x << "   |";
        if (defined)
            cout << setw(14) << setprecision(4) << F << "   |" << endl;
        else
            cout << setw(14) << "undefined" << "   |" << endl;

        x += dx;
    }
    cout << "-------------------------------" << endl;

    return 0;
}