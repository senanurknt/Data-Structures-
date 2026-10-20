#include <stdio.h>

void hanoi(int n, char kaynak, char hedef, char yardimci) {
    if (n == 1) {
        printf("Disk 1: %c cubugundan %c cubuguna tasindi\n", kaynak, hedef);
        return;
    }
    hanoi(n - 1, kaynak, yardimci, hedef);
    printf("Disk %d: %c cubugundan %c cubuguna tasindi\n", n, kaynak, hedef);
    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
    int n = 3; // İstersen disk sayısını buradan değiştirirsin
    printf("--- Hanoi Kuleleri Cozumu (%d Disk) ---\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
