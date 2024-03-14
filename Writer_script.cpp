#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    system("chcp 1251");
    char ch[3000];
    cin.getline(ch, sizeof(ch));
    INPUT Input;
    int flag = 1;
    while (flag)
    {
        if (GetAsyncKeyState(VK_NUMPAD1))
        {
            Input.type = INPUT_KEYBOARD;
            Input.ki.wScan = 0;
            Input.ki.time = 0;
            Input.ki.dwExtraInfo = 0;
            Input.ki.wVk = 8;
            Input.ki.dwFlags = 0;
            SendInput(3, &Input, sizeof(Input));
            Input.ki.dwFlags = KEYEVENTF_KEYUP;
            for (int i = 0; ch[i] != '\0'; i++)
            {
                Input.ki.wVk = VkKeyScanA(ch[i]);
                Input.ki.dwFlags = 0;
                SendInput(3, &Input, sizeof(Input));
                Input.ki.dwFlags = KEYEVENTF_KEYUP;
            }
            flag = 0;
        }
        if (GetAsyncKeyState(VK_NUMPAD0))
        {
            return 0;
        }
    }
    Input.ki.wVk = 0x0D;
    Input.ki.dwFlags = 0;
    SendInput(3, &Input, sizeof(Input));
    Input.ki.dwFlags = KEYEVENTF_KEYUP;
    ZeroMemory(&Input, sizeof(Input));
    return 0;
}
