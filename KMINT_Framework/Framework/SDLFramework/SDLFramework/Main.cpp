#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Astar.h"
#include <Windows.h>
#include "FileReader.h"
#include "Map.h"
#include "Rottweiler.h"
#include "Mister.h"
#include "Misses.h"
#include "RabbitPopulation.h"

std::chrono::system_clock::time_point stepTime;
std::chrono::duration<double> stepTimer;
double stepDuration = 1;

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	
	//create map
	FileReader reader;
	Map map(reader.readFile("graaf.txt"));
	map.createMap();
	
	//create players
	std::vector<Person*> persons;
	Person* meneerJanssen = new Mister('M', Color(255, 0, 0, 255), 30, 50, map.getStartMister(), stepDuration);
	persons.push_back(meneerJanssen);
	Person* mevrouwJanssen = new Misses('V', Color(255, 0, 128, 255), 10, 80, map.getStartMisses(), stepDuration);
	persons.push_back(mevrouwJanssen);
	Rottweiler* Schaap = new Rottweiler(map.getCave(), persons, stepDuration);
	
	//create rabbits
	RabbitPopulation* population = new RabbitPopulation(100);
	population->initialize();
	map.addRabbits(population->get());

	Astar astar;
	
	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
				case SDLK_f:
					
					break;
				case SDLK_SPACE:
					
					break;
				case SDLK_0:
					
					break;
				default:
					break;
				}
			}
		}

		map.show(application);
		for (Person* person : persons)
		{
			person->show(application);
			person->updateState();
		}
		population->show(application);
		population->update();
		Schaap->show(application);
		Schaap->updateState();

		//gamesteps
		stepTimer = std::chrono::system_clock::now() - stepTime;
		if (stepTimer.count() > stepDuration)
		{
			Schaap->raiseThirst();
			stepTime = std::chrono::system_clock::now();
		}
		
		//UI
		application->SetColor(Color(255, 255, 255, 255));
		application->DrawTextItem("Current round: " + std::to_string(1), 100, 10);
		application->DrawTextItem("Rabbits eaten: " + std::to_string(population->getEaten()), 300, 10);
		application->DrawTextItem("Rabbits drowned: " + std::to_string(population->getDrowned()), 500, 10);
		application->DrawTextItem("Thirst: " + std::to_string(Schaap->thirstLevel()), 100, 710);
		application->DrawTextItem("Schaap is currently " + Schaap->currentState(), 300, 710);
		application->DrawTextItem("Meneer Jannsen is currently " + meneerJanssen->currentState(), 650, 710);
		application->DrawTextItem("Mevrouw Janssen is currently " + mevrouwJanssen->currentState(), 1000, 710);
		application->EndTick();
	}
		
	delete mevrouwJanssen;
	delete meneerJanssen;
	delete Schaap;
	delete population;

	return EXIT_SUCCESS;
}
