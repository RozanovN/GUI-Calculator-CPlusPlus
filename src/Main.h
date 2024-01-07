#pragma once

#include <wx/wx.h>
#include "GUI.h"

class Main : public wxApp
{
public:
	Main() = default;

private:
	std::unique_ptr<GUI> firstFrame = nullptr;

public:
	virtual bool OnInit();
};