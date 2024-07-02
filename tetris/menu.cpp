// Menu.cpp
#include<iostream>
#include "Menu.h"

Menu::Menu(float resX, float resY) :mCurrentOption(0), mThemeCurrentOption(0), menuState(MenuState::Main) {

    mTexture.loadFromFile("backgrounds/background1.jpg");
    mBackground.setTexture(&mTexture);
    mBackground.setSize(sf::Vector2f(resX, resY));

    if (!mFont.loadFromFile("fonts/norwester.otf"))
        std::cout << "Font not loaded\n";

    mMainMenuOptions[0].setString("New Game");
    mMainMenuOptions[1].setString("Scores");
    mMainMenuOptions[2].setString("Theme Selection");
    mMainMenuOptions[3].setString("Exit");

    for (int i = 0; i < numberOfMainMenuOptions; i++) {
        mMainMenuOptions[i].setFont(mFont);
        mMainMenuOptions[i].setFillColor(sf::Color::White);
        mMainMenuOptions[i].setCharacterSize(50);
        mMainMenuOptions[i].setPosition(resX / 2 - mMainMenuOptions[i].getString().getSize() * 10, resY / 15 + i * resY / 10);
    }

   mThemeChangeOptions[0].setString("Current Theme: Dark");
    mThemeChangeOptions[1].setString("Dark Theme");
    mThemeChangeOptions[2].setString("Light Theme");
    for (int i = 0; i < numberOfThemeChangeOptions; i++) {
        mThemeChangeOptions[i].setFont(mFont);
        mThemeChangeOptions[i].setFillColor(sf::Color::White);
        mThemeChangeOptions[i].setCharacterSize(50);
        mThemeChangeOptions[i].setPosition(resX / 2 - mThemeChangeOptions[i].getString().getSize() * 10, resY / 8 + i * resY / 10);
    } 



}


void Menu::moveUp() {
    if (menuState == MenuState::Main) {
        if (mCurrentOption - 1 >= 0) {
            mMainMenuOptions[mCurrentOption].setFillColor(sf::Color::White);
            mMainMenuOptions[mCurrentOption].setOutlineColor(sf::Color(255, 16, 240));

            mCurrentOption--;
            if (mCurrentOption <= -1)
                mCurrentOption = numberOfMainMenuOptions - 1;
            mMainMenuOptions[mCurrentOption].setFillColor(sf::Color(255, 16, 240));
            mMainMenuOptions[mCurrentOption].setOutlineColor(sf::Color::White);
        }
    }
    else if (menuState == MenuState::ThemeSelection) {
        if (mThemeCurrentOption - 1 >= 0) {
            mThemeChangeOptions[mThemeCurrentOption].setFillColor(sf::Color::White);
            mThemeChangeOptions[mThemeCurrentOption].setOutlineColor(sf::Color(255, 16, 240));

            mThemeCurrentOption--;
            if (mThemeCurrentOption <= 0)
                mThemeCurrentOption = 2;
            mThemeChangeOptions[mThemeCurrentOption].setFillColor(sf::Color(255, 16, 240));
            mThemeChangeOptions[mThemeCurrentOption].setOutlineColor(sf::Color::White);
        }
    }
    

}

void Menu::moveDown() {
    if (menuState == MenuState::Main) {
        if (mCurrentOption + 1 <= numberOfMainMenuOptions) {
            mMainMenuOptions[mCurrentOption].setFillColor(sf::Color::White);
            mMainMenuOptions[mCurrentOption].setOutlineColor(sf::Color(255, 16, 240));

            mCurrentOption++;

            if (mCurrentOption >= numberOfMainMenuOptions)
                mCurrentOption = 0;
            mMainMenuOptions[mCurrentOption].setFillColor(sf::Color(255, 16, 240));
            mMainMenuOptions[mCurrentOption].setOutlineColor(sf::Color::White);
        }
    }
    else if (menuState == MenuState::ThemeSelection) {
        if (mThemeCurrentOption + 1 <= numberOfThemeChangeOptions) {
            mThemeChangeOptions[mThemeCurrentOption].setFillColor(sf::Color::White);
            mThemeChangeOptions[mThemeCurrentOption].setOutlineColor(sf::Color(255, 16, 240));

            mThemeCurrentOption++;
            if (mThemeCurrentOption >= 3)
                mThemeCurrentOption = 1;
            mThemeChangeOptions[mThemeCurrentOption].setFillColor(sf::Color(255, 16, 240));
            mThemeChangeOptions[mThemeCurrentOption].setOutlineColor(sf::Color::White);
        }
    }
   
}

void Menu::handleEvent(sf::Event event, MainState& mainState, int& score, std::string& name, bool& theme) {

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            moveUp();

        }
        if (event.key.code == sf::Keyboard::Down) {
            moveDown();
        }
        if (event.key.code == sf::Keyboard::Escape) {
            if (menuState == MenuState::Main)
                mainState = MainState::Exit;
            else if (menuState == MenuState::ScoreBoard || menuState == MenuState::ThemeSelection)
                menuState = MenuState::Main;
        }
        if (event.key.code == sf::Keyboard::Return) {
            if (menuState == MenuState::Main) {
                int x = selectedOption();
                if (x == 0) {
                    std::cout << "Enter your name: ";
                    std::getline(std::cin, name);
                    mainState = MainState::Game;
                }
                
                else if (x == 1) {
                    menuState = MenuState::ScoreBoard;
                }
                else if (x == 2) {
                    menuState = MenuState::ThemeSelection;
                }
                else if (x == 3) {
                    mainState = MainState::Exit;
                }
            }
            else if (menuState == MenuState::ThemeSelection) {
                int x = mThemeCurrentOption;
                if (x == 1)
                    theme = false;
                else if (x == 2)
                    theme = true;
            }
           

        }
    }
}


void Menu::update(MainState& mainState, int& score, std::string& name, bool& theme) {
    if (menuState == MenuState::Main) {

    }
    
    else if (menuState == MenuState::ScoreBoard) {

    }
    else if (menuState == MenuState::ThemeSelection) {
        std::string temp = "Current Theme: ";
        if (theme)
            temp += "Light";
        else
            temp += "Dark";
        mThemeChangeOptions[0].setString(temp);
    }
}

void Menu::draw(sf::RenderWindow& window, MainState& mainState, int& score, std::string& name, Highscore& highscore) {
    window.draw(mBackground);
    if (menuState == MenuState::Main) {
        for (int i = 0; i < numberOfMainMenuOptions; i++)
            window.draw(this->mMainMenuOptions[i]);
    }
    else if (menuState == MenuState::ScoreBoard) {
        highscore.drawScore(window);
    }
    else if (menuState == MenuState::ThemeSelection) {
        for (int i = 0; i < numberOfThemeChangeOptions; i++)
            window.draw(this->mThemeChangeOptions[i]);
    }
    
}

int Menu::selectedOption() {
    return mCurrentOption;
}
