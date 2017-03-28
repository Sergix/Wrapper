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
    char current_file_line[BUFFER_SIZE];
    char current_file_contents[BUFFER_SIZE];
    int i;

    vector<string> filelist;
    string search_path = "./*.*";
    WIN32_FIND_DATA fd; 
    HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd); 
    if(hFind != INVALID_HANDLE_VALUE) { 
        do { 
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                filelist.push_back(fd.cFileName);
            }
        } while(::FindNextFile(hFind, &fd)); 
        ::FindClose(hFind);
    } 

    ofstream output(output_file, ios_base::out);

    // Add some metadeta to the top of the output file
    output << "###* " << output_file << "\twrapper-v1.0.1\n" << endl;

    // Iterate through each file, read it, and spit its content out into the output file
    for (i = 0; i < filelist.size(); i++)
    {

        if (filelist[i] == "wrapper-v1.0.1.exe") // Skip the executable itself
            continue;

        ifstream current_file(filelist[i].c_str(), ios_base::in); // Open the file to extract it's contents
        while (!current_file.eof()) // Loop through the file lines
        {
            current_file.getline(current_file_line, 2048); // Get a new line
            strcat(current_file_contents, current_file_line); // Spit the line contents into the full variable
            strcat(current_file_contents, "\n"); // Slap a newline onto the end of each line
        }

        output << "###* " << filelist[i] << '\n' << endl; // Output the name of the file
        output << current_file_contents << endl; // Spit the contents of the file out into the new file

        current_file_contents[0] = 0; // Clear the string
        current_file.close();

    }

    output.close();

    return 0;
}

int main (int argc, char* argv[])
{
    char output_file[256];

    cout << "Wrapper v1.0.1" << endl << "https://github.com/Sergix7440/Wrapper" << endl;

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
