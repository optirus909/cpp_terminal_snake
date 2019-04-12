//
// Created by Andrey Andriyaynen on 15/03/2019.
//

#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include "Game.h"


class KeyPressable ///TODO move to model, because it makes cross dependencies
{
public:
	void virtual onkey(int key) = 0;
	virtual ~KeyPressable()     = 0;
};


class View
{
public:
	void virtual draw () = 0;
	void virtual run  () = 0;
	void virtual resize()= 0;
	void virtual snakepainter(Coord a, Dir d) = 0;
	virtual ~View()      = 0;
	
	static View *  get();
	static View * inst;
	
	Game * game;
	
	KeyPressable * onkey_delegate;
	
	void setonkey(KeyPressable * p)
	{
		onkey_delegate = p;
	}
	
	void set_model(Game * g)
	{
		game = g;
	}
};


#endif //SNAKE_VIEW_H