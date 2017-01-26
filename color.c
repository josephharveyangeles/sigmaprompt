#include<windows.h>

void color (int z)
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),z);
}
