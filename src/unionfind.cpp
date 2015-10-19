#include "disjoint_sets.hpp"

#include <iostream>
#include <sstream>

// Implementation to handle test cases from Kattis on stdin.
int main()
{
    // I/O performance adjustment
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q; // num elements, num operations
    std::cin >> n >> q;

    disjoint_sets sets(n);

    char op;
    int a, b;
    std::stringstream output;
    for (auto i = 0; i < q; i++) {
        std::cin >> op >> a >> b;
        if (op == '?')
            output << (sets.same(a, b) ? "yes\n" : "no\n");
        else
            sets.make_union(a, b);
    }

    std::cout << output.str();

    return 0;
}
