#include <iostream>
#include <Windows.h>

using namespace std;
typedef int (*MsgFunctioned) (int);

HINSTANCE hinstDLL;

	int main()
{
	MsgFunctioned FuncOpenDLL(0);
	hinstDLL = LoadLibrary(L"MyDLL.dll"); // dll loc
	if(hinstDLL != 0)
	{
		FuncOpenDLL = (MsgFunctioned)GetProcAddress(hinstDLL, "FuncOpenDLL"); // All tybe in fund main or h
	}
	
	FuncOpenDLL(5);
	
	FreeLibrary(hinstDLL);
	return 0;
}



