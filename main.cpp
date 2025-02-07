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
int aarr[6] = {1,2,3,4,5,6};
int ssize = sizeof(aarr) / sizeof(aarr[0]);
int random3= rand() % 101;
int random4= rand()% 500;
bool sad=false;
int fast=1;
bool floors=false;
bool enemydo=true;
bool air =true;
bool jump=false;
bool leftMouseButtonPressed= false;
bool start=false;
bool dsa=false;
bool ert=true;
int speed=1;
bool ghj=false;
std::atomic<bool> runing(false);
sf::Text text;
sf::Text hi;
sf::Text starts;
sf::Font font;





void movey(int bevege){
	y=y+bevege;

}

void movex(double bevege){

	x=x+bevege*fast;
}




void gravity(){
while(!runing){
if (start){
if (!floors){
	bevegeEy+=0.0000005*speed;
}
if(air){
	y=y+0.0000005;
} } } }

void bonus(){
while(!runing){
	std::this_thread::sleep_for(std::chrono::nanoseconds(5000000000));
	 
	std::shuffle(aarr, aarr + ssize, std::mt19937(std::random_device{}()));
	
}
}
void input(){
	while(!runing){
		

}}
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
	std::thread repeat_thre(bonus);
	repeat_thre.detach();


    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "SFML works!");
    sf::RectangleShape wall(sf::Vector2f(5000, 50));
    sf::RectangleShape stuff(sf::Vector2f(50, 50));
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
    starts.setFont(font);
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
        if (ert){
        	std::thread repeat_thr(input);
        	repeat_thr.detach();
        	ert=false;
        }
        	
            if (event.type == sf::Event::Closed)
        window.close(); 
        }		
		if(start){

	//	input();
	 
        		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			movey(1);
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (jump){
			movey(-100);			
			jump=false;
		}}

		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			movex(0.1);
		}
		
		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			movex(-0.1);	
		};
        
		if (red==1){
			cube.setFillColor(sf::Color::Red);
		}
		else{
			cube.setFillColor(sf::Color::Blue);
		}
		
		
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
		 if (score==10 && !ghj){
		 	speed=speed+1;
		 	ghj=true;
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
			int random = rand() % 501;
			int random2 = rand() % 401;
			bevegeEx=random;
			bevegeEy=random2;
	
		 }
		 }
		 else{

		 	if (shape.getGlobalBounds( ).intersects( cube.getGlobalBounds())){
			int random = rand() % 501;
			int random2 = rand() % 401;
			bevegeEx=random;
			bevegeEy=random2;
		 	score-=1;
		 	floors=false;
		 			
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
        if (aarr[1]==2){
        
        	if (sad==false){
        		 random3= rand() % 601;
        		
				sad=true;
        	}
        	
        	window.draw(stuff);
        	stuff.setPosition(random3,400);
        	dsa=true;
        
        }
        else {
        	dsa=false;
        	sad=false;
        }
        if (shape.getGlobalBounds( ).intersects( stuff.getGlobalBounds()) && dsa) {
        random3= rand() % 601;
        std::shuffle(aarr, aarr + ssize, std::mt19937(std::random_device{}()));
        int aar[6] = {1,2,3,4,5,6};
        int ssiz = sizeof(aar) / sizeof(aar[0]);
        std::shuffle(aar, aar + ssiz, std::mt19937(std::random_device{}()));
        if (aar[1]==1){
			std::cout << " bvc: ";
        	speed+=1;
        } else {
			fast=fast+1;
			std::cout << " cvb: ";	
			}
		
		}
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
		 	starts.setPosition(100,100);
		 	starts.setString("Start");
		 	window.draw(startb);
		 	starts.setCharacterSize(64);
			window.draw(starts);
		}
		
        window.display();
    }
}
