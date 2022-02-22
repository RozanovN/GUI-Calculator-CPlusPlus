#pragma once

#include "wx/wx.h"
#include <vector>
#include "BasicMath.h"

class GUI : public wxFrame
{
public:
	GUI();
	~GUI();

private:
	wxButton* Button1;
	wxButton* Button2;
	wxButton* Button3;
	wxButton* Button4;
	wxButton* Button5;

	wxButton* Button6;
	wxButton* Button7;
	wxButton* Button8;
	wxButton* Button9;
	wxButton* Button10;

	wxButton* Button11;
	wxButton* Button12;
	wxButton* Button13;
	wxButton* Button14;
	wxButton* Button15;

	wxButton* Button16;
	wxButton* Button17;
	wxButton* Button18;
	wxButton* Button19;
	wxButton* Button20;

	wxButton* Button21;
	wxButton* Button22;
	wxButton* Button23;
	wxButton* Button24;
	wxButton* Button25;

	wxTextCtrl* resultField;
	wxListBox* stepsField;
	BasicMath* calculator;


public:
	void onButtonClicked(wxCommandEvent &event);
	void setButtons();
    void addSteps(const std::string firstOperand, const std::string anOperator, const std::string secondOperand, const std::string result);
	void setCalculator(BasicMath* newCalculator);

public:
	wxDECLARE_EVENT_TABLE();
};

