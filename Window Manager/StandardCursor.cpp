#include "StandardCursor.h"

sf::StandardCursor::StandardCursor(const sf::StandardCursor::TYPE t)
{
    switch(t)
    {
        case sf::StandardCursor::WAIT :
            Cursor = LoadCursor(NULL, IDC_WAIT);
        break;
        case sf::StandardCursor::HAND :
            Cursor = LoadCursor(NULL, IDC_HAND);
        break;
        case sf::StandardCursor::NORMAL :
            Cursor = LoadCursor(NULL, IDC_ARROW);
        break;
        case sf::StandardCursor::TEXT :
            Cursor = LoadCursor(NULL, IDC_IBEAM);
        break;
        //For more cursor options on Windows go here:
        // http://msdn.microsoft.com/en-us/library/ms648391%28v=vs.85%29.aspx
    }
}

void sf::StandardCursor::Set(const sf::WindowHandle& aWindowHandle) const
{
    SetClassLongPtr(aWindowHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
}

sf::StandardCursor::~StandardCursor()
{
    // Nothing to do for destructor :
    // no memory has been allocated (shared ressource principle)
}
