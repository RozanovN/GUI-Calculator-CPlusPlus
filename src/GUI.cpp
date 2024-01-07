#define _USE_MATH_DEFINES
#include <cmath>
#include "GUI.h"
#include <wx/wx.h>
#include <vector>
#include "BasicMath.h"


wxBEGIN_EVENT_TABLE(GUI, wxFrame)
	EVT_BUTTON(10001, GUI::onButtonClicked)
wxEND_EVENT_TABLE()


/**
* Constructs a GUI.
*/
GUI::GUI() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(660, 470))
{
	resultField = std::make_unique<wxTextCtrl>(this, wxID_ANY, "", wxPoint(50, 25), wxSize(290, 50), wxTE_READONLY);
	stepsField = std::make_unique<wxListBox>(this, wxID_ANY, wxPoint(400, 25), wxSize(200, 370));
}

/**
* Sets the calculator.
* 
* @param newCalculator a BasicMath rvalue object representing basic mathematical calculator
*/
void GUI::setCalculator(std::unique_ptr<math::BasicMath>&& newCalculator)
{
	calculator = std::move(newCalculator);
}

/**
* Handles the event associated with a button.
*
* @param event an address for the wxCommandEvent object
*/
void GUI::onButtonClicked(wxCommandEvent& event)
{
	const auto& tempButton = wxDynamicCast(event.GetEventObject(), wxButton);
	if (tempButton->GetLabel().IsSameAs("=")) {
		resultField->SetValue(calculator->calculateExpression(resultField->GetValue().ToStdString(), stepsField));
	}
	else if (tempButton->GetLabel().IsSameAs("pi")) {
		resultField->AppendText(std::to_string(M_PI));
	}
	else if (tempButton->GetLabel().IsSameAs("DEL")) {
		resultField->SetValue(resultField->GetValue().SubString(0, resultField->GetValue().Len() - 2));
	}
	else if (tempButton->GetLabel().IsSameAs("CLR")) {
		resultField->SetValue("");
		stepsField->Clear();
	}
	else {
		resultField->AppendText(tempButton->GetLabel());
	}
	event.Skip();
}

/**
* Sets buttons.
*/
void GUI::setButtons()
{
	const auto& buttonValues = calculator->getButtonValues();
    assert(buttonValues.size() == buttons.size());
    int xSize = 50, ySize = 50;
    int xCoordinate = 50, yCoordinate = 100;
    int id = 10001;
    for (auto i = 0; i < buttonValues.size(); i++) {
        if (i % 5 == 0) {
            yCoordinate += 60;
            xCoordinate = 50;
        }
        buttons[i] = std::make_unique<wxButton>(this, id, buttonValues[i], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
        xCoordinate += 60;
    }
}