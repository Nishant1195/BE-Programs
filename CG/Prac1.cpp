#include <graphics.h>
#include <conio.h>
#include <cmath>
using namespace std;

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = std::max(abs(dx), abs(dy));  // Determine the number of steps

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);  // Plot the pixel
        x += xIncrement;  // Increment the x coordinate
        y += yIncrement;  // Increment the y coordinate
    }
}

void drawCircle(int xc, int yc, int x, int y){
    putpixel(xc+x, yc+y, 2);
    putpixel(xc-x, yc+y, 2);
    putpixel(xc+x, yc-y, 2);
    putpixel(xc-x, yc-y, 2);
    putpixel(xc+y, yc+x, 2);
    putpixel(xc-y, yc+x, 2);
    putpixel(xc+y, yc-x, 2);
    putpixel(xc-y, yc-x, 2);
}


void draw_circle(int xinc,int yinc,int r){
	int x=0,y=r;
	int d = 3-2*r;
	drawCircle(xinc,yinc,x,y);
	while(x<=y){
		if(d<0){
			d=d+4*x+6;
		}
		else{
			d=d+4*(x-y)+10;
			y--;
		}
		x++;
		        drawCircle(xinc, yinc, x, y);
        delay(50);

	}
	
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Example: Draw a line from (100, 200) to (400, 300)
    drawLineDDA(200, 200, 100, 300);
        drawLineDDA(100, 300, 200, 400);
                drawLineDDA(200, 400, 300, 300);
                        drawLineDDA(300, 300, 200, 200);
draw_circle(200,300,70);



    getch();
    closegraph();
    return 0;
}