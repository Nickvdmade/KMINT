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

std::chrono::system_clock::time_point stepTime;
std::chrono::duration<double> stepTimer;
int stepDuration = 1;

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
	std::vector<Rabbit*> rabbits;
	Rabbit* rabbit = new Rabbit(0, 0, 0, 0, 0);
	rabbits.push_back(rabbit);
	map.addRabbits(rabbits);

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
		Schaap->show(application);
		Schaap->updateState();
		for (Person* person : persons)
		{
			person->show(application);
			person->updateState();
		}
		rabbit->show(application);
		
		//gamesteps
		stepTimer = std::chrono::system_clock::now() - stepTime;
		if (stepTimer.count() > stepDuration)
		{
			Schaap->raiseThirst();
			stepTime = std::chrono::system_clock::now();
		}
		
		//UI
		application->DrawTextItem("Thirst: " + std::to_string(Schaap->thirstLevel()), 40, 10);
		application->DrawTextItem("Rabbits eaten: " + std::to_string(Schaap->preyEaten()), 160, 10);
		application->DrawTextItem("Schaap is currently " + Schaap->currentState(), 450, 10);
		application->DrawTextItem("Meneer Jannsen is currently " + meneerJanssen->currentState(), 800, 10);
		application->DrawTextItem("Mevrouw Janssen is currently " + mevrouwJanssen->currentState(), 1100, 10);
		application->EndTick();
	}
		
	delete mevrouwJanssen;
	delete meneerJanssen;
	delete Schaap;
	for (Rabbit* rabbit : rabbits)
		delete rabbit;

	return EXIT_SUCCESS;
}
