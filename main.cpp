#include <iostream>
#include <cstdint>
#include <omp.h>

int
main() {
    uint32_t k = 2;
    uint32_t N = 1 << k; 
    
    uint32_t S[] = {3, 1, 0, 2};
    
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
    
    for(uint32_t i = 0; i < N; ++i) {
        for(uint32_t j = 0; j < N; ++j) {
            std::cout << tabela_wynikow[i * N + j] << " ";
        }
        std::cout << "\n";
    }
    
    delete [] tabela_wynikow;
    return 0;
}
