/*
Author: Daniel Fernández
Date:	27/06/2018
*/

#include <Scene.hpp>

#include <Platform.hpp>
#include <Column.hpp>
#include <Ground.hpp>
#include <Door.hpp>
#include <Tank.hpp>
#include <Wall.hpp>
#include <Key.hpp>

namespace bullet_3da
{
	class MyScene : public Scene
	{
		shared_ptr < Camera > camera;

		unique_ptr < Tank > tank;
		shared_ptr < Door > door;

		int projectile_count;

		std::clock_t time_fire;

		Tank::Controls controls;

		bool door_opened;

	public:

		MyScene();

		void update(float deltaTime) override;

		void processInput(Input::InputData input_data) override;
	};
}