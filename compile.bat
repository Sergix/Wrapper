@echo off
echo Compiling...
cd /MinGW/bin
g++ -static-libstdc++ -static-libgcc -o C:/Users/Sergi/Documents/GitHub/Wrapper/build/wrapper-v%1.exe /Users/Sergi/Documents/GitHub/Wrapper/src/main.cpp
cd /Users/Sergi/Documents/GitHub/Wrapper