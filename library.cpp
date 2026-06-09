#include "library.h"
#include <omp.h>

extern "C" {

uint64_t*
policz_rozklad(const uint32_t* S, uint32_t k) {
    uint32_t N = 1 << k; 
    
    uint64_t* tabela_wynikow = new uint64_t[N * N];
    for(uint32_t i = 0; i < N * N; ++i) {
        tabela_wynikow[i] = 0;
    }
    
    #pragma omp parallel for
    for(uint32_t a = 0; a < N; ++a) {
        for(uint32_t b = 0; b < N; ++b) {
            uint32_t przesuniecie_x = (a + b) % N;
            uint32_t przesuniecie_y = (S[a] + S[b]) % N;
            
            #pragma omp atomic
            tabela_wynikow[przesuniecie_x * N + przesuniecie_y]++;
        }
    }
    
    return tabela_wynikow;
}

void
usun_tablice(uint64_t* arr) {
    if (arr != nullptr) {
        delete [] arr;
    }
}

};
