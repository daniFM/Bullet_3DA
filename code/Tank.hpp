/*

Author: Daniel Fernández
Date:	04/05/2018

*/

#pragma once

#include <vector>
#include <memory>

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

#include <Scene.hpp>
#include <Entity.hpp>
#include <Rigid_Body.hpp>

using namespace std;

namespace bullet_3da
{
	class Tank : public Entity
	{

		/*shared_ptr< btHingeConstraint > turret_constraint;
		shared_ptr< btHingeConstraint > cannon_constraint;*/
		btHingeConstraint * turret_constraint;
		btHingeConstraint * cannon_constraint;

		btHingeConstraint * wheel_r1_constraint;
		btHingeConstraint * wheel_r2_constraint;
		btHingeConstraint * wheel_l1_constraint;
		btHingeConstraint * wheel_l2_constraint;

	public:

		Tank(Scene * scene, glt::Vector3 position);

		shared_ptr < Rigid_Body > getRigidBody() override
		{
			return physics_model;
		}

		void go_forward(float speed)
		{
			wheel_r1_constraint->setMotorTargetVelocity(speed);
			wheel_r2_constraint->setMotorTargetVelocity(speed);
			wheel_l1_constraint->setMotorTargetVelocity(speed);
			wheel_l2_constraint->setMotorTargetVelocity(speed);
		}

		void stop_engine()
		{
			wheel_r1_constraint->setMotorTargetVelocity(0);
			wheel_r2_constraint->setMotorTargetVelocity(0);
			wheel_l1_constraint->setMotorTargetVelocity(0);
			wheel_l2_constraint->setMotorTargetVelocity(0);
		}

		void turn_right()
		{
			wheel_r1_constraint->setMotorTargetVelocity(0.f);
			wheel_r2_constraint->setMotorTargetVelocity(0.f);
			wheel_l1_constraint->setMotorTargetVelocity(+3.f);
			wheel_l2_constraint->setMotorTargetVelocity(+3.f);
		}

		void turn_left()
		{
			wheel_r1_constraint->setMotorTargetVelocity(+3.f);
			wheel_r2_constraint->setMotorTargetVelocity(+3.f);
			wheel_l1_constraint->setMotorTargetVelocity(0.f);
			wheel_l2_constraint->setMotorTargetVelocity(0.f);
		}

	};
}