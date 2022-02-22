#include "Main.h"
#include "BasicMath.h"

wxIMPLEMENT_APP(Main);

Main::Main()
{

}

Main::~Main()
{

}

bool Main::OnInit()
{
	calculator = new BasicMath();
	firstFrame = new GUI();
	firstFrame->setCalculator(calculator);
	firstFrame->setButtons();
	firstFrame->Show();

	return true;
}