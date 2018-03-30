type coord = {
  x: int,
  y: int,
};

type box = (coord, coord);

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

type reducerInterface = {
  state,
  send: action => unit,
};

/* 'a is action, 's is state */
type reducer('a, 's) = ('a, 's);

type middleware('a, 's) = reducer('a, 's) => 's;