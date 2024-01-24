#!/usr/bin/python3
"""Defines an island perimeter measuring function."""


def island_perimeter(grid):
    """Return the perimiter of an island.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for x in range(height):
        for j in range(width):
            if grid[x][j] == 1:
                size += 1
                if (j > 0 and grid[x][j - 1] == 1):
                    edges += 1
                if (x > 0 and grid[x - 1][j] == 1):
                    edges += 1
    return size * 4 - edges * 2
