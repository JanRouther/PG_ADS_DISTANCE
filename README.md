# PG_ADS_DISTANCE
It's a project for Algorithms and Data Structures classes made in 2019


Mean distances

Calculate mean distance D between d-dimensional squares in a d-dimensional cube of size lxlxl (up to k sides may be paried with their opposite sides, see examples) for:

(h=0) a king which can move in any direction (horizontal, vertical and diagonal, as in chess);
(h=1) a straightforward halfking which moves only horizontaly and verticaly (like a tower in chess);
(h=2) a diagonal halfking which moves only diagonally (like a bishop in chess).
Examples:
A Rubic's cube is a three-dimensional cube of size 3x3x3 without paried sides (i.e. k=0).
Two-dimesional "cube" of size 20x20 without paried sides (k=0) consists of 20 lines of 20 two-dimensional squares of size 1x1.
Torus is an example of a two-dimensional structure where four walls create two pairs (k=2). In a cylinder there is only one such pair (k=1). The image features a plagiarist pursued by policemen.

You can assume that if d>2 then either no sides are paried, then k=0, or all sides are paried, then k=2.
Also you can asume d=2 for the most of tests.

Input
In the first line: the number of subsequent lines. In the following lines: d, l, k and h separated by spaces.
Output

