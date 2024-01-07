#include "Main.h"
#include "BasicMath.h"

wxIMPLEMENT_APP(Main);


bool Main::OnInit()
{
	firstFrame = std::make_unique<GUI>();
	firstFrame->setCalculator(std::make_unique<math::BasicMath>());
	firstFrame->setButtons();
	firstFrame->Show();

	return true;
}