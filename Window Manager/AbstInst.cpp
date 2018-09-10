#include "../Include/WinManager.h"

sf::AbstInst::AbstInst(InstData instData) :
	instData_(instData)
{

}

sf::InstData sf::AbstInst::GetInstData()
{
	return instData_;
}

