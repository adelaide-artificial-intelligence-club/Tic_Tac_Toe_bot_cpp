// utttbot.cpp

#include "utttbot.h"

#include <iostream>
#include <sstream>

//setup your stuff here
UTTTBot::UTTTBot()
{
	board.resize(9);
	for (int i = 0; i < 9; i++) {
		board[i].resize(9);
	}
	field.resize(3);
	for (int i = 0; i < 3; i++) {
		field[i].resize(3);
	}
}

//main loop
void UTTTBot::run() {
	string line;
	while (getline(cin, line)) {
		vector<string> command = split(line, ' ');
		if (command[0] == "settings") {
			setting(command[1], command[2]);
		} else if (command[0] == "update" && command[1] == "game") {
			update(command[2], command[3]);
		} else if (command[0] == "action" && command[1] == "move") {
			move(stoi(command[2]));
		} else {
			cerr << "Unknown command: " << line << endl;
		}
	}
}

void UTTTBot::move(int timeout) {
	//add your move stuff here
	// the macro board can be accessed with field[X][Y]
	// the 9X9 can be accesed with board[Xb][Yb]
	int x = 1;
	int y = 1;
	cout << "place_disc " << x << " " << y << endl;
}

//update the 9X9 board
void UTTTBot::updateBoard(string value)
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < value.length(); i+=2) {
		if (value[i] == '.') {
			board[x][y] = -1;
		}
		else if (value[i] == '0') {
			board[x][y] = 0;
		}
		else {
			board[x][y] = 1;
		}
		x++;
		if (x > 8) {
			x = 0;
			y++;
		}
	}
	for (int i = 0; i < 9; i ++) {
		for (int j = 0; j < 9; j ++) {
			cerr << board[j][i] << ",";
		}
		cerr << endl;
	}
	cerr << endl;
}

//update 3X3 board
void UTTTBot::updateMacroBoard(string value)
{
	int x = 0;
	int y = 0;
	string str = "";
	for (int i = 0; i < value.length(); i++) {
		if (value[i] == ',' or i == value.length() - 1) {
			if (i == value.length() - 1) {
				str += value[i];
			}
			if (str == ".") {
				macroBoard[x][y] = 2;
			}
			else if (str == "-1") {
				macroBoard[x][y] = -1;
			}
			else if (str == "1") {
				macroBoard[x][y] = 1;
			}
			else {
				macroBoard[x][y] = 0;
			}
			str = "";
			x++;
			if (x > 2) {
				x = 0;
				y++;
			}
		}
		else {
			str += value[i];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cerr << macroBoard[j][i] << ",";
		}
		cerr << endl;
	}
	cerr << endl;
}

//run updates
void UTTTBot::update(string &key, string &value) {
	if (key == "round") {
		r = stoi(value);
	} else if (key == "field") {
		updateBoard(value);
	} else if (key == "macroboard") {
		updateMacroBoard(value);
	}
}

//change settings
void UTTTBot::setting(string &key, string &value) {
	if (key == "timebank") {
		timebank = stoi(value);
	} else if (key == "time_per_move") {
		time_per_move = stoi(value);
	} else if (key == "player_names") {
		vector<string> names = split(value, ',');
		player_names[0] = names[0];
		player_names[1] = names[1];
	} else if (key == "your_bot") {
		your_bot = value;
	} else if (key == "your_botid") {
		your_botid = stoi(value);
	}
}

//split string
vector<string> UTTTBot::split(const string &s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

