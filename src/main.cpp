#include "maple.hpp"

int main() {
    Maple &maple = Maple::instantiate();
    maple.start();
    return 0;
}