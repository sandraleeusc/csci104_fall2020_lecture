#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Provided for students.
void read_maze(string filename, vector<vector<char> > &maze) {
    ifstream ifile(filename);
    int size = 0;
    for (int i = 0; ifile; i++) {
        string line;
        getline(ifile, line);
        if (i == 0) {
            vector<char> maze_line;
            for (char c : line) {
                maze_line.push_back(c);
            }
            size = maze_line.size();
            maze.push_back(maze_line);
        } else {
            vector<char> maze_line(size);
            for (int j = 0; j < line.size(); j++) {
                maze_line[j] = line[j];
            }
            for (int j = line.size(); j < maze_line.size(); j++) {
                maze_line[j] = ' ';
            }
            maze.push_back(maze_line);
        }
    }
    maze.pop_back();
    ifile.close();
}

bool solve(vector<vector<char> > &maze) {
    return true;
}

// Driver code provided.
int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "argc must be 3" << endl; // run like ----> ./maze_solver maze.txt output.txt
        return 1;
    }
    vector<vector<char> > maze;
    read_maze(argv[1], maze);

    if (solve(maze)) {
        ofstream ofile(argv[2]);
        if (ofile) {
            for (int i = 0; i < maze.size(); i++) {
                for (int j = 0; j < maze[i].size(); j++) {
                    ofile << maze[i][j];
                }
                ofile << endl;
            }
        }
        ofile.close();
    }

    return 0;
}

