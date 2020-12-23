#include "std.hpp"

std::optional<int> foo(bool flag) {
    if (flag) return {100};
    else return {};
}

int main() {
    auto op = foo(true);
    std::cout << op.has_value() << std::endl;
    return 0;
}
