#include "func5.h"


// Вычисление π с использованием ряда Лейбница
double Pi(int K)
{
    if (K <= 0) {
        return 0.0f; // некорректный ввод
    }
    
    double pi_approx = 0.0f;
    
    for (int n = 0; n < K; n++) {
        // Формула: π/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
        double term = 1.0f / (2.0f * n + 1.0f);
        
        if (n % 2 == 0) {
            pi_approx += term; // нечетные члены: +
        } else {
            pi_approx -= term; // четные члены: -
        }
    }
    
    return 4.0 * pi_approx;
}

