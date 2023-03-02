#include "Buraucrat.hpp"

int main()
{
    Buraucrat one("Theo", 1);

    Buraucrat two("Kevin", 144);

    Buraucrat three(one);

    two = one;

    return 0;
}
