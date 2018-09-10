#include "../Include/WinManager.h"

sf::Palette::Palette() :
	currInstPos_(0)
{

}

sf::Palette::Palette(std::vector<AbstInst*> palette) :
	palette_(palette),
	currInstPos_(0)
{
}

void sf::Palette::AddInst(AbstInst * inst)
{
	palette_.push_back(inst);
}

void sf::Palette::DelInst()
{
	palette_.pop_back();
}

void sf::Palette::SetActiveInst(int currInstPos)
{
	currInstPos_ = currInstPos;
}

sf::AbstInst * sf::Palette::GetCurrInst()
{
	return palette_[currInstPos_];
}

std::vector<sf::AbstInst*> sf::Palette::GetPalette()
{
	return palette_;
}
