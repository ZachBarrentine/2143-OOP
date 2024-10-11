## P02B - Class Design
### Zach Barrentine
### Description:

A text file is given that holds the four major classes: Dice, Player, Game, and KnuckleBones. In each class are the Data, Actions, and
Relationships that are held.

### Instructions:

- The text file provides pseudo code.
- Inheritance and composition are specified when used.

## Outline:

**Dice Class**: 
- **Data**:
  - `sides`
  - `current_value`
 
- **Actions**:
  - `roll()`
  - `get_value()`
- **Relationships**:
  - Dice will be used by the Player to roll during the game.


**Player Class**:
- **Data**:
  - `first name` +
  - `last name` +
  - `score`
  - `dice_set`: Array of Dice objects
  - `player_stats`+
  - `level` +
  - `userid` +
  - `score` +
  - `streak` +
  - `messaging` +
  
- **Actions**:
  - `roll_dice()`: Roll the dice for the player.
  - `get_score()`: Retrieve the current score.
  - `update_score(points)`: Update the player’s score after each roll.

- **Relationships**:
  - A Player **HAS-A** Dice (composition).
  - A Player **IS-A** participant in the game.

**Game Class**:
- **Data**:
  - `players`
  - `rules`
  - `current_round`
  - `teams` +
  - `team stats` +
- **Actions**:
  - `start_game()`
  - `end_game()`
  - `get_winner()` +
- **Relationships**:
  - The Game class handles the players and their actions.

**Knucklebones Class**:
- **Data**:
  - `board`
  - `knucklebones_specific_rules`
  - `leaderboard` +
  - `coins` +
  - `high score` +
- **Actions**:
  - `start_round()`
  - `end_round()`
  - `calculate_winner()`
- **Relationships**:
  - The Knucklebones class inherits from Game, as Knucklebones **is a** game with specific rules and conditions.

