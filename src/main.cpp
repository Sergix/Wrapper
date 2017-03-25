#include "main.hpp"
using namespace std;

//
// Command Line Arguments for main()
//
// - wrapper [directory] [output file]
//     [0]       [1]          [2]
//
int wrap(char directory[])
{
    char command[259] = "cd ";
    strcat(command, directory);
    cout << command;
    system(command);
    system("dir /b /s /a-d * > temp.dat");


    return 0;
}

int main (int argc, char* argv[])
{
    char directory[256];
    string output_file;

    cout << "Wrapper v1.0" << endl << "https://github.com/Sergix7440/Wrapper" << endl;

    cout << "\nEnter directory to be wrapped\n> ";
    cin >> directory;

    cout << "\nEnter output file\n> ";
    cin >> output_file;

    cout << "\nPackaging..." << endl;
    wrap(directory);
    cout << "Done!";

    

    return 0;
}
