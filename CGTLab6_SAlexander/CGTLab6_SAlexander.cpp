// Sophia Alexander
//CGT 215 Lab 6
//09/29/2026

#include <iostream>
//includes the SFML Graphics library that prof Kesselman made. Allows use of several keywords
#include <SFML/Graphics.hpp>

//allows us to use the standard and sf namespaces. sf is reliant on sfml
using namespace sf;
using namespace std;


int main() {

	//these two lines set the background and foreground using the background and foreground keywords from sfml
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";

	//this block sets the background texture. If the file doesnt load it tells us that with the cout
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	//this block does the same as the last one but with the foreground
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	//This block initializes the backgroundImage then sets it equal to the texture
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();

	//this block does the same as the last one but with the foreground
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();

	//this sets the variable sz (presumed to mean size) to the size of the background image
	Vector2u sz = backgroundImage.getSize();

	//these nested loops will run the code for each individual pixel in the background image
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {

			// You can access the current pixel at x,y like so: Color example = foregroundImage.getPixel(x, y);
			// Color objects store the individual channel values like example.r example.g and example.b
		}
	}


	// By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}

/*  Troubleshooting Notes:
* 
* the first run after writing all the comments resulted in a failure to load error for file
* 
* */


