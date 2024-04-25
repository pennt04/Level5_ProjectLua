/*
Space invaders game
Author:		Philip Alassad
Filename:	Player.cpp
Date:		14/10/2015
Last Updated:	__/__/____

Description: Source file for Player class
*/

#include "Player.h"
#include <stdio.h>

//Constructor
Player::Player(float xPos, float yPos, int lives, string filename)
	:Ship(xPos, yPos, filename)
{
	m_lives = lives;
	m_score = 0;


	//initialize lua
	luaL_openlibs(L); //open libraries for scripts

	if (!LuaOK(L, luaL_dofile(L, "LuaScript.lua")))//open LuaScript
		assert(false);
}

Player::~Player()
{
	//al_destroy_bitmap(m_Ship_image);
	
	//end lua
	lua_close(L);
}

//Methods
int Player::getScore()//gets the current score
{
	return m_score;
}

void Player::reduceLives()
{
	m_lives -= 1;
}

void Player::increaseLives()
{
	m_lives += 1;
}

int Player::getLives()
{
	return m_lives;
}

void Player::setScore(int score)
{
	m_score = m_score + score;
}

void Player::kill()
{
	m_lives = 0;
}

void Player::reset_lives()
{
	m_lives = 3;
}

void Player::reset_score()
{
	m_score = 0;
}








void Player::right()
{
	CallMoveRight(L, "right", m_xpos, m_current_frame);
}

void Player::left()
{
	CallMoveLeft(L, "left", m_xpos, m_current_frame);
}







void Player::Init(Dispatcher& disp)// pass a reference to the static dispatcher
{
	//tell the dispatcher that we have a function for lua
	Dispatcher::Command::voidintfunc f{[this](int score) {return setScore(score); } };
	disp.Register("setScore", Dispatcher::Command{ f });//register the method name and correct signature to the li
}