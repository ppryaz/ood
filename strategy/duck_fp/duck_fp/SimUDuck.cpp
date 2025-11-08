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
    for (int i = 0; i < 3; ++i) PlayWithDuck(redheadDuck);

    mallardDuck.SetFlyBehavior(FlyNoWay());
    PlayWithDuck(mallardDuck);
    mallardDuck.SetFlyBehavior(FlyWithWings());
    PlayWithDuck(mallardDuck);

    RubberDuck rubberDuck;
    for (int i = 0; i < 5; ++i) PlayWithDuck(rubberDuck);
	
    DecoyDuck decoyDuck;
    for (int i = 0; i < 5; ++i) PlayWithDuck(decoyDuck);

    ModelDuck modelDuck;
    for (int i = 0; i < 5; ++i) PlayWithDuck(modelDuck);

    modelDuck.SetFlyBehavior(FlyWithWings());
    for (int i = 0; i < 5; ++i) PlayWithDuck(modelDuck);
	
	return EXIT_SUCCESS;
}
