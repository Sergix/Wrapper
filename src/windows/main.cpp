#include "main.hpp"
using namespace std;

//
// Command Line Arguments for main()
//
// - wrapper [directory] [output file]
//     [0]       [1]          [2]
//
int wrap()
{
    // Application version name
    char version[29] = "wrapper-windows-v";
    strcat(version, APP_VERSION);
    strcat(version, ".exe");

    char output_file[NAME_SIZE];
    string current_file_line;
    string current_file_contents;
    int i;

    cout << "\nNOTICE\nPlace this executable in the directory of all the files you wish to package. If it is not in the correct directory, close the application now and move it." << endl;
    cin.ignore();

    cout << "\nEnter output file (.wrap will be added automatically as the file extension)\n> ";
    cin >> output_file;

    strcat(output_file, ".wrap");

    cout << "\nPackaging..." << endl;

    vector<string> filelist;
    string search_path = "./*.*";
    WIN32_FIND_DATA fd; 
    HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd); 
    if (hFind != INVALID_HANDLE_VALUE) { 
        do { 
            if (! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                filelist.push_back(fd.cFileName);
            }
        } while (::FindNextFile(hFind, &fd)); 
        ::FindClose(hFind);
    } 

    ofstream output(output_file, ios_base::out);

    // Add some metadeta to the top of the output file
    output << "###% " << output_file << "\twrapper-windows-v" << APP_VERSION << '\n' << endl;

    // Iterate through each file, read it, and spit its content out into the output file
    for (i = 0; i < filelist.size(); i++)
    {

        if (filelist[i] == version) // Skip the executable itself
            continue;

        ifstream current_file(filelist[i].c_str(), ios_base::in); // Open the file to extract it's contents
        while (getline(current_file, current_file_line)) // Loop through the file lines
        {
            current_file_contents += current_file_line + '\n'; // Spit the line contents into the full variable
        }

        output << "###* " << filelist[i] << '\n' << endl; // Output the name of the file
        output << current_file_contents << endl; // Spit the contents of the file out into the new file

        current_file_contents = "";
        current_file.close();

    }

    output.close();

    cout << "Done!";

    return 0;
}

int unwrap(char filename[NAME_SIZE] = 0)
{
    char* input_file;
    string current_line_contents;
    string current_string;
    string new_file_name;

    if (filename == 0)
    {
        cout << "\nNOTICE\nPlace this executable in the directory where you would like to unwrap the package files. If it is not in the correct directory, close the application now and move it." << endl;
        cin.ignore();

        cout << "Enter package filename\n> ";
        cin >> input_file;
    }
    else
        input_file = filename;

    cout << "Unwrapping...\n";

    ifstream package(input_file, ios_base::in);

    while (getline(package, current_line_contents))
    {
        // Create a stringstream to handle metadata comments
        istringstream current_line(current_line_contents);

        // Read the first string
        current_line >> current_string;

        // If the current read string is a metadata comment
        if (current_string == "###*")
        {
            // Read the rest of the string, which contains the filename.
            while(current_line >> current_string)
            {
                // Append the current string onto the filename (for handling filenames with spaces)
                new_file_name += current_string;
            }

            // Skip to the next iteration, which will now read from the new file
            continue;
        }

        // If the filename is empty, skip to the next iteration
        if (new_file_name == "")
            continue;

        // Open a new output file to read data from
        ofstream output(new_file_name.c_str(), ios_base::out);

        // Loop through the rest of the file
        while (getline(package, current_line_contents))
        {
            // Create a stringstream to handle metadata comments
            istringstream current_line(current_line_contents);

            // Read the first string
            current_line >> current_string;

            // If the current read string is a metadata comment
            if (current_string == "###*")
            {
                new_file_name = "";
                // Read the rest of the string, which contains the filename.
                while(current_line >> current_string)
                {
                    // Append the current string onto the filename (for handling filenames with spaces)
                    new_file_name = new_file_name + current_string;
                }

                // Skip to the next iteration, which will now read from the new file
                break;
            }

            // Output the contents to the file
            output << current_line_contents << '\n';
        }

    }

    return 0;
}

int main (int argc, char* argv[])
{
    int option;

    if (argc > 1)
    {
        unwrap(argv[1]);
        return 0;
    }

    cout << "Wrapper v" << APP_VERSION << "\nhttps://github.com/Sergix/Wrapper" << endl;
    cout << "Select an action to perform\n---------------------------\n\t1. Create a new package\n\t2. Unpack a package file" << endl;

    cout << "> ";
    cin >> option;
    switch (option)
    {
        case 1:
            wrap();
            break;

        case 2:
            unwrap();
            break;

        default:
            cout << "\nInput not recognized. Please enter the number of the option you would like to perform.";
            break;
    }

    cin.ignore();

    return 0;
}
