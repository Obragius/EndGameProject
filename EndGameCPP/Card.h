#include <iostream>
#include <vector>
#include <algorithm>
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
            vector<string> names = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"}; // Create an array of all names 
            vector<string> suits = {"Hearts","Diamonds","Spades","Clubs"};



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
                auto it = find(this->names.begin(),this->names.end(), this->name); // Find the index of the card
                int index = distance(this->names.begin(),it);

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