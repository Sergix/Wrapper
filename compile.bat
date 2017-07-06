@echo off
echo Compiling...
cd /MinGW/bin
g++ -static-libstdc++ -static-libgcc -o C:/Users/Sergi/Development/GitHub/Wrapper/build/windows/wrapper-windows-v%1.exe /Users/Sergi/Development/GitHub/Wrapper/src/windows/main.cpp
cd /Users/Sergi/Development/GitHub/Wrapper