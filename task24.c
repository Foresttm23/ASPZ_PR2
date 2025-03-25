#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSG "Function: %s, local: %p\n"

void func3() {
    int local;
    printf(MSG, __func__, &local);
    pause();
}

void func2() {
    int local;
    printf(MSG, __func__, &local);
    func3();
}

void func1() {
    int local;
    printf(MSG, __func__, &local);
    func2();
}

int main() {
    int local;
    printf(MSG, __func__, &local);
    func1();
    return 0;
}