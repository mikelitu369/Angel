

#pragma once


namespace MKbox2D
{
	class Input
	{
	
	public:
		static Input& instance()
		{
			static Input scene_manager;
			return scene_manager;
		}


		float horizontal = 0.0f;
		float vertical = 0.0f;


	};
}