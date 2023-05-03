#pragma once
#include "ApplicationHarness.h"
#include "Maths.h"
#include <vector>

class DotClicker : public Application
{



public:

	void Update(float delta);

	void OnLeftClick() override;
	void OnLeftRelease() override;
	void OnRightClick() override;

	int GetPointAtPosition(Vec2 position);
};