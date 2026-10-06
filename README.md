A high-performance computational extension that bridges the gap between **C++** and **Python**. This project demonstrates how to bypass Python performance bottlenecks by offloading heavy data processing logic into native C++ modules using `pybind11`. This project uses a A* pathfinder algorithm as a good example, due to its slowness in python.

---

## Key Features
* **Fast Performance:** Core algorithms written in modern C++ (C++17/20) for optimal memory efficiency and execution speed.
* **Python Integration:** Custom data bindings that expose native C++ classes and functions directly to Python as standard packages.
* **Modern Packaging:** Fully configured with `pyproject.toml` and `setup.py` for effortless local development and editable installs (`pip install -e .`).

---

## Tech Stack
* **Language 1:** Modern C++ (C++17/20)
* **Language 2:** Python >=3.9
* **Build System:** CMake, `pybind11`
* **Testing:** Google Test (C++) / Pytest (Python)

---

## Project Architecture

```text
├── cxx_core/          # Core C++ algorithms, data structures, and logic
├── bindings/          # pybind11 interface definitions exposing C++ to Python
├── setup.py           # For local development
├── test_pathfinder.py # Test run in python
├── requirements.txt   # Requirements
├── pyproject.toml     # Configuration for local development
├── main.cpp           # Test for the A*
├── CMakeLists.txt     # Build system configuration
└── README.md
```
---

## Quick Start

Follow these steps to set up and run the C++ A* pathfinder extension locally.

### 1. Prerequisites
Ensure you have the following installed on your system:
* Python (>=3.9)
* CMake
* A C++ compiler (such as MSVC on Windows, GCC, or Clang)

### 2. Clone the Repository & Set Up Virtual Environment
```powershell
git clone [https://github.com/PetjaLempinen/High-performance-python-extension.git](https://github.com/PetjaLempinen/High-performance-python-extension.git)
cd High-performance-python-extension
```

### Create and activate a virtual environment
```
python -m venv venv
```
### On Windows (PowerShell):
```
.\venv\Scripts\Activate.ps1
```
### On macOS/Linux:
```
source venv/bin/activate
```
### Install build tools and requirements
```
pip install -r requirements.txt
```

### Install the package in editable mode and build the C++ extension locally
```pip install -e .
python setup.py build_ext --inplace
```
#### Don't forget to move or ensure the compiled pathfinder_ext.cp314-win_amd64.pyd file is in your working directory if needed, or handled by your build output

### Run test script
```
python test_pathfinder.py
```