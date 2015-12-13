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
#ifndef DISJOINT_SETS_HPP_INCLUDED
#define DISJOINT_SETS_HPP_INCLUDED

#include <string>
#include <vector>

// The responsibility of this class is to represent a disjoint sets data
// structure (also called union-find data structure or merge-find set).
//
// It keeps track of a set of elements partitioned into a number of disjoint
// (non-overlapping) subsets.
class disjoint_sets {
public:
    // Construct a disjoint set with specified number of elements. Each
    // element starts out alone in their own set.
    disjoint_sets(int elements);
    // Union by rank the sets in which a an b are located in.
    void make_union(int a, int b);
    // Validate if if a and b are in the same set. Return true if they are in the same
    // set, false otherwise.
    bool same(int a, int b);
    // Return a string representation of the disjoint set. Each index will
    // show which set it belongs to.
    std::string to_string();
private:
    // Link a and b, the parent is decided by rank.
    void make_link(int a, int b);
    // Return the index for a set in which x is located in. This is the index
    // to the root in the parent pointer tree.
    //
    // This function will do a path compression, meaning it will attempt to
    // flattening the structure of the tree while searching. It does this by
    // attaching each visited node on the way to a root node directly to the
    // root node.
    int find(int x);

    // Every set has a parent pointer tree
    struct node {
        int value;
        int rank;
        node * parent;
    };

    std::vector<node> sets;
};

#endif
