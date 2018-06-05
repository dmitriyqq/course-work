//
// Created by dima on 18.03.18.
//

#include "ComputerBoard.h"
#include "../Model/BestFSSolver.hh"

ComputerBoard::ComputerBoard(int player_id, const Board &game, bool enableInput, QWidget *parent)
        : PlayerBoard(player_id, game, enableInput, true, parent),
          worker([game, this]() {
              std::shared_ptr<AbstractScoreFunctor> score_func(new SimpleScoreFunctor());

              BestFSSolver solver(score_func, GlobalSettings::get().getAiMaxLevel());

              Board sample = game;

              moves = solver.solveWrap(sample);

          }) {

}

GameMove ComputerBoard::getNextMove() {
    if (worker.joinable()) {
        worker.join();
        std::cout << "moves: " << moves.size() << std::endl;
    }

    if (moves.size()) {
        GameMove move = moves.back();
        moves.pop_back();
        applyMove(move);
        return move;
    }

    return GameMove::NOPE;
}


void ComputerBoard::handleCanMove(GameMove m) {
    makeMove(getNextMove());
}

ComputerBoard::~ComputerBoard() {
    if (worker.joinable())
        worker.detach();
};

