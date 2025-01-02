#include <graphics.h>
#include <cmath>
using namespace std;

// Encapsulation of drawing methods
class ShapeDrawer {
public:
    // Draw a line using the DDA Algorithm
    void drawLineDDA(int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;

        int steps = max(abs(dx), abs(dy));
        float xIncrement = dx / (float)steps;
        float yIncrement = dy / (float)steps;

        float x = x1, y = y1;
        for (int i = 0; i <= steps; i++) {
            putpixel(round(x), round(y), WHITE);
            x += xIncrement;
            y += yIncrement;
        }
    }

    // Draw a circle using Bresenham's Circle Algorithm
    void drawCircleBresenham(int xc, int yc, int r) {
        int x = 0, y = r;
        int d = 3 - 2 * r;  // Decision variable

        while (x <= y) {
            plotCirclePoints(xc, yc, x, y);
            if (d < 0) {
                d = d + 4 * x + 6;
            } else {
                d = d + 4 * (x - y) + 10;
                y--;
            }
            x++;
        }
    }

    // Draw the entire pattern
    void drawPattern(int xc, int yc, int r, int width, int height) {
        // Draw the rectangle
        drawLineDDA(xc - width / 2, yc - height / 2, xc + width / 2, yc - height / 2);  // Top
        drawLineDDA(xc + width / 2, yc - height / 2, xc + width / 2, yc + height / 2);  // Right
        drawLineDDA(xc + width / 2, yc + height / 2, xc - width / 2, yc + height / 2);  // Bottom
        drawLineDDA(xc - width / 2, yc + height / 2, xc - width / 2, yc - height / 2);  // Left

        // Draw the diamond
        drawLineDDA(xc, yc - r, xc - r, yc);  // Top-left
        drawLineDDA(xc - r, yc, xc, yc + r);  // Bottom-left
        drawLineDDA(xc, yc + r, xc + r, yc);  // Bottom-right
        drawLineDDA(xc + r, yc, xc, yc - r);  // Top-right

        // Draw the circle
        drawCircleBresenham(xc, yc, r);
    }

private:
    // Helper function to plot symmetrical points for the circle
    void plotCirclePoints(int xc, int yc, int x, int y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    ShapeDrawer drawer;

    // Center of the pattern and dimensions
    int xc = 300, yc = 300;  // Center of the pattern
    int radius = 100;        // Radius of the circle
    int rectWidth = 200;     // Width of the rectangle
    int rectHeight = 200;    // Height of the rectangle

    // Draw the pattern
    drawer.drawPattern(xc, yc, radius, rectWidth, rectHeight);

    getch();
    closegraph();
    return 0;
}
