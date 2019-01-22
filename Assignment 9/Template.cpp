//modified and completed by Kalli Bonin
//Assignment #9 - Question 1 - CardHand Class

#include <iostream>
#include <stdlib.h>     // rand
#include <time.h>       // time
#include <fstream>

using namespace std;

enum Suit {NONE, CLUBS, HEARTS, DIAMONDS, SPADES};

class Card
{
public:
    int value;
    Suit suit;
    
    //default constructor to ensure empty hand
    Card() 
	{
    	value = 0;
    	suit = NONE;
    }
};

class CardHand
{
private:
	Card hand[52];
	int handSize;
	void SortCards();
public:
    int GetHandSize() const;
    bool AddCard(Card new_card);
    int BetterHand(CardHand otherHand);
    void PrintHand(ostream & out);
    
    CardHand()
    {
    	handSize = 5;
    }
    
    CardHand(int handSize0)
    {
    	//check to see if it exceeds max size or min size
		if (handSize0 > 52 || handSize0 < 1)
    		handSize = 5;
    	else
    		handSize = handSize0;
    }
};

bool DealCards(CardHand hands[], int num_hands)
{
    // check if there are enough cards (only 52 cards available)
    int cards_needed = 0;
    for (int hand_index = 0; hand_index < num_hands; hand_index++)
    {
        cards_needed += hands[hand_index].GetHandSize();
    }
    if (cards_needed > 52)
        return false;

    const int NUM_CARDS = 52;
    Card deck[NUM_CARDS];
    int current_value = 1;
    Suit current_suit = CLUBS;

    // create the deck of cards
    for (int card_index = 0; card_index < NUM_CARDS; card_index++)
    {
        deck[card_index].value = current_value;
        deck[card_index].suit = current_suit;

        current_value++;
        if (current_value > 13)
        {
            switch (current_suit)
            {
                case CLUBS: current_suit = HEARTS;
                    break;
                case HEARTS: current_suit = DIAMONDS;
                    break;
                case DIAMONDS: current_suit = SPADES;
                    break;
                default: break;
            }
            current_value = 1;
        }
    }

    // seed the random number generator
    srand(time(NULL));

    // randomly pull cards from the deck and assign them to each hand
    for (int hand_index = 0; hand_index < num_hands; hand_index++)
    {
        for (int card_index = 0; card_index < hands[hand_index].GetHandSize(); 
		card_index++)
        {
            Card assign_card;
            assign_card.value = 0;
            assign_card.suit = NONE;

            while (assign_card.value == 0)
            {
                int try_card = rand() % 52;

                if (deck[try_card].value > 0)
                {
                    assign_card.value = deck[try_card].value;
                    assign_card.suit = deck[try_card].suit;
                    deck[try_card].value = 0;
                    deck[try_card].suit = NONE;
                }
            }

            hands[hand_index].AddCard(assign_card);
        }
    }

    return true;
}

int main()
{
	const int NUM_HANDS = 4;
	
	//calls default constructor so there will be 5 cards in each of the 4 hands
	CardHand player[NUM_HANDS];
	
	
	DealCards(player, NUM_HANDS);
	
	//create and check output file
	ofstream fout("hands_list.txt");
	if (!fout)
	{
		cout << "Could not open file.";
		return EXIT_FAILURE;
	}
	
	//print all four hands
	for (int i = 0; i < NUM_HANDS; i++)
		player[i].PrintHand(fout);
	
	//comparing hands
	int best = 0;
	for (int i = 1; i < NUM_HANDS; i++)
	{
		if (player[i].BetterHand(player[best]) == 1)
			best = i;	
	}
	
	fout << "Player " << best+1 << " has the best hand." << endl;
	
    return 0;
}

int CardHand::GetHandSize() const
{
    return handSize;
}

bool CardHand::AddCard(Card new_card)
{
	//check within the bounds of the hand 
	for (int i = 0; i < handSize; i++)
	{
		//ensure space is empty
		if (hand[i].value == 0 && hand[i].suit == 0)
		{	
			hand[i].value = new_card.value;
			hand[i].suit = new_card.suit;
			return true;
		}
	}
	
	//if it doesn't find space in hand
    return false;
}

void CardHand::SortCards()
{
	//sort by ascending value
	for (int pass = 0; pass < handSize - 1; pass++)
	{
		int minValue = hand[pass].value;
		Suit minSuit = hand[pass].suit;
		int minIndex = pass;
		
		for (int check = pass+1; check < handSize; check++)
		{
			if (hand[check].value > minValue)
			{
				minValue = hand[check].value;
				minSuit = hand[check].suit;
				minIndex = check;
			}
			

		}
		
		hand[minIndex].value = hand[pass].value;
		hand[minIndex].suit = hand[pass].suit;

		hand[pass].value = minValue;
		hand[pass].suit  = minSuit;

	}
	
	//sort by ascending suit
	int curValue = 1;
	
	for (int pass = 0; pass < handSize - 1; pass++)
	{
		int minValue = hand[pass].value;
		Suit minSuit = hand[pass].suit;
		int minIndex = pass;
		int check = pass + 1;
			
		while (hand[check].value == minValue)
		{
			if (hand[check].suit > minSuit)
			{
				minValue = hand[check].value;
				minSuit = hand[check].suit;
				minIndex = check;
			}
			
			check++;
		}
		
		hand[minIndex].value = hand[pass].value;
		hand[minIndex].suit = hand[pass].suit;
		hand[pass].value = minValue;
		hand[pass].suit = minSuit;
	}
		
}

int CardHand::BetterHand(CardHand otherHand) 
{
	//this function takes into account the value of the card
	//the hand with the highest sum of card values has the better hand
	int thisSum = 0, otherSum = 0;
	
	for (int i = 0; i < handSize; i++)
	{
		thisSum += (*this).hand[i].value;
		otherSum += otherHand.hand[i].value;
	}
	
	if (thisSum > otherSum)
		return 1;
	else if (thisSum < otherSum)
		return -1;
	else
		return 0;
}

void CardHand::PrintHand(ostream & out)
{
	SortCards();
	
	out << "------------------------ start of hand ---------------------------"
		<< endl;
		
	for (int i = 0; i < handSize; i++)
	{
		//use switch-case to assign letter values to face cards
		switch (hand[i].value)
			{
				case 1:
					out << "A";
					break;
				case 11:
					out << "J";
					break;
				case 12:
					out << "Q";
					break;
				case 13:
					out << "K";
					break;
				default:
					out << hand[i].value;
					break;
			}
		
		//use switch-case to assign suit string
		switch (hand[i].suit)
            {
                case CLUBS: 
					out << " CLUBS" << endl;
                    break;
                case HEARTS: 
					out << " HEARTS" << endl;
                    break;
                case DIAMONDS: 
					out << " DIAMONDS" << endl;
                    break;
                case SPADES:
                	out << " SPADES" << endl;
                	break;
                default: 
                	out << " NONE" << endl;
					break;
            }
	}
		
	
	out << "------------------------- end of hand ----------------------------"
		<< endl;
	
}
