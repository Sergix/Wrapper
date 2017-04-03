<img src="https://github.com/Sergix7440/Wrapper/blob/master/wrapper.png?raw=true" alt="Wrapper"/>

## Programming language package manager.

### Definition
The goal of this project is to create a simple solution to package multiple files and metadata into a single portable file that can be built and extracted using the application.
The metadata of the package, such as header and transfer information, bundle data, and file "borders" will all be handled by the application.

### Implementation
This project will be built in C++ and compiled for Windows and Linux using the MinGW g++ compiler. The source code for the Linux version will vary from the Windows version due to directory formatting.

### Dependencies
One of the aims of this project is that the source code will rely on 0 dependencies outside of the standard C++ compiler/libraries and included source code.

### Builds
Once you build a file from the source code to an executable (.exe), push it to the /build folder, along with the associated changelog (see Changelog section), and the source code (see Source Code section).
The format of the executable's filename is as follows: "wrapper-v(build version).exe"

### Source Code
Keep all updated and current source code in the /src directory, which should be updated with every build.
When pushing the source code with a build, keep the file names the same. If creating a new file, simply name the file as the topic of its contents. Keep the name clear and concise, and the file's contents in line with its name.
As mentioned in the "Builds" section, package the source code with every build into a ".zip" file that should be placed in the /build/src directory when pushing a build.
The format for the file should be as follows: "(build version)-src.zip".

### Changelog
Every time an update is pushed, the changelog will be updated and pushed as well.
It is highly recommended that every time you build you update the changelog. Once you add something to the changelog, DO NOT remove the entry if, and only if, it is incorrect.
The global changelog file is in the root folder of the project and is named "changelog.txt"; EVERY note will go into this file. It is also required that when you push a build you push an associated changelog file, formatted "(build version)-changelog.txt". This file should be pushed to the /build/changelog directory.
The format for a changelog entry is as follows:
`
[MM/DD/YYYY-HH:MM (version)]   
(entry contents)   
(entry contents)   
(newline before next entry)   
`

Timestamps should be in 24-hour (aka military) time.

### Documentation
Documentation should be published with every major release.
A "major" release is defined as one with the version number that corresponds to the following examples: "1.x", "2.x", "3.x"
Documentation guidelines are to be written in Markdown formatting. Guidelines are as follows:

- Main Header: \#
- Subheadings: \#\#\#
- Standard text
- Code blocks use markdown code block formatting

## Build Targets
As of the latest update, Wrapper is now available for both Windows and Linux systems. All builds are as follows:

    - 1.0       [Windows]           DEPRECATED
    - 1.0.1     [Windows]
    - 1.0.2     [Windows]
    - 1.0.2.1   [Windows]   [Linux]
    - 1.0.2.2   [Windows]   [Linux] DEPRECATED
    - 1.0.2.3   [Windows]   [Linux]
