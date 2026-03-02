#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

enum Gamestates {
    MENU,
    PLAYING,
    HIGHSCORES,
    GAMEOVER,
    LEVEL_SELECT
};

enum GameLevel {
    BEGINNER,
    ADVANCED
};

// Window and grid settings
const int CELL_SIZE = 30;  // Increased for better visibility
const int ROW = 10;
const int COLUMN = 20;
const int SIDE_PANEL_WIDTH = 250;  // Increased for better text display

int window_height = COLUMN * CELL_SIZE;
int window_width = ROW * CELL_SIZE + SIDE_PANEL_WIDTH;

int score = 0;
int linescleared = 0;
int level = 1;
GameLevel currentGameLevel = BEGINNER;
bool gameover = false;
int field[COLUMN][ROW] = { 0 };

struct point
{
    int x, y;
} a[4], b[4], shadow[4];

// Beginner shapes (only 4 different blocks)
int beginnerShapes[4][4] = {
    {1,5,9,13}, // I-shape
    {1,4,5,6},  // T-shape  
    {1,5,9,8},  // L-shape
    {1,2,5,6},  // O-shape
};

// All shapes (7 different blocks for advanced level)
int allShapes[7][4] = {
    {1,5,9,13}, // I-shape  
    {0,1,5,6 }, // Z-shape
    {1,2,4,5 }, // S-shape
    {1,4,5,6 }, // T-shape
    {1,5,9,8 }, // L-shape
    {1,5,9,10}, // J-shape
    {1,2,5,6 }, // O-shape
};

// Function declarations
bool check();
bool spawnnewpieces(point a[]);
void clearLines();
void drawScoreAndLevel(RenderWindow& window, Font& font);
void updateshadow();
void drawMenu(RenderWindow& window, Font& font, int selectedItem);
void drawLevelSelect(RenderWindow& window, Font& font, int selectedItem);
void drawHighScores(RenderWindow& window, Font& font);
void saveHighScore();
void loadHighScore();
void resetGame();

// Menu items
const int MENU_ITEMS = 3;
string menuOptions[MENU_ITEMS] = { "START", "HIGH SCORES", "EXIT" };

// Level select items
const int LEVEL_ITEMS = 2;
string levelOptions[LEVEL_ITEMS] = { "BEGINNER", "ADVANCED" };

bool check() {
    for (int i = 0; i < 4; i++)
    {
        if (a[i].x < 0 || a[i].x >= ROW)
            return false;
        if (a[i].y >= COLUMN)
            return false;
        if (a[i].y >= 0 && field[a[i].y][a[i].x])
            return false;
    }
    return true;
}

bool checkshadow(point piece[]) {
    for (int i = 0; i < 4; i++)
    {
        if (piece[i].x < 0 || piece[i].x >= ROW)
            return false;
        if (piece[i].y >= COLUMN)
            return false;
        if (piece[i].y >= 0 && field[piece[i].y][piece[i].x])
            return false;
    }
    return true;
}

int current_color;
int current_shape_type;

bool spawnnewpieces(point a[]) {
    if (currentGameLevel == BEGINNER) {
        // Beginner level: only 4 shapes (0-3)
        current_color = rand() % 4;
        current_shape_type = rand() % 4;

        for (int i = 0; i < 4; i++)
        {
            a[i].x = beginnerShapes[current_shape_type][i] % 4 + ROW / 2 - 2;
            a[i].y = beginnerShapes[current_shape_type][i] / 4 - 2;
        }
    }
    else {
        // Advanced level: all 7 shapes
        current_color = rand() % 7;
        current_shape_type = rand() % 7;

        for (int i = 0; i < 4; i++)
        {
            a[i].x = allShapes[current_shape_type][i] % 4 + ROW / 2 - 2;
            a[i].y = allShapes[current_shape_type][i] / 4 - 2;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (a[i].y >= 0 && field[a[i].y][a[i].x])
            return false;
    }
    return true;
}

void updateshadow() {
    for (int i = 0; i < 4; i++) {
        shadow[i] = a[i];
    }
    while (true) {
        for (int i = 0; i < 4; i++) {
            shadow[i].y += 1;
        }
        if (!checkshadow(shadow)) {
            for (int i = 0; i < 4; ++i) {
                shadow[i].y -= 1;
            }
            break;
        }
    }
}

void clearLines() {
    int linesclearedthisturn = 0;
    for (int i = COLUMN - 1; i >= 0; i--) {
        bool full = true;
        for (int j = 0; j < ROW; j++) {
            if (field[i][j] == 0) {
                full = false;
                break;
            }
        }
        if (full) {
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < ROW; j++) {
                    field[k][j] = field[k - 1][j];
                }
            }
            for (int j = 0; j < ROW; j++) {
                field[0][j] = 0;
            }
            linesclearedthisturn++;
            linescleared++;
            i++;  // Check same row again
        }
    }
    if (linesclearedthisturn > 0) {
        switch (linesclearedthisturn) {
        case 1: score += 100 * level; break;
        case 2: score += 300 * level; break;
        case 3: score += 500 * level; break;
        case 4: score += 800 * level; break;
        }
        level = 1 + (linescleared / 10);
    }
}

// High Score System
struct HighScore {
    string name;
    int score;
    GameLevel level;
};

vector<HighScore> highScores;

void loadHighScore() {
    highScores.clear();
    ifstream file("High_Score.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            int score;
            int levelInt;
            if (ss >> name >> score >> levelInt) {
                highScores.push_back({ name, score, static_cast<GameLevel>(levelInt) });
            }
        }
        file.close();
    }
    sort(highScores.begin(), highScores.end(), [](const HighScore& a, const HighScore& b) {
        return a.score > b.score;
        });
}

void saveHighScore() {
    loadHighScore();

    if (highScores.size() < 10 || score > highScores.back().score) {
        HighScore newScore = { "Player", score, currentGameLevel };
        highScores.push_back(newScore);

        sort(highScores.begin(), highScores.end(), [](const HighScore& a, const HighScore& b) {
            return a.score > b.score;
            });

        if (highScores.size() > 10) {
            highScores.pop_back();
        }

        ofstream file("High_Score.txt");
        for (const auto& hs : highScores) {
            file << hs.name << " " << hs.score << " " << hs.level << endl;
        }
        file.close();
    }
}

void resetGame() {
    gameover = false;
    score = 0;
    linescleared = 0;
    level = 1;
    for (int i = 0; i < COLUMN; i++) {
        for (int j = 0; j < ROW; j++) {
            field[i][j] = 0;
        }
    }
    if (!spawnnewpieces(a)) {
        gameover = true;
    }
    updateshadow();
}

void drawScoreAndLevel(RenderWindow& window, Font& font) {
    // Create background for score panel
    RectangleShape panel(Vector2f(SIDE_PANEL_WIDTH, window_height));
    panel.setFillColor(Color(50, 50, 50));
    panel.setPosition(ROW * CELL_SIZE, 0);
    window.draw(panel);

    // Draw current level info
    Text levelTypeText;
    levelTypeText.setFont(font);
    levelTypeText.setCharacterSize(24);
    levelTypeText.setFillColor(currentGameLevel == ADVANCED ? Color::Yellow : Color::Green);
    levelTypeText.setPosition(ROW * CELL_SIZE + 20, 30);
    levelTypeText.setString("MODE:\n" + string(currentGameLevel == ADVANCED ? "ADVANCED" : "BEGINNER"));
    window.draw(levelTypeText);

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(ROW * CELL_SIZE + 20, 100);
    scoreText.setString("SCORE:\n" + to_string(score));
    window.draw(scoreText);

    Text levelText;
    levelText.setFont(font);
    levelText.setCharacterSize(24);
    levelText.setFillColor(Color::White);
    levelText.setPosition(ROW * CELL_SIZE + 20, 170);
    levelText.setString("LEVEL:\n" + to_string(level));
    window.draw(levelText);

    Text linesText;
    linesText.setFont(font);
    linesText.setCharacterSize(24);
    linesText.setFillColor(Color::White);
    linesText.setPosition(ROW * CELL_SIZE + 20, 240);
    linesText.setString("LINES:\n" + to_string(linescleared));
    window.draw(linesText);

    // Draw level differences
    Text levelInfoText;
    levelInfoText.setFont(font);
    levelInfoText.setCharacterSize(16);
    levelInfoText.setFillColor(Color::Cyan);
    levelInfoText.setPosition(ROW * CELL_SIZE + 20, 320);

    string levelInfo = "BEGINNER:\n";
    levelInfo += "- 4 block types\n";
    levelInfo += "- Slower speed\n\n";
    levelInfo += "ADVANCED:\n";
    levelInfo += "- 7 block types\n";
    levelInfo += "- Faster speed\n";
    levelInfo += "- Speed increases\n";
    levelInfo += "  with level";
    levelInfoText.setString(levelInfo);
    window.draw(levelInfoText);

    // Draw controls info
    Text controlsText;
    controlsText.setFont(font);
    controlsText.setCharacterSize(16);
    controlsText.setFillColor(Color::Green);
    controlsText.setPosition(ROW * CELL_SIZE + 20, window_height - 150);
    controlsText.setString("CONTROLS:\nLeft/Right: Move\nUp: Rotate\nDown: Fast Drop\nR: Restart\nESC: Menu");
    window.draw(controlsText);
}

void drawMenu(RenderWindow& window, Font& font, int selectedItem) {
    window.clear(Color::Black);

    // Draw title
    Text titleText;
    titleText.setFont(font);
    titleText.setCharacterSize(48);
    titleText.setFillColor(Color::Cyan);
    titleText.setString("TETRIS GAME");
    FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setPosition((window_width - titleBounds.width) / 2, 80);
    window.draw(titleText);

    // Draw game level info
    Text infoText;
    infoText.setFont(font);
    infoText.setCharacterSize(24);
    infoText.setFillColor(Color::Yellow);
    infoText.setString("FEATURING 2 DIFFERENT LEVELS!");
    FloatRect infoBounds = infoText.getLocalBounds();
    infoText.setPosition((window_width - infoBounds.width) / 2, 160);
    window.draw(infoText);

    // Draw menu options
    for (int i = 0; i < MENU_ITEMS; i++) {
        Text menuText;
        menuText.setFont(font);
        menuText.setCharacterSize(36);

        if (i == selectedItem) {
            menuText.setFillColor(Color::Yellow);
            menuText.setString("> " + menuOptions[i] + " <");
        }
        else {
            menuText.setFillColor(Color::White);
            menuText.setString(menuOptions[i]);
        }

        FloatRect menuBounds = menuText.getLocalBounds();
        menuText.setPosition((window_width - menuBounds.width) / 2, 240 + i * 70);
        window.draw(menuText);
    }

    // Draw instructions
    Text instructionText;
    instructionText.setFont(font);
    instructionText.setCharacterSize(20);
    instructionText.setFillColor(Color::Green);
    instructionText.setString("Use UP/DOWN arrows to navigate, ENTER to select");
    FloatRect instructionBounds = instructionText.getLocalBounds();
    instructionText.setPosition((window_width - instructionBounds.width) / 2, window_height - 60);
    window.draw(instructionText);
}

void drawLevelSelect(RenderWindow& window, Font& font, int selectedItem) {
    window.clear(Color::Black);

    // Draw title
    Text titleText;
    titleText.setFont(font);
    titleText.setCharacterSize(36);
    titleText.setFillColor(Color::Yellow);
    titleText.setString("SELECT GAME LEVEL");
    FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setPosition((window_width - titleBounds.width) / 2, 60);
    window.draw(titleText);

    // Draw level descriptions
    Text beginnerDesc;
    beginnerDesc.setFont(font);
    beginnerDesc.setCharacterSize(20);
    beginnerDesc.setFillColor(selectedItem == 0 ? Color::Green : Color(150, 150, 150));
    beginnerDesc.setString("BEGINNER LEVEL:\n- 4 different block types\n- Slower falling speed\n- Perfect for learning");
    FloatRect beginnerBounds = beginnerDesc.getLocalBounds();
    beginnerDesc.setPosition((window_width - beginnerBounds.width) / 2, 140);
    window.draw(beginnerDesc);

    Text advancedDesc;
    advancedDesc.setFont(font);
    advancedDesc.setCharacterSize(20);
    advancedDesc.setFillColor(selectedItem == 1 ? Color::Green : Color(150, 150, 150));
    advancedDesc.setString("ADVANCED LEVEL:\n- All 7 block types\n- Faster falling speed\n- Speed increases with level\n- For experienced players");
    FloatRect advancedBounds = advancedDesc.getLocalBounds();
    advancedDesc.setPosition((window_width - advancedBounds.width) / 2, 280);
    window.draw(advancedDesc);

    // Draw level options
    for (int i = 0; i < LEVEL_ITEMS; i++) {
        Text levelText;
        levelText.setFont(font);
        levelText.setCharacterSize(32);

        if (i == selectedItem) {
            levelText.setFillColor(Color::Yellow);
            levelText.setString("> " + levelOptions[i] + " <");
        }
        else {
            levelText.setFillColor(Color::White);
            levelText.setString(levelOptions[i]);
        }

        FloatRect levelBounds = levelText.getLocalBounds();
        levelText.setPosition((window_width - levelBounds.width) / 2, 440 + i * 60);
        window.draw(levelText);
    }

    // Draw instructions
    Text instructionText;
    instructionText.setFont(font);
    instructionText.setCharacterSize(20);
    instructionText.setFillColor(Color::Green);
    instructionText.setString("Use UP/DOWN arrows to navigate, ENTER to select level");
    FloatRect instructionBounds = instructionText.getLocalBounds();
    instructionText.setPosition((window_width - instructionBounds.width) / 2, window_height - 60);
    window.draw(instructionText);
}

void drawHighScores(RenderWindow& window, Font& font) {
    window.clear(Color::Black);

    // Draw title
    Text titleText;
    titleText.setFont(font);
    titleText.setCharacterSize(36);
    titleText.setFillColor(Color::Yellow);
    titleText.setString("HIGH SCORES");
    FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setPosition((window_width - titleBounds.width) / 2, 40);
    window.draw(titleText);

    // Draw column headers
    Text rankHeader;
    rankHeader.setFont(font);
    rankHeader.setCharacterSize(24);
    rankHeader.setFillColor(Color::Cyan);
    rankHeader.setString("RANK");
    rankHeader.setPosition(100, 100);
    window.draw(rankHeader);

    Text nameHeader;
    nameHeader.setFont(font);
    nameHeader.setCharacterSize(24);
    nameHeader.setFillColor(Color::Cyan);
    nameHeader.setString("NAME");
    nameHeader.setPosition(200, 100);
    window.draw(nameHeader);

    Text scoreHeader;
    scoreHeader.setFont(font);
    scoreHeader.setCharacterSize(24);
    scoreHeader.setFillColor(Color::Cyan);
    scoreHeader.setString("SCORE");
    scoreHeader.setPosition(350, 100);
    window.draw(scoreHeader);

    Text levelHeader;
    levelHeader.setFont(font);
    levelHeader.setCharacterSize(24);
    levelHeader.setFillColor(Color::Cyan);
    levelHeader.setString("LEVEL");
    levelHeader.setPosition(500, 100);
    window.draw(levelHeader);

    // Draw scores
    for (size_t i = 0; i < highScores.size() && i < 10; i++) {
        // Rank
        Text rankText;
        rankText.setFont(font);
        rankText.setCharacterSize(22);
        rankText.setFillColor(i < 3 ? Color::Yellow : Color::White);
        rankText.setString(to_string(i + 1) + ".");
        rankText.setPosition(110, 140 + i * 35);
        window.draw(rankText);

        // Name
        Text nameText;
        nameText.setFont(font);
        nameText.setCharacterSize(22);
        nameText.setFillColor(i < 3 ? Color::Yellow : Color::White);
        nameText.setString(highScores[i].name);
        nameText.setPosition(200, 140 + i * 35);
        window.draw(nameText);

        // Score
        Text scoreText;
        scoreText.setFont(font);
        scoreText.setCharacterSize(22);
        scoreText.setFillColor(i < 3 ? Color::Yellow : Color::White);
        scoreText.setString(to_string(highScores[i].score));
        scoreText.setPosition(350, 140 + i * 35);
        window.draw(scoreText);

        // Level
        Text levelText;
        levelText.setFont(font);
        levelText.setCharacterSize(22);
        levelText.setFillColor(i < 3 ? Color::Yellow : Color::White);
        levelText.setString(highScores[i].level == ADVANCED ? "ADVANCED" : "BEGINNER");
        levelText.setPosition(500, 140 + i * 35);
        window.draw(levelText);
    }

    // Draw back instructions
    Text backText;
    backText.setFont(font);
    backText.setCharacterSize(20);
    backText.setFillColor(Color::Green);
    backText.setString("Press ESC to return to menu");
    FloatRect backBounds = backText.getLocalBounds();
    backText.setPosition((window_width - backBounds.width) / 2, window_height - 60);
    window.draw(backText);
}

int main() {
    srand(time(0));
    RenderWindow window(VideoMode(window_width, window_height), "TETRIS GAME - 2 LEVELS!");
    window.setFramerateLimit(60);

    Gamestates currentState = MENU;
    Texture t, gameoverpic;

    // Menu navigation
    int selectedMenuItem = 0;
    int selectedLevelItem = 0;

    // Load textures
    if (!t.loadFromFile("tiles.png")) {
        cout << "Tiles image not found!" << endl;
        return -1;
    }
    t.setSmooth(false);
    Sprite s(t);
    Sprite shadowSprite(t);

    // Movement variables
    int dx = 0;
    bool rotate = false;
    float moveTimer = 0;
    const float moveDelay = 0.1f;  // Delay between moves for smooth movement
    bool keyPressed = false;  // To prevent too fast movement

    // Load font
    Font font;
    if (!font.loadFromFile("ARIAL.TTF")) {
        cout << "Font not found!" << endl;
        if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
            cout << "Could not load any font!" << endl;
            return -1;
        }
    }

    // Load game over texture
    if (!gameoverpic.loadFromFile("gameover.png")) {
        cout << "Game over image not found! Creating text-based game over." << endl;
    }
    Sprite gameoverpicsprite(gameoverpic);

    // Scale game over sprite
    if (gameoverpic.getSize().x > 0) {
        FloatRect gb = gameoverpicsprite.getLocalBounds();
        float scaleX = static_cast<float>(window_width) / gb.width;
        float scaleY = static_cast<float>(window_height) / gb.height;
        float scale = min(scaleX, scaleY);
        gameoverpicsprite.setScale(scale, scale);

        FloatRect finalBounds = gameoverpicsprite.getGlobalBounds();
        gameoverpicsprite.setPosition(
            (window_width - finalBounds.width) / 2,
            (window_height - finalBounds.height) / 2
        );
    }

    // Load high scores at start
    loadHighScore();

    Clock clock;
    float timer = 0;
    float delay = 0.3f;

    while (window.isOpen())
    {
        float time = clock.restart().asSeconds();
        timer += time;
        moveTimer += time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

            if (currentState == MENU) {
                if (e.type == Event::KeyPressed) {
                    if (e.key.code == Keyboard::Up) {
                        selectedMenuItem = (selectedMenuItem - 1 + MENU_ITEMS) % MENU_ITEMS;
                    }
                    else if (e.key.code == Keyboard::Down) {
                        selectedMenuItem = (selectedMenuItem + 1) % MENU_ITEMS;
                    }
                    else if (e.key.code == Keyboard::Enter) {
                        if (selectedMenuItem == 0) { // START
                            currentState = LEVEL_SELECT;
                        }
                        else if (selectedMenuItem == 1) { // HIGH SCORES
                            loadHighScore(); // Reload scores
                            currentState = HIGHSCORES;
                        }
                        else if (selectedMenuItem == 2) { // EXIT
                            window.close();
                        }
                    }
                }
            }
            else if (currentState == LEVEL_SELECT) {
                if (e.type == Event::KeyPressed) {
                    if (e.key.code == Keyboard::Up) {
                        selectedLevelItem = (selectedLevelItem - 1 + LEVEL_ITEMS) % LEVEL_ITEMS;
                    }
                    else if (e.key.code == Keyboard::Down) {
                        selectedLevelItem = (selectedLevelItem + 1) % LEVEL_ITEMS;
                    }
                    else if (e.key.code == Keyboard::Enter) {
                        // Set selected level
                        currentGameLevel = (selectedLevelItem == 0) ? BEGINNER : ADVANCED;
                        resetGame(); // Reset game with selected level
                        currentState = PLAYING;
                    }
                    else if (e.key.code == Keyboard::Escape) {
                        currentState = MENU;
                    }
                }
            }
            else if (currentState == HIGHSCORES) {
                if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape) {
                    currentState = MENU;
                }
            }
            else if (currentState == PLAYING && !gameover) {
                if (e.type == Event::KeyPressed)
                {
                    if (e.key.code == Keyboard::Escape) {
                        currentState = MENU;
                    }
                    else if (e.key.code == Keyboard::Up) {
                        rotate = true;
                    }
                    else if (e.key.code == Keyboard::Left && moveTimer > moveDelay) {
                        dx = -1;
                        moveTimer = 0;
                    }
                    else if (e.key.code == Keyboard::Right && moveTimer > moveDelay) {
                        dx = 1;
                        moveTimer = 0;
                    }
                }
            }
            else if (currentState == PLAYING && gameover) {
                if (e.type == Event::KeyPressed) {
                    if (e.key.code == Keyboard::R) {
                        resetGame();
                    }
                    else if (e.key.code == Keyboard::Escape) {
                        currentState = MENU;
                    }
                }
            }
        }

        // Handle continuous key presses in PLAYING state with delay
        if (currentState == PLAYING && !gameover && moveTimer > moveDelay) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                dx = -1;
                moveTimer = 0;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                dx = 1;
                moveTimer = 0;
            }
        }

        // Calculate current delay based on level and game mode
        float current_delay;
        if (Keyboard::isKeyPressed(Keyboard::Down) && currentState == PLAYING && !gameover) {
            current_delay = 0.05f; // Fast drop
        }
        else if (currentState == PLAYING) {
            if (currentGameLevel == BEGINNER) {
                // Beginner: slower base speed, less speed increase with level
                current_delay = max(0.15f, 0.5f - (level - 1) * 0.03f);
            }
            else {
                // Advanced: faster base speed, more speed increase with level
                current_delay = max(0.08f, 0.4f - (level - 1) * 0.05f);
            }
        }

        // Game logic for PLAYING state
        if (currentState == PLAYING && !gameover) {
            // Movement - only move one cell at a time
            if (dx != 0) {
                for (int i = 0; i < 4; i++)
                    b[i] = a[i];

                for (int i = 0; i < 4; i++)
                    a[i].x += dx;

                if (!check())
                    for (int i = 0; i < 4; i++)
                        a[i] = b[i];

                dx = 0;  // Reset after moving
            }

            // Rotation (no rotation for O-piece in advanced mode)
            if (rotate) {
                bool isRotatable = true;
                if (currentGameLevel == ADVANCED) {
                    // In advanced, O-shape (index 6) is not rotatable
                    isRotatable = (current_shape_type != 6);
                }

                if (isRotatable) {
                    for (int i = 0; i < 4; i++)
                        b[i] = a[i];

                    // Choose pivot point based on shape
                    point p;
                    if (currentGameLevel == BEGINNER) {
                        p = (current_shape_type == 0) ? a[2] : a[1]; // For beginner shapes
                    }
                    else {
                        p = (current_shape_type == 0) ? a[2] : a[1]; // For advanced shapes
                    }

                    for (int i = 0; i < 4; i++) {
                        int x = a[i].y - p.y;
                        int y = a[i].x - p.x;
                        a[i].x = p.x - x;
                        a[i].y = p.y + y;
                    }

                    if (!check())
                        for (int i = 0; i < 4; i++)
                            a[i] = b[i];
                }
                rotate = false;
            }

            // Gravity
            if (timer > current_delay)
            {
                for (int i = 0; i < 4; i++)
                    b[i] = a[i];

                for (int i = 0; i < 4; i++)
                    a[i].y += 1;

                if (!check())
                {
                    for (int i = 0; i < 4; i++)
                        a[i] = b[i];

                    // Place piece in field
                    for (int i = 0; i < 4; i++)
                        if (a[i].y >= 0)
                            field[a[i].y][a[i].x] = current_color + 1;

                    // Clear completed lines
                    clearLines();

                    // Spawn new piece
                    if (!spawnnewpieces(a)) {
                        gameover = true;
                        saveHighScore();  // Save score when game ends
                    }
                    updateshadow();
                }
                else
                {
                    updateshadow();
                }
                timer = 0;
            }
        }

        // DRAWING SECTION
        window.clear(Color::Black);

        if (currentState == MENU) {
            drawMenu(window, font, selectedMenuItem);
        }
        else if (currentState == LEVEL_SELECT) {
            drawLevelSelect(window, font, selectedLevelItem);
        }
        else if (currentState == HIGHSCORES) {
            drawHighScores(window, font);
        }
        else if (currentState == PLAYING) {
            // Draw game board background
            RectangleShape boardBackground(Vector2f(ROW * CELL_SIZE, COLUMN * CELL_SIZE));
            boardBackground.setFillColor(Color(30, 30, 30));
            boardBackground.setPosition(0, 0);
            window.draw(boardBackground);

            // Draw grid lines
            for (int i = 0; i <= ROW; i++) {
                RectangleShape line(Vector2f(1, COLUMN * CELL_SIZE));
                line.setFillColor(Color(60, 60, 60));
                line.setPosition(i * CELL_SIZE, 0);
                window.draw(line);
            }
            for (int i = 0; i <= COLUMN; i++) {
                RectangleShape line(Vector2f(ROW * CELL_SIZE, 1));
                line.setFillColor(Color(60, 60, 60));
                line.setPosition(0, i * CELL_SIZE);
                window.draw(line);
            }

            // Draw placed pieces
            for (int i = 0; i < COLUMN; i++) {
                for (int j = 0; j < ROW; j++) {
                    if (field[i][j]) {
                        s.setTextureRect(IntRect((field[i][j] - 1) * 18, 0, 18, 18));
                        s.setScale(CELL_SIZE / 18.0f, CELL_SIZE / 18.0f);  // Scale to fit new cell size
                        s.setPosition(j * CELL_SIZE, i * CELL_SIZE);
                        window.draw(s);
                        s.setScale(1.0f, 1.0f);  // Reset scale
                    }
                }
            }

            if (!gameover) {
                shadowSprite.setTextureRect(IntRect(current_color * 18, 0, 18, 18));
                shadowSprite.setColor(Color(255, 255, 255, 128));
                shadowSprite.setScale(CELL_SIZE / 18.0f, CELL_SIZE / 18.0f);
                for (int i = 0; i < 4; i++) {
                    if (shadow[i].y >= 0) {
                        shadowSprite.setPosition(shadow[i].x * CELL_SIZE, shadow[i].y * CELL_SIZE);
                        window.draw(shadowSprite);
                    }
                }
                shadowSprite.setColor(Color::White);
                shadowSprite.setScale(1.0f, 1.0f);
            }

            // Draw falling piece (if game not over)
            if (!gameover) {
                s.setTextureRect(IntRect(current_color * 18, 0, 18, 18));
                s.setScale(CELL_SIZE / 18.0f, CELL_SIZE / 18.0f);
                for (int i = 0; i < 4; i++) {
                    if (a[i].y >= 0) {
                        s.setPosition(a[i].x * CELL_SIZE, a[i].y * CELL_SIZE);
                        window.draw(s);
                    }
                }
                s.setScale(1.0f, 1.0f);
            }

            // Draw score and level panel
            drawScoreAndLevel(window, font);

            // Draw game over screen
            if (gameover) {
                // Dark overlay
                RectangleShape overlay(Vector2f(window_width, window_height));
                overlay.setFillColor(Color(0, 0, 0, 180));
                window.draw(overlay);

                if (gameoverpic.getSize().x > 0) {
                    window.draw(gameoverpicsprite);
                }
                else {
                    // Draw text-based game over
                    Text gameOverText;
                    gameOverText.setFont(font);
                    gameOverText.setCharacterSize(48);
                    gameOverText.setFillColor(Color::Red);
                    gameOverText.setString("GAME OVER");
                    FloatRect gameOverBounds = gameOverText.getLocalBounds();
                    gameOverText.setPosition((window_width - gameOverBounds.width) / 2, window_height / 2 - 50);
                    window.draw(gameOverText);
                }

                // Draw game mode info
                Text modeText;
                modeText.setFont(font);
                modeText.setCharacterSize(24);
                modeText.setFillColor(currentGameLevel == ADVANCED ? Color::Yellow : Color::Green);
                modeText.setString("Mode: " + string(currentGameLevel == ADVANCED ? "ADVANCED" : "BEGINNER"));
                modeText.setPosition(
                    (window_width - modeText.getLocalBounds().width) / 2,
                    window_height - 180
                );
                window.draw(modeText);

                // Draw restart instructions
                Text restartText;
                restartText.setFont(font);
                restartText.setCharacterSize(24);
                restartText.setFillColor(Color::Yellow);
                restartText.setString("Press R to Restart");
                restartText.setPosition(
                    (window_width - restartText.getLocalBounds().width) / 2,
                    window_height - 50
                );
                window.draw(restartText);

                // Draw menu return instruction
                Text menuText;
                menuText.setFont(font);
                menuText.setCharacterSize(20);
                menuText.setFillColor(Color::Cyan);
                menuText.setString("Press ESC to return to Menu");
                menuText.setPosition(
                    (window_width - menuText.getLocalBounds().width) / 2,
                    window_height - 90
                );
                window.draw(menuText);

                // Draw final score
                Text finalScoreText;
                finalScoreText.setFont(font);
                finalScoreText.setCharacterSize(28);
                finalScoreText.setFillColor(Color::Green);
                finalScoreText.setString("Final Score: " + to_string(score));
                finalScoreText.setPosition(
                    (window_width - finalScoreText.getLocalBounds().width) / 2,
                    window_height - 130
                );
                window.draw(finalScoreText);
            }
        }

        window.display();
    }

    return 0;
}