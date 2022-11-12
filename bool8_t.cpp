#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

class bool8_t
{
    uint8_t bits;

public:
    // false as default
    bool8_t()
    {
        bits = 0;
    }
    bool8_t(bool status)
    {
        if (status)
            bits = 255;
        else
            bits = 0;
    }

    bool operator[](int i)
    {
        try
        {
            if (i >= 0 && i <= 7)
            {
                int mask = pow(2, 7 - i);

                if ((mask & bits) == mask)
                    return true;
                return false;
            }
            else
                throw i;
        }
        catch (int x)
        {
            cout << "Returning false: " << '[' << i << ']' << " -> Invalid index\n";
            return false;
        }
    }

    void set(int i, bool status)
    {
        if (i >= 0 && i <= 7)
        {
            int mask = pow(2, 7 - i);

            if (status)
                bits = bits | mask;
            else
            {
                if ((*this)[i])
                {
                    if (bits > mask)
                        bits -= mask;
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < 8; i++)
            cout << (*this)[i];
        cout << endl;
    }

    int _() { return bits; }

}arr;

int main()
{
    cout << "sizeof(bool)    : " << sizeof(bool) << endl;
    cout << "sizeof(bool8_t) : " << sizeof(bool8_t) << endl << endl;

    cout << "Setting i=6 to true...\n";
    arr.set(6, true);
    arr.print();
    cout << endl;

    cout << "Setting i=1 to true...\n";
    arr.set(1, true);
    arr.print();
    cout << endl;

    cout << "Setting i=3 to true...\n";
    arr.set(3, true);
    arr.print();
    cout << endl;

    cout << "Setting i=3 to false...\n";
    arr.set(3, false);
    arr.print();
    cout << endl;

    cout << "Setting i=6 to false...\n";
    arr.set(6, false);
    arr.print();
    cout << endl;

    cout << arr[9] << endl;
    return 0;
}