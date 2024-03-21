# CHECKERS

For the correct operation of the program it is necessary:

--> Windows: unpack the SFML-2.5.1 library

--> MacOS: download the SFML library using the command:
"brew install sfml"

---

### Scope of responsibility:

- See more: [Documentation](doc/Documentation.pdf) (only in Polish)


<table border="1">
  <thead>
    <tr>
      <th>Name</th>
      <th>Contributions (Activities)</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Przemysław Janiszewski</td>
      <td>
        <ul>
          <li>Game engine (gameplay according to game rules)</li>
          <li>PvP mode</li>
          <li>PvE mode</li>
          <li>Textures: pawns, board, advertisements, implementation</li>
          <li>Timer</li>
          <li>Chat</li>
          <li>Move marking - highlighting</li>
          <li>Advantage indicator</li>
          <li>Side gameplay loop</li>
          <li>Game window handling</li>
          <li>Time-limited game</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>Julia Kluk</td>
      <td>
        <ul>
          <li>Main menu, options menu, attribute change, user account management, player ranking</li>
          <li>Login</li>
          <li>Registration of new users, program window handling, loop handling (main and side menus)</li>
          <li>Menu textures (main and side menus)</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>Jakub Kleszcz</td>
      <td>
        <ul>
          <li>Top 5 users ranking</li>
          <li>Registration of new players</li>
          <li>User login to the system</li>
          <li>Player data modification</li>
        </ul>
      </td>
    </tr>
  </tbody>
</table>

---

![Simple Checkers](doc/checkers.gif)

---

## CHECKERS RULES - BASED ON GERMAN STYLE

### GENERAL :
> first player to move: player with lighter pieces

> board size: 8x8

> piece reaching the end of the board becomes a queen

> winner: player who eliminates all of the opponent's pieces or puts the opponent in a position where they have no legal moves

> time limit: player who exceeds their time limit loses

> draw: 15 moves without a capture by either player

---

### MOVEMENT RULES:
> players can only move on dark squares

> pieces can only move forward one square (exception: captures)

> queens can move any number of squares diagonally, forward or backward (unless blocked by other pieces)

---

### CAPTURES:
> captures are mandatory

> captures by queens take priority

> if multiple captures have the same priority, player can choose which to make

> pieces can only capture forward, if the square beyond the opponent's piece is empty (the piece lands on that square after the capture). it can then make another capture if possible

> queens can capture diagonally, if the square beyond the opponent's piece is empty (the queen lands on that square after the capture). it can then make another capture if possible on any diagonal
