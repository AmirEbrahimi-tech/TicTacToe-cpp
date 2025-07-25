#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "grid.hpp"

int main () {
    // First test

    // Grid test;
    // test.input();
    // test.input();
    // test.input();

    // test.display();

    // Second test

    // Grid test1 = testGridWinningRow();
    // Grid test2 = testGridWinningColumn();
    // Grid test3 = testGridWinningDiagonal();
    // Grid test4 = testGrid();
    // Grid test5 = testGrid();
    // Grid test6 = testGrid();
    // Grid test7 = testGrid();
    // Grid test8 = testGrid();

    // test1.display();
    // test2.display();
    // test3.display();
    // test4.display();
    // test5.display();
    // test6.display();
    // test7.display();
    // test8.display();
    // if (test1.gameFinished()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test2.gameFinished()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test3.gameFinished()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test4.gameFinished()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test5.gameFinished()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test6.gameFinished()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test7.gameFinished()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test8.gameFinished()) cout << "yay" << endl;
    // else cout << "nay" << endl;

    // Third test

    // Grid test;
    // test.display();
    // test.getStatus();
    // int i = 0;
    // do {
    //     if (i % 2 == 0) test.setOneRandomPiece(Type::O);
    //     else test.setOneRandomPiece(Type::X);
    //     test.display();
    //     test.getStatus();
    //     i++;
    //     test.setAllPieces();
    // } while (!test.gameFinished());
    // cout << "took " << i << " rounds" << endl;
    // cout << "DONE!" << endl;

    // Fourth test

    // Grid test;
    // test.display();
    // // test.getStatus();
    // int i = 0;
    // do {
    //     if (i % 2 == 0) test.input(Type::O);
    //     else test.input(Type::X);
    //     test.setAllPieces();
    //     test.display();
    //     // test.getStatus();
    //     i++;
    // } while (!test.gameFinished());
    // cout << "took " << i << " rounds" << endl;
    // cout << "DONE!" << endl;

    // Fifth test

    Grid test;
    int turn = distribTurn();
    test.display();
    // test.getStatus();
    int counter = 0;
    Type winner;
    do {
        if (turn % 2 == 0) test.input(Type::O, turn);
        else test.input(Type::X, turn);
        test.setAllPieces();
        test.display();
        // test.getStatus();
        turn++;
        counter++;
    } while (!test.gameFinished(winner));
    cout << "took " << counter << " rounds" << endl;
    winAnounce(winner);
    return 0;
}



// int main() {

//     // // Create the main window
//     // sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

//     // // Load a sprite to display
//     // sf::Texture texture;
//     // if (!texture.loadFromFile("cb.bmp"))
//     //     return EXIT_FAILURE;
//     // sf::Sprite sprite(texture);

// 	// // Start the game loop
//     // while (app.isOpen())
//     // {
//     //     // Process events
//     //     sf::Event event;
//     //     while (app.pollEvent(event))
//     //     {
//     //         // Close window : exit
//     //         if (event.type == sf::Event::Closed)
//     //             app.close();
//     //     }

//     //     // Clear screen
//     //     app.clear();

//     //     // Draw the sprite
//     //     app.draw(sprite);

//     //     // Update the window
//     //     app.display();
//     // }

//     return 0;
// }