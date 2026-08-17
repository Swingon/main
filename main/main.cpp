#include <iostream>

//definicja zmiennych
bool sessionActive = false; //sesja
int currentGame = 0;	//obecna gra


//funkcje

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
			
			if (sessionActive == true)
			{
				std::cout << "Session is already active" << std::endl;
			}
			else
			{
				currentGame = chooseGame();
				std::cout << "Game Selected: " << currentGame << std::endl;
				sessionActive = true;
			}
			break;
		case 2:
			// End session
			break;

		case 3:
			if (sessionActive = true) {
				std::cout << "Current session: " << currentGame << std::endl;
			}
			else {
				std::cout << "Session is not active: "<< std::endl;
			}
			break;

		case 4:
			// wyjście z Game Trackera
			break;

		default:
			// błędny wybór
			break;
		}

	} while (choiceTracker != 4);
}


int chooseMode() {
	int choiceModeInside;
	std::cin >> choiceModeInside;

	switch (choiceModeInside)
	{
	case 1:
		std::cout << "Game Tracker selected" << std::endl;
		gameTracker();
		break;
	case 2:
		std::cout << "FPS Analyzer selected" << std::endl;
		break;
	case 3:
		std::cout << "Reaction Test selected" << std::endl;
		break;
	case 4:
		std::cout << "Backup Manager selected" << std::endl;
		break;
	case 5:
		std::cout << "Statistics selected" << std::endl;
		break;
	case 6:
		std::cout << "Exiting..." << std::endl;
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
