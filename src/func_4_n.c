#include "func4.h"

// Наивный алгоритм
int GCF(int A, int B)
{
    int min = (A < B) ? A : B;
    int gcd = 1;
    
    for (int i = 1; i <= min; i++)
    {
        if (A % i == 0 && B % i == 0)
        {
            gcd = i;
        }
    }
    
    return gcd;
}
