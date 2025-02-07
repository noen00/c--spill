#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "test.h"
#include <atomic>
extern int bevegeEx;
extern int bevegeEy;
extern int speed;

int arr[6] = {1,2,3,4,5,6};
int size = sizeof(arr) / sizeof(arr[0]);
std::atomic<bool> running(false);
extern int red;
void test(){
while(!running){
        std::shuffle(arr, arr + size, std::mt19937(std::random_device{}()));
        
		if (arr[1]==1){
			red=0;	
		}
		else if (arr[2]==1){
			red=0;	
		}
		else if (arr[3]==1){
			red=0;	
		}
		else if (arr[4]==1){
			red=0;	
		}
		else if (arr[5]==1){
			//bevegeEx+=1;
			red=1;	
		}
		else {
			red=1;	
		};

        std::this_thread::sleep_for(std::chrono::nanoseconds(200000000 / speed));
}
}
