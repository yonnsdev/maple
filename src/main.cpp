#include "maple.hpp"

int main() {
    Maple &maple = Maple::instantiate();
    maple.run();
    return 0;
}