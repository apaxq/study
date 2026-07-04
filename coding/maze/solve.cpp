#include "maze.h"
#include "path.h"
#include<queue>
#include<vector>
#include<list>
#include<utility>
#include<iostream>
#include<sstream>

path solve_dfs(Maze& m, int rows, int cols);
path solve_bfs(Maze& m, int rows, int cols);
path solve_dijkstra(Maze& m, int rows, int cols);
path solve_tour(Maze& m, int rows, int cols);

bool checkPath(path p, point position);
bool checkDirection(Maze& m, path& p, path& visitedRooms, point& position, int direction);
void checkDirection(Maze& m, path& p, queue<path>& pQueue, queue<point>& positionQueue, point& position, int direction);
void checkDirection(Maze& m, path& p, priority_queue <pair<uint32_t,point>, vector<pair<uint32_t,point>>, greater<pair<uint32_t,point>>>& directionQueue, point& position, int direction);
bool checkAllDirections(Maze& m, path& p, path& visitedRooms, point& position);

int main(int argc, char** argv)
{
    if(argc != 4)
    {
        cerr << "usage:\n"
             << "./maze option rows cols\n"
             << " options:\n"
             << "  -dfs: depth first search (backtracking)\n"
             << "  -bfs: breadth first search\n"
             << "  -dij: dijkstra's algorithm\n"
             << "  -tour: all corners tour\n"
             << "  -basic: run dfs, bfs, and dij\n"
             << "  -advanced: run dfs, bfs, dij and tour" << endl;
        return 0;
    }
    string opt(argv[1]);

    int rows, cols;
    stringstream s;
    s << argv[2] << " " << argv[3];
    s >> rows >> cols;

    // construct a new random maze;
    Maze m(rows, cols);

    // print the initial maze out
    cout << "Initial maze" << endl;
    m.print_maze(cout, opt == "-dij" || opt == "-tour");

    if(opt == "-dfs")
    {
        cout << "\nSolved dfs" << endl;
        path p = solve_dfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);
    }


    if(opt == "-bfs")
    {
        cout << "\nSolved bfs" << endl;
        path p = solve_bfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);
    }

    if(opt == "-dij")
    {
        cout << "\nSolved dijkstra" << endl;
        path p = solve_dijkstra(m, rows, cols);
        m.print_maze_with_path(cout, p, true, false);
    }

    if(opt == "-tour")
    {
        cout << "\nSolved all courners tour" << endl;
        path p = solve_tour(m, rows, cols);
        m.print_maze_with_path(cout, p, true, true);
    }
    if(opt == "-basic")
    {
        cout << "\nSolved dfs" << endl;
        path p = solve_dfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);

        cout << "\nSolved bfs" << endl;
        p = solve_bfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);

        cout << "\nSolved dijkstra" << endl;
        p = solve_dijkstra(m, rows, cols);
        m.print_maze_with_path(cout, p, true, false);
    }
    if(opt == "-advanced")
    {
        cout << "\nSolved dfs" << endl;
        path p = solve_dfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);

        cout << "\nSolved bfs" << endl;
        p = solve_bfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);

        cout << "\nSolved dijkstra" << endl;
        p = solve_dijkstra(m, rows, cols);
        m.print_maze_with_path(cout, p, true, false);

        cout << "\nSolved all courners tour" << endl;
        p = solve_tour(m, rows, cols);
        m.print_maze_with_path(cout, p, true, true);
    }
}

path solve_dfs(Maze& m, int rows, int cols)
{
    path p;
    path visitedRooms;

    point position;
    position.first = 0;
    position.second = 0;
    p.push_back(position);

    bool solved = false;

    while(!solved) {
        if (checkPath(visitedRooms, position)) {
            // We've been here before, go back
            p.pop_back();
            position = p.back();
        }else {
            if (!checkAllDirections(m, p, visitedRooms, position)) {
                // No movable position, add to visited rooms and go back
                visitedRooms.push_back(position);
                p.pop_back();
                position = p.back();
            }
        }

        if (position.first == rows-1 && position.second == cols - 1) {
            // We've found a solution, we don't need to loop again!
            solved = true;
        }
    }

    return p;
}

path solve_bfs(Maze& m, int rows, int cols)
{
    path p;
    path visitedRooms;

    point position;
    position.first = 0;
    position.second = 0;

    queue<path> pQueue;
    pQueue.push(p);

    queue<point> positionQueue;
    positionQueue.push(position);

    bool solved = false;

    while (!solved) {
        position = positionQueue.front();
        p = pQueue.front();

        positionQueue.pop();
        pQueue.pop();

        p.push_back(position);

        if (!checkPath(visitedRooms, position)) {
            visitedRooms.push_back(position);
            checkDirection(m, p, pQueue, positionQueue, position, DOWN);
            checkDirection(m, p, pQueue, positionQueue, position, LEFT);
            checkDirection(m, p, pQueue, positionQueue, position, UP);
            checkDirection(m, p, pQueue, positionQueue, position, RIGHT);
        }

        if (position.first == rows-1 && position.second == cols - 1) {
            solved = true;
        }
    }

    return p;
}

path solve_dijkstra(Maze& m, int rows, int cols)
{
    path p;
    path visitedRooms;

    point position;
    position.first = 0;
    position.second = 0;

    queue<path> pQueue;
    pQueue.push(p);

    queue<point> positionQueue;
    positionQueue.push(position);

    priority_queue <pair<uint32_t,point>, vector<pair<uint32_t,point>>, greater<pair<uint32_t,point>>> directionQueue;

    bool solved = false;

    while (!solved) {
        position = positionQueue.front();
        p = pQueue.front();

        positionQueue.pop();
        pQueue.pop();

        p.push_back(position);

        if (position.first == rows-1 && position.second == cols - 1) {
            solved = true;
        }

        if (!checkPath(visitedRooms, position)) {
            visitedRooms.push_back(position);

            checkDirection(m, p, directionQueue, position, DOWN);
            checkDirection(m, p, directionQueue, position, LEFT);
            checkDirection(m, p, pQueue, positionQueue, position, UP);
            checkDirection(m, p, pQueue, positionQueue, position, RIGHT);

            while (!directionQueue.empty()) {
                if (!checkPath(visitedRooms, directionQueue.top().second)) {
                    positionQueue.push(directionQueue.top().second);
                    pQueue.push(p);
                    directionQueue.pop();
                }else {
                    directionQueue.pop();
                }
            }
        }
    }

    return p;
}

path solve_tour(Maze& m, int rows, int cols)
{
    return list<point>();
}

// Helper Functions

bool checkPath(path p, point position) {
    if (!p.empty()) {
        for (auto i=p.begin(); i!=p.end(); ++i) {
            if (i->first == position.first && i->second == position.second) {
                return true;
            }
        }
    }

    return false;
}

bool checkDirection(Maze& m, path& p, path& visitedRooms, point& position, int direction) {
    if (m.can_go(direction, position.first, position.second)) {
        point tempPosition;
        tempPosition.first = position.first + moveIn(direction).first;
        tempPosition.second = position.second + moveIn(direction).second;

        if (!checkPath(visitedRooms, tempPosition) && !checkPath(p, tempPosition)) {
            position = tempPosition;
            p.push_back(position);
            return true;
        }
    }
    return false;
}

void checkDirection(Maze& m, path& p, queue<path>& pQueue, queue<point>& positionQueue, point& position, int direction) {
    if (m.can_go(direction, position.first, position.second)) {
        point tempPosition;
        tempPosition.first = position.first + moveIn(direction).first;
        tempPosition.second = position.second + moveIn(direction).second;

        positionQueue.push(tempPosition);
        pQueue.push(p);
    }
}

void checkDirection(Maze& m, path& p, priority_queue <pair<uint32_t,point>, vector<pair<uint32_t,point>>, greater<pair<uint32_t,point>>>& directionQueue, point& position, int direction) {
    if (m.can_go(direction, position.first, position.second)) {
        point tempPosition;
        tempPosition.first = position.first + moveIn(direction).first;
        tempPosition.second = position.second + moveIn(direction).second;

        directionQueue.push(make_pair(m.cost(position.first, position.second, direction), tempPosition));
    }
}

bool checkAllDirections(Maze& m, path& p, path& visitedRooms, point& position) {
    return checkDirection(m, p, visitedRooms, position, DOWN)
                || checkDirection(m, p, visitedRooms, position, LEFT)
                || checkDirection(m, p, visitedRooms, position, UP)
                || checkDirection(m, p, visitedRooms, position, RIGHT);
}