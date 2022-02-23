#define _USE_MATH_DEFINES
#include <math.h>
#include "GUI.h"


wxBEGIN_EVENT_TABLE(GUI, wxFrame)
	EVT_BUTTON(10001, onButtonClicked)
wxEND_EVENT_TABLE()

using namespace std;

/**
* Constructs a GUI.
*/
GUI::GUI() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(660, 470))
{
	resultField = new wxTextCtrl(this, wxID_ANY, "", wxPoint(50, 25), wxSize(290, 50), wxTE_READONLY);
	stepsField = new wxListBox(this, wxID_ANY, wxPoint(400, 25), wxSize(200, 370));
}

/**
* Destructs this GUI.
*/
GUI::~GUI()
{
	
}

/**
* Sets the calculator.
* 
* @param newCalculator a BasicMath object representing basic mathematical calculator
*/
void GUI::setCalculator(BasicMath* newCalculator) 
{
	calculator = newCalculator;
}

/**
* Handles the event associated with a button.
*
* @param event an address for the wxCommandEvent object
*/
void GUI::onButtonClicked(wxCommandEvent& event)
{
	wxButton* tempButton = wxDynamicCast(event.GetEventObject(), wxButton);
	if (tempButton->GetLabel().IsSameAs("=")) {
		resultField->SetValue(calculator->calculateExpression(resultField->GetValue().ToStdString(), stepsField));
	}
	else if (tempButton->GetLabel().IsSameAs("pi")) {
		resultField->AppendText(to_string(M_PI));
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
	vector<string> buttonValues = calculator->getButtonValues();
	vector<wxButton> result;
	int xSize = 50, ySize = 50;
	int xCoordinate = 50, yCoordinate = 100;
	int id = 10001;

	Button1 = new wxButton(this, id, buttonValues[0], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button2 = new wxButton(this, id, buttonValues[1], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button3 = new wxButton(this, id, buttonValues[2], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button4 = new wxButton(this, id, buttonValues[3], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button5 = new wxButton(this, id, buttonValues[4], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	yCoordinate += 60;

	xCoordinate = 50;
	Button6 = new wxButton(this, id, buttonValues[5], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button7 = new wxButton(this, id, buttonValues[6], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button8 = new wxButton(this, id, buttonValues[7], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button9 = new wxButton(this, id, buttonValues[8], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button10 = new wxButton(this, id, buttonValues[9], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	yCoordinate += 60;

	xCoordinate = 50;
	Button11 = new wxButton(this, id, buttonValues[10], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button12 = new wxButton(this, id, buttonValues[11], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button13 = new wxButton(this, id, buttonValues[12], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button14 = new wxButton(this, id, buttonValues[13], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button15 = new wxButton(this, id, buttonValues[14], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	yCoordinate += 60;

	xCoordinate = 50;
	Button16 = new wxButton(this, id, buttonValues[15], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button17 = new wxButton(this, id, buttonValues[16], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button18 = new wxButton(this, id, buttonValues[17], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button19 = new wxButton(this, id, buttonValues[18], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button20 = new wxButton(this, id, buttonValues[19], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	yCoordinate += 60;

	xCoordinate = 50;
	Button21 = new wxButton(this, id, buttonValues[20], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button22 = new wxButton(this, id, buttonValues[21], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button23 = new wxButton(this, id, buttonValues[22], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button24 = new wxButton(this, id, buttonValues[23], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	xCoordinate += 60;
	Button25 = new wxButton(this, id, buttonValues[24], wxPoint(xCoordinate, yCoordinate), wxSize(xSize, ySize));
	yCoordinate += 60;
}