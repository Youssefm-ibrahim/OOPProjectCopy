#include "GameObject.h"

GameObject::GameObject(Game* r_pGame, point ref, int r_width, int r_height, color fc, color bc) : Drawable (r_pGame, ref, r_width, r_height)
{
	fillColor = fc;
	borderColor = bc;
}

void GameObject::setRefPoint(point p)
{
	RefPoint = p;
}


// you should implement this function knowing that each game object has refPoint, width and height 
// for simplicity, you can consider all game objects are rectangles
bool GameObject::collisionDetection(const GameObject& other)
{
	// Check if the two rectangles overlap
	if (RefPoint.x < other.RefPoint.x + other.width &&
		RefPoint.x + width > other.RefPoint.x &&
		RefPoint.y < other.RefPoint.y + other.height &&
		height + RefPoint.y > other.RefPoint.y) {
		return true;
	}
	return false;
}
