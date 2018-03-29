type coord = {
  x: int,
  y: int,
};

/* State declaration */
type state = {
  startCoord: option(coord),
  endCoord: option(coord),
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

type reducer = (action, state);

type middleware = reducer => reducer;