#include <stdio.h>
#include <cs50.h>

bool triangle (int x, int y, int z)


bool triangle (int x, int y, int z)
{
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }
    else if ((x + y >= z) || (x + z >= y) || (y + z >= x))
    {
        return true;
    }
    else
    {
        return false;
    }
}