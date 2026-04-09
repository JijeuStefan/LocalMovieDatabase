# LocalMovieDatabase

## 📋 Description

**Local Movie Database** is a **C++** + **Qt** application for exploring and managing a local movie collection. Users can search, watch, and organize movies, while admins can manage the entire repository with ease. Admins can manage the entire repository by adding, removing, or updating movies. The app combines a clean GUI with practical features like IMDb links, watch lists, and export options.

This application was developed as a learning project to practice the C++ programming language, Object-Oriented Programming (OOP), and the Model-View-Controller (MVC) architecture.

## 🎬 Demo

### 🖥️ User Demo 
![User Demo](./assets/FindRecipe.gif)

### ⚙️ Admin Demo 
![Admin Demo](./assets/IngredientDetection.gif)

## ✨ Features

### User
- **Browse Movies** – View all available movies in the local repository
- **Genre-Based Search** – Filter movies by genre
- **IMDb Integration** – Open IMDb pages for movies directly in the browser
- **Watch List Management** – 
  - Add movies to a personal watch list
  - Remove movies after watching
  - Export watch list in **CSV** or **HTML** formats
- **Like Movies** – Increase a movie’s popularity in the repository

### Admin
- **Repository Management** – View all movies in the repository
- **Add Movies** – Add new movies with details like title, genre, year, likes, and trailer link
- **Remove Movies** – Delete movies from the repository
- **Update Movies** – Edit existing movie details
- **Repository Sync** – Automatically update the movie list for the users when repository changes occur

## 🛠️ Tech Stack

- **Programming Language** – C++  
- **GUI Framework** – Qt  
- **Data Storage** – Local text files (CSV, HTML) for watch lists and movie repository  
- **Object-Oriented Design** – Classes for User, Admin, Movie, Repositories, and GUI components  
- **Build System** – CMake with MinGW (Windows)  
- **Cross-Platform Support** – Windows, Linux, macOS (via Qt)  
  
## 🚀 Quick Start

### Prerequisites

List what needs to be installed beforehand:
- **C++** 17 or higher  
- **Qt** 6.x (with Widgets module)  
- **CMake** 3.16+  
- **A C++ compiler** (e.g., GCC/MinGW on Windows, Clang on Linux, MSVC on Windows) 

### Installation

```bash
# Clone the repository
git clone https://github.com/JijeuStefan/LocalMovieDatabase.git
cd LocalMovieDatabase/Qt_project

# Create a build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build . --config Debug
```

### Usage
```bash
# Run the application
./Qt_project       # Linux/macOS
Qt_project.exe     # Windows

# On startup, select CSV or HTML for your watch list file.
# Switch between User and Admin modes to explore and manage movies.
```

## 📁 Project Structure

```text
LocalMovieDatabase/
├── Qt_project/            # Main C++ Qt project folder
│   ├── main.cpp           # Program entry point
│   ├── StartApp.cpp       # Qt application setup and initial window
│   ├── domain/            # Domain classes (e.g., Movie)
│   ├── Repo/              # Repository classes for storing and managing movies
│   ├── Service/           # Service layer with business logic
│   ├── View/              # GUI classes (AdminGUI, UserGUI, main GUI)
│   ├── Validators/        # User-defined validators for input data
│   ├── exceptions/        # User-defined exceptions
│   ├── all_movies.txt     # Base movie repository data
│   ├── watch_list.csv     # Watch list file in CSV format
│   └── watch_list.html    # Watch list file in HTML format
└── README.md              # This file
```

## 📚 Documentation

### C++ / Core
- [C++ Standard Library (STL)](https://en.cppreference.com/w/cpp) – Vectors, strings, algorithms, and more  
- [OOP in C++](https://www.learncpp.com/) – Classes, inheritance, encapsulation  

### GUI / Frontend
- [Qt Documentation](https://doc.qt.io/) – Layouts, widgets, signals/slots  

### Architecture
- [Model-View-Controller (MVC)](https://en.wikipedia.org/wiki/Model–view–controller) – For separating business logic and GUI  

### File Handling
- [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) – Export and read watch lists  
- [HTML](https://developer.mozilla.org/en-US/docs/Web/HTML) – Export and read watch lists

## 📝 Usage

This project is developed for educational purposes only.

It uses **Qt (Free/Open-Source License)** for the GUI with the Qt libraries under the GPL/LGPL licenses.
## 👤 Author

**JijeuStefan**
- GitHub: [@JijeuStefan](https://github.com/JijeuStefan)
