from collections import defaultdict
from itertools import count

cubes = defaultdict(list)
smallest_cube = 'z'  # A string which is greater than all numeric strings

for i in count():
    cube = i ** 3
    base_permutation = ''.join(sorted(str(cube)))
    cubes[base_permutation].append(cube)

    if len(cubes[base_permutation]) == 5:
        # Track the smallest cube with exactly 5 permuted cubes.
        smallest_cube = min(smallest_cube, base_permutation)
    elif len(cubes[base_permutation]) == 6 and smallest_cube == base_permutation:
        # Clear the smallest cube if its 6th cube was found.
        smallest_cube = 'z'

    # Stop searching if the iterator has more digits than the current smallest cube.
    if smallest_cube.isdigit() and len(smallest_cube[0]) < len(base_permutation):
        print(min(cubes[smallest_cube]))
        break
