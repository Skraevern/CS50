Compile: clang -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm -o filter filter.c helpers.c

Grayscale:      ./filter -g images/yard.bmp out.bmp 
Sepia:          ./filter -s images/yard.bmp out.bmp
Reflect:        ./filter -r images/yard.bmp out.bmp
Blur:           ./filter -b images/yard.bmp out.bmp