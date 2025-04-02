So Long

📝 Project Description

So Long is a small 2D game built using the minilibX graphics library. The goal of the game is to navigate a character through a maze, collect all the collectibles, and reach the exit while avoiding enemies (if implemented). This project is part of the 42 curriculum and is designed to introduce students to basic graphics programming and event handling.

🎮 Features

Player movement using keyboard inputs.

Map rendering from a .ber file.

Collectible items that must be gathered before exiting.

Basic enemy mechanics (optional).

Real-time rendering using minilibX.

Simple win/lose conditions.

🛠 Installation & Compilation

Prerequisites

A Unix-based operating system (Linux or macOS).

minilibX installed on your system.

Make and a C compiler (gcc recommended).

Steps

# Clone this repository
git clone https://github.com/yourusername/so_long.git
cd so_long

# Compile the project
make

# Run the game with a valid map
./so_long maps/example.ber

🎮 How to Play

Move the character using WASD or Arrow Keys.

Collect all items on the map.

Reach the exit to complete the level.

Avoid enemies (if applicable)!

Close the game using ESC or the window close button.

🗺 Map Format

The game reads map files with the .ber extension. The map should follow these rules:

Walls (1) must surround the entire map.

Free space is represented by 0.

The player’s starting position is P.

Collectibles are represented by C.

The exit is marked as E.

Optional enemies may be represented by X.

Example:

111111
1P0C01
100001
1C0E01
111111

🖼 Screenshots

(Add screenshots or GIFs of your game here)

🤝 Contributing

Contributions are welcome! Feel free to submit issues or pull requests.
