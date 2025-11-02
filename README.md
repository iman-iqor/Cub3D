
Cub3D

A 3D maze game inspired by the classic Wolfenstein 3D, built using raycasting techniques. This project demonstrates fundamental computer graphics concepts and game development principles.
📋 Table of Contents

    About
    Features
    Prerequisites
    Installation
    Usage
    Map Configuration
    Controls
    Technical Details
    Acknowledgments

🎮 About

Cub3D is a raycasting engine that renders a 3D perspective inside a maze from a 2D map. The project explores fundamental algorithms in computer graphics, including raycasting, texture mapping, and real-time rendering.
✨ Features

    Raycasting Engine: Real-time 3D rendering using raycasting algorithm
    Texture Mapping: Different textures for walls (North, South, East, West)
    Floor and Ceiling Colors: Customizable RGB colors
    Smooth Movement: WASD movement controls with camera rotation
    Collision Detection: Prevents walking through walls
    Minimap (Bonus): Optional minimap display
    Doors (Bonus): Interactive door system
    Animated Sprites (Bonus): Support for animated elements

🔧 Prerequisites

    Operating System: Linux or macOS but with intel ship not m1 or 2 ....because of openGl(you can search more to understand a frero ;) )
    Compiler: gcc or clang
    Libraries:
        MLX42 or MiniLibX
        Math library (-lm)
        X11 libraries (Linux only)

📦 Installation

**Clone the repository:
git clone https://github.com/yourusername/cub3d.git
cd cub3d

**Compile the project:

1) cd minilibx
2) make
3) cd ..
4) make


🚀 Usage

Run the program with a map file as an argument:
bash

./cub3D maps/map2.cub


🗺️ Map Configuration

Maps use the .cub extension and follow this format:
Map File Structure

NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111

Map Elements

    NO, SO, WE, EA: Texture paths for each wall direction
    F: Floor color (RGB format: R,G,B)
    C: Ceiling color (RGB format: R,G,B)
    1: Wall
    0: Empty space (walkable)
    N, S, E, W: Player starting position and orientation

Map Rules

    Map must be surrounded by walls (1s)
    Only one player start position
    Valid characters: 0, 1, N, S, E, W, and space
    Spaces represent void (not walkable)

🎯 Controls

Key	Action
W	Move forward
S	Move backward
A	Strafe left
D	Strafe right
←	Rotate camera left
→	Rotate camera right
ESC	Exit game

🔬 Technical Details
Raycasting Algorithm

The engine uses Digital Differential Analysis (DDA) algorithm to cast rays from the player's position and calculate wall distances and heights.
Key Components

    Ray Casting: Determines wall intersections for each screen column
    Distance Calculation: Uses perpendicular distance to avoid fisheye effect
    Texture Mapping: Maps wall textures based on hit coordinates
    Rendering: Draws vertical slices with correct heights and textures

Performance

    Target: 60 FPS
    Resolution: Configurable (default: 1920x1080)
    Rendering optimization: Distance-based detail reduction


🛠️ Compilation Flags
makefile

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -lm -lXext -lX11

🐛 Common Issues
MLX Errors

    Ensure MLX library is properly installed
    Check library paths in Makefile

Texture Loading Fails

    Verify texture paths in .cub file
    Ensure textures are in XPM format
    Check file permissions

Segmentation Fault

    Validate map file format
    Check for invalid characters in map
    Ensure map is properly closed by walls

📚 Resources

    Lode's Raycasting Tutorial
    Permadi's Ray-Casting Tutorial
    MiniLibX Documentation

👥 Authors
    Developed by 👩‍💻 Iman Iqor and 👨‍💻 Mohamed Benjbara at [UM6P] [1337/42].
    iqorimane85@gmail.com

📄 License

This project is part of the 42 School curriculum.
🙏 Acknowledgments

    42 School for the project concept
    Wolfenstein 3D for inspiration
    The raycasting community for excellent tutorials

Made with ❤️ at 42 School
