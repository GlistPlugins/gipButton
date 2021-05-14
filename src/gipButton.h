/*
 * gipPlugin.h
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#ifndef PLUGINS_GIPBUTTON_SRC_GIPBUTTON_H_
#define PLUGINS_GIPBUTTON_SRC_GIPBUTTON_H_

#include <functional>
#include "gBasePlugin.h"
#include "gImage.h"
#include "gFont.h"


class gipButton : public gBasePlugin {
public:
	static const int SIZE_SMALL = 0, SIZE_DEFAULT = 1, SIZE_BIG = 2, SIZE_CUSTOM = 3;
	static const int STATE_NORMAL = 0, STATE_CLICKED = 1;

	gipButton();
	~gipButton();

	int getId();
	void setPosition(int x, int y);
	void setText(std::string text);
	std::string getText();

	void setup();
	void update();
	void draw();

	void setSize(int size);
	int getSize();
	void setSize(int width, int height);
	int getWidth();
	int getHeight();
	int getFontSize();
	void setState(int state);
	int getState();

	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);


	void setClickCallback(std::function<void(int)> callback);


private:
	gImage buttonimage;
	gFont buttonfont;
	int id;
	int bsw, bsh, bsy, bswhalf, bshhalf;
	int size;
	int w, h, wcustom, hcustom;
	int bx, by;
	std::string text;
	int textw, texth, textx, texty;
	int textcolor[2], tc;
	int fontsize;
	float scaleratio[3];
	int state;

	void setFontSize(int fontSize);
	void placeText();

	std::function<void(int)> callback;

	static int generateButtonId();
	static int nextButtonId;
};

#endif /* PLUGINS_GIPBUTTON_SRC_GIPBUTTON_H_ */
