#include <gtest/gtest.h>
#include <sstream>
#include "../include/trapezoid.hpp"
#include "../include/rhombus.hpp"
#include "../include/pentagon.hpp"

TEST(TrapezoidTest, Area) {
    Trapezoid t(Point(0,0), Point(4,0), Point(1,3), Point(3,3));
    EXPECT_DOUBLE_EQ(9.0, static_cast<double>(t));
}

TEST(TrapezoidTest, Centre) {
    Trapezoid t(Point(0,0), Point(4,0), Point(1,3), Point(3,3));
    Point c = t.centre();
    EXPECT_DOUBLE_EQ(2.0, c.x);
    EXPECT_DOUBLE_EQ(1.5, c.y);
}

TEST(TrapezoidTest, Equal) {
    Trapezoid t1(Point(0,0), Point(4,0), Point(1,3), Point(3,3));
    Trapezoid t2(Point(0,0), Point(4,0), Point(1,3), Point(3,3));
    Trapezoid t3(Point(1,1), Point(5,1), Point(2,4), Point(4,4));
    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

TEST(RhombusTest, Area) {
    Rhombus r(Point(0,1), Point(1,0), Point(0,-1), Point(-1,0));
    EXPECT_DOUBLE_EQ(2.0, static_cast<double>(r));
}

TEST(RhombusTest, Centre) {
    Rhombus r(Point(0,1), Point(1,0), Point(0,-1), Point(-1,0));
    Point c = r.centre();
    EXPECT_DOUBLE_EQ(0.0, c.x);
    EXPECT_DOUBLE_EQ(0.0, c.y);
}

TEST(RhombusTest, Equal) {
    Rhombus r1(Point(0,1), Point(1,0), Point(0,-1), Point(-1,0));
    Rhombus r2(Point(0,1), Point(1,0), Point(0,-1), Point(-1,0));
    Rhombus r3(Point(1,2), Point(2,1), Point(1,0), Point(0,1));
    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
}

TEST(PentagonTest, Area) {
    Pentagon p;
    EXPECT_GT(static_cast<double>(p), 0.0);
}

TEST(PentagonTest, Centre) {
    Pentagon p;
    Point c = p.centre();
    EXPECT_NEAR(0.0, c.x, 1e-9);
    EXPECT_NEAR(0.0, c.y, 1e-9);
}

TEST(PentagonTest, Equal) {
    Pentagon p1;
    Pentagon p2;
    EXPECT_TRUE(p1 == p2);
}

TEST(FigureTest, Polymorphism) {
    Trapezoid* t = new Trapezoid(Point(0,0), Point(4,0), Point(1,3), Point(3,3));
    Rhombus* r = new Rhombus(Point(0,1), Point(1,0), Point(0,-1), Point(-1,0));
    Pentagon* p = new Pentagon();
    Figure* figs[] = {t, r, p};

    for (int i = 0; i < 3; ++i) {
        Point c = figs[i]->centre();
        EXPECT_GT(static_cast<double>(*figs[i]), 0.0);
    }

    delete t;
    delete r;
    delete p;
}

TEST(FigureTest, InvalidTrapezoid) {
    Trapezoid t;
    std::istringstream in("0 0 0 0 1 3 3 3");
    EXPECT_THROW(in >> t, const char*);
}

TEST(FigureTest, InvalidRhombus) {
    Rhombus r;
    std::istringstream in("0 0 1 1 2 2 3 3");
    EXPECT_THROW(in >> r, const char*);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}