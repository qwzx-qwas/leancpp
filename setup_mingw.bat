@echo off
echo Setting up MinGW environment...
set PATH=D:\MinGW\mingw64\bin;%PATH%
echo MinGW PATH: D:\MinGW\mingw64\bin
echo.
echo Testing g++ version:
g++ --version
echo.
echo Testing compilation:
g++ --version | findstr "8.1.0"
if %errorlevel% equ 0 (
    echo MinGW setup successful!
) else (
    echo MinGW setup failed!
)
pause
