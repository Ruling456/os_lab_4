// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>


typedef int (*GCF_func)(int, int);
typedef double (*Pi_func)(int);


// Массив библиотек для загрузки
const char* lib_paths[4] = {
    "./func_4_n.so",  // Наивный алгоритм НОД
    "./func_4_e.so",  // Алгоритм Евклида НОД  
    "./func_5_i.so",  // Ряд Лейбница Pi
    "./func_5_w.so",  // Формула Валлиса Pi
};

enum {func_4_e, func_4_n, func_5_i, func_5_w};
enum {Pi, GCF};



union ans
{
    int ans_int;
    double ans_double;
};


int main() {
    int start, arg1, arg2;
    union ans ans;

    int actual_lib_GCF = func_4_e;
    int actual_lib_PI = func_5_i;
    int last_lib = GCF;

    void* handle = NULL;
    GCF_func actual_func_GCF = NULL;    
    Pi_func actual_func_Pi = NULL;

    printf("Actual GCF - Evklid\nActual Pi - Leibnic\nlast_lib - GCF\n");

    while (1) {
        scanf("%d", &start);

        if (start == 0) {
            if (last_lib == GCF) {
                actual_lib_GCF = (actual_lib_GCF == func_4_e) ? func_4_n : func_4_e;
                printf("Switched GCF to %s\n", 
                       (actual_lib_GCF == func_4_e) ? "Evklid" : "Naive");
            } else {
                actual_lib_PI = (actual_lib_PI == func_5_i) ? func_5_w : func_5_i;
                printf("Switched Pi to %s\n", 
                       (actual_lib_PI == func_5_i) ? "Leibniz" : "Wallis");
            }
        } 
        else if (start == 1) {
            scanf("%d%d", &arg1, &arg2);
            last_lib = GCF;
            
            const char* lib_name = (actual_lib_GCF == func_4_e) 
                                   ? "func_4_e.so" : "func_4_n.so";
            
            handle = dlopen(lib_name, RTLD_LAZY);
            if (!handle) {
                fprintf(stderr, "Error: %s\n", dlerror());
                continue;
            }
            
            actual_func_GCF = dlsym(handle, "GCF");
            if (!actual_func_GCF) {
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                continue;
            }
            
            ans.ans_int = actual_func_GCF(arg1, arg2);
            printf("GCF result: %d\n", ans.ans_int);
            dlclose(handle);
        } 
        else if (start == 2) {
            scanf("%d", &arg1);
            last_lib = Pi;
            
            const char* lib_name = (actual_lib_PI == func_5_i) 
                                   ? "func_5_i.so" : "func_5_w.so";
            
            handle = dlopen(lib_name, RTLD_LAZY);
            if (!handle) {
                fprintf(stderr, "Error: %s\n", dlerror());
                continue;
            }
            
            actual_func_Pi = dlsym(handle, "Pi");
            if (!actual_func_Pi) {
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                continue;
            }
            
            ans.ans_double = actual_func_Pi(arg1);
            printf("Pi approximation: %.15f\n", ans.ans_double);
            dlclose(handle);
        }
    }
    return 0;
};