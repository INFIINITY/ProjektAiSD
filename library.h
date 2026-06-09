#ifndef __LIBRARY_H
#define __LIBRARY_H

#include <cstdint>

extern "C" {
    extern uint64_t* policz_rozklad(const uint32_t* S, uint32_t k);
    extern void usun_tablice(uint64_t* arr);
};

#endif
