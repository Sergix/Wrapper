@echo off
cd test
del test.wrap
echo Hello World>info.txt
echo Hi me>info2.txt
move ..\build\windows\wrapper-windows-v%1.exe .
start wrapper-windows-v%1.exe
pause
del info.txt
del info2.txt
del wrapper-windows-v%1.exe
cd ..