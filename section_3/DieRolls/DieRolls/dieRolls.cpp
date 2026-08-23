#include <ctime>
#include <fmt/base.h>
#include <stdlib.h>

int main() {

    srand(time(nullptr));

    for (int i = 1; i < 11; ++i) {
        fmt::println("Roll {}: {}", i, rand() % 6 + 1);
    }

    return 0;
}
