type coord = {
  x: int,
  y: int,
};

type box = {
  title: string,
  location: (coord, coord),
};

/* State declaration */
type state = {
  startCoord: option(coord),
  endCoord: option(coord),
  boxes: list(box),
};

/* Action declaration */
type action =
  | MouseDown(int, int)
  | MouseMove(int, int)
  | MouseUp(int, int);