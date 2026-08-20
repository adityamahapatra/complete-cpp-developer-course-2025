#include <array>
#include <iostream>
using namespace std;

int main() {

    array<int, 10> myNums;

    for (std::size_t i = 0; i < myNums.size(); i++) {
        myNums[i] = static_cast<int>(i * 2);
    }

    for (int element : myNums) {
        cout << element << endl;
    }

    return 0;
}
