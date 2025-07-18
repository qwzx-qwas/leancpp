@echo off
chcp 65001>nul
if "%1"=="" (
    echo Usage: compile.bat filename.cpp
    echo Example: compile.bat hello.cpp
    exit /b 1
)

set filename=%~n1
echo Compiling %1...
D:\MinGW\mingw64\bin\g++.exe -fdiagnostics-color=always -g -std=c++17 -Wall "%1" -o "%filename%.exe"

if %errorlevel% equ 0 (
    echo ✅ Compilation successful!
    echo Running %filename%.exe...
    echo.
    "%filename%.exe"
) else (
    echo ❌ Compilation failed!
)
