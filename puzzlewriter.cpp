#include "doctest.h"
#include <io.h>
#include "puzzlewriter.h"
#include "svg.hpp"

PuzzleWriter::PuzzleWriter()
{

}

PuzzleWriter::PuzzleWriter(std::string filepath)
{
    this->filepath = filepath;
}

/*
 * Save the puzzle to the filepath of the writer.
 * */
int PuzzleWriter::savePuzzle(std::vector<PuzzlePiece> pieces)
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
    PuzzleWriter w = PuzzleWriter("./test.svg");
    PuzzlePiece p;
    p.addVertex(0,0);
    p.addVertex(100,0);
    p.addVertex(100,100);

    w.savePuzzle({p});

    CHECK(access("./test.svg", F_OK) != -1);
    std::remove("./test.svg");
}
