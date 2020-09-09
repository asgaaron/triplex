@ECHO OFF
:: Compile libraries
cl /c /EHsc ArtLibrary.cpp
lib ArtLibrary.obj

:: Compile game
cl /EHsc triplex.cpp /link ArtLibrary.lib