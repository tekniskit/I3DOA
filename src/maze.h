#ifndef I3DOA_MAZE_H
#define I3DOA_MAZE_H

#include <string>

class Field {
public:
    Field(std::string name) : name(name) {
        setNeighbors();

        visited = false;
        exit = false;
        start = false;
        steps = 0;
    }

    void setNeighbors(Field* n1 = nullptr, Field* n2 = nullptr, Field* n3 = nullptr, Field* n4 = nullptr) {
        neighbors[0] = n1;
        neighbors[1] = n2;
        neighbors[2] = n3;
        neighbors[3] = n4;
    }

    Field* neighbors[4];
    bool visited;
    int steps;
    bool exit;
    bool start;
    std::string name;
};


void maze(Field& field, int steps = 0) {
    field.visited = true;
    field.steps = steps;

    std::cout << "Visited " << field.name << " in " << field.steps << " steps." << std::endl;

    if (field.exit) return;

    for (int i=0; i<4; i++) {
        Field* n = field.neighbors[i];

        if (n != nullptr && !n->visited)
            maze(*n, field.steps + 1);
    }
}

void shortestPath(Field& field) {
    std::cout << field.name << std::endl;

    if (field.start) return;

    Field* min = field.neighbors[0];

    for (int i=1; i<4; i++) {
        Field* n = field.neighbors[i];

        if (n != nullptr && n->steps < min->steps)
            min = n;
    }

    shortestPath(*min);
}

#endif //I3DOA_MAZE_H