#ifndef ENGINE_PROJECTILE
#define ENGINE_PROJECTILE

#include "Entity.h"
#include "Engine/Components/PhysicsObject.h"

class Projectile : public Entity, public PhysicsObject
{
public:
	Projectile(std::unique_ptr<Hitbox> _hitbox);
	~Projectile();

	virtual void Move() override = 0;
	virtual void Render() const override = 0;
	virtual void DebugPhysics() const override = 0;
};

#endif