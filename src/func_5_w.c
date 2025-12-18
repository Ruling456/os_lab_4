#include "func5.h"

// Вычисление π с использованием формулы Валлиса
double Pi(int K)
{
    if (K <= 0) {
        return 0.0f; // некорректный ввод
    }
    
    double product = 1.0f;
    
    for (int n = 1; n <= K; n++) {
        // Формула: π/2 = (2/1 * 2/3) * (4/3 * 4/5) * (6/5 * 6/7) * ...
        // или: π/2 = ∏[n=1 to ∞] (4n² / (4n² - 1))
        
        double numerator = 4.0f * n * n;
        double denominator = numerator - 1.0f;
        double term = numerator / denominator;
        
        product *= term;
    }
    
    return 2.0 * product;
}