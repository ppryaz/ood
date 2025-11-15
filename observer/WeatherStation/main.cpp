/*
Задание 1 — Отображение полной статистической информации +++
Задание 2 — Безопасное уведомление наблюдателей - ну хз, во первых еще попробуй удали себя из списка наблюдателей из Update
В приложении Weather Station работа метода NotifyObservers может
привести к неопределенному поведению, если из метода Update наблюдатель
выполнит удаление себя из списка наблюдателей. Придумайте и реализуйте
решение для данной проблемы.
Задание 3 — Приоритеты наблюдателей — 30 баллов	+++

*/

#include "WeatherData.h"

int main()
{
	CWeatherData wd;

	CDisplay display;
	wd.RegisterObserver(display , 2 );

	CStatsDisplay statsDisplay;
	wd.RegisterObserver(statsDisplay, 1);

	wd.SetMeasurements(3, 0.7, 760);
	wd.SetMeasurements(4, 0.8, 761);

	wd.RemoveObserver(statsDisplay);


	wd.SetMeasurements(10, 0.8, 761);
	wd.SetMeasurements(-10, 0.8, 761);
	
	return 0;
}