#pragma once

#include<iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include<memory>
//including classes

#include"score.h"
// number of items in menu
#define numberOfMainMenuOptions 4
#define numberOfThemeChangeOptions 3

enum class MainState {
    None,
    Menu,
    Game,
    Exit
};

enum class MenuState {
    Main,
    ScoreBoard,
    ThemeSelection
};

class Menu {
private:
    int mCurrentOption;
    int mThemeCurrentOption;

    sf::Font mFont;

    sf::Text mMainMenuOptions[numberOfMainMenuOptions];
    sf::Text mThemeChangeOptions[numberOfThemeChangeOptions];

    sf::RectangleShape mBackground;
    sf::Texture mTexture;

    MenuState menuState;
    MainState mainState;

public:
    Menu(float resX, float resY);
    void moveUp();
    void moveDown();
    void handleEvent(sf::Event event, MainState& mainState, int& score, std::string& name, bool& theme);
    void update(MainState& mainState, int& score, std::string& name, bool& theme);
    void draw(sf::RenderWindow& window, MainState& mainState, int& score, std::string& name, Highscore& highscore);
    int selectedOption();
};
