class Reference
{

public :

	//Friend functions
	friend bool equals(Reference x, Reference y);

	//Constructors
	Reference(std::string title1 = "No Title", std::string firstName1 = "Blank", std::string lastName1 = "Anonymous", 
			int MOP1 =1, int DOP1 = 1, int YOP1 = 2000 , int pages1 = 10, int citationCount1 = 0, char type1 = 'J',
				std::string venue1 = "EMSE", std::string city1 = "New York", std::string country1 = "United States" );

	//Used to initialize the rest of the member data to the defualts
	Reference(int newCitationCount);

	//Accessors
	std::string getTitle();
	std::string getLastname();
	int getMonth();
	int getDay();
	int getYear();
	std::string getAuthor();
	
	//Extra Accessors
	char getType();
	std::string getFirstname();
	std::string getVenue();
	std::string getCity();
	std::string getCountry();
	int getPages();
	int getCitationCount();

	//Mutators
	bool setTitle(std::string newTitle);
	bool setFirstname(std::string newFirstName);
	bool setLastname(std::string newLastName);
	bool setMonth(int newMonth);
	bool setDay(int newDay);
	bool setYear(int newYear);
	bool setCitationCount(int newCitationCount);
	bool setType(char newType);

	//Other functions
	void show();
	bool setFormat(char newFormat);
	void parse(std::string CSV);
	bool updateCitationCount(int newCitation);
	
private:
	char formatSetting;
	std::string title;
	std::string firstName;
	std::string lastName ;
	int MOP ;
	int DOP ;
	int YOP ;
	int pages ; 
	int citationCount ;
	char type ;
	std::string venue ;
	std::string city ;
	std::string country ;
};
