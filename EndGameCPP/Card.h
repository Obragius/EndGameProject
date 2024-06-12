#include <iostream>
using namespace std;
namespace myCard
{
    class Card
    {
        private:
            string suit;
            string name;
        public:
            // Moved the names to public attrbiutes to use in the deck class
            string names[13] = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"}; // Create an array of all names 
            string suits[4] = {"Hearts","Diamonds","Spades","Clubs"};



            Card()
            {

            }

            Card(string suit, string name)
            {
                this->suit = suit;
                this->name = name;
            }

            string getSuit()
            {
                return this->suit;
            }

            void setSuit(string suit)
            {
                this->suit = suit;
            }

            string getName()
            {
                return this->name;
            }

            void setName(string name)
            {
                this->name = name;
            }

            int getValue()
            {
                // Switch statements cannot use strings so a workaround
                int index = Card::names->find(this->name); // Find the index of the card
                if (index < 9)
                {
                    return index + 2;
                }
                else if (index > 8 && index < 12)
                {
                    return 10;
                }
                else
                {
                    return 11;
                }
            }

            int getAltValue()
            {
                if (this->name == "Ace")
                {
                    return 1;
                }
                else
                {
                    return this->getValue();
                }
            }

                

    };
}