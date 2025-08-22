#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLineA, INT nCmdShow)
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLineA);
	UNREFERENCED_PARAMETER(nCmdShow);
	
	INT_PTR res = 1;
	
	TCHAR szPath[MAX_PATH + 24 + 16];
	DWORD dwRes = GetModuleFileName(0, szPath, MAX_PATH);
	if (dwRes == MAX_PATH)
	{
		goto ErrorMessage;
	}
	
	LPTSTR lpEnd = szPath + lstrlen(szPath);
	for (; lpEnd > szPath && lpEnd[-1] != '\\'; lpEnd--);
	lstrcpy(lpEnd, TEXT("bin\\GlamorousToolkit.exe"));
	
	lpEnd += lstrlen(lpEnd);
	lstrcpy(lpEnd, TEXT(":Zone.Identifier"));
	DeleteFile(szPath);
	*lpEnd = '\0';
	
	res = (INT_PTR)ShellExecute(NULL, TEXT("open"), szPath, NULL, NULL, SW_SHOW);
	if (res <= 32)
	{
ErrorMessage:
		MessageBox(NULL, TEXT("Glamorous Toolkit konnte nicht gefunden oder gestartet werden!\n\nHaben Sie die ganze ZIP-Datei extrahiert?"), TEXT("Glamorous Toolkit"), MB_ICONWARNING);
		return (INT)res + 1;
	}
	
	return 0;
}
