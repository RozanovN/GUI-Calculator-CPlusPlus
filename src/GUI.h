#pragma once

#include <vector>
#include "BasicMath.h"

class GUI : public wxFrame
{
public:
	GUI();

private:
    std::array<std::unique_ptr<wxButton>, 25> buttons;

    std::unique_ptr<wxTextCtrl> resultField;
    std::unique_ptr<wxListBox> stepsField;
    std::unique_ptr<math::BasicMath> calculator;


public:
	void onButtonClicked(wxCommandEvent& event);
	void setButtons();
	void setCalculator(std::unique_ptr<math::BasicMath>&& newCalculator);

public:
	wxDECLARE_EVENT_TABLE();
};

