#ifndef I3DOA_MAZE_H
#define I3DOA_MAZE_H

#include <string>

class Field {
public:
    Field(std::string name, bool exit = false) : name(name), exit(exit) {
        up = nullptr;
        down = nullptr;
        left = nullptr;
        right = nullptr;
        visited = false;
        steps = 0;
    }

    Field* up;
    Field* down;
    Field* left;
    Field* right;
    bool visited;
    int steps;
    bool exit;
    std::string name;
};


void maze(Field& field, int steps = 0) {
    field.visited = true;
    field.steps = steps;

    std::cout << "visited " << field.name << " in " << field.steps << " steps." << std::endl;

    if (field.exit) return;

    if (field.up != nullptr && !field.up->visited) maze(*field.up, field.steps+1);
    if (field.down != nullptr && !field.down->visited) maze(*field.down, field.steps+1);
    if (field.left != nullptr && !field.left->visited) maze(*field.left, field.steps+1);
    if (field.right != nullptr && !field.right->visited) maze(*field.right, field.steps+1);
}


#endif //I3DOA_MAZE_H