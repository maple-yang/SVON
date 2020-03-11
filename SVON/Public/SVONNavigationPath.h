#pragma once

#include <stdint.h>
#include <vector>
#include "SVONMath.h"

namespace SVON
{
	enum class SVONPathCostType : uint8_t
	{
		MANHATTAN,
		EUCLIDEAN
	};

	struct SVONPathPoint
	{
		FloatVector position; // Potisoin of the point
		int layer; // Layer that the point came from (so we can infer it's volume)

		SVONPathPoint()
			: position(FloatVector())
			, layer(-1)
		{}

		SVONPathPoint(const FloatVector& aPositoion, int aLayer)
			: position(aPositoion)
			, layer(aLayer)
		{
		}
	};

	struct SVONNavigationPath
	{
	public:
		void AddPoint(const SVONPathPoint& aPoint);
		void ResetForRepath();

		const std::vector<SVONPathPoint>& GetPathPoints()const {
			return points;
		}

		bool IsReady() const { return isReady; }
		void SetIsReady(bool aIsReady) { isReady = aIsReady; }

	protected:
		bool isReady;
		std::vector<SVONPathPoint> points;
	};
}