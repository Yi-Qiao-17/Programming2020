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
	void reset();//重設52張牌
	void shuffle();//洗牌
	Card dealCard();//回傳下一個Card object from the deck.
	bool moreCards();//判斷是否還有下一張牌可繼續使用
};

class Hand {
private:
	vector<Card>v_hand;
public:
	Hand(DeckOfCards&);//抽出五張牌
	void print();//輸出手上5張牌
	void takeAgain(DeckOfCards&);//丟掉目前手上的牌重新抽五張
	const bool pair();
	const bool twoPair();
	const bool threeOfAKind();
	const bool fourOfAKind();
	const bool flush();
	const bool fullHouse();
	const bool straight();
};

#endif // !s1081420_Poker_H
