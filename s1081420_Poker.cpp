#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include <cstdlib>
#include "s1081420_Poker.h" // Card, DeckOfCards, Hand class definition
using namespace std;

string faceNames[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six","Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
string suitNames[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

Card::Card(int f, int s) {
	face = f;
	suit = s;
}

string Card::toString() {
	string s = faceNames[face] + " of " + suitNames[suit];
	return s;
}
int  Card::getface() {
	return face;
}
int  Card::getsuit() {
	return suit;
}

DeckOfCards::DeckOfCards() {
	currentCard = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			Card c(j, i);
			v.push_back(c);
		}
	}
}

void DeckOfCards::reset() {
	currentCard = 0;
	DeckOfCards d;
	d.shuffle();
	currentCard = 0;
	*this = d;
}

void DeckOfCards::shuffle() {
	srand(time(0));
	int num = rand() % 52;//0~51
	int currentnum = 0;
	while (currentnum < 51) {
		num = rand() % 52;//0~51
		if (num <= currentnum)continue;
		Card temp(0,0);
		temp = v[num];
		v[num] = v[currentnum];
		v[currentnum] = temp;
		++currentnum;
	}
}

Card DeckOfCards::dealCard() {
	if (currentCard < 52) {
		return v[currentCard++];
	}
	else cout << "dealCard has no next card" << endl;

}

bool DeckOfCards::moreCards() {
	if (currentCard < 52)return true;
	else return false;
}

Hand::Hand(DeckOfCards  &deck) {
	v_hand.clear();
	for (int i = deck.currentCard; i < deck.currentCard + 5; i++) {
		//Card c = deck.v[i];
		if(i<52)
		v_hand.push_back(deck.v[i]);
	}
	deck.currentCard += 5;
}//抽出五張牌

void Hand::print() {
	for (int i = 0; i < 5; i++) {
		cout << v_hand[i].toString() << endl;
	}
}//輸出手上5張牌

void  Hand::takeAgain(DeckOfCards& deck) {
	v_hand.clear();
	Hand h(deck);
	if (h.v_hand.size() ==2)deck.currentCard = 52;
	*this = h;
}//丟掉目前手上的牌重新抽五張

const bool Hand::pair() {
	int array[13] = { 0 };
	for (int i = 0; i < 5; i++) {
		int num = v_hand[i].getface();
		array[num]++;
	}
	int i = 0, j = 0;
	while (i < 13) {
		if (array[i] == 2) { 
			j++;
		}
		i++;
	}
	if (j == 1)return true;
	else return false;
}
const bool Hand::twoPair() {
	int array[13] = { 0 };
	for (int i = 0; i < 5; i++) {
		int num = v_hand[i].getface();
		array[num]++;
	}
	int i = 0, j = 0;
	while (i < 13) {
		if (array[i] == 2) {
			j++;
		}
		i++;
	}
	if (j == 2)return true;
	else return false;
}
const bool Hand::threeOfAKind() {
	int array[13] = { 0 };
	for (int i = 0; i < 5; i++) {
		int num = v_hand[i].getface();
		array[num]++;
	}
	int i = 0, j = 0;
	while (i < 13) {
		if (array[i] == 3) {
			j++;
		}
		i++;
	}
	if (j == 1)return true;
	else return false;
}
const bool Hand::fourOfAKind() {
	int array[13] = { 0 };
	for (int i = 0; i < 5; i++) {
		int num = v_hand[i].getface();
		array[num]++;
	}
	int i = 0, j = 0;
	while (i < 13) {
		if (array[i] == 4) {
			j++;
		}
		i++;
	}
	if (j == 1)return true;
	else return false;
}
const bool Hand::flush() {//
	int array[4] = { 0 };
	for (int i = 0; i < 5; i++) {
		int num = v_hand[i].getsuit();
		array[num]++;
	}
	int i = 0, j = 0;
	while (i < 4) {
		if (array[i] == 5) {
			j++;
		}
		i++;
	}
	if (j == 1)return true;
	else return false;
}
const bool Hand::fullHouse() {
	if (this->pair()) {
		if (this->threeOfAKind())return true;
	}
	else return false;
}
const bool Hand::straight() {
	int array[13] = { 0 };
	for (int i = 0; i < 5; i++) {
		int num = v_hand[i].getface();
		array[num]++;
	}
	int j = 0;
	for (int i = 0; i < 13; i++) {
		if (array[i] == 1) {
			while ((i + 4) < 13) {
				if (array[i] == 1 && array[i + 1] == 1 && array[i + 2] == 1 && array[i + 3] == 1 && array[i + 4] == 1)return true;
				else return false;
			}
		}
		return false;
	}
}