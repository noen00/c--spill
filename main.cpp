#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "test.h"
#include <atomic>
#include <cstdlib>
#include <fstream>

double x=50.0;
double y=10.0;
int red=0;
int bevegeEx=10;
double bevegeEy=100;
int asd=0;
int score=0;
bool floors=false;
bool enemydo=true;
bool air =true;
bool jump=false;
bool leftMouseButtonPressed= false;
bool start=false;
std::atomic<bool> runing(false);
sf::Text text;
sf::Text hi;
sf::Font font;



void movey(int bevege){


	y=y+bevege;


}
void gravity(){
while(!runing){
if (start){
if (!floors){
	bevegeEy+=0.0000005;
}
if(air){
	y=y+0.0000005;
}
} 
} 
}

void movex(double bevege){
	x=x+bevege;
}

int main()
{ 		
    std::ifstream readFile("example.txt");
    int storedNumber;
    
    if (readFile.is_open()) {
        readFile >> storedNumber;
       std::cout <<" higscore: " <<storedNumber;
        readFile.close();
        }

	std::thread repeat_thread(test);
	repeat_thread.detach();
	std::thread repeat_threa(gravity);
	repeat_threa.detach();
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "SFML works!");
    sf::RectangleShape wall(sf::Vector2f(5000, 50));
    sf::RectangleShape shape(sf::Vector2f(50, 50));
    sf::RectangleShape startb(sf::Vector2f(500, 500));
   	startb.setFillColor(sf::Color::Blue);
    sf::RectangleShape cube(sf::Vector2f(50, 50)); 
    cube.setFillColor(sf::Color::Blue);
    shape.setPosition(x,y);
    shape.setFillColor(sf::Color::Green);
    
	if (!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSansBold.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return 1;
    }
    
    text.setFont(font);
    hi.setFont(font);
    while (window.isOpen()){
    
    	sf::Event event;
    	
    	        while (window.pollEvent(event))
    	        {
    	        
    	         if (event.type == sf::Event::MouseButtonPressed){
    	         
    	            if (event.mouseButton.button == sf::Mouse::Left)
    	            {
    	                leftMouseButtonPressed = true;
    	            }
    	        }
    	        else if (event.type == sf::Event::MouseButtonReleased)
    	        {
    	        
    	            if (event.mouseButton.button == sf::Mouse::Left)
    	            {
    	                leftMouseButtonPressed = false;
    	            }
    	        }
    	            if (event.type == sf::Event::Closed)
    	                window.close();
    	        };
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
        window.close(); 
        }		
		if(start){

		if (red==1){
			cube.setFillColor(sf::Color::Red);
		}
		else{
			cube.setFillColor(sf::Color::Blue);
		}
		
		if (event.type == sf::Event::KeyPressed && event.key.code== sf::Keyboard::Down){
			movey(1);
		}
		
		 if (event.type == sf::Event::KeyPressed && event.key.code== sf::Keyboard::Up && jump){

			int i=0;
			
			movey(-100);
			i+=1;
					
			jump=false;
		}

		 if (event.type == sf::Event::KeyPressed && event.key.code== sf::Keyboard::Right){
			movex(0.1);
		}
		
		 if (event.type == sf::Event::KeyPressed && event.key.code== sf::Keyboard::Left){
			movex(-0.1);	
		};
		 if (event.type == sf::Event::KeyPressed && event.key.code== sf::Keyboard::V){
			bevegeEx+=10;	
		};
		
		 if (shape.getGlobalBounds( ).intersects( wall.getGlobalBounds())) {

		if (y <480){
			y=450;

		}
			air=false;
			jump=true;	
		 }
		 else{
		 	air=true;
		 }

		if(red==0){
		 if (shape.getGlobalBounds( ).intersects( cube.getGlobalBounds()) && leftMouseButtonPressed ) {
		 	score+=1;
		 	floors=false;
			
    		if (score>storedNumber){
    			std::ofstream writeFile("example.txt");
    		    if (writeFile.is_open()) {
		        writeFile << score;
		        std::cout <<" higscore: " <<storedNumber;
		        writeFile.close();
		        }
        		
    		}		 	
    		
			std::cout << " asdsad: ";
			int random = rand() % 801;
			int random2 = rand() % 101;
			bevegeEx=random;
			bevegeEy=random2;
	
		 }
		 }
		 else{

		 	if (shape.getGlobalBounds( ).intersects( cube.getGlobalBounds())){
		 		window.close();
		 	}
		 }
		 		 
		if (y==450){
			jump=true;
		}
		else{
			jump=false;
		}

		text.setString(std::to_string(score)); 
		hi.setString(std::to_string(storedNumber));
		hi.setPosition(100,100);
		cube.setPosition(bevegeEx,bevegeEy);
		shape.setPosition(x,y);
		wall.setPosition(-500,500);
        window.clear();        
        window.draw(wall);
        window.draw(shape);
        window.draw(cube);
        window.draw(text);
        window.draw(hi);
        if (cube.getGlobalBounds( ).intersects( wall.getGlobalBounds())) {
			floors=true;
		}
		
		}
		else{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosFloat(mousePos.x, mousePos.y);
		        if(startb.getGlobalBounds().contains(mousePosFloat)){sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		 			sf::Vector2f mousePosFloat(mousePos.x, mousePos.y);		         
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && leftMouseButtonPressed ){
						leftMouseButtonPressed=false;
						start=true;
						floors=false;
						
			}

		 }
		 
			window.draw(startb);
		}
		
        window.display();
    }
}
