#include "Individual.h"

float randomFloat(const float& minVal, const float& maxVal) {
	float res;
	res = (float)rand() / RAND_MAX;
	return minVal + res * (maxVal - minVal);
}

void Individual::think()
{
	if (targetReached)
	{
		
		do
		{
			angle = rand() % 360;
			angle = angle * 3.14 / 180;
			float dist = randomFloat(0, range);
			target.x = position.x + dist * 20 * sin(angle);
			target.y = position.y + dist * 20 * cos(angle);
			
		} while (target.x > 1024 || target.y > 720 || target.x < 0 || target.y < 0);
		targetReached = false;
	}
	else
	{
		
		if (abs(position.x - target.x) <= 1 && abs(position.y - target.y) <= 1)
		{
			
			targetReached = true;
		}
		else
		{
			position.x += speed * sin(angle);
			position.y += speed * cos(angle);
		}
	}
	body.setPosition(position);
}


sf::Vector2f Individual::getPosition()
{
	return position;
}

Individual::Individual()
{
	size = 1;
	speed = 0.1;
	range = 100;

	color = sf::Color::Red;
	position.x = (float)(rand() % 500);
	position.y = (float)(rand() % 600);
	target.x = -1;
	target.y = -1;
	targetReached = true;
	body.setPosition(position);
	body.setRadius(size * 20);
	body.setOrigin((float)size * 20, (float)size * 20);
	body.setFillColor(color);
}
