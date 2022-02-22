#pragma once

#include "wx/wx.h"
#include "GUI.h"

class Main : public wxApp
{
public:
	Main();
	~Main();

private:
	GUI* firstFrame = nullptr;
	BasicMath* calculator = nullptr;

public:
	virtual bool OnInit();
};