#include <iostream>
#include <typeinfo>

using namespace std;

int main(int argc, char const *argv[])
{
    float x = 5;
    cout << typeid((25, sqrt(9.0), ++x, printf("123"))).name();

    return 0;
}
