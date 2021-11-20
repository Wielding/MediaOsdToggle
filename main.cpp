#include <Windows.h>

#include <string>
#include <vector>

std::vector<HWND> FindWindowsWithClass(const std::wstring& className, HWND parent)
{
    std::vector<HWND> result;
    HWND hWnd;

    if ((hWnd = FindWindowEx(parent, nullptr, className.c_str(), L""))!=nullptr) {
        result.emplace_back(hWnd);
    }

    return result;
}

// This recursion is overkill for this situation since there are only 2 classes in the list. I copied it from another
// app I wrote, so it is already tested.  Why mess with what is not broken.
std::vector<HWND> FindWindowsWithClassList(const std::vector<std::wstring>& classList, HWND parent = nullptr)
{
    std::vector<HWND> result;

    if (classList.empty()) {
        return result;
    }

    std::vector<std::wstring> newList{};
    newList.insert(newList.begin(), classList.begin()+1, classList.end());

    auto handleList = FindWindowsWithClass(*classList.begin(), parent);

    if (newList.empty()) {
        return handleList;
    }

    for (auto* handle: handleList) {
        auto children = FindWindowsWithClassList(newList, handle);
        result.insert(result.begin(), children.begin(), children.end());
    }

    return result;
}

INT WINAPI wWinMain(
        _In_ HINSTANCE hInstance,
        _In_opt_ HINSTANCE hPrevInstance,
        _In_ LPWSTR lpCmdLine,
        _In_ int nShowCmd
)
{
    // Raise and lower the volume to make sure we can locate the window
    keybd_event(VK_VOLUME_UP, 0, 0, 0);
    Sleep(250); // we need to pause to give windows a chance to process the volume up event.
    keybd_event(VK_VOLUME_DOWN, 0, 0, 0);

    std::vector<std::wstring> classes = {L"NativeHWNDHost", L"DirectUIHWND"};

    const auto foundWindows = FindWindowsWithClassList(classes);

    // We did not find it so just give up.  Why was it not found? I don't know.  It has never failed be before.
    if (foundWindows.empty()) {
        return 8;
    }

    for (auto* hWindow: foundWindows) {
        auto styles = GetWindowLong(hWindow, GWL_STYLE);

        int cmdShow = SW_HIDE;

        if ((styles & WS_VISIBLE)==0) {
            cmdShow = SW_SHOW;
        }

        ShowWindow(hWindow, cmdShow);
    }

    return 0;
}