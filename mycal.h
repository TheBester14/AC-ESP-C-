#pragma once
#include "structs.h"
class MyMaths
{
		public:
			vec3d screen;
			vec4d clipCoords;
			vec3d NDC;

			bool worldToScreen(vec3d pos, vec3d& screen, float matrix[16], int width, int height);

			float getDistance3d(vec3d m_pos, vec3d en_pos);
};

