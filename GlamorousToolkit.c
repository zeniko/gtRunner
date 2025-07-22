#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLineA, INT nCmdShow)
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLineA);
	UNREFERENCED_PARAMETER(nCmdShow);
	
	TCHAR szPath[MAX_PATH];
	GetModuleFileName(0, szPath, MAX_PATH);
	
	LPTSTR lpEnd = szPath + lstrlen(szPath);
	for (; lpEnd > szPath && lpEnd[-1] != '\\'; lpEnd--);
	lstrcpy(lpEnd, TEXT("bin\\GlamorousToolkit.exe"));
	
	INT_PTR res = (INT_PTR)ShellExecute(NULL, TEXT("open"), szPath, NULL, NULL, SW_SHOW);
	if (res <= 32)
	{
		MessageBox(NULL, TEXT("Glamorous Toolkit konnte nicht gefunden werden!\n\nHaben Sie die ganze ZIP-Datei extrahiert?"), TEXT("Glamorous Toolkit"), MB_ICONWARNING);
		return res + 1;
	}
	
	return 0;
}
