#ifndef Interface_h
#define Interface_h

class Interface {
public:

    float x=0, y=0, width=0, height=0;
  //  bool clicked;

    Interface();
    Interface(float startX, float startY, float buttonWidth ,float buttonHeight)
        : x(startX), y(startY), width(buttonWidth), height(buttonHeight) /*clicked(false) */{}

    bool isMouseOver(float mouseX, float mouseY) {
        return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
    }
    void menu();
    void drawMap();
};




#endif
