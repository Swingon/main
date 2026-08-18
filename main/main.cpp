#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <format>
#include <vector>

//definicja zmiennych
bool sessionActive = false; //sesja
int currentGame = 0;	//obecna gra
std::chrono::steady_clock::time_point sessionStart;//czas rozpoczęcia sesji


//funkcje
 
//wyświetlannie menu głównego
void displayMenu() {
	system("cls");
	std::cout << "GameTools" << std::endl;

	std::cout << "1. Game Tracker" << std::endl;
	std::cout << "2. FPS Analyzer" << std::endl;
	std::cout << "3. Reaction Test" << std::endl;
	std::cout << "4. Backup Manager" << std::endl;
	std::cout << "5. Statistics" << std::endl;
	std::cout << "6. Exit" << std::endl;

	std::cout << "Select an option: " << std::endl;
}

//wybieranie gry w GameTracker
int chooseGame() {
	system("cls");
	std::cout << "Choose Game" << std::endl;
	std::cout << "1. League Of Legends" << std::endl;
	std::cout << "2. Counter-Strike" << std::endl;
	std::cout << "3. Minecraft" << std::endl;
	std::cout << "4. EA FC" << std::endl;
	std::cout << "5. Other" << std::endl;

	int choiceGame;
	std::cin >> choiceGame;


	return choiceGame;
}

//pobieranie nazwy gry w GameTracker
std::string getGameName(int game)
{
	switch (game)
	{
	case 1:
		return "League Of Legends";

	case 2:
		return "Counter-Strike";
	case 3:
		return "Minecraft";
	case 4:
		return "EA FC";
	case 5:
		return "Other";

	}

	return "...";
}

//pobieranie czasu sesji
std::string getSessionDuration() {
	auto duration = std::chrono::steady_clock::now() - sessionStart;
	auto secs = std::chrono::duration_cast<std::chrono::seconds>(duration);

	auto h = std::chrono::duration_cast<std::chrono::hours>(secs);
	secs -= h;
	auto m = std::chrono::duration_cast<std::chrono::minutes>(secs);
	secs -= m;

	return std::format("{}h {}min {}s", h.count(), m.count(), secs.count());
}

//wybieranie trybu w GamneTracker
void gameTracker()
{	

	
	int choiceTracker;

	do
	{
		system("cls");
		std::cout << "GameTracker" <<std::endl;
		std::cout << "1. Start Session" << std::endl;
		std::cout << "2. End Session" << std::endl;
		std::cout << "3. Show Current Session" << std::endl;
		std::cout << "4. Back" << std::endl;

		std::cin >> choiceTracker;

		switch (choiceTracker)
		{
		case 1:
			
			if (sessionActive)
			{
				std::cout << "Session is already active" << std::endl;

			}
			else
			{
				currentGame = chooseGame();
				sessionActive = true;
				sessionStart = std::chrono::steady_clock::now();
				std::cout << "Game Selected: " << getGameName(currentGame) << std::endl;
				
			}
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;
		case 2:
			if (sessionActive)
			{
				auto length = getSessionDuration();
				std::cout << "session ended " << "Duration: " << length << " seconds" <<std::endl;
				sessionActive = false;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			break;

		case 3:
			if (sessionActive) {
				auto length = getSessionDuration();
				std::cout << "Current session: " << getGameName(currentGame) << " Duration: " << length << " seconds" << std::endl;
			}
			else {
				std::cout << "Session is not active "<< std::endl;
			}
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;

		case 4:
			displayMenu();
			break;

		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;
		}

	} while (choiceTracker != 4);
}

//wybieranie trybu w menu głównynm
int chooseMode() {
	int choiceModeInside;
	std::cin >> choiceModeInside;

	switch (choiceModeInside)
	{
	case 1:
		std::cout << "Game Tracker selected" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		gameTracker();
		break;
	case 2:
		std::cout << "FPS Analyzer selected" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		break;
	case 3:
		std::cout << "Reaction Test selected" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		break;
	case 4:
		std::cout << "Backup Manager selected" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		break;
	case 5:
		std::cout << "Statistics selected" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		break;
	case 6:
		std::cout << "Exiting..." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		break;	
	default:
		std::cout << "Invalid choice. Please try again." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		break;
	}
	return choiceModeInside;
}

int main()
{
	int choiceModeOutside;
	do {
		displayMenu();
		 choiceModeOutside = chooseMode();
	} while (choiceModeOutside != 6);
}
