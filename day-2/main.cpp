#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

std::map<std::string, std::string> opponent_RPS = {
    {"A", "rock"},
    {"B", "paper"},
    {"C", "scissors"}
};

std::map<std::string, std::string> player_RPS = {
        {"X", "rock"},
        {"Y", "paper"},
        {"Z", "scissors"}
};

std::map<std::string, int> score_player = {
        {"rock", 1},
        {"paper", 2},
        {"scissors", 3}
};

std::map<std::string, int> score_game = {
        {"lost", 0},
        {"draw", 3},
        {"won", 6}
};

std::map<std::string, std::string> my_goals_dict = {
        {"X", "lose"},
        {"Y", "draw"},
        {"Z", "win"}
};

// Determine outcome of the round
int score_RPS_game(std::string player, std::string opponent) {
    if (opponent == "rock") {
        if (player == "rock"){
            return score_game["draw"];
        }
        else if (player == "paper"){
            return score_game["won"];
        }
        else if (player == "scissors"){
            return score_game["lost"];
        }
    }
    else if (opponent == "paper") {
        if (player == "rock"){
            return score_game["lost"];
        }
        else if (player == "paper"){
            return score_game["draw"];
        }
        else if (player == "scissors"){
            return score_game["won"];
        }
    }
    else if (opponent == "scissors") {
        if (player == "rock"){
            return score_game["won"];
        }
        else if (player == "paper"){
            return score_game["lost"];
        }
        else if (player == "scissors"){
            return score_game["draw"];
        }
    }

    std::cout << "Invalid input!!!" << std::endl;
    return 0;
}

// Determine my move for the round
std::string my_move(std::string &opponent_move, std::string &my_goal) {
    if (opponent_move == "rock") {
        if (my_goal == "win"){
            return "paper";
        }
        else if (my_goal == "draw"){
            return "rock";
        }
        else if (my_goal == "lose"){
            return "scissors";
        }
    }
    else if (opponent_move == "paper") {
        if (my_goal == "win"){
            return "scissors";
        }
        else if (my_goal == "draw"){
            return "paper";
        }
        else if (my_goal == "lose"){
            return "rock";
        }
    }
    else if (opponent_move == "scissors") {
        if (my_goal == "win"){
            return "rock";
        }
        else if (my_goal == "draw"){
            return "scissors";
        }
        else if (my_goal == "lose"){
            return "paper";
        }
    }

    std::cout << "Invalid input!!!" << std::endl;
    return "BLABLA";
}

// PART 1
//int main() {
//
//    // Open the file
//    std::ifstream file("input.txt");
//
//    std::vector<std::string> opponent_moves;
//    std::vector<std::string> player_moves;
//
//    // Check if the file is open
//    if (file.is_open()) {
//        // Read the file line by line
//        // Store the first letter as the opponent's move
//        // Store the second letter as the player's move
//        std::string line;
//        while (std::getline(file, line)) {
//            if (line.size() == 3) {
//                opponent_moves.push_back(opponent_RPS[line.substr(0, 1)]);
//                player_moves.push_back(player_RPS[line.substr(2, 1)]);
//            }
//        }
//    }
//
//    // Close the file
//    file.close();
//
//    // Calculate the score
//    // The score is the sum of score_player
//    // and score_RPS_game
//    int score = 0;
//    for (int i = 0; i < opponent_moves.size(); i++) {
//        score += score_player[player_moves[i]];
//        score += score_RPS_game(player_moves[i], opponent_moves[i]);
//    }
//
//    // Print the score
//    std::cout << "Score: " << score << std::endl;
//
//
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

// PART 2
int main() {
    // Open the file
    std::ifstream file("input.txt");

    std::vector<std::string> opponent_moves;
    std::vector<std::string> player_moves;
    std::vector<std::string> my_goals;

    // Check if the file is open
    if (file.is_open()) {
        // Read the file line by line
        // Store the first letter as the opponent's move
        std::string line;
        while (std::getline(file, line)) {
            if (line.size() == 3) {
                opponent_moves.push_back(opponent_RPS[line.substr(0, 1)]);
                my_goals.push_back(my_goals_dict[line.substr(2, 1)]);
            }
        }
    }

    // Close the file
    file.close();

    // Calculate my moves
    for (int i = 0; i < opponent_moves.size(); i++) {
        player_moves.push_back(my_move(opponent_moves[i], my_goals[i]));
    }

    // Calculate the score
    // The score is the sum of score_player
    // and score_RPS_game
    int score = 0;
    for (int i = 0; i < opponent_moves.size(); i++) {
        score += score_player[player_moves[i]];
        score += score_RPS_game(player_moves[i], opponent_moves[i]);
    }

    // Print the score
    std::cout << "Score: " << score << std::endl;



    // Calculate the score
    return 0;
}
