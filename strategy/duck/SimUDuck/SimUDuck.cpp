#include "lib/Duck/DecoyDuck.h"
#include "lib/Duck/MallardDuck.h"
#include "lib/Duck/ModelDuck.h"
#include "lib/Duck/RedheadDuck.h"
#include "lib/Duck/RubberDuck.h"
#include "lib/DuckFunctions.h"
#include <cstdlib>

int main()
{
	MallardDuck mallardDuck;	
	for (int i = 0; i < 5; ++i) PlayWithDuck(mallardDuck);

	RedheadDuck redheadDuck;
	for (int i = 0; i < 5; ++i) PlayWithDuck(redheadDuck);
	
	RubberDuck rubberDuck;
	for (int i = 0; i < 5; ++i) PlayWithDuck(rubberDuck);
	
	DecoyDuck decoyDuck;
	for (int i = 0; i < 5; ++i) PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);

	modelDuck.SetFlyBehavior(std::make_unique<FlyWithWings>());
	for (int i = 0; i < 5; ++i) PlayWithDuck(modelDuck);
	
	return EXIT_SUCCESS;
}