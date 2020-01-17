#pragma once
#include"main.h"
class Individual : public sf::Drawable
{
private:
	sf::Vector2f position;
	sf::Vector2f target;
	bool targetReached;
	float size;
	float speed;
	float angle;
	float range;
	sf::Color color;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(body);
	}
	sf::CircleShape body;
public:
	void think();
	sf::Vector2f getPosition();
	Individual();


};

