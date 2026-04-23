This simulation project was created for a university course.
The project is still in progress.

# Licznik rowerowy w C++

Projekt przedstawia przykładową implementację licznika rowerowego w języku C++ z wykorzystaniem danych z czujnika Halla. Program symuluje działanie urządzenia, obliczając prędkość, dystans, średnią i maksymalną prędkość oraz rozpoznając stan jazdy.

## Funkcjonalność

- odczyt impulsów z czujnika Halla
- obliczanie aktualnej prędkości
- obliczanie przebytego dystansu
- obliczanie średniej prędkości
- zapamiętywanie maksymalnej prędkości
- obsługa stanów:
  - `Idle`
  - `Riding`
  - `Paused`

## Zastosowane wzorce projektowe

- **Adapter** – oddzielenie logiki programu od źródła impulsów
- **Strategy** – możliwość zmiany sposobu filtrowania prędkości
- **Observer** – powiadamianie modułów wyświetlania i logowania
- **State** – obsługa różnych stanów pracy licznika

## Struktura projektu

- `include/` – pliki nagłówkowe
- `src/` – pliki źródłowe
- `CMakeLists.txt` – konfiguracja budowania projektu

## Budowanie projektu

```bash
mkdir build
cd build
cmake ..
cmake --build .
