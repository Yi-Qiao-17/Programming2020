#pragma once
#ifndef s1081420_Poker_H
#define s1081420_Poker_H

#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include <cstdlib>
using namespace std;

class Card {
	private:
		int face;
		int suit;
	public:
		Card(int, int);
		string toString();//EX. Ace of Hearts
		int getface();
		int getsuit();
};

class DeckOfCards {
private:
	
public:
	vector<Card>v;
	int currentCard;
	DeckOfCards();
	void reset();//���]52�i�P
	void shuffle();//�~�P
	Card dealCard();//�^�ǤU�@��Card object from the deck.
	bool moreCards();//�P�_�O�_�٦��U�@�i�P�i�~��ϥ�
};

class Hand {
private:
	vector<Card>v_hand;
public:
	Hand(DeckOfCards&);//��X���i�P
	void print();//��X��W5�i�P
	void takeAgain(DeckOfCards&);//�ᱼ�ثe��W���P���s�⤭�i
	const bool pair();
	const bool twoPair();
	const bool threeOfAKind();
	const bool fourOfAKind();
	const bool flush();
	const bool fullHouse();
	const bool straight();
};

#endif // !s1081420_Poker_H
