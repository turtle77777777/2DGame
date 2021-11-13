#include "Collider.hpp"

/* The plan is each object that we want to process collisions for
 * should have a collider. This collider should be made of an arbitrary
 * number of ColliderSides (literally just a line between two points,
 * each point is given in world coordinates). Collisions can be
 * detected by checking:
 * - For each side of the given object's collider:
 *   - For each object (find a way to limit this, either only objects on
 *     screen or within a specific radius)
 *     - Check if the given object's collider intersects the object whose
 *       collider we are checking against. If they intersect, there is a
 *       collision
 */

Collider::Collider() {
}

Collider::~Collider() {
}