# <span style="color: #4A90E2;">Cub3D README</span>

## <span style="color: #eeeeee;">Table of Contents</span>
1. [map.cub](#map.cub)
2. [Player Orientation and Movement](#player-orientation-and-movement)
    - [Player Orientation](#player-orientation)
    - [Player Movement](...)
## <span style="color: #4A90E2;"> Map.cub</span>
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

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
```

## <span style="color: #4A90E2;">Player Orientation and Movement</span>

### <span style="color: #ffffff;">Player Orientation</span>
The player's orientation refers to the direction they are facing in the game world. The orientation is defined by an angle:

- **North (0° or 360°)**: The player is looking straight up on the map.
    - **Vector**: (x: 0, y: -1)
- **East (90°)**: The player is looking directly to the right.
    - **Vector**: (x: 1, y: 0)
- **South (180°)**: The player is looking straight down on the map.
    - **Vector**: (x: 0, y: 1)
- **West (270°)**: The player is looking directly to the left.
    - **Vector**: (x: -1, y: 0)

## **Note:**
 - The vector for North is (x: 0, y: -1) because when moving North, the player's </br>
  y-coordinate should decrease.</br> This means that to move upwards on the map (towards the North), </br>we need to decrement the y-position, hence y = -1.

```c
    typedef struct s_player
    {
        int   x; ## postion of the letter in map 
        int   y;
        float posx; ## position of the player in map
        float posy;
        float directionx; 
        float directiony;
    } t_player;
    typedef struct s_data
    {
        t_player player;
    } t_data;
```
```c
  // The player has the letter 'N' in the map, indicating they are looking North
  
  player.x = 4; 
  player.y = 12;
  player.posx = player.x + 0.5f; // to put player the center of the square
  player.posy = player.y + 0.5f;
  player.directionx = 0;
  player.directiony = -1;
```
- now we define directions and pos of the player and letter in the map

### <span style="color: #ffffff;">Rotation of the player</span>

#### We Need angle of rotation
```c
  #define ROTATION_SPEED 0.01f # we just take this value (randomly)
```

#### Formula of find new direction
```
  x' = x * cos(O) - y * sin(O)
  y' = y * cos(O) + x * sin(O)
```
### Implement
```c
  float olddirectionx = player.directionx;
  float olddirectiony = player.directiony;
  
  player.directionx = olddirectionx * cos(ROTATION_SPEED) - olddirectiony * sin(ROTATION_SPEED);
  player.directionY = olddirectiony * cos(ROTATION_SPEED) + olddirectionx * sin(ROTATION_SPEED);
```

## Note:
#### To make the code cleaner, we can introduce a flag that represents whether the rotation is to the left or to the right.

### Example Implementation:

```c
    // Check the flag to determine the direction of camera rotation
    if (flag == CAMERA_LEFT)
        camera_left_right(cub, (float)FAIL);  // Rotate the camera to the left
    if (flag == CAMERA_RIGHT)
        camera_left_right(cub, (float)RIGHT); // Rotate the camera to the right
```
### Example with values

```c
  ## turn left so flag = -1
    float olddirectionx = 0;
    float olddirectiony = -1;

    player.directionx = 0 * cos(ROTATION_SPEED * flag) - -1 * sin(ROTATION_SPEED * flag);// 0.00999983333 
    player.directionY = -1 * cos(ROTATION_SPEED * flag) + 0 * sin(ROTATION_SPEED * flag);// -0.99995000041
```
### <span style="color: #ffffff;">Player Movement</span>

#### We Need Speed of movements

```c
  #define MOVE_SPEED 0.05f # we just take this value (randomly)
```
```c
 pos + dir - plane <-----------> pos + dir + plane 
                     \   |   /              
                      \  |  /               
                       \ | / <-- pos + dir
                        \|/
                        pos
```

#### we define FOV of the player
```c
  # let say we Need FOV 66 deg
  # we need to vector of left(pos + dir - plane) and for right(pos + dir + plane)

  we know:
        tan(O) = sin / cos
        FOV = 66 so half equale 33
                
       1 - Half of Fov:
            half_FOV = 33
                    
       2 - degree to radian:
            radian = half_FOV * 3.14 / 180 => 0.5759586532
       
       3 - Find Perpendicular Vector:
            we have dir(0, -1) so (-dirY, dirx) => (1, 0)
       4 - Normalize Perpendicular Vector:
            length = (sqrt((1 ^ 2) + (0 ^ 2))) // 1
                    
            norm_planX = 1 / length // 1
            norm_planY = 0 / length // 0
            
           planex = norm_planx * tan(radian); // 0.6494075933
           planey = norm_plany * tan(radian); // 0

       so: pos(0, 0), dir(0, -1), plane(0, 0.65);
```

#### Check if new position have a wall or anything else, but with collision

#####  => Forward: 

```c
  ## for collision we need to see if square is valid for x and y individual

    int ele = map[player.posy + player.planex * distance][player.posx];
    
    # check for y

    posy -= planex * move_speed;

    # check for x
    
    ele = map[posy][posx - planey * distance]
    
    posx += planey * move_speed
```

### Example:

```c
    # lets say:
        player(7.915279 , 11.347449);
        plane(0.281595, 0.596912);
        distance: -0.22f
        move_speed:0.05f
        map[11][8] == wall
        
        so:

        ele = map[11.347449 + (0.281595 * -0.22)][7.945125]
        ele = map[11.2854981][7.945125] = map[11][7]
        posy -= (0.281595*-0.05)
        posy = 11.333369
        for: x
        ele = map[11.333369 ][7.945125 - (0.596912 * 0.22)]
        ele = map[11.333369][8.07644564] = map[11][8]
        posx = 7.915279 # because next postion have a wall
        
```# current
# current
