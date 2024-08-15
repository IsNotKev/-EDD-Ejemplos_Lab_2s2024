#include "matrix.h"

int main() {
    Matrix m;
    m.insert(1, 5, true);
    m.insert(0, 3, false);
    m.insert(1, 1, false);
    m.insert(4, 1, true);
    m.insert(5, 3, false);
    m.insert(5, 10, true);
    m.insert(1, 1, true);

    m.print();

    return 0;
}
