#include "UIWindow.h"

using namespace Mel::GUI;

int main()
{
    UIWindow* myWindow = new UIWindow();
    myWindow->Display(640, 480, "Mehrbod MK's OpenGL Window!", false);

    while (true)
    {
        myWindow->Render();
    }

    return 0;
}