#include <iostream>
#include "maze.h"

int main() {
    Field f11("11");
    Field f12("12");
    Field f13("13");
    Field f14("14");

    Field f21("21");
    Field f22("22");
    Field f23("23");
    Field f24("24");

    Field f31("31");
    Field f32("32");
    Field f33("33");
    Field f34("34");

    Field f41("41");
    Field f42("42");
    Field f43("43");
    Field f44("44");

    Field start("start");
    start.start = true;

    Field exit("exit");
    exit.exit = true;

    start.setNeighbors(&f11);
    f11.setNeighbors(&start, &f12, &f21);
    f12.setNeighbors(&f13, &f11);
    f13.setNeighbors(&f12);
    f14.setNeighbors(&f24);
    f21.setNeighbors(&f11, &f31);
    f22.setNeighbors(&f32);
    f23.setNeighbors(&f24, &f33);
    f24.setNeighbors(&f14, &f23, &f34);
    f31.setNeighbors(&f21, &f32, &f41);
    f32.setNeighbors(&f22, &f31);
    f33.setNeighbors(&f23, &f43);
    f34.setNeighbors(&f24, &f44);
    f41.setNeighbors(&f31, &f42);
    f42.setNeighbors(&f41, &f43);
    f43.setNeighbors(&f42, &f33);
    f44.setNeighbors(&f34, &exit);
    exit.setNeighbors(&f44);

    maze(start);
    shortestPath(exit);

    return 0;
}
