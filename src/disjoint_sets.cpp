// Disjoint sets implementation.
// Copyright (C) 2015 Mattias Harrysson
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#include "disjoint_sets.hpp"

#include <algorithm>
#include <sstream>

disjoint_sets::disjoint_sets(int elements)
    : sets(elements)
{
    for (auto i = 0; i < elements; i++) {
        auto * node = &sets[i];
        node->value = i;
        node->rank = 0;
        node->parent = node;
    }
}

void disjoint_sets::make_union(int a, int b)
{
    const auto a_root = find(a);
    const auto b_root = find(b);
    if (a_root != b_root)
        make_link(a_root, b_root);
}

bool disjoint_sets::same(int a, int b)
{
    return a == b ? true : find(a) == find(b);
}

std::string disjoint_sets::to_string()
{
    std::stringstream ss;

    for (auto i = 0; i < sets.size(); i++)
        ss << "[" << i << "]: " << find(i) << "\n";

    return ss.str();
}

int disjoint_sets::max_rank()
{
    if (sets.empty())
        return 0;

    std::vector<int> counts(sets.size(), 0);
    for (auto i = 0; i < sets.size(); i++)
        counts[find(i)]++;

    return *std::max_element(counts.begin(), counts.end());
}

void disjoint_sets::make_link(int a, int b)
{
    auto * i = &sets[a];
    auto * j = &sets[b];

    if (i->rank < j->rank)
        i->parent = j;
    else {
        j->parent = i;
        if (i->rank == j->rank)
            i->rank++;
    }
}

int disjoint_sets::find(int x)
{
    auto * p = sets[x].parent;
    auto px = p->value;

    if (px != x)
        p = &sets[find(px)];

    return p->value;
}
