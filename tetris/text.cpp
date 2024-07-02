#include "text.h"

CustomText::CustomText(const int rows, const int cols, const int cellSize, const int resX, const int resY) {
	if (!font.loadFromFile("fonts/norwester.otf"))
		std::cout << "Font not loaded\n";

	preview.setFont(font);
	preview.setString("Next Block");
	preview.setPosition((cellSize * cols * 1.3) - resX / 4, cellSize * rows * 0.18);
	hold.setFont(font);
	hold.setString("Hold");
	hold.setPosition((cellSize * cols * 1.3) - resX / 4, cellSize * rows * 0.54);

	playerTitleText.setFont(font);
	playerTitleText.setString("Player: ");
	playerTitleText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.18);
	scoreTitleText.setFont(font);
	scoreTitleText.setString("Score: ");
	scoreTitleText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.36);
	//levelTitleText.setFont(font);
	//levelTitleText.setString("Level: ");
	//levelTitleText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.54);
	lineTitleText.setFont(font);
	lineTitleText.setString("Lines: ");
	lineTitleText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.72);
	escape.setFont(font);
	escape.setString("Esc to Exit");
	escape.setCharacterSize(20);
	escape.setPosition(resX / 3 + cellSize * cols * 1.6, cellSize * rows * 0.93);

}

void CustomText::setText(std::string name, const int score, const int level, const int line, const int rows, const int cols, const int cellSize, const int resX, const int resY, sf::Color color) {
	escape.setFillColor(color);
	preview.setFillColor(color);
	hold.setFillColor(color);

	playerTitleText.setFillColor(color);
	playerNameText.setFillColor(color);
	scoreTitleText.setFillColor(color);
	scoreText.setFillColor(color);
	//levelTitleText.setFillColor(color);
	//levelText.setFillColor(color);
	lineTitleText.setFillColor(color);
	lineText.setFillColor(color);


	playerNameText.setFont(font);
	playerNameText.setString(name);
	playerNameText.setCharacterSize(25);
	playerNameText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.26);

	scoreText.setFont(font);
	scoreText.setString(std::to_string(score));
	scoreText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.42);
	scoreText.setCharacterSize(25);

	//levelText.setFont(font);
	//levelText.setString(std::to_string(level));
	//levelText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.60);
	//levelText.setCharacterSize(25);

	lineText.setFont(font);
	lineText.setString(std::to_string(line));
	lineText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.78);
	lineText.setCharacterSize(25);

}
void CustomText::drawText(sf::RenderWindow& window) {
	window.draw(playerTitleText);
	window.draw(playerNameText);
	window.draw(scoreTitleText);
	window.draw(scoreText);
	//window.draw(levelTitleText);
	//window.draw(levelText);
	window.draw(lineTitleText);
	window.draw(lineText);
	window.draw(escape);
	window.draw(hold);
	window.draw(preview);

}
