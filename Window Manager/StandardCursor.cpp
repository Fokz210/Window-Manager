#include "StandardCursor.h"

sfext::StandardCursor::StandardCursor(const sfext::StandardCursor::TYPE t)
{
    switch(t)
    {
        case sfext::StandardCursor::WAIT :
            Cursor = LoadCursor(NULL, IDC_WAIT);
        break;
        case sfext::StandardCursor::HAND :
            Cursor = LoadCursor(NULL, IDC_HAND);
        break;
        case sfext::StandardCursor::NORMAL :
            Cursor = LoadCursor(NULL, IDC_ARROW);
        break;
        case sfext::StandardCursor::TEXT :
            Cursor = LoadCursor(NULL, IDC_IBEAM);
        break;
    }
}

void sfext::StandardCursor::Set(const sf::WindowHandle& aWindowHandle) const
{
    SetClassLongPtr(aWindowHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
}

sfext::StandardCursor::~StandardCursor()
{
}
