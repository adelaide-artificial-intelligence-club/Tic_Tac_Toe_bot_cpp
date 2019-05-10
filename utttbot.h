// utttbot.h

#ifndef UTTTBOT_H
#define UTTTBOT_H

#include <string>
#include <vector>
using namespace std;

class UTTTBot {
private:
	int timebank;
	int time_per_move;
	string player_names[2];
	string your_bot;
	int your_botid;
	int r;
	vector<vector<int>> board;
	vector<vector<int>> field;

	vector<string> split(const std::string &s, char delim);
	void setting(string &key, string &value);
	void update(string &key, string &value);
	void move(int timeout);
	void updateField(std::string value);
	void updateBoard(std::string value);
public:
	UTTTBot();
	void run();
};

#endif // UTTTBOT_H

