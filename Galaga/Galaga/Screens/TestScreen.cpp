#include "TestScreen.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Graphics/ShapeRenderer.h"

TestScreen::TestScreen(int w, int h) : Screen(w, h) {
	color = Color::LIGHT_GRAY;

	std::cout << box1.GetBox().ToString() << std::endl;
	std::cout << box2.GetBox().ToString() << std::endl;
}

TestScreen::~TestScreen() {

}

void TestScreen::Update() {
	cir1.SetCenter(Mouse::GetWorldPos());

	if (box1.IsCollidingWith(&cir1))
		//std::cout << box2.GetBox().ToString() << std::endl;
		std::cout << "Colliding!" << std::endl;
}

void TestScreen::Render() {
	BeginRender();
	
	box1.Render(Color::BLUE);
	box2.Render(Color::RED);
	cir1.Render(Color::MAGENTA);

	EndRender();
}

Screen* TestScreen::Clone() {
	return new TestScreen(*this);
}