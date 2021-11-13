#pragma once

#include <vector>

/**
 * @brief A struct to represent a side of an object's collider (2 points)
 */
struct ColliderSide {
};

class Collider {
private:
public:
	std::vector<ColliderSide*> colliderPtrVector;
	Collider();
	~Collider();
};
