import ctypes
import numpy as np

biblioteka = ctypes.CDLL('./library.dll')

biblioteka.policz_rozklad.argtypes = [ctypes.POINTER(ctypes.c_uint32), ctypes.c_uint32]
biblioteka.policz_rozklad.restype = ctypes.POINTER(ctypes.c_uint64)

biblioteka.usun_tablice.argtypes = [ctypes.POINTER(ctypes.c_uint64)]

k = 2
N = 1 << k
S_lista = [3, 1, 0, 2]

S_c_tablica = (ctypes.c_uint32 * N)(*S_lista)

wskaznik_wynik = biblioteka.policz_rozklad(S_c_tablica, ctypes.c_uint32(k))

if wskaznik_wynik:
    plaska_lista = [wskaznik_wynik[i] for i in range(N * N)]
    macierz_gotowa = np.array(plaska_lista).reshape((N, N))
    print(macierz_gotowa)
    
    biblioteka.usun_tablice(wskaznik_wynik)
