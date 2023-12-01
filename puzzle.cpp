#include "doctest.h"
#include "puzzle.h"

Puzzle::Puzzle() {}

/**
 * Create a puzzle out of an existing vector of pieces.
 * @brief Puzzle::Puzzle
 * @param pieces, the vector of pieces that gets copied into this puzzle.
 */
Puzzle::Puzzle(std::vector<PuzzlePiece> pieces){
    this->pieces = pieces;
}

TEST_CASE("Puzzle pieces are immutual"){
    std::vector<PuzzlePiece> pieces = {PuzzlePiece()};
    Puzzle p = Puzzle(pieces);

    //Modify external vector but not the pieces in the puzzle.
    pieces.push_back(PuzzlePiece());

    CHECK(p.getPieces().size() != pieces.size());
}

/**
 * Get the puzzle pieces of this puzzle.
 *
 * @brief Puzzle::getPieces
 * @return the puzzle pieces of this puzzle in the order of creation.
 */
std::vector<PuzzlePiece> Puzzle::getPieces()
{
    return pieces;
}

/**
 * Add a puzzle piece to the puzzle.
 * @brief Puzzle::addPiece
 * @param piece, the puzzle piece to add.
 */
void Puzzle::addPiece(PuzzlePiece piece)
{
    pieces.push_back(piece);
}

TEST_CASE("Puzzle test adding pieces"){
    Puzzle p;
    p.addPiece(PuzzlePiece());

    CHECK(p.getPieces().size() == 1);

    p.addPiece(PuzzlePiece());
    CHECK(p.getPieces().size() == 2);
}
