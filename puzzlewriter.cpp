#include "doctest.h"
#include <io.h>
#include "puzzlewriter.h"
#include "svg.hpp"

PuzzleWriter::PuzzleWriter()
{

}

PuzzleWriter::PuzzleWriter(std::string filepath,  std::vector<PuzzlePiece> pieces)
{
    this->filepath = filepath;
    this->pieces = pieces;
}

/*
 * Save the puzzle to the filepath of the writer.
 * */
int PuzzleWriter::savePuzzle()
{
    SVG::SVG root;

    root.style("polygon").set_attr("fill", "red");
    auto shapes = root.add_child<SVG::Group>();

    for(PuzzlePiece p : pieces){
        std::vector<SVG::Point> points;
        for(Vertex v : p.getVertecies()){
            points.push_back(SVG::Point(v.getX(), v.getY()));
        }
        *shapes << SVG::Polygon(points);
    }

    root.autoscale();

    std::ofstream outfile(filepath);
    outfile << std::string(root);
}

TEST_CASE("Save to the puzzle"){
    PuzzlePiece p;
    p.addVertex(0,0);
    p.addVertex(100,0);
    p.addVertex(100,100);

    PuzzleWriter w = PuzzleWriter("./test.svg", {p});
    w.savePuzzle();

    CHECK(access("./test.svg", F_OK) != -1);
    std::remove("./test.svg");
}
