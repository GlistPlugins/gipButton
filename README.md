# gipButton
A blue button plugin for GlistEngine

## Installation
Fork & clone this project into ~/dev/glist/glistplugins

## Usage
1. Add gipButton into plugins of your GlistApp/CMakeLists.txt

2. Include gipButton.h in GameCanvas.h
#include "gipButton.h"

3. Create a callback function
void GameCanvas::buttonClicked(int buttonId);

4. Define gipButton object
gipButton button;

5. Set callback and position
void GameCanvas::setup() {
    button.setClickCallback(std::bind(&GameCanvas::buttonClicked, this, std::placeholders::_1));
    button.setPosition(100, 100);
}

7. Draw
void GameCanvas::draw() {
    button.draw();
}

8. Listen and process the clicks in your callback function
