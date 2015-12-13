#include "disjoint_sets.hpp"

#include <gmock/gmock.h>

TEST(DisjointSetsTest, Kattis1)
{
    disjoint_sets sets(10);

    EXPECT_FALSE(sets.same(1, 3));
    EXPECT_FALSE(sets.same(3, 1));

    sets.make_union(1, 8);
    EXPECT_TRUE(sets.same(1, 8));
    EXPECT_TRUE(sets.same(8, 1));

    sets.make_union(3, 8);
    EXPECT_TRUE(sets.same(3, 8));
    EXPECT_TRUE(sets.same(8, 3));

    EXPECT_TRUE(sets.same(1, 3));
    EXPECT_TRUE(sets.same(3, 1));
}

TEST(DisjointSetsTest, Kattis2)
{
    disjoint_sets sets(4);

    EXPECT_TRUE(sets.same(0, 0));

    sets.make_union(0, 1);
    EXPECT_TRUE(sets.same(0, 1));
    EXPECT_TRUE(sets.same(1, 0));

    sets.make_union(1, 2);
    EXPECT_TRUE(sets.same(1, 2));
    EXPECT_TRUE(sets.same(2, 1));

    sets.make_union(0, 2);
    EXPECT_TRUE(sets.same(0, 2));
    EXPECT_TRUE(sets.same(2, 0));

    EXPECT_FALSE(sets.same(0, 3));
    EXPECT_FALSE(sets.same(3, 0));
}

TEST(DisjointSetsTest, StartingState)
{
    const auto n = 1000;
    disjoint_sets sets(n);

    for (auto i = 0u; i < n; i++) {
        for (auto j = 0u; j < n; j++) {
            if (i == j)
                EXPECT_TRUE(sets.same(i, j));
            else {
                EXPECT_FALSE(sets.same(i, j));
                EXPECT_FALSE(sets.same(j, i));
            }
        }
    }
}

TEST(DisjointSetsTest, ComplexSet)
{
    disjoint_sets sets(20);

    sets.make_union(1, 2);
    sets.make_union(2, 3);
    sets.make_union(3, 4);
    sets.make_union(5, 6);
    sets.make_union(6, 1);

    sets.make_union(9, 10);
    sets.make_union(10, 11);
    sets.make_union(11, 12);
    sets.make_union(12, 13);
    sets.make_union(13, 14);
    sets.make_union(14, 9);

    sets.make_union(10, 2);

    EXPECT_TRUE(sets.same(1, 2));
    EXPECT_TRUE(sets.same(2, 1));
    EXPECT_TRUE(sets.same(2, 3));
    EXPECT_TRUE(sets.same(3, 2));
    EXPECT_TRUE(sets.same(3, 4));
    EXPECT_TRUE(sets.same(4, 3));
    EXPECT_TRUE(sets.same(5, 6));
    EXPECT_TRUE(sets.same(6, 5));
    EXPECT_TRUE(sets.same(6, 1));
    EXPECT_TRUE(sets.same(1, 6));

    EXPECT_TRUE(sets.same(10, 9));
    EXPECT_TRUE(sets.same(9, 10));
    EXPECT_TRUE(sets.same(11, 10));
    EXPECT_TRUE(sets.same(10, 11));
    EXPECT_TRUE(sets.same(12, 11));
    EXPECT_TRUE(sets.same(11, 12));
    EXPECT_TRUE(sets.same(13, 12));
    EXPECT_TRUE(sets.same(12, 13));
    EXPECT_TRUE(sets.same(14, 13));
    EXPECT_TRUE(sets.same(13, 14));
    EXPECT_TRUE(sets.same(9, 14));
    EXPECT_TRUE(sets.same(14, 9));

    EXPECT_TRUE(sets.same(10, 2));
    EXPECT_TRUE(sets.same(2, 10));

    EXPECT_TRUE(sets.same(1, 14));
    EXPECT_TRUE(sets.same(14, 1));
    EXPECT_TRUE(sets.same(4, 13));
    EXPECT_TRUE(sets.same(13, 4));

    EXPECT_FALSE(sets.same(1, 19));
    EXPECT_FALSE(sets.same(19, 1));
    EXPECT_FALSE(sets.same(5, 16));
    EXPECT_FALSE(sets.same(16, 5));
    EXPECT_FALSE(sets.same(17, 2));
    EXPECT_FALSE(sets.same(2, 17));
}

TEST(DisjointSetsTest, MaxRank)
{
    disjoint_sets sets1(0);
    EXPECT_EQ(sets1.max_rank(), 0);

    disjoint_sets sets2(5);
    EXPECT_EQ(sets2.max_rank(), 1);

    sets2.make_union(1, 2);
    sets2.make_union(3, 4);
    EXPECT_EQ(sets2.max_rank(), 2);

    sets2.make_union(4, 0);
    EXPECT_EQ(sets2.max_rank(), 3);

    sets2.make_union(0, 1);
    EXPECT_EQ(sets2.max_rank(), 5);

    disjoint_sets sets3(1000);
    for (auto i = 1; i < 1000; i++)
        sets3.make_union(i, i - 1);
    EXPECT_EQ(sets3.max_rank(), 1000);
}

int main(int argc, char ** argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
