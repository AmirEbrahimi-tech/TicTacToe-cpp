

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
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "grille.hpp"


int main () {
    // first test

    // Grille test;
    // test.input();
    // test.input();
    // test.input();

    // test.affichage();

    // second test

    // Grille test1 = testGrilleGagnantLigne();
    // Grille test2 = testGrilleGagnantColonne();
    // Grille test3 = testGrilleGagnantDiagonale();
    // Grille test4 = testGrille();
    // Grille test5 = testGrille();
    // Grille test6 = testGrille();
    // Grille test7 = testGrille();
    // Grille test8 = testGrille();

    // test1.affichage();
    // test2.affichage();
    // test3.affichage();
    // test4.affichage();
    // test5.affichage();
    // test6.affichage();
    // test7.affichage();
    // test8.affichage();
    // if (test1.partieFinie()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test2.partieFinie()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test3.partieFinie()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test4.partieFinie()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test5.partieFinie()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test6.partieFinie()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test7.partieFinie()) cout << "yay" << endl;
    // else cout << "nay" << endl;
    // if (test8.partieFinie()) cout << "yay" << endl;
    // else cout << "nay" << endl;

    // third test

    // Grille test;
    // test.affichage();
    // test.getStatus();
    // int i = 0;
    // do {
    //     if (i % 2 == 0) test.setOneRandomPiece(Type::O);
    //     else test.setOneRandomPiece(Type::X);
    //     test.affichage();
    //     test.getStatus();
    //     i++;
    //     test.setAllPieces ();
    // } while (!test.partieFinie());
    // cout << "took " << i << " rounds" << endl;
    // cout << "DONE!" << endl;

    // fourth test

    Grille test;
    test.affichage();
    test.getStatus();
    int i = 0;
    do {
        if (i % 2 == 0) test.setOneRandomPiece(Type::O);
        else test.setOneRandomPiece(Type::X);
        test.setAllPieces ();
        test.affichage();
        test.getStatus();
        i++;
    } while (!test.partieFinie());
    cout << "took " << i << " rounds" << endl;
    cout << "DONE!" << endl;
    

    return 0;
}
