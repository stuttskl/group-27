/******************************************************************************
** Program name: GameEngine.cpp
** Author: April Castaneda, Victoria Fisher, Katie Stutts
** Date: 06.20.2019
** Description: GameEngine class implementation file.
******************************************************************************/
#include "GameEngine.hpp"

/******************************************************************************
** Description: Constructor
******************************************************************************/
GameEngine::GameEngine()
{
	// First, set variables
	setTurns(START_TURNS);	

	// Next, create deck
	createDeck();

	// Display deck at first -- for testing
//	cout << "Deck before shuffle: " << endl;
//	displayDeck();

	// Next, shuffle deck
//	shuffleDeck();

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

/******************************************************************************
** Description: Getters
******************************************************************************/
int GameEngine::getTurns()
{
	return turns;
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
** Description: Function that creates menus.
******************************************************************************/
void GameEngine::createMenus()
{
    displayHand();
    int cardToPlay = 0;
    cout << "Which card would you like to play?" << endl;
    cin >> cardToPlay;
    cout << "You entered " << cardToPlay << endl;
//    cout << "You have " << hand.size() << " cards remaining." << endl;

    // verifies that user is selecting a valid card
    while (cardToPlay <= 0 || cardToPlay > hand.size())
    {
        cout << "Please select a valid card." << endl;
        cin >> cardToPlay;
    }


}

/******************************************************************************
** Description: Function to run game
******************************************************************************/
void GameEngine::runGame()
{
	// Test display deck
//	cout << "Deck: " << endl;
//	displayDeck();

	// First, display game title and rules
	// Need to be implemented -- not written yet
	displayTitle();	
	displayRules();

	// Next, display hand -- basic implementation for now
//	cout << "Hand: " << endl;
//	displayHand();

	// Next, draw card from pile, add to table, and display table
	Card *drawn = drawPile();
	addTable(drawn, 0); // Adds drawn card at position 0
	cout << endl << "Cards on the table: " << endl;
	displayTable();	

	// Next, ask user which card they would like to play from hand
	createMenus();

	// decrement turns
	turns--;
}

/******************************************************************************
** Description: Function that draws from pile.
******************************************************************************/
Card* GameEngine::drawPile()
{
	// Store card on top of pile
	Card *top = pile.front();
	Card *copy = new Card(*top);
	
	// Display temp card
	cout << "Card drawn from pile reads:" << endl;
	top->displayCard();
	cout << endl;

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
** Description: Function that displays game title.
******************************************************************************/
void GameEngine::displayTitle()
{
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
	for(unsigned i = 0; i < hand.size(); i++)
	{
		cout << i+1 << ". ";
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
	for(unsigned i = 0; i < table.size(); i++)
	{
		cout << i+1 << ". ";
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

