﻿#include "Hall.h"

bool Hall::init() {
  upLeftX = .0f, upLeftY = .0f;
  downRightX = .0f, downRightY = .0f;

  sizeHeight = SIZEHALL, sizeWidth = SIZEHALL;
  return true;
}

void Hall::generateFloor(float X, float Y, INT32 layer) {
  INT32 randomNum = rand();
  Sprite* tmpSprite = nullptr;
  Value imageName("");

  if (randomNum % 4 == 0)
    imageName = "Map//floor3.png";
  else if (randomNum % 3 == 0)
    imageName = "Map//floor2.png";
  else
    imageName = "Map//floor1.png";

  tmpSprite = Sprite::create(imageName.asString().c_str());
  this->addChild(tmpSprite);
  tmpSprite->setGlobalZOrder(layer);
  tmpSprite->setPosition(Point(X, Y));
  vecFloor.pushBack(tmpSprite);
}

void Hall::generateWall(float X, float Y, INT32 layer) {
  INT32 randomNum = rand();
  Sprite* tmpSprite = nullptr;
  Value imageName("");

  if (randomNum % 6 == 0)
    imageName = "Map//wall2.png";
  else
    imageName = "Map//wall1.png";

  tmpSprite = Sprite::create(imageName.asString().c_str());
  this->addChild(tmpSprite, layer);
  tmpSprite->setGlobalZOrder(layer);
  tmpSprite->setPosition(Point(X, Y + (WALLHEIGHT - FLOORHEIGHT) / 2));
  vecWall.pushBack(tmpSprite);
}

void Hall::createMap() {
  srand(time(nullptr));

  const float X = upLeftX - (dir % 2 == 0 ? 0 : FLOORWIDTH);
  const float Y = upLeftY + (dir % 2 == 0 ? FLOORHEIGHT : 0);
  //(X, Y) is upLeft Position;

  float curX = X, curY = Y;
  for (INT32 H = sizeHeight - 1; H >= 0; H--) {  // for height and width
    for (INT32 W = 0; W <= sizeWidth - 1; W++) {
      if ((dir % 2 == 0) && (H == 0 || H == sizeHeight - 1)) {
        generateWall(curX, curY, 2);
      } else if ((dir % 2 == 1) && (W == 0 || W == sizeWidth - 1)) {
        generateWall(curX, curY, 2);
      } else
        generateFloor(curX, curY, 1);
      // randomly generate floor and Wall

      curX += FLOORWIDTH;
    }
    curX = X, curY -= FLOORHEIGHT;
  }
}