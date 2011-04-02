//***************************************************************************//
//                                                                           //
//                          Gurki Media Productions                          //
//                             (C) Tobias Gurdan                             //
//                                                                           //
//***************************************************************************//

#include "Object3.h"

// constructors
Object3::Object3(void)
{
	SetPosition( vec3::Zero() );
	SetOrientation( quat::Identity() );
}

Object3::Object3(const vec3& position)
{
	SetPosition(position);
	SetOrientation( quat::Identity() );
}

Object3::Object3(real x, real y, real z)
{
	SetPosition(x, y, z);
	SetOrientation( quat::Identity() );
}

// methods
void Object3::Render(void) const
{
	glBegin(GL_POINTS);

		glVertex3fv(pos.v); 

	glEnd();
}

void Object3::UpdateWorldMatrix(void)
{
	world.SetTranslation(pos);
	world.SetRotation(ori);
}

// setter
void Object3::SetPosition(const vec3& position)
{
	pos = position;
	world.SetTranslation(pos);
}

void Object3::SetPosition(real x, real y, real z)
{
	pos = vec3(x, y, z);
	world.SetTranslation(pos);
}

void Object3::SetOrientation(const quat& orientation)
{
	ori = orientation;
	world.SetRotation(ori);
}

void Object3::SetOrientation(real yaw, real pitch, real roll)
{
	ori = Quaternion::WithEulerAngles(yaw, pitch, roll);
	world.SetRotation(ori);
}

// getter
vec3 Object3::GetPosition(void) const
{
	return pos;
}

quat Object3::GetOrientation(void) const
{
	return ori;
}

vec3 Object3::GetPointOnSurface(real u, real v, real w) const
{
	return vec3::Zero();	
}
