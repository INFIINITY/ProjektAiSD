# Projekt zaliczeniowy: Równoległe wyznaczanie rozkładu wartości funkcji

## Cel projektu
Opracowanie wydajnego algorytmu, który dla zadanej funkcji $S$ wyznacza rozkład zależności pomiędzy wartościami:
* $\Delta x = (a+b) \pmod{2^k}$
* $\Delta y = (S(a)+S(b)) \pmod{2^k}$

dla wszystkich możliwych par $a, b \in \{0, 1, \dots, 2^k-1\}$.

Algorytm musi zostać zaimplementowany w języku C lub C++, a następnie udostępniony jako biblioteka dynamiczna, którą można wykorzystać z poziomu języka Python.

## Reprezentacja funkcji S i dane wejściowe
Funkcja $S$ przekazywana jest jako tablica zawierająca dokładnie $N = 2^k$ elementów, gdzie $S[i] = S(i)$.

Program przyjmuje dwa argumenty:
1. **Parametr $k$**: Liczba całkowita dodatnia ($k > 0$) określająca rozmiar przestrzeni ($N = 2^k$).
2. **Tablica wartości funkcji $S$**: Tablica długości $N = 2^k$ zawierająca wartości funkcji.

## Obliczenia
Dla wszystkich par $a, b \in \{0, 1, \dots, N-1\}$ należy wyznaczyć $\Delta x$ oraz $\Delta y$, a następnie zwiększyć odpowiedni licznik o jeden:
$$ T[\Delta x][\\Delta y] \mathrel{+}= 1 $$

Wynikiem działania ma być macierz $T[N][N]$, gdzie $T[i][j]$ oznacza liczbę par $(a,b)$ spełniających powyższe warunki.

## Etapy i wymagania (Oceny)

### 1. Wersja podstawowa (Ocena max: 3.0)
* Implementacja w języku C/C++.
* Poprawne wyznaczanie macierzy zliczeń $T$.
* Wersja całkowicie sekwencyjna (bez OpenMP).

### 2. Wersja równoległa (Ocena max: 4.0)
* Zrównoleglenie przetwarzania par $(a,b)$ za pomocą biblioteki **OpenMP**.
* Odpowiednie rozwiązanie problemu współbieżnego dostępu do wspólnej macierzy wynikowej (np. redukcja, sekcje krytyczne, operacje atomowe).

### 3. Wersja rozszerzona (Ocena max: 5.0)
* Utworzenie **biblioteki dynamicznej** (np. `.dll` / `.so`).
* Przygotowanie interfejsu w języku Python wykorzystującego moduł **`ctypes`**.
* Skrypt w Pythonie musi: załadować bibliotekę, przekazać $k$ oraz tablicę $S$, odebrać wynik i zamienić go na strukturę wygodną do przetwarzania (np. **NumPy array**).

## Oczekiwane interfejsy

**C/C++:**
```c
uint64_t* compute_distribution(
    const uint32_t* S,
    uint32_t k
);
```

**Python:**
```python
import ctypes
import numpy as np

lib = ctypes.CDLL("./distribution.dll")
result = lib.compute_distribution(...)
# Konwersja na macierz NxN w NumPy
```

## Dodatkowe kryteria oceny
* Wydajność implementacji i skalowalność względem liczby wątków.
* Poprawne zarządzanie pamięcią (brak wycieków).
* Jakość dokumentacji i czytelność kodu.
* Przygotowanie testów poprawności.
* Analiza przyspieszenia uzyskanego dzięki OpenMP.
