#include "pch.h"
#include "CppUnitTest.h"
#include "../SimUDuck/lib/Duck/DecoyDuck.h"
#include "../SimUDuck/lib/Duck/MallardDuck.h"
#include "../SimUDuck/lib/Duck/ModelDuck.h"
#include "../SimUDuck/lib/Duck/RedheadDuck.h"
#include "../SimUDuck/lib/Duck/RubberDuck.h"
#include "../SimUDuck/lib/DuckFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestduck
{
	TEST_CLASS(UnitTestduck)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MallardDuck mallardDuck;
		}
	};
}
