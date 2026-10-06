import sys
import os

# Point to your build/Release folder where the .pyd lives
build_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "build", "Release"))
sys.path.insert(0, build_path)

import pathfinder_ext

def main():
    print("Successfully imported pathfinder_ext!")
    
    # Test Point class
    start = pathfinder_ext.Point(0, 0)
    goal = pathfinder_ext.Point(4, 4)
    
    print(f"Start: {start}")
    print(f"Goal: {goal}")
    
    # Define a simple grid (e.g., 0 for walkable, 1 for obstacles)
    # Adjust this depending on how your C++ findPath signature expects the grid!
    grid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 1, 0],
        [1, 1, 0, 0, 0],
        [0, 0, 0, 1, 0]
    ]
    
    try:
        # Call your C++ find_path function
        path = pathfinder_ext.find_path(grid, start, goal)
        print(f"Path found successfully! Result: {path}")
    except Exception as e:
        print(f"Note on function signature: {e}")
        print("Tip: Check your C++ findPath argument types to match this call if needed.")

if __name__ == "__main__":
    main()