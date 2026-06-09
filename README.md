# Projekt AiSD
Projekt zaliczeniowy. Zamiast stawiać wirtualną maszynę z Linuxem, pracowałem na Windowsie z wykorzystaniem MSYS2, żeby mieć wygodny dostęp do make i g++. Zależności i kompilacja działają identycznie wszędzie indziej. Wersja Pythona z jakiej korzystałem to 3.10.11.

## Instalacja bibliotek
Wymagana biblioteka numpy: `pip install numpy`

## Uruchomienie
Kompilacja i uruchomienie:
`make`
`python main.py`

## Krótki opis implementacji:
- Wersja sekwencyjna w C++ (zwykła podwójna pętla i arytmetyka modulo).
- Zrównoleglenie za pomocą dyrektyw OpenMP (w celu uniknięcia nadpisywania wyników w tablicy przez wiele wątków zastosowano dyrektywę `#pragma omp atomic`).
- Przekształcenie kodu C++ w bibliotekę dynamiczną i udostępnienie jej dla języka Python poprzez moduł `ctypes`.
