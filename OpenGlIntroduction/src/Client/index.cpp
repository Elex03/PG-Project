#include <stdio.h>
#include "Window.h"

int main(int argc, char** argv) {
	GL::Window window("OpenGl", 800, 600);

	while(window.Runner()){
		window.GetEnvents();
	}
	
	return 0;
}