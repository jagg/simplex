@echo off

set PROJECT_NAME=simplex
set EX_LIBS=w:\libs

mkdir ..\..\build
pushd ..\..\build

del /Q *
copy %EX_LIBS%\SDL2-2.0.14\lib\x64\* . >nul
copy %EX_LIBS%\SDL2_image-2.0.5\lib\x64\* . >nul
copy %EX_LIBS%\SDL2_ttf-2.0.15\lib\x64\* . >nul

set EX_INCLUDES= /I%EX_LIBS%\SDL2-2.0.14\include /I%EX_LIBS%\SDL2_image-2.0.5\include /I%EX_LIBS%\SDL2_ttf-2.0.15\include
set LIBS=SDL2.lib SDL2main.lib Shell32.lib SDL2_image.lib SDL2_ttf.lib
cl /std:c++17 /EHsc /W4 /FC /Zi /nologo /Fesimplex.exe w:\%PROJECT_NAME%\code\*.cpp /Iw:\%PROJECT_NAME%\code\include %EX_INCLUDES% %LIBS% /link  /SUBSYSTEM:CONSOLE

