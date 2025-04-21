#include <iostream>
#include <vector>

using namespace std;

int main() {

    const int GAMES = 500;
    const int ROUNDS = 6;

    vector<bool> possible_bots(8, true); 

    vector<vector<int>> our_strategies = {
        {2, 3, 4, 5, 6, 1},  // Против минимальной карты
        {1, 6, 5, 4, 3, 2},  // Против максимальной карты
        {3, 2, 4, 6, 5, 1},  // Против (1,2,3 → 4,5,6)
        {6, 5, 1, 3, 2, 4},  // Против (4,5,6 → 1,2,3)
        {3, 4, 5, 6, 2, 1},  // Против случайной из 2 мин
        {6, 5, 4, 3, 2, 1},  // Против случайной из 2 макс
        {4, 5, 6, 3, 2, 1},  // Против случайной из 3 мин
        {6, 5, 4, 3, 2, 1}   // Против случайной из 3 макс
    };

    
    for (int game = 0; game < GAMES; game++) {
        vector<int> bot_moves(ROUNDS);

        int count_true = 0;
        int last_possible_bot = -1;

        for (int i = 0; i < 8; i++) {
            if (possible_bots[i]) {
                count_true++;
                if (last_possible_bot == -1) {
                    last_possible_bot = i;  
                }
            }
        }

        for (int round = 0; round < ROUNDS; ++round) {

            if (count_true == 1) {
                cout << our_strategies[last_possible_bot][round] << endl;
                cout.flush();

                cin >> bot_moves[round];

            } else {
                cout << our_strategies[last_possible_bot][round] << endl;
                cout.flush();

                cin >> bot_moves[round];
                if (round == 0) {
                    int first_bot_move;
                    first_bot_move = bot_moves[round];

                    if (first_bot_move == 1) {
                        possible_bots[1] = false;
                        possible_bots[3] = false;
                        possible_bots[5] = false;
                        possible_bots[7] = false;
                    }
                    if (first_bot_move == 2) {
                        possible_bots[0] = false;
                        possible_bots[1] = false;
                        possible_bots[5] = false;
                        possible_bots[3] = false;
                        possible_bots[7] = false;
                    }
                    if (first_bot_move == 3) {
                        possible_bots[1] = false;
                        possible_bots[0] = false;
                        possible_bots[3] = false;
                        possible_bots[4] = false;
                        possible_bots[5] = false;
                        possible_bots[7] = false;
                    }
                    if (first_bot_move == 4) {
                        possible_bots[0] = false;
                        possible_bots[1] = false;
                        possible_bots[2] = false;
                        possible_bots[4] = false;
                        possible_bots[5] = false;
                        possible_bots[6] = false;
                    }
                    if (first_bot_move == 5) {
                        possible_bots[0] = false;
                        possible_bots[1] = false;
                        possible_bots[2] = false;
                        possible_bots[4] = false;
                        possible_bots[6] = false;
                    }
                    if (first_bot_move == 6) {
                        possible_bots[0] = false;
                        possible_bots[2] = false;
                        possible_bots[4] = false;
                        possible_bots[6] = false;
                    }
                }
                
                if (possible_bots[2] == true && round < 3) {
                    if (bot_moves[round] > 3) {
                        possible_bots[2] = false;
                    }
                }
                if (possible_bots[3] == true && round > 2) {
                    if (bot_moves[round] > 3) {
                        possible_bots[3] = false;
                    }
                } 
            }
        }
    }

    return 0;
}



