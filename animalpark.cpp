
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/*Checks every character for anything other than (+/-/c/C/d/D/p/P)
First character can only be (c/C/d/D)
Last character can only be (p/P)
Checks that string is not empty
*/
bool checkcharacters(string animalparkString);
bool checkcharacters(string animalparkString)
{	
	size_t k = 0;

	if (animalparkString.empty())
	{
		return(false);
	}
	for (size_t k = 0; k < animalparkString.size(); k++)
	{
		char c = animalparkString.at(k);
		switch (c)
		{
		case 'd':
		case 'D':
		case 'c':
		case 'C':
		case 'p':
		case 'P':
		case '+':
		case '-':
			break;
		default:
			return(false);
			break;
		}
	}
	char d = animalparkString.at(0);
	switch (d)
	{
	case 'd':
	case 'D':
	case 'c':
	case 'C':
		break;
	default:
		return(false);
		break;
	}
	char e = animalparkString.at(animalparkString.size() - 1);
	switch (e)
	{
	case 'p':
	case 'P':
		break;
	default:
		return(false);
		break;
	}
	return(true);
}

/* Using the defined int state (1 or 0) , function differentiates between 1)blocks of letters and 2)plus and minus signs
Checks that block of letters is followed by plus and minus signs
Checks that plus and minus signs are followed only by (c/C/d/D)
Checks that within a block of letters, there are both animals and pets
Checks that within a block of letters, all animals come before all pets
*/
bool checkorder(string animalparkString);
bool checkorder(string animalparkString)
{
	size_t k = 0;
	int state = 1;
	bool hasAnimals = false;
	bool hasPeople = false;
	bool statement = true;

	for (size_t k = 0; k < animalparkString.size(); k++)
	{
		if (state == 1)
		{
			char c = animalparkString.at(k);
			switch (c)
			{
			case 'd':
			case 'D':
			case 'c':
			case 'C':
				if (hasPeople == true)
				{
					statement = false;
					break;
				}
				else
				{
					hasAnimals = true;
					break;
				}
			case 'p':
			case 'P':
				if (hasAnimals == false)
				{
					statement = false;
					break;
				}
				else
				{
					hasPeople = true;
					break;
				}
			case '+':
			case '-':
				if (hasAnimals == true && hasPeople == true)
				{
					state = 0;
					break;
				}
				else
				{
					statement = false;
					break;
				}
			}
		}
		else
		{
			char c = animalparkString.at(k);
			switch (c)
			{
			case 'd':
			case 'D':
			case 'c':
			case 'C':
				state = 1;
				hasAnimals = true;
				hasPeople = false;
				break;
			case 'p':
			case 'P':
				statement = false;
				break;
			case '+':
			case '-':
				statement = false;
				break;
			}
		}
		
	}
	if (hasAnimals == true && hasPeople == true && statement == true)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

/* Checks that none of puppies, dogs, kittens, cats, children, adults have a value smaller than zero at any point in the string
Checks that within a block of letters, there is no positive value of both cats (kittens and adult cats) and dogs (puppies and adult dogs)
(i.e. checks that cats and dogs don't mix)
Defined int state (1 or 0) is used to switch between adding and subtracting according to whether a plus and minus sign is encountered respectively
*/
bool checklogic(string animalparkString);
bool checklogic(string animalparkString)
{
	int d = 0;
	int D = 0;
	int K = 0;
	int C = 0;
	int p = 0;
	int P = 0;
	int dogs = 0;
	int cats = 0;
	int state = 1;
	
	for (size_t k = 0; k < animalparkString.size(); k++)
	{
		if (state == 1)
		{
			char c = animalparkString.at(k);
			switch (c)
			{
			case 'd':
				d = d + 1;
				dogs = dogs + 1;
				break;
			case 'D':
				D = D + 1;
				dogs = dogs + 1;
				break;
			case 'c':
				K = K + 1;
				cats = cats + 1;
				break;
			case 'C':
				C = C + 1;
				cats = cats + 1;
				break;
			case 'p':
				p = p + 1;
				break;
			case 'P':
				P = P + 1;
				break;
			case '+':
				cats = 0;
				dogs = 0;
				break;
			case '-':
				state = 0;
				cats = 0;
				dogs = 0;
				break;
			}
		}
		else
		{
			char c = animalparkString.at(k);
			switch (c)
			{
			case 'd':
				d = d - 1;
				dogs = dogs + 1;
				break;
			case 'D':
				D = D - 1;
				dogs = dogs + 1;
				break;
			case 'c':
				K = K - 1;
				cats = cats + 1;
				break;
			case 'C':
				C = C - 1;
				cats = cats + 1;
				break;
			case 'p':
				p = p - 1;
				break;
			case 'P':
				P = P - 1;
				break;
			case '+':
				state = 1;
				cats = 0;
				dogs = 0;
				break;
			case '-':
				cats = 0;
				dogs = 0;
				break;
			}
		}
		if ((dogs > 0) && (cats > 0))
		{
			return(false);
		}
		if ((d < 0) || (D < 0) || (K < 0) || (C < 0) || (p < 0) || (P < 0))
		{
			return(false);
		}
	}
	return(true);
}

/*All of checkcharacters(string animalparkString), checkorder(string animalparkString), and checklogic(string animalparkString)
have to return true for string to be a valid animal park string
*/
bool isValidAnimalParkString(string animalparkString);
bool isValidAnimalParkString(string animalparkString)
{
	if ((checkcharacters(animalparkString) == true) && (checkorder(animalparkString) == true) && (checklogic(animalparkString) == true))
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

/*Totals number of dogs, defined int state (1 or 0) is used to switch between adding and subtracting 
according to whether a plus and minus sign is encountered respectively
*/
int dogsLeft(string animalparkString);
int dogsLeft(string animalparkString)
{
	if (isValidAnimalParkString(animalparkString) == false)
	{
		return(-1);
	}
	else
	{
		int state = 1;
		int dogs = 0;
		for (size_t k = 0; k < animalparkString.size(); k++)
		{
			if (state == 1)
			{
				char c = animalparkString.at(k);
				switch (c)
				{
				case 'd':
				case 'D':
					dogs = dogs + 1;
					break;
				case '-':
					state = 0;
					break;
				default:
					break;
				}
			}
			else
			{
				char c = animalparkString.at(k);
				switch (c)
				{
				case 'd':
				case 'D':
					dogs = dogs - 1;
					break;
				case '+':
					state = 1;
					break;
				default:
					break;
				}
			}
		}
		return(dogs);
	}
}

/*Totals number of cats, defined int state (1 or 0) is used to switch between adding and subtracting
according to whether a plus and minus sign is encountered respectively
*/
int catsLeft(string animalparkString);
int catsLeft(string animalparkString)
{
	if (isValidAnimalParkString(animalparkString) == false)
	{
		return(-1);
	}
	else
	{
		int state = 1;
		int cats = 0;
		for (size_t k = 0; k < animalparkString.size(); k++)
		{
			if (state == 1)
			{
				char c = animalparkString.at(k);
				switch (c)
				{
				case 'c':
				case 'C':
					cats = cats + 1;
					break;
				case '-':
					state = 0;
					break;
				default:
					break;
				}
			}
			else
			{
				char c = animalparkString.at(k);
				switch (c)
				{
				case 'c':
				case 'C':
					cats = cats - 1;
					break;
				case '+':
					state = 1;
					break;
				default:
					break;
				}
			}
		}
		return(cats);
	}
}

/*Totals number of people, defined int state (1 or 0) is used to switch between adding and subtracting
according to whether a plus and minus sign is encountered respectively
*/
int peopleLeft(string animalparkString);
int peopleLeft(string animalparkString)
{
	if (isValidAnimalParkString(animalparkString) == false)
	{
		return(-1);
	}
	else
	{
		int state = 1;
		int people = 0;
		for (size_t k = 0; k < animalparkString.size(); k++)
		{
			if (state == 1)
			{
				char c = animalparkString.at(k);
				switch (c)
				{
				case 'p':
				case 'P':
					people = people + 1;
					break;
				case '-':
					state = 0;
					break;
				default:
					break;
				}
			}
			else
			{
				char c = animalparkString.at(k);
				switch (c)
				{
				case 'p':
				case 'P':
					people = people - 1;
					break;
				case '+':
					state = 1;
					break;
				default:
					break;
				}
			}
		}
		return(people);
	}
}

int main()
{


	return(0);
}
