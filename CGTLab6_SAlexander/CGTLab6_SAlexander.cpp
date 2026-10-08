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

	//this block sets the background image. If the file doesnt load it tells us that with the cout
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

	//This block initializes the backgroundImage then sets it equal to the already established image
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();

	//this block does the same as the last one but with the foreground
	Image foregroundImage;
	//fills the image with the data from the texture we established earlier
	foregroundImage = foregroundTex.copyToImage();

	//this sets the variable sz (presumed to mean size) to the size of the background image
	Vector2u sz = backgroundImage.getSize();

	// Assume that the top left corner of the foreground is green screen.
	Color greenScreen = foregroundImage.getPixel(0, 0);

	//these nested loops will run the code for each individual pixel in the background image
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {

			// You can get the color of the current pixel at x,y like so: 
				Color Current = foregroundImage.getPixel(x, y);
			// Color objects store the individual channel values like example.r example.g and example.b

			//this block should take any pixel that is green screen and erase it
			if (Current == greenScreen) {
				
				foregroundImage.setPixel(x, y);
				backgroundImage.getPixel(x, y);

			}

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
* the first run after writing all the comments resulted in a failure to load error for 
* file images1/backgrounds/winter.png. I think this may be resolved by putting all of the
* images in a folder called images1. Lets try that.
* 
* That did fix the issue. Now we get Yoda with a green background.I tried taking the example code
* inside the nested loops "Color example = foregroundImage.getPixel(x, y);" and uncommenting it.
* This did not change the output.
* 
* What I need to do now is figure out the color of the greenscreen pixels and tell the nested loops
* to delete the pixel if it's that color. I swear I've done this lab before at some point- its uncanny.
* 
* Next, I looked through the first image processing lecture on brightspace to try and figure out next
* steps. I established a line that identifies the pixel color for green screen and made an if loop inside
* the nested if loop so that as it runs through each pixel, it checks if it is green screen. Now I just
* need to figure out how to make it delete it once it has identified it.
* 
* */


