#include "Utils.h"
namespace Utils
{
	Point2D<int> WorldPositionToMapBlockCoords(Vector3 position)
	{
		return Point2D<int>(floor((32 - (position.x / (BlockSize)))),floor((32 - (position.y / (BlockSize)))));
	}
}