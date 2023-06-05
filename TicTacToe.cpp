
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "TicTacToe.h"
#include "Player.h"


void TicTacToe::header() {
    std::cout << "   ****************************************" << std::endl;
    std::cout << "*********** KRIZIC KRUZIC 3.4 BETA ***********" << std::endl;
    std::cout << "   ****************************************\n" << std::endl;
}



//==================================================================================================================



void TicTacToe::score() {

    if (_gameMode == 1) {
        std::cout << "\t     " << player1.getScoreVSC() << "     -      " << computer.getScoreVSP() << std::endl << std::endl;
        std::cout << "      " << player1.playerInfo() << "  vs  " << computer.playerInfo() << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    if (_gameMode == 2) {
        std::cout << "\t     " << player1.getScoreVSP() << "     -      " << player2.getScoreVSP() << std::endl << std::endl;
        std::cout << "      " << player1.playerInfo() << "  vs  " << player2.playerInfo() << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
}



//==================================================================================================================



void TicTacToe::setGameMode() {
    system("cls");
    header();

    std::cout << "\n\t1. Jedan igrac" << std::endl;
    std::cout << "\t2. Dva igraca" << std::endl;
    std::cout << "\t0. IZLAZ" << std::endl;
    std::cout << "\n\tUnos: ";

    char input = ' ';

    do {
        std::cin >> input;
        if (input == '1') {
            _gameMode = 1;
        }
        else if (input == '2') {
            _gameMode = 2;
        }
        else if (input == '0') {
            _gameMode = 0;
        }
        else {
            std::cout << "\tGRESKA: Kriv unos! ";
        }
    } while (input != '1' && input != '2' && input != '0');

}


//==================================================================================================================

void TicTacToe::setGameLevel() {
    system("cls");
    header();

    std::cout << "\n\t1. Lagano" << std::endl;
    std::cout << "\t2. Srednje" << std::endl;
    std::cout << "\t3. Tesko" << std::endl;
    std::cout << "\n\tUnos: ";

    char input = ' ';

    do {
        std::cin >> input;

        if (input == '1') {
            _gameLevel = 1;
        }
        else if (input == '2') {
            _gameLevel = 2;
        }
        else if (input == '3') {
            _gameLevel = 3;
        }
        else {
            std::cout << "\tGRESKA: Kriv unos! ";
        }
    } while (input != '1' && input != '2' && input != '3');

}


//==================================================================================================================


void TicTacToe::setPlayer() {
    system("cls");
    header();

    std::cout << "\n\tOdaberite znak X ili O: ";

    char input = ' ';
    bool isValid = true;

    do {
        isValid = true;

        std::cin >> input;

        if (input == 'x' || input == 'X') {
            player1.setSymbol(X_VAL);
            computer.setSymbol(O_VAL);
        }
        else if (input == 'o' || input == 'O') {
            player1.setSymbol(O_VAL);
            computer.setSymbol(X_VAL);
        }
        else {
            std::cout << "\tGRESKA: Unos mora biti X ili O! ";
            isValid = false;
        }
    } while (isValid == false);
}


//==================================================================================================================



void TicTacToe::changePlayer() {
    if (_currentPlayer == X_VAL) {
        _currentPlayer = O_VAL;
    }
    else {
        _currentPlayer = X_VAL;
    }
}


//==================================================================================================================




void TicTacToe::setGame() {

    board.clearBoard();
    _currentPlayer = X_VAL;

    header();

    setGameMode();

    if (_gameMode == 1) {
        setGameLevel();
        setPlayer();
    }
    else if (_gameMode == 2) {
        if (_gameNumber % 2 == 0) {
            player1.setSymbol(O_VAL);
            player2.setSymbol(X_VAL);
        }
        else {
            player1.setSymbol(X_VAL);
            player2.setSymbol(O_VAL);
        }
    }
}



//==================================================================================================================




void TicTacToe::runGame() {
    setGame();

    while (_gameMode != 0) {
        system("cls");
        header();

        score();

        board.printBoard();

        if (_currentPlayer == X_VAL) {
            std::cout << "\n\tIgrac X je na redu\n" << std::endl;
        }
        else {
            std::cout << "\n\tIgrac O je na redu\n" << std::endl;
        }

        if (_gameMode == 1 && _currentPlayer == computer.getSymbol()) {

            computerMove();
        }
        else {

            playerMove();
        }


        if (endGame() == true) {
            endScreen();
        }
        else {
            changePlayer();
        }

    }
}




//==================================================================================================================




void TicTacToe::endScreen() {

    char input = ' ';

    std::cout << "\n\t1. Igraj ponovo" << std::endl;
    std::cout << "\t2. Natrag na Menu" << std::endl;
    std::cout << "\n\tUnos: ";
    
    do {
        std::cin >> input;

        if (input == '1') {
            if (_gameMode == 1) {
                system("cls");
                board.clearBoard();
                setPlayer();
                _currentPlayer = X_VAL;
            }
            else if (_gameMode == 2) {
                system("cls");
                board.clearBoard();
                _gameNumber++;
                if (_gameNumber % 2 == 0) {
                    player1.setSymbol(O_VAL);
                    player2.setSymbol(X_VAL);
                }
                else {
                    player1.setSymbol(X_VAL);
                    player2.setSymbol(O_VAL);
                }
                _currentPlayer = X_VAL;
            }
        }
        else if (input == '2') {

            if (_gameMode == 2) {
                _gameNumber++;
            }

            system("cls");
            setGame();
        }
        else {
            std::cout << "\tGRESKA: Kriv unos! ";
        }
    } while (input != '1' && input != '2');

}


//==================================================================================================================


void TicTacToe::computerMove() {
    if (_gameLevel == 1) {
        randomMove();
    }

    else if (_gameLevel == 2 || _gameLevel == 3) {
        bestMove();
    }
}


//==================================================================================================================



void TicTacToe::randomMove() {
    bool _valid = false;
    int x;
    int y;

    srand(time(0));

    do {
        x = rand() % 3;
        y = rand() % 3;
        if (board.getVal(x, y) == NO_VAL) {
            _valid = true;
        }
    } while (_valid == false);

    board.setVal(x, y, computer.getSymbol());
}



//==================================================================================================================s




void TicTacToe::playerMove() {
    bool wasValid = false;
    int x, y;

    do {
        std::cout << "\tUnesi red (0-2): ";
        while (!(std::cin >> x)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\tGRESKA: Kriv unos! Unesi ponovo: ";
        }

        std::cout << "\tUnesi stupac (0-2): ";
        while (!(std::cin >> y)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\tGRESKA: Kriv unos! Unesi ponovo: ";
        }

        if (x < 0 || y < 0 || x > 2 || y > 2) {
            std::cout << "\tGRESKA: Kriv unos reda ili stupca!" << std::endl;
        }
        else if (board.getVal(x, y) != 0) {
            std::cout << "\tGRESKA: Mjesto je zauzeto!" << std::endl;
        }
        else {
            wasValid = true;
        }

    } while (!wasValid);

    if (_currentPlayer == player1.getSymbol()) {
        board.setVal(x, y, player1.getSymbol());
    }
    else {
        board.setVal(x, y, player2.getSymbol());
    }

}


//==================================================================================================================



int TicTacToe::endGame() {

    int check = checkVictory();

    char input = ' ';

    if (check == X_VAL) {

        if (_gameMode == 1) {
            if (computer.getSymbol() == X_VAL)
            {
                computer.setScoreVSP(computer.getScoreVSP() + 1);
            }
            else {
                player1.setScoreVSC(player1.getScoreVSC() + 1);
            }
        }
        else if (_gameMode == 2) {
            if (player1.getSymbol() == X_VAL) {
                player1.setScoreVSP(player1.getScoreVSP() + 1);
            }
            else {
                player2.setScoreVSP(player2.getScoreVSP() + 1);
            }
        }
        system("cls");
        header();
        score();
        board.printBoard();

        std::cout << "\n\n\tIgrac X je pobijedio!" << std::endl;

        return true;
    }
    else if (check == O_VAL) {

        if (_gameMode == 1) {
            if (computer.getSymbol() == O_VAL)
            {
                computer.setScoreVSP(computer.getScoreVSP() + 1);
            }
            else {
                player1.setScoreVSC(player1.getScoreVSC() + 1);
            }
        }
        else if (_gameMode == 2) {
            if (player1.getSymbol() == O_VAL) {
                player1.setScoreVSP(player1.getScoreVSP() + 1);
            }
            else {
                player2.setScoreVSP(player2.getScoreVSP() + 1);
            }
        }
        system("cls");
        header();
        score();
        board.printBoard();

        std::cout << "\n\n\tIgrac O je pobijedio!" << std::endl;

        return true;
    }

    else if (check == TIE_VAL) {

        system("cls");
        header();
        score();
        board.printBoard();

        std::cout << "\n\n\tNerijeseno!" << std::endl;

        return true;
    }
    else {
        return false;
    }

}


//==================================================================================================================


int TicTacToe::checkVictory() {
    for (int i = 1; i <= 2; i++) {
        /*provjera redova*/
        if (board.getVal(0, 0) == i && board.getVal(0, 1) == i && board.getVal(0, 2) == i) {
            return i;
        }
        if (board.getVal(1, 0) == i && board.getVal(1, 1) == i && board.getVal(1, 2) == i) {
            return i;
        }
        if (board.getVal(2, 0) == i && board.getVal(2, 1) == i && board.getVal(2, 2) == i) {
            return i;
        }
        /*provjera stupaca*/
        if (board.getVal(0, 0) == i && board.getVal(1, 0) == i && board.getVal(2, 0) == i) {
            return i;
        }
        if (board.getVal(0, 1) == i && board.getVal(1, 1) == i && board.getVal(2, 1) == i) {
            return i;
        }
        if (board.getVal(0, 2) == i && board.getVal(1, 2) == i && board.getVal(2, 2) == i) {
            return i;
        }
        //provjera dijagonala
        if (board.getVal(0, 0) == i && board.getVal(1, 1) == i && board.getVal(2, 2) == i) {
            return i;
        }
        if (board.getVal(0, 2) == i && board.getVal(1, 1) == i && board.getVal(2, 0) == i) {
            return i;
        }
    }
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (board.getVal(x, y) == NO_VAL) {
                return NO_VAL;
            }
        }
    }
    return TIE_VAL;
}


//==================================================================================================================


void TicTacToe::bestMove() {
    ComputerMoves bestMove = getBestMove(computer.getSymbol());
    board.setVal(bestMove.x, bestMove.y, computer.getSymbol());
}


//==================================================================================================================



ComputerMoves TicTacToe::getBestMove(int player, int depth)
{
    int result = checkVictory();

    // osnovni uvjet koji sluzi kako se rekurzija nebi biskonacno pozivala
    // ako je komjuter pobijedio vraca +10 bodova, a ako je izgubio -10.
    // kako nebi doslo do problema gdje se kompjuter predaje, odnosno gdje komjuter ne igra do kraja nego bira jer 
    // dobiva isti broj bodova ako izgubi odmah ili na kraju igre dodaje se parametar depth,
    // odnosno broj poteza koji sluzi kako bi se igra produljila do kraja jer postoji nada da ce
    // suprotni igrac napraviti gresku

    if (result == computer.getSymbol())
    {
        return ComputerMoves(10 - depth);
    }
    else if (result == player1.getSymbol())
    {
        if (_gameLevel == 2) {
            return ComputerMoves(depth - 6);
        }        
        if (_gameLevel == 3) {
            return ComputerMoves(depth - 10);
        }   
    }
    else if (result == TIE_VAL)
    {
        return ComputerMoves(+10);    
    }

    depth++;

    //vektor se koristi kako bi se u njega pohranili potezi
    std::vector<ComputerMoves> moves;

    //For petlja pretrazuje prazno mjesto u polje u koje kompjuter postavlja vrijednost
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (board.getVal(x, y) == NO_VAL)
            {
                //Definira se objekt klase Computer u koju se spremaju koordinate upisanog polja
                ComputerMoves move;
                move.x = x;
                move.y = y;


                //Dok se funkcija ne obavi privremeno se upisuju vrijednosti u polje
                board.setVal(x, y, player);


                //kad se postavlia vrijednost dobavljaju se njegovi bodovi tako da se
                //rekurzivno poziva dok se ne dode do rezultata
                //ako je komjuter odigrao potez trazi se najbolji potez za drugog igraca

                if (player == computer.getSymbol()) {
                    move.score = getBestMove(player1.getSymbol(), depth).score;
                }
                else {
                    move.score = getBestMove(computer.getSymbol(), depth).score;
                }

                //u vektor se sprema potez
                moves.push_back(move);

                //vraca se vrijednst polja na 0 
                board.setVal(x, y, NO_VAL);
            }
        }
    }

    int bestMove = 0;


    if (player == computer.getSymbol())
    {
        int bestScore = -1000;
        for (size_t i = 0; i < moves.size(); i++)
        {
            //iz vektora se odabire potez sa najvecim brojem bodova
            if (moves[i].score > bestScore)
            {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    else
    {
        int bestScore = 1000;
        for (size_t i = 0; i < moves.size(); i++)
        {
            //odabire se potez sa najvecim brojem bodova
            if (moves[i].score < bestScore) {

                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }

    //vraca se najbolji potez
    return moves[bestMove];
}