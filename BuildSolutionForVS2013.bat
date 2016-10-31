echo off

mkdir Build
cd Build
REM This is for Building a Visual studio 2013 Solution for the experemental program, also note that x64 is targeted
cmake ../ -G "Visual Studio 12 2013 Win64"
