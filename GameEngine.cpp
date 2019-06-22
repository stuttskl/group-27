/******************************************************************************
** Program name: GameEngine.cpp
** Author: April Castaneda, Victoria Fisher, Katie Stutts
** Date: 06.20.2019
** Description: GameEngine class implementation file.
******************************************************************************/
#include "GameEngine.hpp"
#include "inputValid.hpp"

/******************************************************************************
** Description: Constructor
******************************************************************************/
GameEngine::GameEngine()
{
	// First, set variables
	setTurns(START_TURNS);	
	setChoice(0);

	// Next, create deck
	createDeck();

	// Display deck at first -- for testing
//	cout << "Deck before shuffle: " << endl;
//	displayDeck();

	// Next, shuffle deck
	shuffleDeck();

	// Next, deal hand
	dealHand();

	// Next, create pile from leftover deck
	createPile();

}

/******************************************************************************
** Description: Destructor
******************************************************************************/
GameEngine::~GameEngine()
{
	// Delete deck here
	// Delete hand here
	// Delete table here
	// Delete pile here
	// Delete discard here
}

/******************************************************************************
** Description: Setters
******************************************************************************/
void GameEngine::setTurns(int turns)
{
	this->turns = turns;
}

void GameEngine::setChoice(int choice)
{
	this->choice = choice;
}

/******************************************************************************
** Description: Getters
******************************************************************************/
int GameEngine::getTurns()
{
	return turns;
}

int GameEngine::getChoice()
{
	return choice;
}

/******************************************************************************
** Description: Function that creates deck of cards.
******************************************************************************/
void GameEngine::createDeck()
{
	deck = new Card* [INIT_CARDS];

	// Initialize all to NULL
	for(int i = 0; i < INIT_CARDS; i++)
	{
		deck[i] = NULL;
	}

	// Create specific cards
	deck[0] = new Card(-3500, 0, "Inventions", "Domestication of the horse.");
	deck[1] = new Card(-3200, 1, "Inventions", "Sailing is invented in ancient Egypt.");
	deck[2] = new Card(-3000, 2, "Inventions", "Papyrus -- the first paper -- is invented in ancient Egypt.");
	deck[3] = new Card(-2000, 3, "Inventions", "The chariot is invented in Rome.");
	deck[4] = new Card(-1750, 4, "Inventions", "Thank the Phoenicians! They invented a universal alphabet.");
	deck[5] = new Card(-500, 5, "Inventions", "Cast iron is invented in China.");
	deck[6] = new Card(50, 6, "Inventions", "The first vending machine is invented.");
	deck[7] = new Card(1960, 7, "Inventions", "Maiman invents the first functioning laser.");
	deck[8] = new Card(118, 8, "Inventions", "Appearance of the earliest wheelbarrow, found in a Chinese tomb.");
	deck[9] = new Card(300, 9, "Inventions", "Earliest evidence of the fishing reel.");
	deck[10] = new Card(589, 10, "Inventions", "Toilet paper! Imagine living without that...");
	deck[11] = new Card(650, 11, "Inventions", "The windmill is created in Persia.");
	deck[12] = new Card(800, 12, "Inventions", "Gunpowder is created in China.");
	deck[13] = new Card(850, 13, "Inventions", "Algebra is developed in Syria.");
	deck[14] = new Card(875, 14, "Inventions", "The concept of zero as a number is implemented in India.");
	deck[15] = new Card(975, 15, "Inventions", "Fireworks are invented in China.");
	deck[16] = new Card(1050, 16, "Inventions", "The first ambulances appear in Palestine and Lebanon.");
	deck[17] = new Card(1286, 17, "Inventions", "Eyeglasses are invented in Italy.");
	deck[18] = new Card(1439, 18, "Inventions", "Gutenberg invents the printing press.");
	deck[19] = new Card(1577, 19, "Inventions", "Newspaper is invented in Korea.");
	deck[20] = new Card(1709, 20, "Inventions", "Cristofori crafts the first piano.");
	deck[21] = new Card(1755, 21, "Inventions", "Cullen invents the first refrigerator.");
	deck[22] = new Card(1877, 22, "Inventions", "Bell receives a patent for his telephone.");
	deck[23] = new Card(1888, 23, "Inventions", "Loud invents the ballpoint pen.");
	deck[24] = new Card(1945, 24, "Inventions", "The atomic bomb is developed as part of the Manhattan Project.");
	deck[25] = new Card(-20000, 25, "History", "Earliest evidence of humans executing control over crops.");
	deck[26] = new Card(-8000, 26, "History", "By this year, farming is fully established along the Nile.");
	deck[27] = new Card(-5400, 27, "History", "The first cities emerge in Mesopotamia.");
	deck[28] = new Card(-2560, 28, "History", "Building of the Great Pyramid of Giza.");
	deck[29] = new Card(-800, 29, "History", "The rise of ancient Greek civilization.");
	deck[30] = new Card(-753, 30, "History", "The rise of ancient Roman civilization.");
	deck[31] = new Card(-563, 31, "History", "The life of Buddha and birth of Buddhism.");
	deck[32] = new Card(-336, 32, "History", "Alexander the Great reigns and creates an immense empire.");
	deck[33] = new Card(-221, 33, "History", "China unifies under Emperor Huang, who begins building the Great Wall.");
	deck[34] = new Card(50, 34, "History", "The earliest known Christian text is written.");
	deck[35] = new Card(632, 35, "History", "Completion of the Qu'ran and birth of Islam.");
	deck[36] = new Card(800, 36, "History", "Charlemagne is crowned as the First Holy Roman Emperor.");
	deck[37] = new Card(1066, 37, "History", "William the Conqueror conquers England.");
	deck[38] = new Card(1095, 38, "History", "The First Crusade.");
	deck[39] = new Card(1026, 39, "History", "Genghis Khan establishes a vast Mongol empire.");
	deck[40] = new Card(1215, 40, "History", "The Magna Carta is signed by King John.");
	deck[41] = new Card(1325, 41, "History", "Rise of Aztec civilization.");
	deck[42] = new Card(1347, 42, "History", "The Black Death devastates Europe.");
	deck[43] = new Card(1350, 43, "History", "The Renaissance begins in Europe.");
	deck[44] = new Card(1492, 44, "History", "Columbus lands in the West Indes and claims the land for Spain.");
	deck[45] = new Card(1517, 45, "History", "Luther's 95 Theses start the Protestant Reformation.");
	deck[46] = new Card(1607, 46, "History", "Jamestown becomes the first permanent English colony in America.");
	deck[47] = new Card(1632, 47, "History", "The Taj Mahal is built.");
	deck[48] = new Card(1776, 48, "History", "The Declaration of Independence is signed.");
	deck[49] = new Card(1815, 49, "History", "The Napoleonic Wars end when Napoleon is exiled to St. Helena.");
	deck[50] = new Card(1848, 50, "Computer Science", "Boolean algebra is invented by George Boole.");
	deck[51] = new Card(1911, 51, "Computer Science", "IBM is formed.");
	deck[52] = new Card(1937, 52, "Computer Science", "Alan Turing develops the concept of a theoretical computing machine.");
	deck[53] = new Card(1954, 53, "Computer Science", "The FORTRAN programming language is developed at IBM.");
	deck[54] = new Card(1963, 54, "Computer Science", "ASCII is developed to standardize data exchange among computers.");
	deck[55] = new Card(1971, 55, "Computer Science", "Email is invented.");
	deck[56] = new Card(1972, 56, "Computer Science", "Atari releases Pong.");
	deck[57] = new Card(1975, 57, "Computer Science", "Microsoft is founded by Bill Gates and Paul Allen.");
	deck[58] = new Card(1976, 58, "Computer Science", "Apple Computer is founded by Steve Wozniak and Steve Jobs.");
	deck[59] = new Card(1945, 59, "Computer Science", "The term 'computer bug' is first used by Grace Hopper.");
	deck[60] = new Card(1991, 60, "Computer Science", "The World Wide Web is launched to the public.");
	deck[61] = new Card(1968, 61, "Computer Science", "DARPA creates ARPAnet, the first operational computer network.");
	deck[62] = new Card(1995, 62, "Computer Science", "The Java programming language is introduced.");
	deck[63] = new Card(1993, 63, "Computer Science", "Creation of Mosaic, the first popular web browser.");
	deck[64] = new Card(1972, 64, "Computer Science", "The C programming language is released.");
	deck[65] = new Card(1947, 65, "Computer Science", "The transistor is created at Bell Labs");
	deck[66] = new Card(-87, 66, "Computer Science", "The earliest known analog computer is developed in ancient Greece");
	deck[67] = new Card(2005, 67, "Computer Science", "Linus Torvalds creates git.");
	deck[68] = new Card(1999, 68, "Computer Science", "Wireless internet (Wi-Fi) is standardized.");
	deck[69] = new Card(2007, 69, "Computer Science", "Apple releases the very first iPhone.");
	deck[70] = new Card(1703, 70, "Computer Science", "Liebnitz introduces the binary number system.");
	deck[71] = new Card(1991, 71, "Computer Science", "The Python programming language is released.");
	deck[72] = new Card(1971, 72, "Computer Science", "The first personal computer is sold in the USA.");
	deck[73] = new Card(1822, 73, "Computer Science", "Babbage begins building the first mechanical computer.");
	deck[74] = new Card(1843, 74, "Computer Science", "Ada Lovelace develops the first computer algorithm.");
	deck[75] = new Card(1971, 75, "Video Games", "'Computer Space,' the first commercial arcade game, is introduced.");
	deck[76] = new Card(1972, 76, "Video Games", "Magnavox introduces the Odyssey, the first home video game system.");
	deck[77] = new Card(1985, 77, "Video Games", "Nintendo releases the NES, reviving the video game industry.");
	deck[78] = new Card(1950, 78, "Video Games", "Turing and Champernowne create the earliest known chess program.");
	deck[79] = new Card(1977, 79, "Video Games", "The Atari Video Computer System features removable cartridges.");
	deck[80] = new Card(1952, 80, "Video Games", "A checkers program and a tic-tac-toe program become the first games to use a monitor.");
	deck[81] = new Card(1958, 81, "Video Games", "'Tennis for Two' is the first game created solely for entertainment.");
	deck[82] = new Card(1961, 82, "Video Games", "MIT students create 'Spacewar!', the first widespread computer game.");
	deck[83] = new Card(1978, 83, "Video Games", "'Space Invaders' is released.");
	deck[84] = new Card(1980, 84, "Video Games", "'Pac-Man' is released.");
	deck[85] = new Card(1983, 85, "Video Games", "The video game crash abruptly ends the second generation of consoles.");
	deck[86] = new Card(1983, 86, "Video Games", "'Snipes' is the first network game written for personal computers.");
	deck[87] = new Card(1993, 87, "Video Games", "DOOM is released.");
	deck[88] = new Card(1979, 88, "Video Games", "Microvision becomes the first handheld system to use cartridges.");
	deck[89] = new Card(1987, 89, "Video Games", "A 16-bit generation of consoles begins.");
	deck[90] = new Card(1990, 90, "Video Games", "The SNES is released.");
	deck[91] = new Card(1991, 91, "Video Games", "SEGA releases 'Sonic the Hedgehog,' beginning the console war.");
	deck[92] = new Card(1989, 92, "Video Games", "Release of Nintendo's Game Boy.");
	deck[93] = new Card(1994, 93, "Video Games", "Video games are now assigned ESRB ratings.");
	deck[94] = new Card(1991, 94, "Video Games", "'Street Fighter II' revives the arcade industry.");
	deck[95] = new Card(1984, 95, "Video Games", "'Tetris' is released.");
	deck[96] = new Card(1995, 96, "Video Games", "Sony's PlayStation becomes the industry leader.");
	deck[97] = new Card(2001, 97, "Video Games", "Microsoft releases the Xbox.");
	deck[98] = new Card(2010, 98, "Video Games", "The Xbox 360 standardizes cloud gaming.");
	deck[99] = new Card(2008, 99, "Video Games", "Social network games gain mainstream popularity.");
	deck[100] = new Card(2009, 100, "Pop Culture", "Lady Gaga's debut single 'Just Dance' hits #1 on the Billboard Hot 100.");
	deck[101] = new Card(1994, 101, "Pop Culture", "'Friends', an American television sitcom, first airs on NBC.");
	deck[102] = new Card(1992, 102, "Pop Culture", "Radiohead, an English rock band, releases their debut single 'Creep.'");
	deck[103] = new Card(2002, 103, "Pop Culture", "Detroit takes Hollywood when '8 Mile,' a film starring Eminem, premieres.");
	deck[104] = new Card(2012, 104, "Pop Culture", "Disney acquires Lucasfilm and gains ownership of Star Wars. ");
	deck[105] = new Card(2011, 105, "Pop Culture", "'Game of Thrones' premieres on HBO.");
	deck[106] = new Card(2014, 106, "Pop Culture", "Kamala Khan debuts as Ms. Marvel, the first Muslim Marvel character.");
	deck[107] = new Card(2015, 107, "Pop Culture", "Star Wars returns with 'The Force Awakens.'");
	deck[108] = new Card(1973, 108, "Pop Culture", "Black Panther, the first black superhero, receives his first starring feature.");
	deck[109] = new Card(1966, 109, "Pop Culture", "The first 'Star Trek' series, simply called 'Star Trek,' debuts on NBC.");
	deck[110] = new Card(1930, 110, "Pop Culture", "The Academy Awards ceremony is first broadcast on radio.");
	deck[111] = new Card(1986, 111, "Pop Culture", "'Watchmen,' an American superhero series, is published by DC comics.");
	deck[112] = new Card(1949, 112, "Pop Culture", "The Lego Group begins manufacturing a line of interlocking toy bricks.");
	deck[113] = new Card(1941, 113, "Pop Culture", "Archibald Andrews debuts with Betty and Jughead in Pep Comics #22.");
	deck[114] = new Card(2017, 114, "Pop Culture", "Jodie Whittaker becomes the first female Doctor on 'Doctor Who.'");
	deck[115] = new Card(2016, 115, "Pop Culture", "'Stranger Things,' a nostalgic trip to the '80s, premieres on Netflix.");
	deck[116] = new Card(1979, 116, "Pop Culture", "'Alien,' a sci-fi horror film directed by Ridley Scott, is released.");
	deck[117] = new Card(1981, 117, "Pop Culture", "'Raiders of the Lost Ark, the first of the Indiana Jones series, premieres.");
	deck[118] = new Card(1963, 118, "Pop Culture", "The X-men first appear in 'The X-Men' #1.");
	deck[119] = new Card(1982, 119, "Pop Culture", "'Blade Runner,' a sci-fi noir film directed by Ridley Scott, premieres.");
	deck[120] = new Card(1984, 120, "Pop Culture", "'Ghostbusters,' an American fantasy comedy film, is released.");
	deck[121] = new Card(1997, 121, "Pop Culture", "The first 'Harry Potter' book is released.");
	deck[122] = new Card(2013, 122, "Pop Culture", "'Rick and Morty,' an adult sci-fi animated series, premieres.");
	deck[123] = new Card(1937, 123, "Pop Culture", "'The Hobbit,' or 'There and Back Again,' is published to critical acclaim.");
	deck[124] = new Card(1985, 124, "Pop Culture", "Hayao Miyazaki co-founds Studio Ghibli.");
	deck[125] = new Card(1856, 125, "Pop Culture", "Burberry, beloved for its tailored trench coats, is founded.");
	deck[126] = new Card(1984, 126, "Pop Culture", "'Akira,' a Japanese animated post-apocalyptic cyberpunk film, premieres.");
	deck[127] = new Card(1990, 127, "Pop Culture", "'Ice Ice Baby' becomes the first hip-hop single to top the Billboard Hot 100.");
	deck[128] = new Card(1998, 128, "Pop Culture", "One of the greatest plays in NBA History: Michael Jordan, Game 6.");
	deck[129] = new Card(1968, 129, "Pop Culture", "Stanley Kubrick's '2001: A Space Odyssey' is released.");
	deck[130] = new Card(1989, 130, "Pop Culture", "Nine Inch Nails's first album, 'Pretty Hate Machine,' debuts.");
	deck[131] = new Card(1932, 131, "Pop Culture", "Shirley Temple begins her film career at 3 years old.");
	deck[132] = new Card(1995, 132, "Pop Culture", "NSYNC, one of the best-selling American boy bands, is formed.");
	deck[133] = new Card(1972, 133, "Pop Culture", "WWF Champion Wrestling, the original TV show of the WWF, first airs.");
	deck[134] = new Card(1971, 134, "Pop Culture", "Michael Jackson, the 'King of Pop,' begins his solo career.");
	deck[135] = new Card(1956, 135, "Pop Culture", "Elvis Presley first records with RCA, producing 'Heart Break Hotel.'");
	deck[136] = new Card(1919, 136, "Pop Culture", "Babe Ruth (the 'Bambino') breaks the MLB single-season home run record.");
	deck[137] = new Card(1962, 137, "Pop Culture", "Ringo Starr joins the Beatles and they release their first hit, 'Love Me Do.'");
	deck[138] = new Card(1964, 138, "Pop Culture", "Muhammad Ali wins the world heavyweight championship at the age of 22.");
	deck[139] = new Card(1941, 139, "Pop Culture", "Bob Dylan is born.");
	deck[140] = new Card(1946, 140, "Pop Culture", "Norma Jean signs with Fox and changes her name to Marilyn Monroe.");
	deck[141] = new Card(1931, 141, "Pop Culture", "Al Capone -- aka 'Scarface' -- is arrested and prosecuted for tax evasion.");
	deck[142] = new Card(1921, 142, "Pop Culture", "Charlie Chaplin's first feature film, 'The Kid,' is released.");
	deck[143] = new Card(1972, 143, "Pop Culture", "'The Godfather' is released.");
	deck[144] = new Card(1953, 144, "Pop Culture", "Singer Frank Sinatra wins an Academy Award for 'From Here to Eternity.'");
	deck[145] = new Card(1958, 145, "Pop Culture", "Hitchcock's 'Vertigo' is released.");
	deck[146] = new Card(1954, 146, "Pop Culture", "'The Tonight Show,' the world's longest running talk show, premieres.");
	deck[147] = new Card(1928, 147, "Pop Culture", "Walt Disney develops the character of Mickey Mouse.");
	deck[148] = new Card(1969, 148, "Pop Culture", "David Bowie releases 'Space Oddity.'");
	deck[149] = new Card(1936, 149, "Pop Culture", "Joe DiMaggio makes his major league debut.");
}

/******************************************************************************
** Description: Function that shuffles deck of cards.
******************************************************************************/
void GameEngine::shuffleDeck()
{
	for(int i = 0; i < INIT_CARDS; i++)
	{
		// Random for remaining positions
		int r = i + (rand() % (INIT_CARDS - i));

		// Swap card at current position with card at rand position
		swap(deck[i], deck[r]);
	}
}

/******************************************************************************
** Description: Function that deals hand.
******************************************************************************/
void GameEngine::dealHand()
{
	// Adds first INIT_HAND# of cards from deck into hand
	for(int i = 0; i < INIT_HAND; i++)
	{
		hand.push_back(deck[i]);
	}
}

/******************************************************************************
** Description: Function that creates pile from deck -- after hand has been 
**		dealt.
******************************************************************************/
void GameEngine::createPile()
{
	for(int i = INIT_HAND; i < INIT_CARDS; i++)
	{
		pile.push(deck[i]);
	} 
}

/******************************************************************************
** Description: Function to run game
******************************************************************************/
void GameEngine::runGame()
{
	// Test display deck
//	cout << "Deck after shuffle: " << endl;
//	displayDeck();

	// First, display game title and rules
	// Need to be implemented -- not written yet
	displayTitle();	
	displayRules();

	// Next, draw card from pile and add to table
	Card *drawn = drawPile(1);	// show situation #1 script
	addTable(drawn, 0); // Adds drawn card at position 0
	
	// Loop until user wins or turns == 0
	do
	{
		cout << "\t\t\t\t\t\t\t\tYOU HAVE " << turns << " TURNS REMAINING." << endl;
		// Next, display table
		displayTable();	
		pressEnter();
		
		// Next, display hand -- basic implementation for now
		displayHand();

		// Next, play hand -- returns card player chooses to play
		Card *cardInPlay = playHand();

		// Next, display table again and ask user where to place card
		displayTable();
		Card *returned = playTable(cardInPlay);

		// Determine if a card was drawn from table or not
		if(returned == NULL)
		{
			// Do nothing, continue to end of do, while loop
		}
		else
		{
			// Card was drawn so add card to hand
			hand.push_back(returned);
		}

		// decrement turns
		turns--;

		// Determine if player won by not having any cards
		if(hand.size() <= 0)
		{
			cout << "\n\nYOU DO NOT HAVE ANY MORE CARDS IN YOUR HAND.\n\n";
			cout << "\n\nYOU HAVE WON!!!\n\n";
			hasWon = 1;
		}
	}
	while((turns > 0) && (hasWon == 0));

	// If user lost
	if(hasWon == 0)
	{
		cout << "\n\nYOU HAVE RUN OUT OF TIME. GAME OVER!\n\n";
	}
}

/******************************************************************************
** Description: Function that draws from pile.
******************************************************************************/
Card* GameEngine::drawPile(int situation)
{
	// Store card on top of pile
	Card *top = pile.front();
	Card *copy = new Card(*top);
	
	// Display situation #1 script -- dealer draws card
	if(situation == 1)
	{	
		cout << "\t\t     THE DEALER DRAWS A CARD FROM THE DECK. IT READS: " << endl << endl;
		cout << "\t  ";
		top->displayCard();
		cout << endl << endl << "\t\t\tTHE DEALER PLACES THE CARD ON THE TABLE." << endl << endl;
		pressEnter();
	}
	else // Display situation #2 script -- player draws card
	{	
		cout << "\t\t     YOU DRAW A CARD FROM THE DECK. IT READS: " << endl << endl;
		cout << "\t  ";
		top->displayCard();
		cout << endl << endl << "\t\t\tYOU PUT THE CARD IN YOUR HAND." << endl << endl;
		pressEnter();
	}

	// Delete front of pile
	pile.pop();

	// Return stored card
	return copy;
}

/******************************************************************************
** Description: Function that adds card to cards on table at position.
******************************************************************************/
void GameEngine::addTable(Card* inCard, int pos)
{
	// If no cards yet on table
	if(table.empty())
	{
		table.push_back(inCard);
	}
	else	// If there are cards already, use position
	{
		// Create iterator pointing to position
		auto itPos = table.begin() + pos;

		// Insert card at position
		table.insert(itPos, inCard);
	}
}

/******************************************************************************
** Description: Function that has user press enter to continue.
******************************************************************************/
void GameEngine::pressEnter()
{
	// Have user press enter to continue
	cout << "                                 Press Enter to Continue";
	getchar();
//	cin.ignore();

	cout << endl << endl;
}

/******************************************************************************
** Description: Function that plays hand.
******************************************************************************/
Card* GameEngine::playHand()
{
	string cardToPlay = "";
//    int cardToPlay = 0;
	bool inputValid = false;	

	// Ask user to choose card
	cout << "\t\t\t    WHICH CARD WOULD YOU LIKE TO PLAY?" << endl;

//    cardToPlay = getIntInput();
//    while (cardToPlay <= 0 || cardToPlay > hand.size())
//    {
//        cout << "Please make a valid card selection." << endl;
//        cardToPlay = getIntInput();
//    }
	
	// Loop until correct input
	do
	{
		getline(cin, cardToPlay);
		inputValid = validateInput(cardToPlay, 1, hand.size());
	}
	while(!inputValid);

	// Let user know which card they chose
	cout << "\n\t\t\t\t      CARD IN PLAY:\n\n";
	cout << "\t  ";
	hand[choice-1]->displayCard();	// index = choice - 1
	cout << endl << endl;

	// Make copy of card
	Card *copy = new Card(*hand[choice-1]);

	// Delete card from hand vector
	hand.erase(hand.begin()+(choice-1));

	// Return card copy
	return copy;
}

/******************************************************************************
** Description: Function that plays card on the table.
******************************************************************************/
Card* GameEngine::playTable(Card* played)
{
	string cardToPlay = "";
	bool inputValid = false;
	int tableIndex = 0;	// Store index for chosen card on table

	// First, ask user which card on the table the player would like to 
	// place their card in hand next to
	cout << "\t\t\t PLEASE CHOOSE A CARD ON THE TABLE TO PLACE CARD IN HAND NEXT TO:\n\n";

	// Validate that card exists, loop until correct input
	do
	{
		getline(cin, cardToPlay);
		inputValid = validateInput(cardToPlay, 1, table.size());
	}
	while(!inputValid);

	// Store index for chosen card on table
	tableIndex = choice - 1;

	// Let user know which card they chose
	cout << "\t\t\t CARD ON TABLE:\n\n";
	cout << "\t  ";
	table[tableIndex]->displayCard();
	cout << endl << endl;

	// Display card in hand again
	cout << "\t\t\t CARD IN HAND:\n\n";
	cout << "\t   ";
	played->displayCard();
	cout << endl << endl;	

	// Next, ask user if card in hand should be placed before or after
	// card on table
	cout << "\t\t\t WOULD YOU LIKE TO PLACE THE CARD IN HAND BEFORE OR AFTER THE CARD ON THE TABLE?\n\n";
	cout << "1. Before\n";
	cout << "2. After\n";

	// Loop until input is between 1-2
	do
	{
		getline(cin, cardToPlay);
		inputValid = validateInput(cardToPlay, 1, 2);
	}
	while(!inputValid);

	// Determine if player placed card in correct chronological order 
	// If player chose 1. Before
	if(choice == 1)
	{
		// Did card in hand occur before card on table?
		// Correct condition
		if(played->getYear() <= table[tableIndex]->getYear())
		{
			// Insert card in table vector before card on table
			auto it = table.begin() + tableIndex;
			table.insert(it, played);
			cout << "\n\n YOU HAVE PLACED THE CARD IN THE CORRECT CHRONOLOGICAL ORDER.\n\n";
			return NULL;
		}
		else	// Incorrect condition
		{
			// Let user know incorrect choice
			cout << "\n\n CARD IN HAND DOES NOT OCCUR BEFORE THE EVENT. CARD IS DISCARDED.\n\n";
			cout << "\n\n YOU MUST DRAW A NEW CARD FROM THE DECK.\n\n";			
			pressEnter();

			// Draw card
			Card* drawn = drawPile(2);	// Show situation #2 script

			// Return drawn card
			return drawn;
		}
	}
	else // If player chose 2. after
	{
		// Did card in hand occur after card on table?
		// Correct condition
		if(played->getYear() >= table[tableIndex]->getYear())
		{
			// Insert card in table vector after card on table
			auto it = table.begin() + (tableIndex + 1);
			table.insert(it, played);
			cout << "\n\n YOU HAVE PLACED THE CARD IN THE CORRECT CHRONOLOGICAL ORDER.\n\n";
			return NULL;
		}
		else	// Incorrect condition
		{
			// Let user know incorrect choice
			cout << "\n\n CARD IN HAND DOES NOT OCCUR AFTER THE EVENT. CARD IS DISCARDED.\n\n";
			cout << "\n\n YOU MUST DRAW A NEW CARD FROM THE DECK.\n\n";			
			pressEnter();

			// Draw card
			Card* drawn = drawPile(2);	// Show situation #2 script

			// Return drawn card
			return drawn;
		}
	}
}

/******************************************************************************
** Description: Function that validates integer input.
******************************************************************************/
bool GameEngine::validateInput(string pick, int min, unsigned max)
{
	// Check to see input is not empty
	if(pick.empty())
	{
		cout << "Input Error. Try again." << endl;
		return 0;
	}

	// Go through characters of string to determine if integer
	for(unsigned int i = 0; i < pick.size(); i++)
	{
		char temp = ' ';	// temp holder for chars in string
		
		temp = pick.at(i);

		// If not a number
		if(!isdigit(temp))
		{
			cout << "Input Error. Try again." << endl;
			return 0;
		}
	}

	// Data is an integer, so turn string into an integer
	int tempInt = stoi(pick);

	// static_cast max into int
	int maxCast = static_cast<int>(max);
		
	// Now, see if data is not between min and max
	if(!((tempInt >= min) && (tempInt <= maxCast)))
	{
		cout << "Input Error. Try again." << endl;
		return 0;
	}

	// Data is valid, so assign tempInt to member variable choice
	choice = tempInt;
	return 1;
}

/******************************************************************************
** Description: Function that displays game title.
******************************************************************************/
void GameEngine::displayTitle()
{
	cout << TITLE;
	pressEnter();
}

/******************************************************************************
** Description: Function that displays game rules.
******************************************************************************/
void GameEngine::displayRules()
{
}

/******************************************************************************
** Description: Function that displays hand
******************************************************************************/
void GameEngine::displayHand()
{
	cout << endl << CARDSINHAND;

	cout << "\t\t\t\t     CARD(S) IN HAND:\n\n";
	for(unsigned i = 0; i < hand.size(); i++)
	{
		cout << "\t" << left << i+1 << ". ";
		hand[i]->displayCard();
		cout << endl;
	}
	cout << endl;
}

/******************************************************************************
** Description: Function that displays table
******************************************************************************/
void GameEngine::displayTable()
{
	cout << endl << CARDSONTABLE;

	cout << "\t\t\t\t  CARD(S) ON THE TABLE:\n\n";
	
	for(unsigned i = 0; i < table.size(); i++)
	{
		cout << "\t" << left << i+1 << ". ";
		table[i]->displayCard();
		cout << endl;
	}
	cout << endl;
}

/******************************************************************************
** Description: Function that displays deck - for testing
******************************************************************************/
void GameEngine::displayDeck()
{
	for(int i = 0; i < INIT_CARDS; i++)
	{
		cout << i+1 << ". ";
		deck[i]->displayCard();
		cout << endl;
	}
	cout << endl;
}

/******************************************************************************
** Description: Function that displays pile.
******************************************************************************/
void GameEngine::displayPile()
{
	int i = 1; 	// Pile card counter

	while(!pile.empty())
	{
		// Store front of pile in temp Card
		Card *temp = pile.front();

		// Display temp card
		cout << i << ". ";
		temp->displayCard();
		cout << endl;

		// Increment counter
		i++;

		// Pop off front
		pile.pop();
	}
}

