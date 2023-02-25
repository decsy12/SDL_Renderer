@echo off

rem Get name of thhe current directory
for %%i in ("%~dp0.") do set "currentdir=%%~nxi"

rem Recursively find all .c files in folder
for /r %%i in (*.c) do (
    echo Found file: %currentdir%\src\%%~nxi
)

rem Recursively find all .c files in folder
for /r %%i in (*.h) do (
    echo Found file: %currentdir%\inc\%%~nxi
)

echo Compiling SDL Renderer...
cd C:\Users\Declan\Documents\Projects\Rendering\SDL_Renderer_Engine
g++ -o main.exe -Iinc ./src/main.c -Iinc ./src/mesh.c -Iinc ./src/general.c -lmingw32 -lSDL2main -lSDL2
echo Completed!
pause