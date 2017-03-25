#include "main.hpp"
using namespace std;

//
// Command Line Arguments for main()
//
// - wrapper [directory] [output file]
//     [0]       [1]          [2]
//
int wrap(char output_file[])
{
    char current_file_name[256];
    char current_file_contents[131072];

    // A little trick I found somewhere ;)
    system("dir /b /s /a-d * > wrapper-filelist.temp");

    ofstream output(output_file, ios_base::out);
    ifstream filelist("wrapper-filelist.temp", ios_base::in);

    // Add some metadeta to the top of the output file
    output << output_file << endl;

    // Iterate through each file, read it, and spit its content out into the output file
    filelist.getline(current_file_name, 512);
    while (!filelist.eof())
    {
        ifstream current_file(current_file_name, ios_base::in);
        while (!current_file.eof())
        {
            current_file.getline(current_file_contents, 2048);
            strcat(current_file_contents, "\n");
        }

        output << current_file_name << endl;
        output << current_file_contents;

        filelist.getline(current_file_name, 512);
    }

    output.close();
    filelist.close();

    return 0;
}

int main (int argc, char* argv[])
{
    char output_file[256];

    cout << "Wrapper v1.0" << endl << "https://github.com/Sergix7440/Wrapper" << endl;

    cout << "\nNOTICE" << endl << "Place this executable in the directory of all the files you wish to package. If it is not in the correct directory, close the application now and move it.";

    cin.ignore();

    cout << "\nEnter output file\n> ";
    cin >> output_file;

    cout << "\nPackaging..." << endl;
    wrap(output_file);
    cout << "Done!";

    cin.ignore();

    return 0;
}
