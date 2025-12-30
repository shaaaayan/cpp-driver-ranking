# Driver Ranking System (C++)

## Overview
This project implements a **Driver Ranking System** in C++ that processes race performance data, validates inputs, ranks drivers by completion time, and computes time differentials from the leader.

The program emphasizes **robust input handling**, **modular design**, and **clean formatting**, following best practices for introductory and intermediate C++ programming.

---

## Features
- Parses structured driver data from standard input
- Trims and validates input fields (name, country, time, ranking number)
- Handles invalid and malformed data gracefully
- Ranks drivers by fastest completion time
- Computes and displays time differences from first place
- Outputs clean, formatted rankings

---

## Files
| File | Description |
|-----|------------|
| `rank.cpp` | Program entry point and main control flow |
| `rank_functions.h` | Function declarations |
| `rank_functions.cpp` | Core logic for trimming, parsing, ranking, and output |

---

## Sample Input

56.7884 MDV 3 Tapp
62.454 NGR 26 Hoss
27.3388 AUS 24 Jahnke

## Sample Output

Final results!!
[1] 27.34 Jahnke (AUS) +0.00
[2] 31.23 Rutz (LUX) +3.89
[3] 50.10 Shoop (MDV) +22.76


---

## Build & Run
Compile using `g++` (C++17):

```bash
g++ -std=c++17 -Wall -Wextra -Werror rank.cpp rank_functions.cpp -o rank
./rank

