/*
 * gipButton.cpp
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#include "gipButton.h"

int gipButton::nextButtonId = 1;


gipButton::gipButton() {
	id = generateButtonId();
	setup();
}

gipButton::~gipButton() {
}

int gipButton::getId() {
	return id;
}

int gipButton::generateButtonId() {
	nextButtonId++;
	return nextButtonId - 1;
}

void gipButton::setup() {
	scaleratio[SIZE_SMALL] = (float)getScreenHeight() / 1636;
	scaleratio[SIZE_DEFAULT] = (float)getScreenHeight() / 1080;
	scaleratio[SIZE_BIG] = (float)getScreenHeight() / 540;
	state = STATE_NORMAL;
	buttonimage.loadImage("gipButton/button.png");
	bsw = buttonimage.getWidth();
	bsh = buttonimage.getHeight();
	bswhalf = bsw / 2;
	bshhalf = bsh / 2;
	bsy = bshhalf * state;
	setSize(SIZE_DEFAULT);
	wcustom = w;
	hcustom = h;
	bx = 0;
	by = 0;
	text = "Button " + gToStr(id);
	fontsize = 20 * scaleratio[size];
	setFontSize(fontsize);
	textcolor[STATE_NORMAL] = 255;
	textcolor[STATE_CLICKED] = 212;
	tc = textcolor[STATE_NORMAL];
}

void gipButton::setPosition(int x, int y) {
	bx = x;
	by = y;
	placeText();
}

void gipButton::setText(std::string text) {
	this->text = text;
	textw = buttonfont.getStringWidth(text);
	texth = buttonfont.getStringHeight(text);
	placeText();
}

std::string gipButton::getText() {
	return text;
}


void gipButton::update() {
//	gLogi("gipButton") << "update";
}

void gipButton::draw() {
	buttonimage.drawSub(bx, by, w, h, 0, bsy, bsw, bshhalf);
	renderer->setColor(tc, tc, tc);
	buttonfont.drawText(text, textx, texty);
	renderer->setColor(255, 255, 255);
}

void gipButton::setSize(int size) {
	this->size = size;
	switch(size) {
	case SIZE_SMALL:
		w = bsw * scaleratio[SIZE_SMALL];
		h = bsh * scaleratio[SIZE_SMALL] / 2;
		break;
	case SIZE_DEFAULT:
		w = bsw * scaleratio[SIZE_DEFAULT];
		h = bsh * scaleratio[SIZE_DEFAULT] / 2;
		break;
	case SIZE_BIG:
		w = bsw * scaleratio[SIZE_BIG];
		h = bsh * scaleratio[SIZE_BIG] / 2;
		break;
	case SIZE_CUSTOM:
		w = wcustom;
		h = hcustom;
		break;
	default:
		break;
	}
	placeText();
}

void gipButton::setFontSize(int fontSize) {
	fontsize = fontSize;
	buttonfont.loadFont("FreeSans.ttf", fontsize);
	setText(text);
}

int gipButton::getFontSize() {
	return fontsize;
}

void gipButton::setState(int state) {
	this->state = state;
	bsy = bshhalf * state;
}

int gipButton::getState() {
	return state;
}


void gipButton::placeText() {
	textx = bx + ((w - textw) / 2) - 3;
	texty = by + h - ((h - texth) / 2) - 3;
}

int gipButton::getSize() {
	return size;
}

void gipButton::setSize(int width, int height) {
	wcustom = width;
	hcustom = height;
	w = wcustom;
	h = hcustom;
	size = SIZE_CUSTOM;
	placeText();
}

int gipButton::getWidth() {
	return w;
}

int gipButton::getHeight() {
	return h;
}

void gipButton::mouseDragged(int x, int y, int button) {
}

void gipButton::mousePressed(int x, int y, int button) {
	if (x >= bx && x < bx + w && y >= by && y < by + h) {
		bsy = bshhalf;
		tc = textcolor[STATE_CLICKED];
	}
}

void gipButton::mouseReleased(int x, int y, int button) {
	if (x >= bx && x < bx + w && y >= by && y < by + h) {
		state = 1 - state;
		bsy = bshhalf * state;
		tc = textcolor[state];
		callback(id);
	}
}

void gipButton::setClickCallback(std::function<void(int)> callback) {
	this->callback = callback;
}



